// Typedefs for statemachine====================================================================================================
#include "mcc_generated_files/system/pins.h"
enum States {
	S_Error, //State waarin de problemstatemachine handelt en de normale state machine niks mag doen
	S_Init, //Opstart state
	S_Discharge, //Normale operatie
	S_Shutdown, //Batterij is leegg
	S_Charge, //Batterij aan het laden
	S_Batt_Full //Batterij vol, maar aan de lader
};
enum Events {
	E_Error,
	E_Error_Handled, //Probleem is afgehandelt door de problemstatemachine, normale statemachine mag opnieuw opstarten
	E_Init_Done, //Opstarten is afgelopen, klaar voor normale operatie
	E_No_Event, //Er gebeurt niks, doorgaan zoals net
	E_Batt_Empty, //Batterij is leeg, Accu moet uit
	E_Charger_Connected, //Lader is aangesloten, ga opladen
	E_Charger_Disconnected, //Lader is losgehaald, ga naar normale operatie
	E_Batt_Full //Batterij is volledig opgeladen ga naar S_Batt_Full
};
enum Flow { //Flow wordt gebruikt om de verschillende states aan elkaar te verbinden zonder dat er dingen fout gaan
	F_Entry,
	F_Run,
	F_Exit
};

//Includes=============================================================================================================================
#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include <avr/sleep.h>
#include "mcc_generated_files/adc/adc0.h"
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/power/power.h"

#include "Libraries/I2C.h"
#include "Libraries/Timed_Functions.h"

//ADC0_MOXPOS Defines==================================================================================================================
#define Temp_Cell_1 	0x07	//PF0
#define Temp_Cell_2 	0x06	//PD7
#define Temp_Cell_3 	0x05	//PD6
#define Temp_Cell_4 	0x04	//PD5
#define Cell_Voltage_1 	0x01	//PD2
#define Cell_Voltage_2 	0x00	//PD1
#define Cell_Voltage_3 	0x03	//PD4
#define Cell_Voltage_4 	0x02	//PD3

//Variables for statemachine============================================================================================================
enum States CurrentState = S_Init;
enum States NextState = S_Init; 
enum Events CurrentEvent = E_No_Event;
enum Flow CurrentFlow = F_Entry;

//ADC0_Result Variables===============================================================================================================
volatile uint16_t Temp_Cell_1_Result = 0;
volatile uint16_t Temp_Cell_2_Result = 0;
volatile uint16_t Temp_Cell_3_Result = 0;
volatile uint16_t Temp_Cell_4_Result = 0;
volatile uint16_t Cell_Voltage_1_Result = 0;
volatile uint16_t Cell_Voltage_2_Result = 0;
volatile uint16_t Cell_Voltage_3_Result = 0;
volatile uint16_t Cell_Voltage_4_Result = 0;
volatile bool ADC0_Filled_All_Values = false;

//Conversion Functions=================================================================================================================
uint16_t ADC0RES_to_mV(uint16_t ADCRES) {//Convert ADC result to mV
	return (ADCRES * 4096) / 3300;//3300mV reference, 12 bit ADC
}
uint16_t mV_to_CellVoltage(uint16_t mV){//Convert input to real cell voltage
	return (mV/1.2)+3000; //Voltage multiplier of 1.2, subtraction of 3000mV
}
uint16_t BFG_Result_to_Voltage(uint16_t BFG_RES){//Convert BFG LTC2943 result to voltage in mV
	return (23.6*(BFG_RES/65535));
}

//Hardware Functions=================================================================================================================
void ShutdownAllPins(){ //Zet alle output pinnen uit
	Drain_Cell_1_SetLow();
	Drain_Cell_2_SetLow();
	Drain_Cell_3_SetLow();
	Drain_Cell_4_SetLow();
	EN_Batt_SetLow();
	EN_Lader_SetLow();
}
void PrepareBFG(enum LTC2943_ADC_Mode ADC_Mode, enum LTC2943_Prescalar_Mode Prescalar_Mode, enum LTC2943_ALCC_Pin_Mode ALCC_Pin_Mode) {//Zet de BFG in de goed modus
	Current_LTC2943_ADC_Mode = ADC_Mode;
	Current_LTC2943_Prescalar_Mode = Prescalar_Mode;
	Current_LTC2943_ALCC_Pin_Mode = ALCC_Pin_Mode;
	LTC2943_Shutdown = 0;
	Write_Control_REG();
}

