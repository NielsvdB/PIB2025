#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include "mcc_generated_files/adc/adc0.h"
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/power/power.h"

#include "Libraries/I2C.h"

//Maximum Parameters
#define TempRatio 0.3327 //R(T)/R(25C). In datasheet NTC, Thermistors 10KOhm 5%, Mouser number: 581-NB20K00103JBA.
#define MaxTemp 22440/(6800+3786*TempRatio) // Conversion from resistance to temperature using Tempratio
#define Amount_Of_Overtemps_Allowed 2 //Number of allowed overtemps

//BFG charge defines
#define Charge_Scale 0.340*(50/5)*(256/4096) //Each bit represents 0.2125mAh
#define Batt_Capacity_mAh 3200 //Battery capacity in mAh
#define Lowest_Allowed_Charge_Normal_Operation 20 //Lowest allowed charge percentage before shutdown (Within normal operation)
#define Absolute_Lowest_Allowed_Charge 15 //Absolute lowest allowed charge percentage before shutdown
//ADC0_MOXPOS Defines
#define Temp_Cell_1 	0x07	//PF0
#define Temp_Cell_2 	0x06	//PD7
#define Temp_Cell_3 	0x05	//PD6
#define Temp_Cell_4 	0x04	//PD5
#define Check_3v3 		0x08	//PF1 Must be changed to enable internal nets, because of broken pin============================================
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

//Amount of overtemps
volatile uint8_t Overtemp_Count = 0;
//Acumulated Charge Variables
volatile uint16_t Accumulated_Charge = 0;

//Designate enums===================================================================
enum flow {
	F_Entry, 
	F_Exit, 
	F_Run};
