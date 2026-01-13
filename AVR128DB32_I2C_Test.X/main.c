// Typedefs voor statemachine====================================================================================================
enum States {
	S_Error, //State waarin de problemstatemachine handelt en de normale state machine niks mag doen
	S_Init, //Opstart state
	S_Discharge, //Normale operatie
	S_Shutdown, //Batterij is leegg
	S_Charge, //Batterij aan het laden
	S_Batt_Full //Batterij vol, maar aan de lader
};
enum Events {
	E_Error, // Er is een probleem die niet kan worden opgelost door deze statemachine, de problemstatemachine neemt over
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

// Typedefs voor problem statemachine========================================================================================
enum ProblemStates {
	PS_No_Problem, //Er is geen probleem, deze statemachine doet niks
	PS_Overvolt,
	PS_Handle_BFG_Alert,
	PS_Total_Shutdown,
	PS_Count_Fix
};
enum ProblemEvents {
	PE_No_Event,
	PE_Alert,
	PE_Overtemp,
	PE_Undervolt,
	PE_Overvolt,
	PE_Count_Fail,
	PE_Single_Cell_Empty,
	PE_Over_Current,
	PE_BFG_Overtemp,
	PE_Systeem_Integratie_Nood
};


//Typedef voor I2C===============================================================================================================
enum HomeReg {
	HOME_STATUS = 0x00,
	HOME_COMMAND = 0x01,
	HOME_DATA_IN = 0x02,
	HOME_DATA_OUT = 0x03
};
//Includes=============================================================================================================================
#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include "mcc_generated_files/adc/adc0.h"
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/power/power.h"
#include "mcc_generated_files/system/pins.h"

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

//Cell defines=======================================================================================================================
#define Amount_Of_Cells 4
#define Min_Charge 600

//Cell voltage defines
#define Min_Cell_Voltage 3200
#define Max_Cell_Voltage 3700
#define Cell_Voltage_Start_Drain 3650
#define Cell_Voltage_Stop_Drain 3600

//Temp defines
#define Max_Temp 250

//BFG Maximums and Minimums
#define Max_Charge_Current_RAW 5462
#define Max_Discharge_Current_RAW 19100
#define Max_Battery_Voltage_RAW 41098
#define Min_Battery_Voltage_RAW 33323
#define Min_Battery_Charge_RAW 51417

//I2C================================================================================================================================
#define NUM_REGISTERS 4

//Variables voor statemachine============================================================================================================
enum States CurrentState = S_Init;
enum States NextState = S_Init; 
enum Events CurrentEvent = E_No_Event;
enum Flow CurrentFlow = F_Entry;

//Variables voor de problemstatemachine==============================================================================================
enum ProblemStates CurrentProblemState = PS_No_Problem;
enum ProblemStates NextProblemState = PS_No_Problem;
enum ProblemEvents CurrentProblemEvent = PE_No_Event;
bool OvervoltCells[Amount_Of_Cells] = {0};

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

//I2C Variables========================================================================================================================
static uint8_t register_data[NUM_REGISTERS] = {0, 0, 0, 0};
static uint8_t register_selected = 0;
static uint8_t rx_byte_count = 0; // NIEUWE TELLER: Aantal ontvangen data bytes (exclusief Adres)

//Cell Variables=====================================================================================================================
float Accumulated_Charge = 0;
//I2C naar systeemintegratie functios=================================================================================================
void set_home_status(uint8_t status_value) {
    if (status_value <= 4) {
        register_data[HOME_STATUS] = status_value;
    }
}
void process_command(uint8_t command) {
    switch (command) {
        case 10:
            CurrentEvent = E_Error;
            break;
        case 6:
            //Code voor starten met opladen
			CurrentEvent = E_Charger_Connected;
			set_home_status(1);
            break;
        case 7:
            //Code voor stoppen met opladen
			CurrentEvent = E_Batt_Full;
			set_home_status(1);
            break;
        default:
            //Code voor onbekende commando
            break;
    }
}
bool TWI0_EventHandler(i2c_client_transfer_event_t event) {
    switch(event) {
        case I2C_CLIENT_TRANSFER_EVENT_ADDR_MATCH:
            // Reset de teller voor een nieuwe Write/Read transactie.
            rx_byte_count = 0;
            return true; // Altijd ACK de adres-match

        case I2C_CLIENT_TRANSFER_EVENT_RX_READY: {
            uint8_t received = TWI0_ReadByte();
            rx_byte_count++; // Tel de ontvangen data byte

            // 1. REGISTER SELECTIE & COMMANDO/DATA ONTVANGEN (MASTER WRITE)
            if (rx_byte_count == 1) { 
                // Eerste data byte (het Register-adres)
                register_selected = received;
                // printf("Slave selecteert Register: 0x%X\n", register_selected);
            } else {
                // Tweede data byte (de Data voor het Register)
                if (register_selected < NUM_REGISTERS) {
                    register_data[register_selected] = received;
                    // printf("Slave ontvangt data voor 0x%X: %u\n", register_selected, received);
                    
                    if (register_selected == HOME_COMMAND) {
                        process_command(received);
                    }
                }
            }
            return true; // Altijd ACK om de volgende byte te ontvangen
        }

        case I2C_CLIENT_TRANSFER_EVENT_TX_READY: {
            // 2. DATA ZENDEN (MASTER READ)
            if (register_selected < NUM_REGISTERS) {
                uint8_t data_to_send = register_data[register_selected];
                TWI0_WriteByte(data_to_send);
                // printf("Slave stuurt Register 0x%X: %u\n", register_selected, data_to_send);
            } else {
                TWI0_WriteByte(0xFF);
            }
            return true;
        }

        case I2C_CLIENT_TRANSFER_EVENT_STOP_BIT_RECEIVED:
            // De transactie is volledig afgesloten, geen verdere actie nodig
            return true;

        default:
            return true;
    }
}


//Conversion Functions=================================================================================================================
uint16_t ADC0RES_to_mV(uint16_t ADCRES) {//Convert ADC result to mV
	return (ADCRES/4096) * 1024;//3300mV reference, 12 bit ADC
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
	CurrentProblemEvent = PE_Alert;
}
void Charger_Connect_ISR (){ //De interupt handler voor het aansluiten en loshalen van de lader
	if(Lader_Output_GetValue()){ // Dit kan misgaan door contactdender!!!
		CurrentEvent = E_Charger_Connected;
	}
	else {
		CurrentEvent = E_Charger_Disconnected;
	}
}

//Regular Functions==================================================================================================================
enum ProblemEvents TempCheck() {//Check if any temperature is above maximum
	if(Temp_Cell_1_Result > Max_Temp || Temp_Cell_2_Result > Max_Temp || Temp_Cell_3_Result > Max_Temp || Temp_Cell_4_Result > Max_Temp) {
		return PE_Overtemp;
	}else {
		return PE_No_Event;
	}
}

enum ProblemEvents Monitor_Batt (){
	Accumulated_Charge = Get_Battery_Charge_In_mAh();
	register_data[HOME_DATA_IN] = (Accumulated_Charge-600)/3000*100;
	if(Cell_Voltage_1_Result <= Min_Cell_Voltage || Cell_Voltage_2_Result <= Min_Cell_Voltage || Cell_Voltage_3_Result <= Min_Cell_Voltage || Cell_Voltage_4_Result <= Min_Cell_Voltage){
		CurrentEvent = E_Batt_Empty;
		return PE_No_Event;
	}
	else if (Cell_Voltage_1_Result >= Max_Cell_Voltage || Cell_Voltage_2_Result >= Max_Cell_Voltage || Cell_Voltage_3_Result >= Max_Cell_Voltage || Cell_Voltage_4_Result >= Max_Cell_Voltage){
		return PE_Overvolt;
	}
	else if(Accumulated_Charge < Min_Charge){
		CurrentEvent = E_Batt_Empty;
		return PE_No_Event;
	}
	else{
		return TempCheck();
	}
}

void Balance_Cells(){
	//Bypass cell 1 if voltage to high
	if(Cell_Voltage_1_Result > Cell_Voltage_Start_Drain){
		Drain_Cell_1_SetHigh();
	}
	else if (Cell_Voltage_1_Result < Cell_Voltage_Stop_Drain){
		Drain_Cell_1_SetLow();
	}

	//Bypass cell 2 if voltage to high
	if(Cell_Voltage_2_Result > Cell_Voltage_Start_Drain){
		Drain_Cell_2_SetHigh();
	}
	else if (Cell_Voltage_2_Result < Cell_Voltage_Stop_Drain){
		Drain_Cell_2_SetLow();
	}

	//Bypass cell 3 if voltage to high
	if(Cell_Voltage_3_Result > Cell_Voltage_Start_Drain){
		Drain_Cell_3_SetHigh();
	}
	else if (Cell_Voltage_3_Result < Cell_Voltage_Stop_Drain){
		Drain_Cell_3_SetLow();
	}
	
	//Bypass cell 4 if voltage to high
	if(Cell_Voltage_4_Result > Cell_Voltage_Start_Drain){
		Drain_Cell_4_SetHigh();
	}
	else if (Cell_Voltage_4_Result < Cell_Voltage_Stop_Drain){
		Drain_Cell_4_SetLow();
	}
}

bool IsBatteryCharged(){
	if (Cell_Voltage_1_Result >= Cell_Voltage_Stop_Drain && Cell_Voltage_2_Result >= Cell_Voltage_Stop_Drain && Cell_Voltage_3_Result >= Cell_Voltage_Stop_Drain && Cell_Voltage_4_Result >= Cell_Voltage_Stop_Drain){
		return true;
	}
	else {
		return false;
	}
}

enum Events Overcharged_Cells(){
	bool CheckOvervolt = 0;
	if(Cell_Voltage_1_Result > Max_Cell_Voltage){
		CheckOvervolt = 1;
		Drain_Cell_1_SetHigh();
	}
	else if(Cell_Voltage_1_Result <= Max_Cell_Voltage)
		Drain_Cell_1_SetLow();
	if(Cell_Voltage_2_Result > Max_Cell_Voltage){
		CheckOvervolt = 1;
		Drain_Cell_2_SetHigh();
	}
	else if(Cell_Voltage_2_Result <= Max_Cell_Voltage)
		Drain_Cell_2_SetLow();
	if(Cell_Voltage_3_Result > Max_Cell_Voltage){
		Drain_Cell_3_SetHigh();
		CheckOvervolt = 1;
	}
	else if(Cell_Voltage_3_Result <= Max_Cell_Voltage)
		Drain_Cell_3_SetLow();
	if(Cell_Voltage_4_Result > Max_Cell_Voltage){
		Drain_Cell_4_SetHigh();
		CheckOvervolt = 1;
	}
	else if(Cell_Voltage_4_Result <= Max_Cell_Voltage)
		Drain_Cell_4_SetLow();
	if (CheckOvervolt){
		CurrentProblemEvent = PE_Overvolt;
		return E_No_Event;
	}
	else {
		CurrentProblemEvent = PE_No_Event;
		return E_Error_Handled;
	}
}

// Statemachine Functions============================================================================================================
void Switch_State (){ //Schakel naar nieuwe state
	CurrentEvent = E_No_Event;
	CurrentState = NextState;
	CurrentFlow = F_Entry;
}
void Error_Entry (){
	ShutdownAllPins();
}
enum Events Init_Run(){
	PrepareBFG(Automatic_Mode, M_256, Alert_Mode);
	//Instellen van de limieten
	Set_LTC2943_REG(Accumulated_Charge_REG, 0xFFFF); //Zet de lading op max om errors te voorkomen
	Set_LTC2943_REG(Current_Threshold_High_REG, Max_Charge_Current_RAW);//	((MaxLaadStroom*ShuntWeerstand)/60mV*32767)+32767
	Set_LTC2943_REG(Current_Threshold_Low_REG, Max_Discharge_Current_RAW);//	((-MaxOntlaadStroom*ShuntWeerstand)/60mV*32767)+32767
	Set_LTC2943_REG(Voltage_Threshold_High_REG, Max_Battery_Voltage_RAW);
	Set_LTC2943_REG(Voltage_Threshold_Low_REG, Min_Battery_Voltage_RAW);
	Set_LTC2943_REG(Charge_Threshold_Low_REG, Min_Battery_Charge_RAW);// Nog een keer checken
    
