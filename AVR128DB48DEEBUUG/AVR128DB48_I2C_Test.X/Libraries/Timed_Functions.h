#define TCB0_Period_In_ms 10

#define ERROR_LED_Array_Size 6

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

void Set_Error_Pattern(enum problemevents error_code);

void Setup_Timed_Functions();

