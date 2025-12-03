
/*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
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
#include "mcc_generated_files/system/system.h"

#define BFG_ADDR 0x64

//Read Addresses
#define Status_REG                      0x00 //8 bit
#define Voltage_REG                     0x08 //16 bit
#define Current_REG                     0x0E //16 bit
#define Temperature_REG                 0x14 //16 bit

//Write Addresses
#define Control_REG                     0x01 //8 bit
#define Accumulated_Charge_REG          0x02 //16 bit
#define Charge_Threshold_High_REG       0x04 //16 bit
#define Charge_Threshold_Low_REG        0x06 //16 bit
#define Voltage_Threshold_High_REG      0x0A //16 bit
#define Voltage_Threshold_Low_REG       0x0C //16 bit
#define Current_Threshold_High_REG      0x10 //16 bit
#define Current_Threshold_Low_REG       0x12 //16 bit
#define Temperature_Threshold_High_REG  0x16 //8 bit
#define Temperature_Threshold_Low_REG   0x17 //8 bit


void Set_BFG_REG_8(uint8_t reg, uint8_t value) {
    uint8_t data[2] = {reg, value};
    // Send 2 bytes: [Register Address] [Value]
    TWI1_Write(BFG_ADDR, data, 2); 
    while(TWI1_IsBusy()); // Wait for transmission to finish
}

void Set_BFG_REG_16(uint8_t reg, uint16_t value) {
    uint8_t data[3];
    data[0] = reg;
    data[1] = (uint8_t)(value >> 8); // MSB
    data[2] = (uint8_t)(value & 0xFF); // LSB
    
    TWI1_Write(BFG_ADDR, data, 3);
    while(TWI1_IsBusy());
}

uint8_t Get_BFG_REG_8(uint8_t reg) {
    uint8_t writeBuf[1] = {reg};
    uint8_t readBuf[1] = {0};
    
    // Send Register Address -> Restart -> Read 1 Byte
    // If using MCC Classic, use: I2C0_WriteRead(LTC2943_ADDR, writeBuf, 1, readBuf, 1);
    while(!TWI1_WriteRead(BFG_ADDR, writeBuf, 1, readBuf, 1));
    
    while(TWI1_IsBusy()); // Wait for transaction to finish
    
    return readBuf[0];
}

uint16_t Get_BFG_REG_16(uint8_t reg) {
    uint8_t writeBuf[1] = {reg};
    uint8_t readBuf[2] = {0, 0};
    
    // Send Register Address -> Restart -> Read 2 Bytes
    // If using MCC Classic, use: I2C0_WriteRead(LTC2943_ADDR, writeBuf, 1, readBuf, 2);
    while(!TWI1_WriteRead(BFG_ADDR, writeBuf, 1, readBuf, 2));
    
    while(TWI1_IsBusy()); // Wait for transaction to finish
    
    // Combine the MSB (byte 0) and LSB (byte 1)
    return (uint16_t)((readBuf[0] << 8) | readBuf[1]);
}

void Write_BFG_Reg(uint8_t reg, uint16_t data){
    switch(reg){
        case Control_REG:
            Set_BFG_REG_8(reg, data);
            break;
        case Accumulated_Charge_REG:
            Set_BFG_REG_16(reg, data);
            break;
        case Charge_Threshold_High_REG:
            Set_BFG_REG_16(reg, data);
            break;
        case Charge_Threshold_Low_REG:
            Set_BFG_REG_16(reg, data);
            break;
        case Voltage_Threshold_High_REG:
            Set_BFG_REG_16(reg, data);
            break;
        case Voltage_Threshold_Low_REG:
            Set_BFG_REG_16(reg, data);
            break;
        case Current_Threshold_High_REG:
            Set_BFG_REG_16(reg, data);
            break;
        case Current_Threshold_Low_REG:
            Set_BFG_REG_16(reg, data);
            break;
        case Temperature_Threshold_High_REG:
            Set_BFG_REG_8(reg, data);
            break;
        case Temperature_Threshold_Low_REG:
            Set_BFG_REG_8(reg, data);
            break;
        default:
            break;
            
    }
    return();
}

uint16_t Read_BFG_Reg(uint8_t reg){
    switch(reg){
        case Status_REG:
            return(Get_BFG_REG_8(reg));
            break;
        case Voltage_REG:
            return(Get_BFG_REG_16(reg));
            break;
        case Current_REG:
            return(Get_BFG_REG_16(reg));
            break;
        case Temperature_REG:
            return(Get_BFG_REG_16(reg));
            break;
        case Control_REG:
            return(Get_BFG_REG_8(reg));
            break;
        case Accumulated_Charge_REG:
            return(Get_BFG_REG_16(reg));
            break;
        case Charge_Threshold_High_REG:
            return(Get_BFG_REG_16(reg));
            break;
        case Charge_Threshold_Low_REG:
            return(Get_BFG_REG_16(reg));
            break;
        case Voltage_Threshold_High_REG:
            return(Get_BFG_REG_16(reg));
            break;
        case Voltage_Threshold_Low_REG:
            return(Get_BFG_REG_16(reg));
            break;
        case Current_Threshold_High_REG:
            return(Get_BFG_REG_16(reg));
            break;
        case Current_Threshold_Low_REG:
            return(Get_BFG_REG_16(reg));
            break;
        case Temperature_Threshold_High_REG:
            return(Get_BFG_REG_8(reg));
            break;
        case Temperature_Threshold_Low_REG:
            return(Get_BFG_REG_8(reg));
            break;
        default:
            break;
    }
}