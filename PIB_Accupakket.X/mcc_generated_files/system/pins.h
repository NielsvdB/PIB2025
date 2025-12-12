/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  1.1.0
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

#ifndef PINS_H_INCLUDED
#define PINS_H_INCLUDED

#include <avr/io.h>
#include "./port.h"

//get/set Lader_Input aliases
#define Lader_Input_SetHigh() do { PORTC_OUTSET = 0x2; } while(0)
#define Lader_Input_SetLow() do { PORTC_OUTCLR = 0x2; } while(0)
#define Lader_Input_Toggle() do { PORTC_OUTTGL = 0x2; } while(0)
#define Lader_Input_GetValue() (VPORTC.IN & (0x1 << 1))
#define Lader_Input_SetDigitalInput() do { PORTC_DIRCLR = 0x2; } while(0)
#define Lader_Input_SetDigitalOutput() do { PORTC_DIRSET = 0x2; } while(0)
#define Lader_Input_SetPullUp() do { PORTC_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define Lader_Input_ResetPullUp() do { PORTC_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define Lader_Input_SetInverted() do { PORTC_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define Lader_Input_ResetInverted() do { PORTC_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define Lader_Input_DisableInterruptOnChange() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define Lader_Input_EnableInterruptForBothEdges() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define Lader_Input_EnableInterruptForRisingEdge() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define Lader_Input_EnableInterruptForFallingEdge() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define Lader_Input_DisableDigitalInputBuffer() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define Lader_Input_EnableInterruptForLowLevelSensing() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC1_SetInterruptHandler Lader_Input_SetInterruptHandler

//get/set IO_PF3 aliases
#define IO_PF3_SetHigh() do { PORTF_OUTSET = 0x8; } while(0)
#define IO_PF3_SetLow() do { PORTF_OUTCLR = 0x8; } while(0)
#define IO_PF3_Toggle() do { PORTF_OUTTGL = 0x8; } while(0)
#define IO_PF3_GetValue() (VPORTF.IN & (0x1 << 3))
#define IO_PF3_SetDigitalInput() do { PORTF_DIRCLR = 0x8; } while(0)
#define IO_PF3_SetDigitalOutput() do { PORTF_DIRSET = 0x8; } while(0)
#define IO_PF3_SetPullUp() do { PORTF_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PF3_ResetPullUp() do { PORTF_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PF3_SetInverted() do { PORTF_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PF3_ResetInverted() do { PORTF_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PF3_DisableInterruptOnChange() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PF3_EnableInterruptForBothEdges() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PF3_EnableInterruptForRisingEdge() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PF3_EnableInterruptForFallingEdge() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PF3_DisableDigitalInputBuffer() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PF3_EnableInterruptForLowLevelSensing() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PF3_SetInterruptHandler IO_PF3_SetInterruptHandler

//get/set IO_PF2 aliases
#define IO_PF2_SetHigh() do { PORTF_OUTSET = 0x4; } while(0)
#define IO_PF2_SetLow() do { PORTF_OUTCLR = 0x4; } while(0)
#define IO_PF2_Toggle() do { PORTF_OUTTGL = 0x4; } while(0)
#define IO_PF2_GetValue() (VPORTF.IN & (0x1 << 2))
#define IO_PF2_SetDigitalInput() do { PORTF_DIRCLR = 0x4; } while(0)
#define IO_PF2_SetDigitalOutput() do { PORTF_DIRSET = 0x4; } while(0)
#define IO_PF2_SetPullUp() do { PORTF_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PF2_ResetPullUp() do { PORTF_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PF2_SetInverted() do { PORTF_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PF2_ResetInverted() do { PORTF_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PF2_DisableInterruptOnChange() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PF2_EnableInterruptForBothEdges() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PF2_EnableInterruptForRisingEdge() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PF2_EnableInterruptForFallingEdge() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PF2_DisableDigitalInputBuffer() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PF2_EnableInterruptForLowLevelSensing() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PF2_SetInterruptHandler IO_PF2_SetInterruptHandler

//get/set IO_PC3 aliases
#define IO_PC3_SetHigh() do { PORTC_OUTSET = 0x8; } while(0)
#define IO_PC3_SetLow() do { PORTC_OUTCLR = 0x8; } while(0)
#define IO_PC3_Toggle() do { PORTC_OUTTGL = 0x8; } while(0)
#define IO_PC3_GetValue() (VPORTC.IN & (0x1 << 3))
#define IO_PC3_SetDigitalInput() do { PORTC_DIRCLR = 0x8; } while(0)
#define IO_PC3_SetDigitalOutput() do { PORTC_DIRSET = 0x8; } while(0)
#define IO_PC3_SetPullUp() do { PORTC_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PC3_ResetPullUp() do { PORTC_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PC3_SetInverted() do { PORTC_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PC3_ResetInverted() do { PORTC_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PC3_DisableInterruptOnChange() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PC3_EnableInterruptForBothEdges() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PC3_EnableInterruptForRisingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PC3_EnableInterruptForFallingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PC3_DisableDigitalInputBuffer() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PC3_EnableInterruptForLowLevelSensing() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC3_SetInterruptHandler IO_PC3_SetInterruptHandler

