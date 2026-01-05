#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include "mcc_generated_files/adc/adc0.h"
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/power/power.h"
#include <avr/wdt.h>
#include "Libraries/I2C.h"

//Watchdog timer
#define wdt_reset() __asm__ __volatile__ ( "wdr")

//Maximum Parameters
#define TempRatio 0.3327 //R(T)/R(25C). In datasheet NTC, Thermistors 10KOhm 5%, Mouser number: 581-NB20K00103JBA.
#define MaxTemp 22440/(6800+3786*TempRatio) // Conversion from resistance to temperature using Tempratio

//ADC0_MOXPOS Defines
#define Temp_Cell_1 	0x07	//PF0
#define Temp_Cell_2 	0x06	//PD7
#define Temp_Cell_3 	0x05	//PD6
#define Temp_Cell_4 	0x04	//PD5
#define Check_3v3 		0x08	//PF1
#define Cell_Voltage_1 	0x01	//PD2
#define Cell_Voltage_2 	0x00	//PD1
#define Cell_Voltage_3 	0x03	//PD4
#define Cell_Voltage_4 	0x02	//PD3

//ADC0_Result Variables
volatile uint16_t Temp_Cell_1_Result = 0;
volatile uint16_t Temp_Cell_2_Result = 0;
volatile uint16_t Temp_Cell_3_Result = 0;
volatile uint16_t Temp_Cell_4_Result = 0;
volatile uint16_t Check_3v3_Result = 0;
volatile uint16_t Cell_Voltage_1_Result = 0;
volatile uint16_t Cell_Voltage_2_Result = 0;
volatile uint16_t Cell_Voltage_3_Result = 0;
volatile uint16_t Cell_Voltage_4_Result = 0;
volatile bool ADC0_Filled_All_Values = false;


//Designate enums===================================================================
enum flow {
	F_Entry, 
	F_Exit, 
	F_Run};
enum state {
	S_Init, 
	S_Discharge, 
	S_Idle, 
	S_Charge, 
	S_Shutdown};
enum events {
	E_NoEvent, 
	E_Batt_Empty, 
	E_Batt_Full, 
	E_Disconnect, 
	E_Plugin};
enum problemstates {
	PS_NoState, 
	PS_BFG_Alert,  
	PS_Overtemp, 
	PS_Cell_Voltage, 
	PS_Total_Shutdown};
enum problemevents {
    PE_NoEvent, 
	PE_Ext_Balance, 
	PE_Alert, 
	PE_Undervolt, 
	PE_Extreme_Overvolt, 
	PE_Unbalance, 
	PE_Overtemp, 
	PE_scnd_Overtemp, 
	PE_CountFail,
	PE_OverCurrent,
	PE_Overvoltage,
	PE_BFG_Overtemp
};

//Variables
enum state CurrentState = S_Init;
enum state NextState = S_Init;
enum events CurrentEvent = E_NoEvent;
enum problemstates CurrentProblemState = PS_NoState;
enum problemstates NextProblemState = PS_NoState;
enum problemevents ProblemEvent = PE_NoEvent;
enum flow flow = F_Entry;
enum flow problemflow = F_Entry;



//Functions ===================================================================
uint16_t ADC0RES_to_mV(uint16_t ADCRES) {//Convert ADC result to mV
	return (ADCRES * 3300) / 4095;//3300mV reference, 12 bit ADC
}
uint16_t mV_to_CellVoltage(uint16_t mV){//Convert input to real cell voltage
	return (mV/1.2)+3000;
}
uint16_t BFG_Result_to_Voltage(uint16_t BFGRES){//Convert BFG LTC2943 result to voltage in mV
	return (23.6*(BFGRES/65535));
}

void ADC0_Conversion_Done(){//Callback function when ADC conversion is done
	switch (ADC0_MUXPOS) {
		case Temp_Cell_1:
			Temp_Cell_1_Result = ADC0RES_to_mV(ADC0.RES);
			ADC0_ChannelSelect(Temp_Cell_2);
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
			Temp_Cell_4_Result = ADC0RES_to_mV(ADC0.RES);
			ADC0_ChannelSelect(Check_3v3);
			break;
		case Check_3v3:
			Check_3v3_Result = ADC0RES_to_mV(ADC0.RES);
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
			Cell_Voltage_4_Result = mV_to_CellVoltage(ADC0RES_to_mV(ADC0.RES));
			ADC0_ChannelSelect(Temp_Cell_1);
			if (!ADC0_Filled_All_Values){
				ADC0_Filled_All_Values = true;
			}
			break;
		default://Only at startup
			ADC0_ChannelSelect(Temp_Cell_1);
			break;
	}
}