//Interrupt handlers================================================================================================================
void ADC0_Conversion_Done_ISR () { //Lees ADC uit
	switch (ADC0_MUXPOS) {
		case Temp_Cell_1:
			Temp_Cell_1_Result = ADC0RES_to_mV(ADC0.RES); //Schrijf ADC waarde naar een globale variabele
			ADC0_ChannelSelect(Temp_Cell_2); //Selecteer het volgende kanaal
			break;
		case Temp_Cell_2:
			Temp_Cell_2_Result = ADC0RES_to_mV(ADC0.RES);
			ADC0_ChannelSelect(Temp_Cell_3);
			break;
		case Temp_Cell_3:
			Temp_Cell_3_Result = ADC0RES_to_mV(ADC0.RES);
			ADC0_ChannelSelect(Temp_Cell_4);
			break;
		case Temp_Cell_4:
			VREF.ADC0REF = 0x0; //Zet vref naar 1.024V
			Temp_Cell_4_Result = ADC0RES_to_mV(ADC0.RES);
			ADC0_ChannelSelect(Cell_Voltage_1);
			break;
		case Cell_Voltage_1:
			Cell_Voltage_1_Result = mV_to_CellVoltage(ADC0RES_to_mV(ADC0.RES));
			ADC0_ChannelSelect(Cell_Voltage_2);
			break;
		case Cell_Voltage_2:
			Cell_Voltage_2_Result = mV_to_CellVoltage(ADC0RES_to_mV(ADC0.RES));
			ADC0_ChannelSelect(Cell_Voltage_3);
			break;
		case Cell_Voltage_3:
			Cell_Voltage_3_Result = mV_to_CellVoltage(ADC0RES_to_mV(ADC0.RES));
			ADC0_ChannelSelect(Cell_Voltage_4);
			break;
		case Cell_Voltage_4:
			VREF.ADC0REF = 0x5; //Zet vref naar VDD
			Cell_Voltage_4_Result = mV_to_CellVoltage(ADC0RES_to_mV(ADC0.RES));
			ADC0_ChannelSelect(Temp_Cell_1);
			if (!ADC0_Filled_All_Values){
				ADC0_Filled_All_Values = true;
			}
			break;
		default://Alleen bij opstarten, want Channel nog niet geselecteerd
			ADC0_ChannelSelect(Temp_Cell_1);
			break;
		}
}
void Enable_External_Balancer_ISR () { //Microcontroller mag niet bemoeien met externe lader, dus alles uit
	DISABLE_INTERRUPTS();
	ShutdownAllPins();
	while(1){sleep_mode();};
}
void BFG_Alert_ISR () {
	;
}
void Charger_Connect_ISR (){ //De interupt handler voor het aansluiten en loshalen van de lader
	if(Lader_Output_GetValue()){ // Dit kan misgaan door contactdender!!!
		CurrentEvent = E_Charger_Connected;
	}
	else {
		CurrentEvent = E_Charger_Disconnected;
	}
}


// Statemachine Functions============================================================================================================
void Switch_State (){ //Schakel naar nieuwe state
	CurrentState = NextState;
	CurrentFlow = F_Entry;
}
void Error_Entry (){
	ShutdownAllPins();
}
enum Events Init_Run(){
	PrepareBFG(Automatic_Mode, M_256, Alert_Mode);
	//Instellen van de limieten
	Set_LTC2943_REG(Current_Threshold_High_REG, 60073); //Deze moeten misschien andersom
	Set_LTC2943_REG(Current_Threshold_Low_REG, 38228);
	Set_LTC2943_REG(Voltage_Threshold_High_REG, 41098);
	Set_LTC2943_REG(Voltage_Threshold_Low_REG, 33323);
	Set_LTC2943_REG(Charge_Threshold_Low_REG, 51417);// Nog een keer checken

	return E_Init_Done;
}
enum Events Discharge_Entry(){
	return E_No_Event;
}
enum Events Discharge_Run(){
	return E_No_Event;
}
void Discharge_Exit(){
	;
}
enum Events Charge_Entry(){
	return E_No_Event;
}
enum Events Charge_Run(){
	return E_No_Event;
}
void Charge_Exit(){
	;
}
enum Events Batt_Full_Entry(){
	return E_No_Event;
}
enum Events Batt_Full_Run(){
	return E_No_Event;
}
void Batt_Full_Exit(){
	;
}
enum Events Shutdown_Entry(){
	return E_No_Event;
}
enum Events Shutdown_Run(){
	return E_No_Event;
}
void Shutdown_Exit(){
	;
}