//get/set IO_PC2 aliases
#define IO_PC2_SetHigh() do { PORTC_OUTSET = 0x4; } while(0)
#define IO_PC2_SetLow() do { PORTC_OUTCLR = 0x4; } while(0)
#define IO_PC2_Toggle() do { PORTC_OUTTGL = 0x4; } while(0)
#define IO_PC2_GetValue() (VPORTC.IN & (0x1 << 2))
#define IO_PC2_SetDigitalInput() do { PORTC_DIRCLR = 0x4; } while(0)
#define IO_PC2_SetDigitalOutput() do { PORTC_DIRSET = 0x4; } while(0)
#define IO_PC2_SetPullUp() do { PORTC_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PC2_ResetPullUp() do { PORTC_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PC2_SetInverted() do { PORTC_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PC2_ResetInverted() do { PORTC_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PC2_DisableInterruptOnChange() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PC2_EnableInterruptForBothEdges() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PC2_EnableInterruptForRisingEdge() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PC2_EnableInterruptForFallingEdge() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PC2_DisableDigitalInputBuffer() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PC2_EnableInterruptForLowLevelSensing() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC2_SetInterruptHandler IO_PC2_SetInterruptHandler

//get/set IO_PD1 aliases
#define IO_PD1_SetHigh() do { PORTD_OUTSET = 0x2; } while(0)
#define IO_PD1_SetLow() do { PORTD_OUTCLR = 0x2; } while(0)
#define IO_PD1_Toggle() do { PORTD_OUTTGL = 0x2; } while(0)
#define IO_PD1_GetValue() (VPORTD.IN & (0x1 << 1))
#define IO_PD1_SetDigitalInput() do { PORTD_DIRCLR = 0x2; } while(0)
#define IO_PD1_SetDigitalOutput() do { PORTD_DIRSET = 0x2; } while(0)
#define IO_PD1_SetPullUp() do { PORTD_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PD1_ResetPullUp() do { PORTD_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PD1_SetInverted() do { PORTD_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PD1_ResetInverted() do { PORTD_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PD1_DisableInterruptOnChange() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PD1_EnableInterruptForBothEdges() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PD1_EnableInterruptForRisingEdge() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PD1_EnableInterruptForFallingEdge() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PD1_DisableDigitalInputBuffer() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PD1_EnableInterruptForLowLevelSensing() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD1_SetInterruptHandler IO_PD1_SetInterruptHandler

//get/set IO_PD2 aliases
#define IO_PD2_SetHigh() do { PORTD_OUTSET = 0x4; } while(0)
#define IO_PD2_SetLow() do { PORTD_OUTCLR = 0x4; } while(0)
#define IO_PD2_Toggle() do { PORTD_OUTTGL = 0x4; } while(0)
#define IO_PD2_GetValue() (VPORTD.IN & (0x1 << 2))
#define IO_PD2_SetDigitalInput() do { PORTD_DIRCLR = 0x4; } while(0)
#define IO_PD2_SetDigitalOutput() do { PORTD_DIRSET = 0x4; } while(0)
#define IO_PD2_SetPullUp() do { PORTD_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PD2_ResetPullUp() do { PORTD_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PD2_SetInverted() do { PORTD_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PD2_ResetInverted() do { PORTD_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PD2_DisableInterruptOnChange() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PD2_EnableInterruptForBothEdges() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PD2_EnableInterruptForRisingEdge() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PD2_EnableInterruptForFallingEdge() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PD2_DisableDigitalInputBuffer() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PD2_EnableInterruptForLowLevelSensing() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD2_SetInterruptHandler IO_PD2_SetInterruptHandler

//get/set IO_PD3 aliases
#define IO_PD3_SetHigh() do { PORTD_OUTSET = 0x8; } while(0)
#define IO_PD3_SetLow() do { PORTD_OUTCLR = 0x8; } while(0)
#define IO_PD3_Toggle() do { PORTD_OUTTGL = 0x8; } while(0)
#define IO_PD3_GetValue() (VPORTD.IN & (0x1 << 3))
#define IO_PD3_SetDigitalInput() do { PORTD_DIRCLR = 0x8; } while(0)
#define IO_PD3_SetDigitalOutput() do { PORTD_DIRSET = 0x8; } while(0)
#define IO_PD3_SetPullUp() do { PORTD_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PD3_ResetPullUp() do { PORTD_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PD3_SetInverted() do { PORTD_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PD3_ResetInverted() do { PORTD_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PD3_DisableInterruptOnChange() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PD3_EnableInterruptForBothEdges() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PD3_EnableInterruptForRisingEdge() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PD3_EnableInterruptForFallingEdge() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PD3_DisableDigitalInputBuffer() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PD3_EnableInterruptForLowLevelSensing() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD3_SetInterruptHandler IO_PD3_SetInterruptHandler

