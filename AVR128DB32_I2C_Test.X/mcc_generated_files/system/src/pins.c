/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 1.1.0
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#include "../pins.h"

static void (*Lader_Input_InterruptHandler)(void);
static void (*IO_PF3_InterruptHandler)(void);
static void (*IO_PF2_InterruptHandler)(void);
static void (*IO_PC3_InterruptHandler)(void);
static void (*IO_PC2_InterruptHandler)(void);
static void (*IO_PD1_InterruptHandler)(void);
static void (*IO_PD2_InterruptHandler)(void);
static void (*IO_PD3_InterruptHandler)(void);
static void (*IO_PD4_InterruptHandler)(void);
static void (*IO_PD5_InterruptHandler)(void);
static void (*IO_PD6_InterruptHandler)(void);
static void (*IO_PD7_InterruptHandler)(void);
static void (*IO_PF0_InterruptHandler)(void);
static void (*IO_PF1_InterruptHandler)(void);
static void (*BFG_Alert_InterruptHandler)(void);
static void (*EN_EXT_Balance_InterruptHandler)(void);
static void (*Drain_Cell_1_InterruptHandler)(void);
static void (*Drain_Cell_2_InterruptHandler)(void);
static void (*Drain_Cell_3_InterruptHandler)(void);
static void (*Drain_Cell_4_InterruptHandler)(void);
static void (*EN_Int_Net_InterruptHandler)(void);
static void (*EN_Lader_InterruptHandler)(void);
static void (*EN_Batt_InterruptHandler)(void);
static void (*Lader_Output_InterruptHandler)(void);
static void (*LED_InterruptHandler)(void);

