#include <stdint.h>
#include "mcc_generated_files/system/system.h"

#include "Libraries/I2C.h"


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
	PE_OverCurrent
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
void PrepareBFG(bool OnOrOff) {
	Current_LTC2943_ADC_Mode = Automatic_Mode;
	Current_LTC2943_Prescalar_Mode = M_256;
	Current_LTC2943_ALCC_Pin_Mode = Alert_Mode;
	LTC2943_Shutdown = 0;
	Write_Control_REG();
}
enum events SelfCheck() {
	;
}
void EnableInternalNet(bool OnOrOff) {
	;
}
void EnableCharging(bool OnOrOff) {
	;
}
void PrepareCharging(bool OnOrOff) {
	;
}
void Charging() {
	;
}
void PrepareShutdown(bool OnOrOff) {
	;
}
void ProblemEntry(bool OnOrOff) {
	;
}
void BFG_Check() {
	;
}
void TempCheck() {
	;
}
void CellFix() {
	;
}
void PrepareTotalShutdown() {
	;
}

void FixCountFail(){
	;
}
void ProblemEvents() {
	switch (ProblemEvent) {
	case PE_NoEvent:
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
		;// Dit moet nog gebeuren.
	}


}


//Main Loop ===============================================================================================
int main() {
	SYSTEM_Initialize();
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
		ProblemEvents();
		switch (CurrentProblemState) {
			case PS_NoState:
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
						break;
				}
				break;
			case PS_Overtemp:
				switch (problemflow) {
					case F_Entry:
						ProblemEntry(1);
					case F_Run:
						TempCheck();
						break;
					case F_Exit:
						ProblemEntry(0);
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
	}
	return 0;
}