//Main Function=========================================================================================================================
int main () {
	SYSTEM_Initialize();
	Setup_Timed_Functions();
	ADC0_ConversionDoneCallbackRegister(ADC0_Conversion_Done_ISR);
	EN_EXT_Balance_SetInterruptHandler(Enable_External_Balancer_ISR);
	BFG_Alert_SetInterruptHandler(BFG_Alert_ISR);
	Lader_Output_SetInterruptHandler(Charger_Connect_ISR);
	while(1) {
		switch (CurrentState){
			case S_Error:
				switch (CurrentEvent){
					case E_Error_Handled:
						NextState = S_Init;
						CurrentFlow = F_Exit;
						break;
					default:
						break;
				}
				switch (CurrentFlow){
					case F_Entry:
					case F_Run:
						break;
					case F_Exit:
						Switch_State ();
						break;
				}
			case S_Init:
				switch (CurrentEvent){
					case E_Init_Done:
						NextState = S_Discharge;
						CurrentFlow = F_Exit;
						break;
					case E_Error:
						NextState = S_Error;
						CurrentFlow = F_Exit;
						break;
					default:
						break;

				}
				switch (CurrentFlow){
					case F_Entry:
					case F_Run:
						CurrentEvent = Init_Run();
						break;
					case F_Exit:
						Switch_State ();
						break;
				}
			case S_Discharge:
				switch (CurrentEvent){
					case E_Charger_Connected:
						NextState = S_Charge;
						CurrentFlow = F_Exit;
						break;
					case E_Batt_Empty:
						NextState = S_Shutdown;
						CurrentFlow = F_Exit;
						break;
					case E_Error:
						NextState = S_Error;
						CurrentFlow = F_Exit;
						break;
					default:
						break;
				}
				switch (CurrentFlow){
					case F_Entry:
						CurrentEvent = Discharge_Entry();
						break;
					case F_Run:
						CurrentEvent = Discharge_Run();
						break;
					case F_Exit:
						Discharge_Exit();
						Switch_State ();
						break;
				}
			case S_Charge:
				switch (CurrentEvent){
					case E_Batt_Full:
						NextState = S_Batt_Full;
						CurrentFlow = F_Exit;
						break;
					case E_Charger_Disconnected:
						NextState = S_Discharge;
						CurrentFlow = F_Exit;
						break;
					case E_Error:
						NextState = S_Error;
						CurrentFlow = F_Exit;
						break;
					default:
						break;
				}
				switch (CurrentFlow){
					case F_Entry:
						CurrentEvent = Charge_Entry();
						break;
					case F_Run:
						CurrentEvent = Charge_Run();
						break;
					case F_Exit:
						Charge_Exit();
						Switch_State ();
						break;
				}
			case S_Batt_Full:
				switch (CurrentEvent){
					case E_Charger_Disconnected:
						NextState = S_Discharge;
						CurrentFlow = F_Exit;
						break;
					case E_Batt_Empty:
						NextState = S_Charge;
						CurrentFlow = F_Exit;
						break;
					case E_Error:
						NextState = S_Error;
						CurrentFlow = F_Exit;
						break;
					default:
						break;
				}
				switch (CurrentFlow){
					case F_Entry:
						CurrentEvent = Batt_Full_Entry();
						break;
					case F_Run:
						CurrentEvent = Batt_Full_Run();
						break;
					case F_Exit:
						Batt_Full_Exit();
						Switch_State ();
						break;
				}
			case S_Shutdown:
				switch (CurrentEvent){
					case E_Charger_Connected:
						NextState = S_Charge;
						CurrentFlow = F_Exit;
						break;
					case E_Error:
						NextState = S_Error;
						CurrentFlow = F_Exit;
						break;
					default:
						break;
				}
				switch (CurrentFlow){
					case F_Entry:
						CurrentEvent = Shutdown_Entry();
						break;
					case F_Run:
						CurrentEvent = Shutdown_Run();
						break;
					case F_Exit:
						Shutdown_Exit();
						Switch_State ();
						break;
				}
		}
	}
	return 0;
}