void PIN_MANAGER_Initialize()
{

  /* OUT Registers Initialization */
    PORTA.OUT = 0x0;
    PORTC.OUT = 0x0;
    PORTD.OUT = 0x0;
    PORTF.OUT = 0x0;

  /* DIR Registers Initialization */
    PORTA.DIR = 0xEF;
    PORTC.DIR = 0x3;
    PORTD.DIR = 0x0;
    PORTF.DIR = 0x10;

  /* PINxCTRL registers Initialization */
    PORTA.PIN0CTRL = 0x0;
    PORTA.PIN1CTRL = 0x0;
    PORTA.PIN2CTRL = 0x0;
    PORTA.PIN3CTRL = 0x0;
    PORTA.PIN4CTRL = 0x3;
    PORTA.PIN5CTRL = 0x0;
    PORTA.PIN6CTRL = 0x0;
    PORTA.PIN7CTRL = 0x0;
    PORTC.PIN0CTRL = 0x0;
    PORTC.PIN1CTRL = 0x2;
    PORTC.PIN2CTRL = 0x0;
    PORTC.PIN3CTRL = 0x0;
    PORTC.PIN4CTRL = 0x0;
    PORTC.PIN5CTRL = 0x0;
    PORTC.PIN6CTRL = 0x0;
    PORTC.PIN7CTRL = 0x0;
    PORTD.PIN0CTRL = 0x0;
    PORTD.PIN1CTRL = 0x0;
    PORTD.PIN2CTRL = 0x0;
    PORTD.PIN3CTRL = 0x0;
    PORTD.PIN4CTRL = 0x0;
    PORTD.PIN5CTRL = 0x0;
    PORTD.PIN6CTRL = 0x0;
    PORTD.PIN7CTRL = 0x0;
    PORTF.PIN0CTRL = 0x0;
    PORTF.PIN1CTRL = 0x0;
    PORTF.PIN2CTRL = 0x0;
    PORTF.PIN3CTRL = 0x0;
    PORTF.PIN4CTRL = 0x0;
    PORTF.PIN5CTRL = 0x2;
    PORTF.PIN6CTRL = 0x0;
    PORTF.PIN7CTRL = 0x0;

  /* PORTMUX Initialization */
    PORTMUX.ACROUTEA = 0x0;
    PORTMUX.CCLROUTEA = 0x0;
    PORTMUX.EVSYSROUTEA = 0x0;
    PORTMUX.SPIROUTEA = 0x0;
    PORTMUX.TCAROUTEA = 0x2;
    PORTMUX.TCBROUTEA = 0x0;
    PORTMUX.TCDROUTEA = 0x0;
    PORTMUX.TWIROUTEA = 0x2;
    PORTMUX.USARTROUTEA = 0x0;
    PORTMUX.ZCDROUTEA = 0x0;

  // register default ISC callback functions at runtime; use these methods to register a custom function
    Lader_Input_SetInterruptHandler(Lader_Input_DefaultInterruptHandler);
    IO_PF3_SetInterruptHandler(IO_PF3_DefaultInterruptHandler);
    IO_PF2_SetInterruptHandler(IO_PF2_DefaultInterruptHandler);
    IO_PC3_SetInterruptHandler(IO_PC3_DefaultInterruptHandler);
    IO_PC2_SetInterruptHandler(IO_PC2_DefaultInterruptHandler);
    IO_PD1_SetInterruptHandler(IO_PD1_DefaultInterruptHandler);
    IO_PD2_SetInterruptHandler(IO_PD2_DefaultInterruptHandler);
    IO_PD3_SetInterruptHandler(IO_PD3_DefaultInterruptHandler);
    IO_PD4_SetInterruptHandler(IO_PD4_DefaultInterruptHandler);
    IO_PD5_SetInterruptHandler(IO_PD5_DefaultInterruptHandler);
    IO_PD6_SetInterruptHandler(IO_PD6_DefaultInterruptHandler);
    IO_PD7_SetInterruptHandler(IO_PD7_DefaultInterruptHandler);
    IO_PF0_SetInterruptHandler(IO_PF0_DefaultInterruptHandler);
    IO_PF1_SetInterruptHandler(IO_PF1_DefaultInterruptHandler);
    BFG_Alert_SetInterruptHandler(BFG_Alert_DefaultInterruptHandler);
    EN_EXT_Balance_SetInterruptHandler(EN_EXT_Balance_DefaultInterruptHandler);
    Drain_Cell_1_SetInterruptHandler(Drain_Cell_1_DefaultInterruptHandler);
    Drain_Cell_2_SetInterruptHandler(Drain_Cell_2_DefaultInterruptHandler);
    Drain_Cell_3_SetInterruptHandler(Drain_Cell_3_DefaultInterruptHandler);
    Drain_Cell_4_SetInterruptHandler(Drain_Cell_4_DefaultInterruptHandler);
    EN_Int_Net_SetInterruptHandler(EN_Int_Net_DefaultInterruptHandler);
    EN_Lader_SetInterruptHandler(EN_Lader_DefaultInterruptHandler);
    EN_Batt_SetInterruptHandler(EN_Batt_DefaultInterruptHandler);
    Lader_Output_SetInterruptHandler(Lader_Output_DefaultInterruptHandler);
    LED_SetInterruptHandler(LED_DefaultInterruptHandler);
}

/**
  Allows selecting an interrupt handler for Lader_Input at application runtime
*/
void Lader_Input_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    Lader_Input_InterruptHandler = interruptHandler;
}

void Lader_Input_DefaultInterruptHandler(void)
{
    // add your Lader_Input interrupt custom code
    // or set custom function using Lader_Input_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PF3 at application runtime
*/
void IO_PF3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PF3_InterruptHandler = interruptHandler;
}

void IO_PF3_DefaultInterruptHandler(void)
{
    // add your IO_PF3 interrupt custom code
    // or set custom function using IO_PF3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PF2 at application runtime
*/
void IO_PF2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PF2_InterruptHandler = interruptHandler;
}

void IO_PF2_DefaultInterruptHandler(void)
{
    // add your IO_PF2 interrupt custom code
    // or set custom function using IO_PF2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PC3 at application runtime
*/
void IO_PC3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PC3_InterruptHandler = interruptHandler;
}

void IO_PC3_DefaultInterruptHandler(void)
{
    // add your IO_PC3 interrupt custom code
    // or set custom function using IO_PC3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PC2 at application runtime
*/
void IO_PC2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PC2_InterruptHandler = interruptHandler;
}

