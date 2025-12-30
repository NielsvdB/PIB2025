#define TCB0_Period_In_ms 1

#define ERROR_LED_Array_Size 6

extern volatile uint64_t Global_Timer;

void Set_Error_Pattern(enum problemstates error_code);

void Setup_Timed_Functions();