//get/set IO_PD4 aliases
#define IO_PD4_SetHigh() do { PORTD_OUTSET = 0x10; } while(0)
#define IO_PD4_SetLow() do { PORTD_OUTCLR = 0x10; } while(0)
#define IO_PD4_Toggle() do { PORTD_OUTTGL = 0x10; } while(0)
#define IO_PD4_GetValue() (VPORTD.IN & (0x1 << 4))
#define IO_PD4_SetDigitalInput() do { PORTD_DIRCLR = 0x10; } while(0)
#define IO_PD4_SetDigitalOutput() do { PORTD_DIRSET = 0x10; } while(0)
#define IO_PD4_SetPullUp() do { PORTD_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PD4_ResetPullUp() do { PORTD_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PD4_SetInverted() do { PORTD_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PD4_ResetInverted() do { PORTD_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PD4_DisableInterruptOnChange() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PD4_EnableInterruptForBothEdges() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PD4_EnableInterruptForRisingEdge() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PD4_EnableInterruptForFallingEdge() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PD4_DisableDigitalInputBuffer() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PD4_EnableInterruptForLowLevelSensing() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD4_SetInterruptHandler IO_PD4_SetInterruptHandler

//get/set IO_PD5 aliases
#define IO_PD5_SetHigh() do { PORTD_OUTSET = 0x20; } while(0)
#define IO_PD5_SetLow() do { PORTD_OUTCLR = 0x20; } while(0)
#define IO_PD5_Toggle() do { PORTD_OUTTGL = 0x20; } while(0)
#define IO_PD5_GetValue() (VPORTD.IN & (0x1 << 5))
#define IO_PD5_SetDigitalInput() do { PORTD_DIRCLR = 0x20; } while(0)
#define IO_PD5_SetDigitalOutput() do { PORTD_DIRSET = 0x20; } while(0)
#define IO_PD5_SetPullUp() do { PORTD_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PD5_ResetPullUp() do { PORTD_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PD5_SetInverted() do { PORTD_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PD5_ResetInverted() do { PORTD_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PD5_DisableInterruptOnChange() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PD5_EnableInterruptForBothEdges() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PD5_EnableInterruptForRisingEdge() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PD5_EnableInterruptForFallingEdge() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PD5_DisableDigitalInputBuffer() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PD5_EnableInterruptForLowLevelSensing() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD5_SetInterruptHandler IO_PD5_SetInterruptHandler

//get/set IO_PD6 aliases
#define IO_PD6_SetHigh() do { PORTD_OUTSET = 0x40; } while(0)
#define IO_PD6_SetLow() do { PORTD_OUTCLR = 0x40; } while(0)
#define IO_PD6_Toggle() do { PORTD_OUTTGL = 0x40; } while(0)
#define IO_PD6_GetValue() (VPORTD.IN & (0x1 << 6))
#define IO_PD6_SetDigitalInput() do { PORTD_DIRCLR = 0x40; } while(0)
#define IO_PD6_SetDigitalOutput() do { PORTD_DIRSET = 0x40; } while(0)
#define IO_PD6_SetPullUp() do { PORTD_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PD6_ResetPullUp() do { PORTD_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PD6_SetInverted() do { PORTD_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PD6_ResetInverted() do { PORTD_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PD6_DisableInterruptOnChange() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PD6_EnableInterruptForBothEdges() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PD6_EnableInterruptForRisingEdge() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PD6_EnableInterruptForFallingEdge() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PD6_DisableDigitalInputBuffer() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PD6_EnableInterruptForLowLevelSensing() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD6_SetInterruptHandler IO_PD6_SetInterruptHandler