void IO_PC2_DefaultInterruptHandler(void)
{
    // add your IO_PC2 interrupt custom code
    // or set custom function using IO_PC2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PD1 at application runtime
*/
void IO_PD1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PD1_InterruptHandler = interruptHandler;
}

void IO_PD1_DefaultInterruptHandler(void)
{
    // add your IO_PD1 interrupt custom code
    // or set custom function using IO_PD1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PD2 at application runtime
*/
void IO_PD2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PD2_InterruptHandler = interruptHandler;
}

void IO_PD2_DefaultInterruptHandler(void)
{
    // add your IO_PD2 interrupt custom code
    // or set custom function using IO_PD2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PD3 at application runtime
*/
void IO_PD3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PD3_InterruptHandler = interruptHandler;
}

void IO_PD3_DefaultInterruptHandler(void)
{
    // add your IO_PD3 interrupt custom code
    // or set custom function using IO_PD3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PD4 at application runtime
*/
void IO_PD4_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PD4_InterruptHandler = interruptHandler;
}

void IO_PD4_DefaultInterruptHandler(void)
{
    // add your IO_PD4 interrupt custom code
    // or set custom function using IO_PD4_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PD5 at application runtime
*/
void IO_PD5_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PD5_InterruptHandler = interruptHandler;
}

void IO_PD5_DefaultInterruptHandler(void)
{
    // add your IO_PD5 interrupt custom code
    // or set custom function using IO_PD5_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PD6 at application runtime
*/
void IO_PD6_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PD6_InterruptHandler = interruptHandler;
}

void IO_PD6_DefaultInterruptHandler(void)
{
    // add your IO_PD6 interrupt custom code
    // or set custom function using IO_PD6_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PD7 at application runtime
*/
void IO_PD7_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PD7_InterruptHandler = interruptHandler;
}

void IO_PD7_DefaultInterruptHandler(void)
{
    // add your IO_PD7 interrupt custom code
    // or set custom function using IO_PD7_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PF0 at application runtime
*/
void IO_PF0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PF0_InterruptHandler = interruptHandler;
}

void IO_PF0_DefaultInterruptHandler(void)
{
    // add your IO_PF0 interrupt custom code
    // or set custom function using IO_PF0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IO_PF1 at application runtime
*/
void IO_PF1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IO_PF1_InterruptHandler = interruptHandler;
}

void IO_PF1_DefaultInterruptHandler(void)
{
    // add your IO_PF1 interrupt custom code
    // or set custom function using IO_PF1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for BFG_Alert at application runtime
*/
void BFG_Alert_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    BFG_Alert_InterruptHandler = interruptHandler;
}

void BFG_Alert_DefaultInterruptHandler(void)
{
    // add your BFG_Alert interrupt custom code
    // or set custom function using BFG_Alert_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for EN_EXT_Balance at application runtime
*/
void EN_EXT_Balance_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    EN_EXT_Balance_InterruptHandler = interruptHandler;
}

void EN_EXT_Balance_DefaultInterruptHandler(void)
{
    // add your EN_EXT_Balance interrupt custom code
    // or set custom function using EN_EXT_Balance_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for Drain_Cell_1 at application runtime
*/
void Drain_Cell_1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    Drain_Cell_1_InterruptHandler = interruptHandler;
}

void Drain_Cell_1_DefaultInterruptHandler(void)
{
    // add your Drain_Cell_1 interrupt custom code
    // or set custom function using Drain_Cell_1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for Drain_Cell_2 at application runtime
*/
void Drain_Cell_2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    Drain_Cell_2_InterruptHandler = interruptHandler;
}

void Drain_Cell_2_DefaultInterruptHandler(void)
{
    // add your Drain_Cell_2 interrupt custom code
    // or set custom function using Drain_Cell_2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for Drain_Cell_3 at application runtime
*/
void Drain_Cell_3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    Drain_Cell_3_InterruptHandler = interruptHandler;
}

