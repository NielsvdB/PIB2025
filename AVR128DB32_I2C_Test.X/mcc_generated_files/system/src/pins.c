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
© [2026] Microchip Technology Inc. and its subsidiaries.

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
static void (*SCL_LTC2943_InterruptHandler)(void);
static void (*SDA_LTC2943_InterruptHandler)(void);
static void (*SCL_Slave_InterruptHandler)(void);
static void (*SDA_Slave_InterruptHandler)(void);
static void (*Cell_2_Pin_InterruptHandler)(void);
static void (*Cell_1_Pin_InterruptHandler)(void);
static void (*Cell_4_Pin_InterruptHandler)(void);
static void (*Cell_3_Pin_InterruptHandler)(void);
static void (*Temp_Cell_4_Pin_InterruptHandler)(void);
static void (*Temp_Cell_3_Pin_InterruptHandler)(void);
static void (*Temp_Cell_2_Pin_InterruptHandler)(void);
static void (*Temp_Cell_1_Pin_InterruptHandler)(void);
static void (*Check_3V3_Pin_InterruptHandler)(void);
static void (*BFG_Alert_InterruptHandler)(void);
static void (*EN_EXT_Balance_InterruptHandler)(void);
static void (*Drain_Cell_1_InterruptHandler)(void);
static void (*Drain_Cell_2_InterruptHandler)(void);
static void (*Drain_Cell_3_InterruptHandler)(void);
static void (*Drain_Cell_4_InterruptHandler)(void);
static void (*EN_Buck_InterruptHandler)(void);
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
    SCL_LTC2943_SetInterruptHandler(SCL_LTC2943_DefaultInterruptHandler);
    SDA_LTC2943_SetInterruptHandler(SDA_LTC2943_DefaultInterruptHandler);
    SCL_Slave_SetInterruptHandler(SCL_Slave_DefaultInterruptHandler);
    SDA_Slave_SetInterruptHandler(SDA_Slave_DefaultInterruptHandler);
    Cell_2_Pin_SetInterruptHandler(Cell_2_Pin_DefaultInterruptHandler);
    Cell_1_Pin_SetInterruptHandler(Cell_1_Pin_DefaultInterruptHandler);
    Cell_4_Pin_SetInterruptHandler(Cell_4_Pin_DefaultInterruptHandler);
    Cell_3_Pin_SetInterruptHandler(Cell_3_Pin_DefaultInterruptHandler);
    Temp_Cell_4_Pin_SetInterruptHandler(Temp_Cell_4_Pin_DefaultInterruptHandler);
    Temp_Cell_3_Pin_SetInterruptHandler(Temp_Cell_3_Pin_DefaultInterruptHandler);
    Temp_Cell_2_Pin_SetInterruptHandler(Temp_Cell_2_Pin_DefaultInterruptHandler);
    Temp_Cell_1_Pin_SetInterruptHandler(Temp_Cell_1_Pin_DefaultInterruptHandler);
    Check_3V3_Pin_SetInterruptHandler(Check_3V3_Pin_DefaultInterruptHandler);
    BFG_Alert_SetInterruptHandler(BFG_Alert_DefaultInterruptHandler);
    EN_EXT_Balance_SetInterruptHandler(EN_EXT_Balance_DefaultInterruptHandler);
    Drain_Cell_1_SetInterruptHandler(Drain_Cell_1_DefaultInterruptHandler);
    Drain_Cell_2_SetInterruptHandler(Drain_Cell_2_DefaultInterruptHandler);
    Drain_Cell_3_SetInterruptHandler(Drain_Cell_3_DefaultInterruptHandler);
    Drain_Cell_4_SetInterruptHandler(Drain_Cell_4_DefaultInterruptHandler);
    EN_Buck_SetInterruptHandler(EN_Buck_DefaultInterruptHandler);
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
  Allows selecting an interrupt handler for SCL_LTC2943 at application runtime
*/
void SCL_LTC2943_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    SCL_LTC2943_InterruptHandler = interruptHandler;
}

void SCL_LTC2943_DefaultInterruptHandler(void)
{
    // add your SCL_LTC2943 interrupt custom code
    // or set custom function using SCL_LTC2943_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for SDA_LTC2943 at application runtime
*/
void SDA_LTC2943_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    SDA_LTC2943_InterruptHandler = interruptHandler;
}

void SDA_LTC2943_DefaultInterruptHandler(void)
{
    // add your SDA_LTC2943 interrupt custom code
    // or set custom function using SDA_LTC2943_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for SCL_Slave at application runtime
*/
void SCL_Slave_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    SCL_Slave_InterruptHandler = interruptHandler;
}

void SCL_Slave_DefaultInterruptHandler(void)
{
    // add your SCL_Slave interrupt custom code
    // or set custom function using SCL_Slave_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for SDA_Slave at application runtime
*/
void SDA_Slave_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    SDA_Slave_InterruptHandler = interruptHandler;
}