bool TempCheck() {//Check if any temperature is above maximum
	if(Temp_Cell_1_Result > MaxTemp || Temp_Cell_2_Result > MaxTemp || Temp_Cell_3_Result > MaxTemp || Temp_Cell_4_Result > MaxTemp) {
		return 1;
	}else {
		return 0;
	}
}
void PrepareBFG(enum LTC2943_ADC_Mode ADC_Mode, enum LTC2943_Prescalar_Mode Prescalar_Mode, enum LTC2943_ALCC_Pin_Mode ALCC_Pin_Mode) {//Prepare BFG LTC2943 for operation
	Current_LTC2943_ADC_Mode = ADC_Mode;
	Current_LTC2943_Prescalar_Mode = Prescalar_Mode;
	Current_LTC2943_ALCC_Pin_Mode = ALCC_Pin_Mode;
	LTC2943_Shutdown = 0;
	Write_Control_REG();
}
enum events SelfCheck() {
	while(!ADC0_Filled_All_Values){;};
	if(TempCheck() == 1){
		return E_Batt_Empty;
	}
	else {
		return E_NoEvent;
	}
}
void EnableInternalNet(bool OnOrOff) {
	if (OnOrOff){
		EN_Buck_SetHigh();
		EN_Batt_SetHigh();
	}
	else{
		EN_Buck_SetLow();
		EN_Batt_SetLow();
	}
	
}
void SetVBatt(bool OnOrOff) {
	if(OnOrOff){
		EN_Batt_SetHigh();
	}
	else{
		EN_Batt_SetLow();
	}
}
void EnableCharging(bool OnOrOff) {
	if( OnOrOff){
		EN_Lader_SetHigh();
	}
	else{
		EN_Lader_SetLow();
	}
}
void Charging() {
	CurrentEvent = SelfCheck();
}
void PrepareShutdown(bool OnOrOff) {
	 POWER_LowPowerModeEnter(POWER_STDBY_MODE);
}
void ProblemEntry(bool OnOrOff) {
	if(OnOrOff){
		EnableCharging(0);
		EnableInternalNet(0);
	}
	else{
		EnableCharging(1);
		EnableInternalNet(1);
	}
}

void DischargeCell(){//Discharge cells that are above 3.65V with hysteresis of 0.27V
	//Drain cell 1
	if(Cell_Voltage_1_Result > 3650){
		Drain_Cell_1_SetHigh();
	}
	else if (Cell_Voltage_1_Result <= 3380){
		Drain_Cell_1_SetLow();
	}
	//Drain cell 2
	if(Cell_Voltage_2_Result > 3650){
		Drain_Cell_2_SetHigh();
	}
	else if (Cell_Voltage_2_Result <= 3380){
		Drain_Cell_2_SetLow();
	}
	//Drain cell 3
	if(Cell_Voltage_3_Result > 3650){
		Drain_Cell_3_SetHigh();
	}
	else if (Cell_Voltage_3_Result <= 3380){
		Drain_Cell_3_SetLow();
	}
	//Drain cell 4
	if(Cell_Voltage_4_Result > 3650){
		Drain_Cell_4_SetHigh();
	}
	else if (Cell_Voltage_4_Result <= 3380){
		Drain_Cell_4_SetLow();
	}
}
enum problemevents BFG_Check() {
	Get_Active_Alerts();
	if(LTC2943_Error_Status_Array[6]){ //Overcurrent
		CurrentEvent = E_Batt_Empty;
	}
	if(LTC2943_Error_Status_Array[1]){ //Voltage Alert
		uint16_t Voltage = BFG_Result_to_Voltage(Get_LTC2943_REG(Voltage_REG));
		if(Voltage <12800){//If voltage is below 12.8V
			CurrentEvent = E_Batt_Empty;
		}
		else if (Voltage >14600 && Voltage < 14800){//If voltage is above 14.6V and below 14.8V
			// DischargeCell();
			CurrentEvent = E_Batt_Empty;
		}
		else if (Voltage >=14800){//If voltage is above 14.8V
			CurrentEvent = E_Batt_Empty;
		}
		else {// If nothing seems to be wrong
			ProblemEvent = PE_NoEvent;
		}
	}
	if(LTC2943_Error_Status_Array[4]){ //Temperature Alert
		CurrentEvent = E_Batt_Empty;
	}
}
//Main Loop ===============================================================================================
int main() {
	SYSTEM_Initialize();

	ADC0_ConversionDoneCallbackRegister(ADC0_Conversion_Done);

	while (1) {
		switch (CurrentState) {
			case S_Init:
				switch (flow) {
					case F_Entry: //Setup
						CurrentEvent = SelfCheck();
					case F_Run: //Check
						break;
					case F_Exit: //Prepare operation
						break;
				}
				switch (CurrentEvent) {
					case E_NoEvent:
						break;
					case E_Batt_Empty:
						NextState = S_Shutdown;
						break;
					default:
						break;
				}
				break;
			case S_Discharge:
				switch (flow) {
					case F_Entry: //Enable internal nets
						EnableInternalNet(1);
					case F_Run://Check status
						CurrentEvent = SelfCheck();
						break;
					case F_Exit: //Disable internal nets
						EnableInternalNet(0);
						break;
				}
				switch (CurrentEvent) {
					case E_NoEvent:
						break;
					case E_Batt_Empty:
						NextState = S_Shutdown;
						break;
					case E_Plugin:
						NextState = S_Charge;
						break;
					default:
						break;
				}
				break;
			case S_Idle:
				switch (flow) {
					case F_Entry:
						;
					case F_Run:
						CurrentEvent = SelfCheck();
						break;
					case F_Exit:
						break;
				}
				switch (CurrentEvent) {
					case E_NoEvent:
						break;
					case E_Disconnect:
						NextState = S_Discharge;
						break;
					default:
						break;
				}
				break;
			case S_Charge:
				switch (flow) {
					case F_Entry: //Enable charging port
						PrepareCharging(1);
					case F_Run:
						Charging();
						break;
					case F_Exit: // Disable Charging port
						PrepareCharging(0);
						break;
				}
				switch (CurrentEvent) {
					case E_NoEvent:
						break;
					case E_Batt_Full:
						NextState = S_Idle;
						break;
					case E_Disconnect:
						NextState = S_Discharge;
						break;
					default:
						break;
				}
				break;
			case S_Shutdown:
				switch (flow) {
					case F_Entry:
						PrepareShutdown(1);
						break;
					case F_Run:
						break;
					case F_Exit:
						PrepareShutdown(0);
						break;
				}
				switch (CurrentEvent) {
					case E_NoEvent:
						break;
					case E_Plugin:
						NextState = S_Charge;
						break;
					default:
						break;
				}
				break;
		}
		CurrentState = NextState;
	}
	return 0;
}