void Drain_Cell_3_DefaultInterruptHandler(void)
{
    // add your Drain_Cell_3 interrupt custom code
    // or set custom function using Drain_Cell_3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for Drain_Cell_4 at application runtime
*/
void Drain_Cell_4_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    Drain_Cell_4_InterruptHandler = interruptHandler;
}

void Drain_Cell_4_DefaultInterruptHandler(void)
{
    // add your Drain_Cell_4 interrupt custom code
    // or set custom function using Drain_Cell_4_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for EN_Int_Net at application runtime
*/
void EN_Int_Net_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    EN_Int_Net_InterruptHandler = interruptHandler;
}

void EN_Int_Net_DefaultInterruptHandler(void)
{
    // add your EN_Int_Net interrupt custom code
    // or set custom function using EN_Int_Net_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for EN_Lader at application runtime
*/
void EN_Lader_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    EN_Lader_InterruptHandler = interruptHandler;
}

void EN_Lader_DefaultInterruptHandler(void)
{
    // add your EN_Lader interrupt custom code
    // or set custom function using EN_Lader_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for EN_Batt at application runtime
*/
void EN_Batt_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    EN_Batt_InterruptHandler = interruptHandler;
}

void EN_Batt_DefaultInterruptHandler(void)
{
    // add your EN_Batt interrupt custom code
    // or set custom function using EN_Batt_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for Lader_Output at application runtime
*/
void Lader_Output_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    Lader_Output_InterruptHandler = interruptHandler;
}

void Lader_Output_DefaultInterruptHandler(void)
{
    // add your Lader_Output interrupt custom code
    // or set custom function using Lader_Output_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for LED at application runtime
*/
void LED_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    LED_InterruptHandler = interruptHandler;
}

void LED_DefaultInterruptHandler(void)
{
    // add your LED interrupt custom code
    // or set custom function using LED_SetInterruptHandler()
}
ISR(PORTA_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTA.INTFLAGS & PORT_INT4_bm)
    {
       BFG_Alert_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT0_bm)
    {
       Drain_Cell_1_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT1_bm)
    {
       Drain_Cell_2_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT2_bm)
    {
       Drain_Cell_3_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT3_bm)
    {
       Drain_Cell_4_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT5_bm)
    {
       EN_Int_Net_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT6_bm)
    {
       EN_Lader_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT7_bm)
    {
       EN_Batt_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTA.INTFLAGS = 0xff;
}

ISR(PORTC_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTC.INTFLAGS & PORT_INT1_bm)
    {
       Lader_Input_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT3_bm)
    {
       IO_PC3_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT2_bm)
    {
       IO_PC2_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT0_bm)
    {
       Lader_Output_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTC.INTFLAGS = 0xff;
}

ISR(PORTD_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTD.INTFLAGS & PORT_INT1_bm)
    {
       IO_PD1_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT2_bm)
    {
       IO_PD2_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT3_bm)
    {
       IO_PD3_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT4_bm)
    {
       IO_PD4_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT5_bm)
    {
       IO_PD5_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT6_bm)
    {
       IO_PD6_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT7_bm)
    {
       IO_PD7_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTD.INTFLAGS = 0xff;
}

ISR(PORTF_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTF.INTFLAGS & PORT_INT3_bm)
    {
       IO_PF3_InterruptHandler(); 
    }
    if(VPORTF.INTFLAGS & PORT_INT2_bm)
    {
       IO_PF2_InterruptHandler(); 
    }
    if(VPORTF.INTFLAGS & PORT_INT0_bm)
    {
       IO_PF0_InterruptHandler(); 
    }
    if(VPORTF.INTFLAGS & PORT_INT1_bm)
    {
       IO_PF1_InterruptHandler(); 
    }
    if(VPORTF.INTFLAGS & PORT_INT5_bm)
    {
       EN_EXT_Balance_InterruptHandler(); 
    }
    if(VPORTF.INTFLAGS & PORT_INT4_bm)
    {
       LED_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTF.INTFLAGS = 0xff;
}

/**
 End of File
*/