	set_home_status(1);

    Clear_LTC2943_Alert();//Clears any error that was left from previous run
    
	return E_Init_Done;
}
enum Events Discharge_Entry(){
	EN_Batt_SetHigh();
	return E_No_Event;
}
enum Events Discharge_Run(){
	CurrentProblemEvent = Monitor_Batt();
	if (CurrentEvent == E_Batt_Empty){
		return E_Batt_Empty;
	}
	else{
		return E_No_Event;
	} 
}
void Discharge_Exit(){
	EN_Batt_SetLow();
}
enum Events Charge_Entry(){
	EN_Lader_SetHigh();
	set_home_status(3);
	return E_No_Event;
}
enum Events Charge_Run(){
	Balance_Cells();
	Accumulated_Charge = Get_Battery_Charge_In_mAh();
	CurrentProblemEvent = Monitor_Batt();
	TCA0.SINGLE.CMP1 = ((Accumulated_Charge-600)/3000*2E16-1);
	if (IsBatteryCharged()){
		return E_Batt_Full;
	}
	else{
		return E_No_Event;
	}
}
void Charge_Exit(){
	TCA0.SINGLE.CMP1 = 0;
	EN_Lader_SetLow();
	set_home_status(1);
}
enum Events Batt_Full_Entry(){
	return E_No_Event;
}
enum Events Batt_Full_Run(){
	CurrentProblemEvent = Monitor_Batt();
	if (CurrentEvent == E_Batt_Empty){
		return E_Batt_Empty;
	}
	else{
		return E_No_Event;
	} 
}
void Batt_Full_Exit(){
	;
}
enum Events Shutdown_Entry(){
	EN_Lader_SetLow();
	EN_Batt_SetLow();
	set_home_status(2);
	return E_No_Event;
}
enum Events Shutdown_Run(){
	CurrentProblemEvent = Monitor_Batt();
	if (CurrentEvent == E_Batt_Empty){
		return E_Batt_Empty;
	}
	else{
		return E_No_Event;
	} 
}
void Shutdown_Exit(){
	;
}

//ProblemState functions==================================================================================================================
enum Events Overvolt(){
	return Overcharged_Cells();
}
enum Events Handle_BFG_Alert(){
	Get_Active_Alerts();
	if (LTC2943_Error_Status_Array[0])
		CurrentProblemEvent = PE_No_Event;
	if (LTC2943_Error_Status_Array[1])
		CurrentProblemEvent = Monitor_Batt();
	if (LTC2943_Error_Status_Array[2])
		CurrentEvent = E_Batt_Empty;
	if (LTC2943_Error_Status_Array[3])
		CurrentEvent = E_Batt_Full;
	if (LTC2943_Error_Status_Array[4])
		CurrentProblemEvent = PE_BFG_Overtemp;
	if (LTC2943_Error_Status_Array[5])
		CurrentProblemEvent = PE_Count_Fail;
	if (LTC2943_Error_Status_Array[6])
		CurrentProblemEvent = PE_Over_Current;
    
