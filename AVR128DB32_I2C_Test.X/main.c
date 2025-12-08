//Libraries
#include "mcc_generated_files/system/system.h"
#include "I2C.h"

//Designate enums===================================================================
enum flow {
	Entry, 
	Exit, 
	Run};
enum state {
	Init, 
	Discharge, 
	Idle, 
	Charge, 
	Shutdown};
enum events {
	NoEvent, 
	Batt_Empty, 
	Batt_Full, 
	Disconnect, 
	Plugin};
enum problemstates {
	NoState, 
	BFG_Alert,  
	Overtemp, 
	Cell_Voltage, 
	Total_Shutdown};
enum problemevents {NoEvent, 
	Ext_Balance, 
	Alert, 
	Undervolt, 
	Extreme_Overvolt, 
	Unbalance, 
	Overtemp, 
	scnd_Overtemp, 
	CountFail};

//Variables
enum state CurrentState = Init;
enum state NextState = Init;
enum events CurrentEvent = NoEvent;
enum problemstates CurrentProblemState = NoState;
enum problemstates NextProblemState = NoState;
enum problemevents ProblemEvent = NoEvent;
enum flow flow = Entry;
enum flow problemflow = Entry;

//Function prototypes===================================================================
void ProblemEvents() {
	switch (ProblemEvent) {
	case NoEvent:
		break;
	case Ext_Balance:
		problemflow = Exit;
		NextProblemState = Total_Shutdown;
		break;
	case Alert:
		problemflow = Exit;
		NextProblemState = BFG_Alert;
		break;
	case Undervolt:
		problemflow = Exit;
		NextProblemState = Total_Shutdown;
		break;
	case Extreme_Overvolt:
		problemflow = Exit;
		NextProblemState = Total_Shutdown;
		break;
	case Unbalance:
		problemflow = Exit;
		NextProblemState = Cell_Voltage;
		break;
	case Overtemp:
		problemflow = Exit;
		NextProblemState = Overtemp;
		break;
	case scnd_Overtemp:
		problemflow = Exit;
		NextProblemState = Total_Shutdown;
		break;
	}
}

void PrepareSelfCheck(bool OnOrOff) {
	;
}
void SelfCheck() {
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
	bool Active_Alerts[7] = Get_Active_Alerts();
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


//Main Loop ===============================================================================================
void main() {
	while (1) {
		switch (CurrentState) {
			case Init:
				switch (flow) {
					case Entry: //Setup
						PrepareSelfCheck(1);
					case Run: //Check
						SelfCheck();
						break;
					case Exit: //Prepare operation
						PrepareSelfCheck(0);
						break;
				}
				switch (CurrentEvent) {
					case NoEvent:
						break;
					case Batt_Empty:
						NextState = Shutdown;
						break;
				}
				break;
			case Discharge:
				switch (flow) {
					case Entry: //Enable internal nets
						EnableInternalNet(1);
					case Run://Check status
						SelfCheck(1);
						break;
					case Exit: //Disable internal nets
						EnableInternalNet(0);
						break;
				}
				switch (CurrentEvent) {
					case NoEvent:
						break;
					case Batt_Empty:
						NextState = Shutdown;
						break;
					case Plugin:
						NextState = Charge;
						break;
				}
				break;
			case Idle:
				switch (flow) {
					case Entry:
						;
					case Run:
						SelfCheck(1);
						break;
					case Exit:
						break;
				}
				switch (CurrentEvent) {
					case NoEvent:
						break;
					case Disconnect:
						NextState = Discharge;
						break;
				}
				break;
			case Charge:
				switch (flow) {
					case Entry: //Enable charging port
						PrepareCharging(1);
					case Run:
						Charging();
						break;
					case Exit: // Disable Charging port
						PrepareChargin(0);
						break;
				}
				switch (CurrentEvent) {
					case NoEvent:
						break;
					case Batt_Full:
						NextState = Idle;
						break;
					case Disconnect:
						NextState = Discharge;
						break;
				}
				break;
			case Shutdown:
				switch (flow) {
					case Entry:
						PrepareShutdown(1);
						break;
					case Run:
						break;
					case Exit:
						PrepareShutdown(0);
						break;
				}
				switch (CurrentEvent) {
					case NoEvent:
						break;
					case Plugin:
						NextState = Charge;
						break;
				}
				break;
		}
		ProblemEvents();
		switch (CurrentProblemState) {
			case NoState:
				break;
			case BFG_Alert:
				switch (problemflow) {
					case Entry:
						ProblemEntry(1);
					case Run:
						BFG_Check();
						break;
					case Exit:
						ProblemEntry(0);
						break;
				}
				break;
			case Overtemp:
				switch (problemflow) {
					case Entry:
						ProblemEntry(1);
					case Run:
						TempCheck();
						break;
					case Exit:
						ProblemEntry(0);
						break;
				}
				break;
			case Cell_Voltage:
				switch (problemflow) {
					case Entry:
						ProblemEntry(1);
					case Run:
						CellFix();
						break;
					case Exit:
						ProblemEntry(0);
						break;
				}
				break;
			case Total_Shutdown:
				switch (problemflow) {
					case Entry:
						ProblemEntry(1);
						PrepareTotalShutdown();
					case Run:
						break;
					case Exit:
						break;
				}
				break;
		}
		CurrentState = NextState;
		CurrentProblemState = NextProblemState;
	}
}