//get/set IO_PD7 aliases
#define IO_PD7_SetHigh() do { PORTD_OUTSET = 0x80; } while(0)
#define IO_PD7_SetLow() do { PORTD_OUTCLR = 0x80; } while(0)
#define IO_PD7_Toggle() do { PORTD_OUTTGL = 0x80; } while(0)
#define IO_PD7_GetValue() (VPORTD.IN & (0x1 << 7))
#define IO_PD7_SetDigitalInput() do { PORTD_DIRCLR = 0x80; } while(0)
#define IO_PD7_SetDigitalOutput() do { PORTD_DIRSET = 0x80; } while(0)
#define IO_PD7_SetPullUp() do { PORTD_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PD7_ResetPullUp() do { PORTD_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PD7_SetInverted() do { PORTD_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PD7_ResetInverted() do { PORTD_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PD7_DisableInterruptOnChange() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PD7_EnableInterruptForBothEdges() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PD7_EnableInterruptForRisingEdge() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PD7_EnableInterruptForFallingEdge() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PD7_DisableDigitalInputBuffer() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PD7_EnableInterruptForLowLevelSensing() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD7_SetInterruptHandler IO_PD7_SetInterruptHandler

//get/set IO_PF0 aliases
#define IO_PF0_SetHigh() do { PORTF_OUTSET = 0x1; } while(0)
#define IO_PF0_SetLow() do { PORTF_OUTCLR = 0x1; } while(0)
#define IO_PF0_Toggle() do { PORTF_OUTTGL = 0x1; } while(0)
#define IO_PF0_GetValue() (VPORTF.IN & (0x1 << 0))
#define IO_PF0_SetDigitalInput() do { PORTF_DIRCLR = 0x1; } while(0)
#define IO_PF0_SetDigitalOutput() do { PORTF_DIRSET = 0x1; } while(0)
#define IO_PF0_SetPullUp() do { PORTF_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PF0_ResetPullUp() do { PORTF_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PF0_SetInverted() do { PORTF_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PF0_ResetInverted() do { PORTF_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PF0_DisableInterruptOnChange() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PF0_EnableInterruptForBothEdges() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PF0_EnableInterruptForRisingEdge() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PF0_EnableInterruptForFallingEdge() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PF0_DisableDigitalInputBuffer() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PF0_EnableInterruptForLowLevelSensing() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PF0_SetInterruptHandler IO_PF0_SetInterruptHandler

//get/set IO_PF1 aliases
#define IO_PF1_SetHigh() do { PORTF_OUTSET = 0x2; } while(0)
#define IO_PF1_SetLow() do { PORTF_OUTCLR = 0x2; } while(0)
#define IO_PF1_Toggle() do { PORTF_OUTTGL = 0x2; } while(0)
#define IO_PF1_GetValue() (VPORTF.IN & (0x1 << 1))
#define IO_PF1_SetDigitalInput() do { PORTF_DIRCLR = 0x2; } while(0)
#define IO_PF1_SetDigitalOutput() do { PORTF_DIRSET = 0x2; } while(0)
#define IO_PF1_SetPullUp() do { PORTF_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PF1_ResetPullUp() do { PORTF_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PF1_SetInverted() do { PORTF_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PF1_ResetInverted() do { PORTF_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PF1_DisableInterruptOnChange() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PF1_EnableInterruptForBothEdges() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PF1_EnableInterruptForRisingEdge() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PF1_EnableInterruptForFallingEdge() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PF1_DisableDigitalInputBuffer() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PF1_EnableInterruptForLowLevelSensing() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PF1_SetInterruptHandler IO_PF1_SetInterruptHandler

//get/set BFG_Alert aliases
#define BFG_Alert_SetHigh() do { PORTA_OUTSET = 0x10; } while(0)
#define BFG_Alert_SetLow() do { PORTA_OUTCLR = 0x10; } while(0)
#define BFG_Alert_Toggle() do { PORTA_OUTTGL = 0x10; } while(0)
#define BFG_Alert_GetValue() (VPORTA.IN & (0x1 << 4))
#define BFG_Alert_SetDigitalInput() do { PORTA_DIRCLR = 0x10; } while(0)
#define BFG_Alert_SetDigitalOutput() do { PORTA_DIRSET = 0x10; } while(0)
#define BFG_Alert_SetPullUp() do { PORTA_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define BFG_Alert_ResetPullUp() do { PORTA_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define BFG_Alert_SetInverted() do { PORTA_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define BFG_Alert_ResetInverted() do { PORTA_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define BFG_Alert_DisableInterruptOnChange() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define BFG_Alert_EnableInterruptForBothEdges() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define BFG_Alert_EnableInterruptForRisingEdge() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define BFG_Alert_EnableInterruptForFallingEdge() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define BFG_Alert_DisableDigitalInputBuffer() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define BFG_Alert_EnableInterruptForLowLevelSensing() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA4_SetInterruptHandler BFG_Alert_SetInterruptHandler