enum state {
	S_NoState,
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
enum problemevents CurrentEvent = PE_NoEvent;
enum problemstates CurrentProblemState = PS_NoState;
enum problemstates NextProblemState = PS_NoState;
enum problemevents ProblemEvent = PE_NoEvent;
enum flow flow = F_Entry;
enum flow problemflow = F_Entry;



//Functions ===================================================================
uint16_t ADC0RES_to_mV(uint16_t ADCRES) {//Convert ADC result to mV
	return (ADCRES * 4096) / 3300;//3300mV reference, 12 bit ADC
}
uint16_t mV_to_CellVoltage(uint16_t mV){//Convert input to real cell voltage
	return (mV/1.2)+3000; //Voltage multiplier of 1.2, subtraction of 3000mV
}
uint16_t BFG_Result_to_Voltage(uint16_t BFG_RES){//Convert BFG LTC2943 result to voltage in mV
	return (23.6*(BFG_RES/65535));
}
void Enable_External_Balancer_Interrupt_Handler(){ //Interupt of external balancer pin
	problemevents = PE_Ext_Balance;
}
void BFG_Alert_Interrupt_Handler(){ //Alert from BFG LTC2943
	ProblemEvent = PE_Alert;
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


uint16_t CheckAccumulatedCharge(){
	Accumulated_Charge = ((Charge_Scale*(Get_LTC2943_REG(Charge_MSB_REG) << 8) | Get_LTC2943_REG(Charge_LSB_REG))/Batt_Capacity_mAh)*100;//Convert to percentage of total capacity;
	return Accumulated_Charge;
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
enum problemevents SelfCheck() {
	Batt_Percentage = CheckAccumulatedCharge();
	if (Batt_Percentage <= Lowest_Allowed_Charge_Normal_Operation){
		CurrentEvent = E_Batt_Empty;
		return PE_NoEvent;
	}
	else if (Batt_Percentage < Absolute_Lowest_Allowed_Charge){
		return PE_Undervolt;
	}

	while(!ADC0_Filled_All_Values){;};
	if(TempCheck()){
		if(Overtemp_Count >= Amount_Of_Overtemps_Allowed){
			return PE_scnd_Overtemp;
		}
		else {
			return PE_Overtemp;
		}
	}
	else {
		return PE_NoEvent;
	}
}

enum problemevents Overtemp(){
	enum problemevents selfcheckresult = SelfCheck();
	if(selfcheckresult == PE_NoEvent){
		return PE_NoEvent;
	}
	else if(selfcheckresult == PE_Overtemp){
		if(!TempCheck()){
			Overtemp_Count++;
			return PE_NoEvent;
		}
		else{
			return PE_Overtemp;
		}
	}
	else if(selfcheckresult == PE_scnd_Overtemp){
		return PE_scnd_Overtemp;
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
void PrepareCharging(bool OnOrOff) {
	;
}
void Charging() {
	ProblemEvent = SelfCheck();
}
void PrepareShutdown(bool OnOrOff) {
	POWER_LowPowerModeEnter(POWER_STDBY_MODE);
}
void ProblemEntry(bool OnOrOff) {
	if(OnOrOff){
		EnableCharging(0);
		EnableInternalNet(0);
		CurrentState = S_NoState;
	}
	else{
		EnableCharging(1);
		EnableInternalNet(1);
		CurrentState = S_Init;
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
	if(LTC2943_Error_Status_Array[6]){ //Current Alert
		return PE_OverCurrent;
	}
	if(LTC2943_Error_Status_Array[1]){ //Voltage Alert
		uint16_t Voltage = BFG_Result_to_Voltage(Get_LTC2943_REG(Voltage_REG));
		if(Voltage <12800){//If voltage is below 12.8V
			return PE_Undervolt;
		}
		else if (Voltage >14600 && Voltage < 14800){//If voltage is above 14.6V and below 14.8V
			DischargeCell();
		}
		else if (Voltage >=14800){//If voltage is above 14.8V
			return PE_Extreme_Overvolt;
		}
		else {// If nothing seems to be wrong
			return PE_NoEvent;
		}
	}
	if(LTC2943_Error_Status_Array[4]){ //Temperature Alert
		return PE_BFG_Overtemp;
	}
	if(LTC2943_Error_Status_Array[2]){ //Charge Alert Low
		CurrentEvent = E_Batt_Empty;
		return PE_NoEvent;
	}
	if (LTC2943_Error_Status_Array[3]){ //Charge Alert High
		CurrentEvent = E_Batt_Full;
		return PE_NoEvent;
	}
	if (LTC2943_Error_Status_Array[5]){ //Accumulated Charge Overflow/ Underflow
		return PE_CountFail;
	}
	if (LTC2943_Error_Status_Array[0]){ //Undervoltage Lockout Alert
		return PE_Ext_Balance; //Output of BFG not trustworthy, use external balancer
	}
}


void PrepareTotalShutdown() {
	;
}

void FixCountFail(){
	if (CurrentState == S_Charge){//Asuming counter overflowed, reset charge to full charge, because counter can only overflow when charging.
		LTC2943_Write_REG(Charge_MSB_REG, 0xFF);
		LTC2943_Write_REG(Charge_LSB_REG, 0xFF);
	}
	else{//Asuming counter underflowed, reset charge to empty charge, because counter can only underflow when discharging.
		LTC2943_Write_REG(Charge_MSB_REG, 0x00);
		LTC2943_Write_REG(Charge_LSB_REG, 0x00);
	}
}
void ProblemEvents() {
	switch (ProblemEvent) {
	case PE_NoEvent:
		
		problemflow = F_Exit;
		NextProblemState = PS_NoState;
		break;
	case PE_Ext_Balance:
		problemflow = F_Exit;
		NextProblemState = PS_Total_Shutdown;
		break;
	case PE_Alert:
		problemflow = F_Exit;
		NextProblemState = PS_BFG_Alert;
		break;
	case PE_Undervolt:
		problemflow = F_Exit;
		NextProblemState = PS_Total_Shutdown;
		break;
	case PE_Extreme_Overvolt:
		problemflow = F_Exit;
		NextProblemState = PS_Total_Shutdown;
		break;
	case PE_Unbalance:
		problemflow = F_Exit;
		NextProblemState = PS_Cell_Voltage;
		break;
	case PE_Overtemp:
		problemflow = F_Exit;
		NextProblemState = PS_Overtemp;
		break;
	case PE_scnd_Overtemp:
		problemflow = F_Exit;
		NextProblemState = PS_Total_Shutdown;
		break;
	case PE_CountFail:
		FixCountFail();
		break;
	case PE_OverCurrent:
		problemflow = F_Exit;
		NextProblemState = PS_Total_Shutdown;
		break;
	case PE_Overvoltage:
		problemflow = F_Exit;
		NextProblemState = PS_Cell_Voltage;
		break;
	}
	Set_Error_Pattern(NextProblemState);


}


//Main Loop ===============================================================================================
int main() {
	SYSTEM_Initialize();
	Setup_Timed_Functions();
	ADC0_ConversionDoneCallbackRegister(ADC0_Conversion_Done);
	EN_EXT_Balance_DefaultInterruptHandler(Enable_External_Balancer_Interrupt_Handler);
	BFG_Alert_DefaultInterruptHandler(BFG_Alert_Interrupt_Handler);
	while (1) {
		switch (CurrentState) {
			case S_NoState:
				break;
			case S_Init:
				switch (flow) {
					case F_Entry: //Setup
						PrepareBFG(Automatic_Mode, M_256, Alert_Mode);
						ProblemEvent = SelfCheck();
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
						Set_Error_Pattern(PE_Ext_Balance);
					case F_Run:
						Charging();
						break;
					case F_Exit: // Disable Charging port
						PrepareCharging(0);
						Set_Error_Pattern(PE_NoEvent);
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
		ProblemEvents();
		switch (CurrentProblemState) {
			case PS_NoState:
				switch (problemflow) {
						case F_Entry:
							;
						case F_Run:
							;
							break;
						case F_Exit:
							;
							problemflow = F_Entry;
							break;
					}
				break;
			case PS_BFG_Alert:
				switch (problemflow) {
					case F_Entry:
						ProblemEntry(1);
					case F_Run:
						BFG_Check();
						break;
					case F_Exit:
						ProblemEntry(0);
						problemflow = F_Entry;
						break;
				}
				break;
			case PS_Overtemp:
				switch (problemflow) {
					case F_Entry:
						ProblemEntry(1);
					case F_Run:
						Overtemp();
						break;
					case F_Exit:
						ProblemEntry(0);
						problemflow = F_Entry;
						break;
				}
				break;
			case PS_Cell_Voltage:
				switch (problemflow) {
					case F_Entry:
						ProblemEntry(1);
					case F_Run:
						CellFix();
						break;
					case F_Exit:
						ProblemEntry(0);
						problemflow = F_Entry;
						break;
				}
				break;
			case PS_Total_Shutdown:
				switch (problemflow) {
					case F_Entry:
						ProblemEntry(1);
						PrepareTotalShutdown();
					case F_Run:
						break;
					case F_Exit:
						break;
				}
				break;
		}
		CurrentState = NextState;
		CurrentProblemState = NextProblemState;
		if(ProblemEvent == PE_NoEvent){
			POWER_LowPowerModeEnter(POWER_IDLE_MODE);
		}
	}
	return 0;
}