    //Clear_LTC2943_Alert();// Moet nog op goede plekken gezet worden
    
	return E_No_Event;
}
void Total_Shutdown(){
	EN_Lader_SetLow();
	EN_Batt_SetLow();
	set_sleep_mode(SLEEP_MODE_STANDBY);
	sleep_mode();
}
enum Events CountFix(){
	if (IsBatteryCharged()){//If battery full reset counter to max
		Set_LTC2943_REG(Accumulated_Charge_REG, 0xFFFF);
	}
	else{//If battery not full reset counter to min
		Set_LTC2943_REG(Accumulated_Charge_REG, 0x0000);
	}
	return E_No_Event;
}


//Main Function=========================================================================================================================
int main () {
	SYSTEM_Initialize();
	Setup_Timed_Functions();
	ADC0_ConversionDoneCallbackRegister(ADC0_Conversion_Done_ISR);
	EN_EXT_Balance_SetInterruptHandler(Enable_External_Balancer_ISR);
	BFG_Alert_SetInterruptHandler(BFG_Alert_ISR);
	Lader_Input_SetInterruptHandler(Charger_Connect_ISR);
    //EN_Batt_SetHigh();
	while(1) {
		//Statemachine=================================
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
				break;
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
				break;
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
						CurrentFlow = F_Run;
						break;
					case F_Run:
						CurrentEvent = Discharge_Run();
						break;
					case F_Exit:
						Discharge_Exit();
						Switch_State ();
						break;
				}
				break;
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
						CurrentFlow = F_Run;
						break;
					case F_Run:
						CurrentEvent = Charge_Run();
						break;
					case F_Exit:
						Charge_Exit();
						Switch_State ();
						break;
				}
				break;
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
						CurrentFlow = F_Run;
						break;
					case F_Run:
						CurrentEvent = Batt_Full_Run();
						break;
					case F_Exit:
						Batt_Full_Exit();
						Switch_State ();
						break;
				}
				break;
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
						CurrentFlow = F_Run;
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
		//Problem statemachine ==================================
		Set_Error_Pattern(CurrentProblemEvent);
		switch (CurrentProblemState){
			case PS_No_Problem:
				switch (CurrentProblemEvent){
					case PE_Alert:
						NextProblemState = PS_Handle_BFG_Alert;
						CurrentEvent = E_Error;
						break;
					case PE_Overtemp:
					case PE_Undervolt:
					case PE_Over_Current:
					case PE_BFG_Overtemp:
					case PE_Systeem_Integratie_Nood:
						NextProblemState = PS_Total_Shutdown;
						CurrentEvent = E_Error;
						break;
					case PE_Overvolt:
						NextProblemState = PS_Overvolt;
						CurrentEvent = E_Error;
						break;
					case PE_Count_Fail:
						NextProblemState = PS_Count_Fix;
						CurrentEvent = E_Error;
						break;
					case PE_Single_Cell_Empty:
						NextProblemState = PS_No_Problem;
						CurrentEvent = E_Batt_Empty;
						CurrentEvent = E_Error;
						break;
					case PE_No_Event:
						NextProblemState = PS_No_Problem;
					default:
						break;
				}
				break;
			case PS_Overvolt:
				switch (CurrentProblemEvent){
					case PE_Overtemp:
					case PE_Undervolt:
					case PE_Over_Current:
					case PE_BFG_Overtemp:
					case PE_Systeem_Integratie_Nood:
						NextProblemState = PS_Total_Shutdown;
						break;
					case PE_No_Event:
						NextProblemState = PS_No_Problem;
					default:
						break;
				}
				CurrentEvent = Overvolt();
				break;
			case PS_Handle_BFG_Alert:
				switch (CurrentProblemEvent){
					case PE_Overtemp:
					case PE_Undervolt:
					case PE_Over_Current:
					case PE_BFG_Overtemp:
					case PE_Systeem_Integratie_Nood:
						NextProblemState = PS_Total_Shutdown;
						break;
					case PE_No_Event:
						NextProblemState = PS_No_Problem;
					default:
						break;
				}
				CurrentEvent = Handle_BFG_Alert();
				break;
			case PS_Total_Shutdown:
				Total_Shutdown();
				break;
			case PS_Count_Fix:
				CurrentEvent = CountFix();
				break;
		}
		CurrentProblemState = NextProblemState;
		set_sleep_mode(SLEEP_MODE_IDLE);
		sleep_mode();
	}
	return 0;
}