//get/set EN_EXT_Balance aliases
#define EN_EXT_Balance_SetHigh() do { PORTF_OUTSET = 0x20; } while(0)
#define EN_EXT_Balance_SetLow() do { PORTF_OUTCLR = 0x20; } while(0)
#define EN_EXT_Balance_Toggle() do { PORTF_OUTTGL = 0x20; } while(0)
#define EN_EXT_Balance_GetValue() (VPORTF.IN & (0x1 << 5))
#define EN_EXT_Balance_SetDigitalInput() do { PORTF_DIRCLR = 0x20; } while(0)
#define EN_EXT_Balance_SetDigitalOutput() do { PORTF_DIRSET = 0x20; } while(0)
#define EN_EXT_Balance_SetPullUp() do { PORTF_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define EN_EXT_Balance_ResetPullUp() do { PORTF_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define EN_EXT_Balance_SetInverted() do { PORTF_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define EN_EXT_Balance_ResetInverted() do { PORTF_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define EN_EXT_Balance_DisableInterruptOnChange() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define EN_EXT_Balance_EnableInterruptForBothEdges() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define EN_EXT_Balance_EnableInterruptForRisingEdge() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define EN_EXT_Balance_EnableInterruptForFallingEdge() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define EN_EXT_Balance_DisableDigitalInputBuffer() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define EN_EXT_Balance_EnableInterruptForLowLevelSensing() do { PORTF.PIN5CTRL = (PORTF.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PF5_SetInterruptHandler EN_EXT_Balance_SetInterruptHandler

//get/set Drain_Cell_1 aliases
#define Drain_Cell_1_SetHigh() do { PORTA_OUTSET = 0x1; } while(0)
#define Drain_Cell_1_SetLow() do { PORTA_OUTCLR = 0x1; } while(0)
#define Drain_Cell_1_Toggle() do { PORTA_OUTTGL = 0x1; } while(0)
#define Drain_Cell_1_GetValue() (VPORTA.IN & (0x1 << 0))
#define Drain_Cell_1_SetDigitalInput() do { PORTA_DIRCLR = 0x1; } while(0)
#define Drain_Cell_1_SetDigitalOutput() do { PORTA_DIRSET = 0x1; } while(0)
#define Drain_Cell_1_SetPullUp() do { PORTA_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define Drain_Cell_1_ResetPullUp() do { PORTA_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define Drain_Cell_1_SetInverted() do { PORTA_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define Drain_Cell_1_ResetInverted() do { PORTA_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define Drain_Cell_1_DisableInterruptOnChange() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define Drain_Cell_1_EnableInterruptForBothEdges() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define Drain_Cell_1_EnableInterruptForRisingEdge() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define Drain_Cell_1_EnableInterruptForFallingEdge() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define Drain_Cell_1_DisableDigitalInputBuffer() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define Drain_Cell_1_EnableInterruptForLowLevelSensing() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA0_SetInterruptHandler Drain_Cell_1_SetInterruptHandler

//get/set Drain_Cell_2 aliases
#define Drain_Cell_2_SetHigh() do { PORTA_OUTSET = 0x2; } while(0)
#define Drain_Cell_2_SetLow() do { PORTA_OUTCLR = 0x2; } while(0)
#define Drain_Cell_2_Toggle() do { PORTA_OUTTGL = 0x2; } while(0)
#define Drain_Cell_2_GetValue() (VPORTA.IN & (0x1 << 1))
#define Drain_Cell_2_SetDigitalInput() do { PORTA_DIRCLR = 0x2; } while(0)
#define Drain_Cell_2_SetDigitalOutput() do { PORTA_DIRSET = 0x2; } while(0)
#define Drain_Cell_2_SetPullUp() do { PORTA_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define Drain_Cell_2_ResetPullUp() do { PORTA_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define Drain_Cell_2_SetInverted() do { PORTA_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define Drain_Cell_2_ResetInverted() do { PORTA_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define Drain_Cell_2_DisableInterruptOnChange() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define Drain_Cell_2_EnableInterruptForBothEdges() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define Drain_Cell_2_EnableInterruptForRisingEdge() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define Drain_Cell_2_EnableInterruptForFallingEdge() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define Drain_Cell_2_DisableDigitalInputBuffer() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define Drain_Cell_2_EnableInterruptForLowLevelSensing() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA1_SetInterruptHandler Drain_Cell_2_SetInterruptHandler