void SDA_Slave_DefaultInterruptHandler(void)
{
    // add your SDA_Slave interrupt custom code
    // or set custom function using SDA_Slave_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for Cell_2_Pin at application runtime
*/
void Cell_2_Pin_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    Cell_2_Pin_InterruptHandler = interruptHandler;
}

void Cell_2_Pin_DefaultInterruptHandler(void)
{
    // add your Cell_2_Pin interrupt custom code
    // or set custom function using Cell_2_Pin_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for Cell_1_Pin at application runtime
*/
void Cell_1_Pin_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    Cell_1_Pin_InterruptHandler = interruptHandler;
}

void Cell_1_Pin_DefaultInterruptHandler(void)
{
    // add your Cell_1_Pin interrupt custom code
    // or set custom function using Cell_1_Pin_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for Cell_4_Pin at application runtime
*/
void Cell_4_Pin_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    Cell_4_Pin_InterruptHandler = interruptHandler;
}

void Cell_4_Pin_DefaultInterruptHandler(void)
{
    // add your Cell_4_Pin interrupt custom code
    // or set custom function using Cell_4_Pin_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for Cell_3_Pin at application runtime
*/
void Cell_3_Pin_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    Cell_3_Pin_InterruptHandler = interruptHandler;
}

void Cell_3_Pin_DefaultInterruptHandler(void)
{
    // add your Cell_3_Pin interrupt custom code
    // or set custom function using Cell_3_Pin_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for Temp_Cell_4_Pin at application runtime
*/
void Temp_Cell_4_Pin_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    Temp_Cell_4_Pin_InterruptHandler = interruptHandler;
}

void Temp_Cell_4_Pin_DefaultInterruptHandler(void)
{
    // add your Temp_Cell_4_Pin interrupt custom code
    // or set custom function using Temp_Cell_4_Pin_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for Temp_Cell_3_Pin at application runtime
*/
void Temp_Cell_3_Pin_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    Temp_Cell_3_Pin_InterruptHandler = interruptHandler;
}

void Temp_Cell_3_Pin_DefaultInterruptHandler(void)
{
    // add your Temp_Cell_3_Pin interrupt custom code
    // or set custom function using Temp_Cell_3_Pin_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for Temp_Cell_2_Pin at application runtime
*/
void Temp_Cell_2_Pin_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    Temp_Cell_2_Pin_InterruptHandler = interruptHandler;
}

void Temp_Cell_2_Pin_DefaultInterruptHandler(void)
{
    // add your Temp_Cell_2_Pin interrupt custom code
    // or set custom function using Temp_Cell_2_Pin_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for Temp_Cell_1_Pin at application runtime
*/
void Temp_Cell_1_Pin_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    Temp_Cell_1_Pin_InterruptHandler = interruptHandler;
}

void Temp_Cell_1_Pin_DefaultInterruptHandler(void)
{
    // add your Temp_Cell_1_Pin interrupt custom code
    // or set custom function using Temp_Cell_1_Pin_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for Check_3V3_Pin at application runtime
*/
void Check_3V3_Pin_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    Check_3V3_Pin_InterruptHandler = interruptHandler;
}

void Check_3V3_Pin_DefaultInterruptHandler(void)
{
    // add your Check_3V3_Pin interrupt custom code
    // or set custom function using Check_3V3_Pin_SetInterruptHandler()
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
  Allows selecting an interrupt handler for EN_Buck at application runtime
*/
void EN_Buck_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    EN_Buck_InterruptHandler = interruptHandler;
}

void EN_Buck_DefaultInterruptHandler(void)
{
    // add your EN_Buck interrupt custom code
    // or set custom function using EN_Buck_SetInterruptHandler()
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
       EN_Buck_InterruptHandler(); 
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
       SCL_Slave_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT2_bm)
    {
       SDA_Slave_InterruptHandler(); 
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
       Cell_2_Pin_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT2_bm)
    {
       Cell_1_Pin_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT3_bm)
    {
       Cell_4_Pin_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT4_bm)
    {
       Cell_3_Pin_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT5_bm)
    {
       Temp_Cell_4_Pin_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT6_bm)
    {
       Temp_Cell_3_Pin_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT7_bm)
    {
       Temp_Cell_2_Pin_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTD.INTFLAGS = 0xff;
}

ISR(PORTF_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTF.INTFLAGS & PORT_INT3_bm)
    {
       SCL_LTC2943_InterruptHandler(); 
    }
    if(VPORTF.INTFLAGS & PORT_INT2_bm)
    {
       SDA_LTC2943_InterruptHandler(); 
    }
    if(VPORTF.INTFLAGS & PORT_INT0_bm)
    {
       Temp_Cell_1_Pin_InterruptHandler(); 
    }
    if(VPORTF.INTFLAGS & PORT_INT1_bm)
    {
       Check_3V3_Pin_InterruptHandler(); 
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