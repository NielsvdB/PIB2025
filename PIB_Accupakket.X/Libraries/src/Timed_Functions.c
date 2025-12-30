#include "../../mcc_generated_files/system/system.h"
#include "../Timed_Functions.h"

// --- Global Variables ---
volatile uint64_t Global_Timer = 0;

// LED Sequencer Variables
// [On, Off, On, Off, On, Off] durations in ms
volatile uint16_t LED_Pattern[ERROR_LED_Array_Size] = {2000, 0, 0, 0, 0, 0}; 
volatile uint8_t  LED_Step_Index = 0;
volatile uint64_t LED_Step_Counter = 0;

// Cell Drain (Kept simple as requested)
uint8_t Cell_Drain_Time = 100;
uint16_t Cell_Drain_Period_ms = 2000;

// --- Function Prototypes ---
void Update_LED_Sequencer(void);
void Update_Cell_Drain(void);

void Update_Timed_Functions(){
    Update_LED_Sequencer();
    Update_Cell_Drain();
}

// --- Interrupt ---
void TCB0_Interrupt(){
    Global_Timer++;
    Update_Timed_Functions();
    //TCB0.CNT = 0;
    
}

// --- The New Sequencer Logic ---
void Update_LED_Sequencer(){
    // 1. Increment time in current step
    LED_Step_Counter++;

    // 2. Check if current step is finished
    if(LED_Step_Counter >= LED_Pattern[LED_Step_Index]){
        
        // Reset counter for the next step
        LED_Step_Counter = 0;
        
        // Move to next step (0 -> 1 -> ... -> 5 -> 0)
        LED_Step_Index++;
        if(LED_Step_Index > ERROR_LED_Array_Size){
            LED_Step_Index = 0;
            TCB0.CNT = 0;
        }
    }

    // 3. Handle Output State
    // Even Index (0, 2, 4) = ON
    // Odd Index  (1, 3, 5) = OFF
    if((LED_Step_Index % 2) == 0){
        // If the duration of this ON step is 0, force LOW to be safe
        if(LED_Pattern[LED_Step_Index] == 0) LED_SetHigh();
        else LED_SetLow();
    } else {
        LED_SetHigh(); 
    }
}

// --- Cell Drain Logic (Unchanged) ---
void Update_Cell_Drain(){
    static uint16_t Drain_Counter = 0;
    Drain_Counter++;
    
    if(Drain_Counter >= Cell_Drain_Period_ms) Drain_Counter = 0;
    
    if(Drain_Counter < Cell_Drain_Time) {
        // Drain_Pin_SetHigh(); 
    } else {
        // Drain_Pin_SetLow();
    }
}

// --- Helper: Set Error Patterns ---
// Call this from Main to set the pattern
void Set_Error_Pattern(enum problemstates error_code){
    // Reset counters to start new pattern immediately
    LED_Step_Index = 0; 
    LED_Step_Counter = 0;

    switch(error_code){
        case 0: //NORMAL (Solid ON)
            LED_Pattern[0] = 1000; 
            LED_Pattern[1] = 0;
            LED_Pattern[2] = 0;    
            LED_Pattern[3] = 0;
            LED_Pattern[4] = 0;    
            LED_Pattern[5] = 0;
            break;

        case 1: //Ext balance
            LED_Pattern[0] = 200;  // ON
            LED_Pattern[1] = 200;  // OFF
            LED_Pattern[2] = 0;  // ON
            LED_Pattern[3] = 0;  // OFF
            LED_Pattern[4] = 0;  // ON
            LED_Pattern[5] = 0;  // OFF
            break;
            
        case 2: //Alert
            LED_Pattern[0] = 200;  // ON
            LED_Pattern[1] = 200;  // OFF
            LED_Pattern[2] = 200;  // ON
            LED_Pattern[3] = 200;  // OFF
            LED_Pattern[4] = 1000;  // ON
            LED_Pattern[5] = 200;  // OFF
            break;
        case 3: //Undervolt
            LED_Pattern[0] = 1;  // ON
            LED_Pattern[1] = 1000;  // OFF
            LED_Pattern[2] = 0;  // ON
            LED_Pattern[3] = 0;  // OFF
            LED_Pattern[4] = 0;  // ON
            LED_Pattern[5] = 0;  // OFF
            break;
        case 4: //Extreme Overvolt
            LED_Pattern[0] = 800;  // ON
            LED_Pattern[1] = 200;  // OFF
            LED_Pattern[2] = 0;  // ON
            LED_Pattern[3] = 0;  // OFF
            LED_Pattern[4] = 0;  // ON
            LED_Pattern[5] = 0;  // OFF
            break;
        case 5: //Unbalance
            LED_Pattern[0] = 200;  // ON
            LED_Pattern[1] = 200;  // OFF
            LED_Pattern[2] = 800;  // ON
            LED_Pattern[3] = 800;  // OFF
            LED_Pattern[4] = 0;  // ON
            LED_Pattern[5] = 0;  // OFF
            break;
        case 6: //Overtemp
        case 7: //Second Overtemp
            LED_Pattern[0] = 50;  // ON
            LED_Pattern[1] = 200;   // OFF
            LED_Pattern[2] = 0;  // ON
            LED_Pattern[3] = 0;   // OFF
            LED_Pattern[4] = 0;  // ON
            LED_Pattern[5] = 0;   // OFF
            break;
        case 8: //Count Fail
            LED_Pattern[0] = 500;  // ON
            LED_Pattern[1] = 400;   // OFF
            LED_Pattern[2] = 300;  // ON
            LED_Pattern[3] = 200;   // OFF
            LED_Pattern[4] = 100;  // ON
            LED_Pattern[5] = 50;   // OFF
            break;
        case 9: //Over Current
            LED_Pattern[0] = 50;  // ON
            LED_Pattern[1] = 50;   // OFF
            LED_Pattern[2] = 0;  // ON
            LED_Pattern[3] = 0;   // OFF
            LED_Pattern[4] = 0;  // ON
            LED_Pattern[5] = 0;   // OFF
            break;
        case 10: // Overvoltage
            LED_Pattern[0] = 50;  // ON
            LED_Pattern[1] = 50;  // OFF
            LED_Pattern[2] = 50;  // ON
            LED_Pattern[3] = 50;  // OFF
            LED_Pattern[4] = 50;  // ON
            LED_Pattern[5] = 500;  // OFF
            break;
    }
}

void Setup_Timed_Functions(){
    TCB0_CaptureCallbackRegister(TCB0_Interrupt);
}