//get/set Drain_Cell_3 aliases
#define Drain_Cell_3_SetHigh() do { PORTA_OUTSET = 0x4; } while(0)
#define Drain_Cell_3_SetLow() do { PORTA_OUTCLR = 0x4; } while(0)
#define Drain_Cell_3_Toggle() do { PORTA_OUTTGL = 0x4; } while(0)
#define Drain_Cell_3_GetValue() (VPORTA.IN & (0x1 << 2))
#define Drain_Cell_3_SetDigitalInput() do { PORTA_DIRCLR = 0x4; } while(0)
#define Drain_Cell_3_SetDigitalOutput() do { PORTA_DIRSET = 0x4; } while(0)
#define Drain_Cell_3_SetPullUp() do { PORTA_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define Drain_Cell_3_ResetPullUp() do { PORTA_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define Drain_Cell_3_SetInverted() do { PORTA_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define Drain_Cell_3_ResetInverted() do { PORTA_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define Drain_Cell_3_DisableInterruptOnChange() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define Drain_Cell_3_EnableInterruptForBothEdges() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define Drain_Cell_3_EnableInterruptForRisingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define Drain_Cell_3_EnableInterruptForFallingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define Drain_Cell_3_DisableDigitalInputBuffer() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define Drain_Cell_3_EnableInterruptForLowLevelSensing() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA2_SetInterruptHandler Drain_Cell_3_SetInterruptHandler

//get/set Drain_Cell_4 aliases
#define Drain_Cell_4_SetHigh() do { PORTA_OUTSET = 0x8; } while(0)
#define Drain_Cell_4_SetLow() do { PORTA_OUTCLR = 0x8; } while(0)
#define Drain_Cell_4_Toggle() do { PORTA_OUTTGL = 0x8; } while(0)
#define Drain_Cell_4_GetValue() (VPORTA.IN & (0x1 << 3))
#define Drain_Cell_4_SetDigitalInput() do { PORTA_DIRCLR = 0x8; } while(0)
#define Drain_Cell_4_SetDigitalOutput() do { PORTA_DIRSET = 0x8; } while(0)
#define Drain_Cell_4_SetPullUp() do { PORTA_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define Drain_Cell_4_ResetPullUp() do { PORTA_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define Drain_Cell_4_SetInverted() do { PORTA_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define Drain_Cell_4_ResetInverted() do { PORTA_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define Drain_Cell_4_DisableInterruptOnChange() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define Drain_Cell_4_EnableInterruptForBothEdges() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define Drain_Cell_4_EnableInterruptForRisingEdge() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define Drain_Cell_4_EnableInterruptForFallingEdge() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define Drain_Cell_4_DisableDigitalInputBuffer() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define Drain_Cell_4_EnableInterruptForLowLevelSensing() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA3_SetInterruptHandler Drain_Cell_4_SetInterruptHandler

//get/set EN_Buck aliases
#define EN_Buck_SetHigh() do { PORTA_OUTSET = 0x20; } while(0)
#define EN_Buck_SetLow() do { PORTA_OUTCLR = 0x20; } while(0)
#define EN_Buck_Toggle() do { PORTA_OUTTGL = 0x20; } while(0)
#define EN_Buck_GetValue() (VPORTA.IN & (0x1 << 5))
#define EN_Buck_SetDigitalInput() do { PORTA_DIRCLR = 0x20; } while(0)
#define EN_Buck_SetDigitalOutput() do { PORTA_DIRSET = 0x20; } while(0)
#define EN_Buck_SetPullUp() do { PORTA_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define EN_Buck_ResetPullUp() do { PORTA_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define EN_Buck_SetInverted() do { PORTA_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define EN_Buck_ResetInverted() do { PORTA_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define EN_Buck_DisableInterruptOnChange() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define EN_Buck_EnableInterruptForBothEdges() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define EN_Buck_EnableInterruptForRisingEdge() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define EN_Buck_EnableInterruptForFallingEdge() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define EN_Buck_DisableDigitalInputBuffer() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define EN_Buck_EnableInterruptForLowLevelSensing() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA5_SetInterruptHandler EN_Buck_SetInterruptHandler

//get/set EN_Lader aliases
#define EN_Lader_SetHigh() do { PORTA_OUTSET = 0x40; } while(0)
#define EN_Lader_SetLow() do { PORTA_OUTCLR = 0x40; } while(0)
#define EN_Lader_Toggle() do { PORTA_OUTTGL = 0x40; } while(0)
#define EN_Lader_GetValue() (VPORTA.IN & (0x1 << 6))
#define EN_Lader_SetDigitalInput() do { PORTA_DIRCLR = 0x40; } while(0)
#define EN_Lader_SetDigitalOutput() do { PORTA_DIRSET = 0x40; } while(0)
#define EN_Lader_SetPullUp() do { PORTA_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define EN_Lader_ResetPullUp() do { PORTA_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define EN_Lader_SetInverted() do { PORTA_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define EN_Lader_ResetInverted() do { PORTA_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define EN_Lader_DisableInterruptOnChange() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define EN_Lader_EnableInterruptForBothEdges() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define EN_Lader_EnableInterruptForRisingEdge() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define EN_Lader_EnableInterruptForFallingEdge() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define EN_Lader_DisableDigitalInputBuffer() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define EN_Lader_EnableInterruptForLowLevelSensing() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA6_SetInterruptHandler EN_Lader_SetInterruptHandler

//get/set EN_Batt aliases
#define EN_Batt_SetHigh() do { PORTA_OUTSET = 0x80; } while(0)
#define EN_Batt_SetLow() do { PORTA_OUTCLR = 0x80; } while(0)
#define EN_Batt_Toggle() do { PORTA_OUTTGL = 0x80; } while(0)
#define EN_Batt_GetValue() (VPORTA.IN & (0x1 << 7))
#define EN_Batt_SetDigitalInput() do { PORTA_DIRCLR = 0x80; } while(0)
#define EN_Batt_SetDigitalOutput() do { PORTA_DIRSET = 0x80; } while(0)
#define EN_Batt_SetPullUp() do { PORTA_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define EN_Batt_ResetPullUp() do { PORTA_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define EN_Batt_SetInverted() do { PORTA_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define EN_Batt_ResetInverted() do { PORTA_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define EN_Batt_DisableInterruptOnChange() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define EN_Batt_EnableInterruptForBothEdges() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define EN_Batt_EnableInterruptForRisingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define EN_Batt_EnableInterruptForFallingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define EN_Batt_DisableDigitalInputBuffer() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define EN_Batt_EnableInterruptForLowLevelSensing() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA7_SetInterruptHandler EN_Batt_SetInterruptHandler

//get/set Lader_Output aliases
#define Lader_Output_SetHigh() do { PORTC_OUTSET = 0x1; } while(0)
#define Lader_Output_SetLow() do { PORTC_OUTCLR = 0x1; } while(0)
#define Lader_Output_Toggle() do { PORTC_OUTTGL = 0x1; } while(0)
#define Lader_Output_GetValue() (VPORTC.IN & (0x1 << 0))
#define Lader_Output_SetDigitalInput() do { PORTC_DIRCLR = 0x1; } while(0)
#define Lader_Output_SetDigitalOutput() do { PORTC_DIRSET = 0x1; } while(0)
#define Lader_Output_SetPullUp() do { PORTC_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define Lader_Output_ResetPullUp() do { PORTC_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define Lader_Output_SetInverted() do { PORTC_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define Lader_Output_ResetInverted() do { PORTC_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define Lader_Output_DisableInterruptOnChange() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define Lader_Output_EnableInterruptForBothEdges() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define Lader_Output_EnableInterruptForRisingEdge() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define Lader_Output_EnableInterruptForFallingEdge() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define Lader_Output_DisableDigitalInputBuffer() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define Lader_Output_EnableInterruptForLowLevelSensing() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC0_SetInterruptHandler Lader_Output_SetInterruptHandler

//get/set LED aliases
#define LED_SetHigh() do { PORTF_OUTSET = 0x10; } while(0)
#define LED_SetLow() do { PORTF_OUTCLR = 0x10; } while(0)
#define LED_Toggle() do { PORTF_OUTTGL = 0x10; } while(0)
#define LED_GetValue() (VPORTF.IN & (0x1 << 4))
#define LED_SetDigitalInput() do { PORTF_DIRCLR = 0x10; } while(0)
#define LED_SetDigitalOutput() do { PORTF_DIRSET = 0x10; } while(0)
#define LED_SetPullUp() do { PORTF_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define LED_ResetPullUp() do { PORTF_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define LED_SetInverted() do { PORTF_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define LED_ResetInverted() do { PORTF_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define LED_DisableInterruptOnChange() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define LED_EnableInterruptForBothEdges() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define LED_EnableInterruptForRisingEdge() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define LED_EnableInterruptForFallingEdge() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define LED_DisableDigitalInputBuffer() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define LED_EnableInterruptForLowLevelSensing() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PF4_SetInterruptHandler LED_SetInterruptHandler

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize();

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for Lader_Input pin. 
 *        This is a predefined interrupt handler to be used together with the Lader_Input_SetInterruptHandler() method.
 *        This handler is called every time the Lader_Input ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void Lader_Input_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for Lader_Input pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for Lader_Input at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void Lader_Input_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PF3 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PF3_SetInterruptHandler() method.
 *        This handler is called every time the IO_PF3 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PF3_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PF3 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PF3 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PF3_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PF2 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PF2_SetInterruptHandler() method.
 *        This handler is called every time the IO_PF2 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PF2_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PF2 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PF2 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PF2_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PC3 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PC3_SetInterruptHandler() method.
 *        This handler is called every time the IO_PC3 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PC3_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PC3 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PC3 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PC3_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PC2 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PC2_SetInterruptHandler() method.
 *        This handler is called every time the IO_PC2 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PC2_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PC2 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PC2 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PC2_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PD1 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PD1_SetInterruptHandler() method.
 *        This handler is called every time the IO_PD1 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PD1_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PD1 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PD1 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PD1_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PD2 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PD2_SetInterruptHandler() method.
 *        This handler is called every time the IO_PD2 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PD2_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PD2 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PD2 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PD2_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PD3 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PD3_SetInterruptHandler() method.
 *        This handler is called every time the IO_PD3 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PD3_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PD3 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PD3 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PD3_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PD4 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PD4_SetInterruptHandler() method.
 *        This handler is called every time the IO_PD4 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PD4_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PD4 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PD4 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PD4_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PD5 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PD5_SetInterruptHandler() method.
 *        This handler is called every time the IO_PD5 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PD5_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PD5 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PD5 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PD5_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PD6 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PD6_SetInterruptHandler() method.
 *        This handler is called every time the IO_PD6 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PD6_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PD6 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PD6 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PD6_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PD7 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PD7_SetInterruptHandler() method.
 *        This handler is called every time the IO_PD7 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PD7_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PD7 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PD7 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PD7_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PF0 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PF0_SetInterruptHandler() method.
 *        This handler is called every time the IO_PF0 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PF0_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PF0 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PF0 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PF0_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IO_PF1 pin. 
 *        This is a predefined interrupt handler to be used together with the IO_PF1_SetInterruptHandler() method.
 *        This handler is called every time the IO_PF1 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IO_PF1_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IO_PF1 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IO_PF1 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IO_PF1_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for BFG_Alert pin. 
 *        This is a predefined interrupt handler to be used together with the BFG_Alert_SetInterruptHandler() method.
 *        This handler is called every time the BFG_Alert ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void BFG_Alert_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for BFG_Alert pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for BFG_Alert at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void BFG_Alert_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for EN_EXT_Balance pin. 
 *        This is a predefined interrupt handler to be used together with the EN_EXT_Balance_SetInterruptHandler() method.
 *        This handler is called every time the EN_EXT_Balance ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void EN_EXT_Balance_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for EN_EXT_Balance pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for EN_EXT_Balance at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void EN_EXT_Balance_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for Drain_Cell_1 pin. 
 *        This is a predefined interrupt handler to be used together with the Drain_Cell_1_SetInterruptHandler() method.
 *        This handler is called every time the Drain_Cell_1 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void Drain_Cell_1_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for Drain_Cell_1 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for Drain_Cell_1 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void Drain_Cell_1_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for Drain_Cell_2 pin. 
 *        This is a predefined interrupt handler to be used together with the Drain_Cell_2_SetInterruptHandler() method.
 *        This handler is called every time the Drain_Cell_2 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void Drain_Cell_2_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for Drain_Cell_2 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for Drain_Cell_2 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void Drain_Cell_2_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for Drain_Cell_3 pin. 
 *        This is a predefined interrupt handler to be used together with the Drain_Cell_3_SetInterruptHandler() method.
 *        This handler is called every time the Drain_Cell_3 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void Drain_Cell_3_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for Drain_Cell_3 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for Drain_Cell_3 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void Drain_Cell_3_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for Drain_Cell_4 pin. 
 *        This is a predefined interrupt handler to be used together with the Drain_Cell_4_SetInterruptHandler() method.
 *        This handler is called every time the Drain_Cell_4 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void Drain_Cell_4_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for Drain_Cell_4 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for Drain_Cell_4 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void Drain_Cell_4_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for EN_Buck pin. 
 *        This is a predefined interrupt handler to be used together with the EN_Buck_SetInterruptHandler() method.
 *        This handler is called every time the EN_Buck ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void EN_Buck_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for EN_Buck pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for EN_Buck at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void EN_Buck_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for EN_Lader pin. 
 *        This is a predefined interrupt handler to be used together with the EN_Lader_SetInterruptHandler() method.
 *        This handler is called every time the EN_Lader ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void EN_Lader_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for EN_Lader pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for EN_Lader at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void EN_Lader_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for EN_Batt pin. 
 *        This is a predefined interrupt handler to be used together with the EN_Batt_SetInterruptHandler() method.
 *        This handler is called every time the EN_Batt ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void EN_Batt_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for EN_Batt pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for EN_Batt at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void EN_Batt_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for Lader_Output pin. 
 *        This is a predefined interrupt handler to be used together with the Lader_Output_SetInterruptHandler() method.
 *        This handler is called every time the Lader_Output ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void Lader_Output_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for Lader_Output pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for Lader_Output at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void Lader_Output_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for LED pin. 
 *        This is a predefined interrupt handler to be used together with the LED_SetInterruptHandler() method.
 *        This handler is called every time the LED ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void LED_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for LED pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for LED at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void LED_SetInterruptHandler(void (* interruptHandler)(void)) ; 
#endif /* PINS_H_INCLUDED */
