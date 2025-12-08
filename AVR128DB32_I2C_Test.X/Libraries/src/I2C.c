#include "../../mcc_generated_files/system/system.h"

#include "../I2C.h"

uint8_t Current_LTC2943_ADC_Mode = Sleep_Mode;
uint8_t Current_LTC2943_Prescalar_Mode = M_4096;
uint8_t Current_LTC2943_ALCC_Pin_Mode = Alert_Mode;
bool LTC2943_Shutdown = 0;

uint8_t LTC2943_Control_REG_Content = 0x3C;

bool LTC2943_Error_Status_Array[7] = {0};

void Set_LTC2943_REG_8(uint8_t Address, uint8_t Data){
    uint8_t Message[2] = {Address, Data};
    
    while(!LTC2943_Write(LTC2943_ADDR, &Message, 2));
    while(LTC2943_IsBusy());
}

void Set_LTC2943_REG_16(uint8_t Address, uint16_t Data){
    uint8_t Message[3];
    Message[0] = Address;
    Message[1] = (uint8_t)(Data >> 8); // MSB
    Message[2] = (uint8_t)(Data & 0xFF); // LSB
    
    while(!LTC2943_Write(LTC2943_ADDR, &Message, 3));
    while(LTC2943_IsBusy());
}

void Set_LTC2943_REG(uint8_t Address, uint16_t Data){
    switch(Address){
        case Control_REG:
        case Temperature_Threshold_High_REG:
        case Temperature_Threshold_Low_REG:
            Set_LTC2943_REG_8(Address, Data);
            break;
        case Accumulated_Charge_REG:
        case Charge_Threshold_High_REG:
        case Charge_Threshold_Low_REG:
        case Voltage_Threshold_High_REG:
        case Voltage_Threshold_Low_REG:
        case Current_Threshold_High_REG:
        case Current_Threshold_Low_REG:
            Set_LTC2943_REG_16(Address, Data);
            break;
    }
}

uint8_t Get_LTC2943_REG_8(uint8_t Address){
    
    uint8_t Return_Value = 0;
    
    while(!LTC2943_WriteRead(LTC2943_ADDR, &Address, 1, &Return_Value, 1));
    while(LTC2943_IsBusy());
    
    return(Return_Value);
}

uint16_t Get_LTC2943_REG_16(uint8_t Address){
    
    uint8_t Return_Values[2] = {0, 0};
    
    while(!LTC2943_WriteRead(LTC2943_ADDR, &Address, 1, &Return_Values, 2));
    while(LTC2943_IsBusy());
    
    return (uint16_t)((Return_Values[0] << 8) | Return_Values[1]);
}

uint16_t Get_LTC2943_REG(uint8_t Address){
    
    switch(Address){
        case Status_REG:
        case Control_REG:
        case Temperature_Threshold_High_REG:
        case Temperature_Threshold_Low_REG:
            return(Get_LTC2943_REG_8(Address));
            break;
        case Voltage_REG:
        case Current_REG:
        case Temperature_REG:
        case Accumulated_Charge_REG:
        case Charge_Threshold_High_REG:
        case Charge_Threshold_Low_REG:
        case Voltage_Threshold_High_REG:
        case Voltage_Threshold_Low_REG:
        case Current_Threshold_High_REG:
        case Current_Threshold_Low_REG:
            return(Get_LTC2943_REG_16(Address));
            break;
    }
}

void Get_Active_Alerts(){
    uint8_t Full_Status_REG = Get_LTC2943_REG_8(Status_REG);
    
    LTC2943_Error_Status_Array[6] = Full_Status_REG & 0x40; //Current Alert
    
    LTC2943_Error_Status_Array[5] = Full_Status_REG & 0x20; //Accumulated Charge OVer/Underflow
    
    LTC2943_Error_Status_Array[4] = Full_Status_REG & 0x10; //Temperature Alert
    
    LTC2943_Error_Status_Array[3] = Full_Status_REG & 0x08; //Charge High Alert
    
    LTC2943_Error_Status_Array[2] = Full_Status_REG & 0x04; //Charge Low Alert
    
    LTC2943_Error_Status_Array[1] = Full_Status_REG & 0x02; //Voltage Alert
    
    LTC2943_Error_Status_Array[0] = Full_Status_REG & 0x01; //Under Voltage Lockout Alert
}

void Write_Control_REG(){
    
    switch(Current_LTC2943_ADC_Mode){
        case Automatic_Mode:
            LTC2943_Control_REG_Content = LTC2943_Control_REG_Content + 0xC0;
            break;
        case Scan_Mode:
            LTC2943_Control_REG_Content = LTC2943_Control_REG_Content + 0x80;
            break;
        case Manual_Mode:
            LTC2943_Control_REG_Content = LTC2943_Control_REG_Content + 0x40;
            break;
        case Sleep_Mode:
            LTC2943_Control_REG_Content = LTC2943_Control_REG_Content + 0x00;
            break;
    }
    
    switch(Current_LTC2943_Prescalar_Mode){
        case M_1:
            LTC2943_Control_REG_Content = LTC2943_Control_REG_Content + 0x00;
            break;
        case M_4:
            LTC2943_Control_REG_Content = LTC2943_Control_REG_Content + 0x08;
            break;
        case M_16:
            LTC2943_Control_REG_Content = LTC2943_Control_REG_Content + 0x10;
            break;
        case M_64:
            LTC2943_Control_REG_Content = LTC2943_Control_REG_Content + 0x18;
            break;
        case M_256:
            LTC2943_Control_REG_Content = LTC2943_Control_REG_Content + 0x20;
            break;
        case M_1024:
            LTC2943_Control_REG_Content = LTC2943_Control_REG_Content + 0x28;
            break;
        case M_4096:
            LTC2943_Control_REG_Content = LTC2943_Control_REG_Content + 0x38;
            break;
    }
    
    switch(Current_LTC2943_ALCC_Pin_Mode){
        case Alert_Mode:
            LTC2943_Control_REG_Content = LTC2943_Control_REG_Content + 0x04;
            break;
        case Charge_Complete_Mode:
            LTC2943_Control_REG_Content = LTC2943_Control_REG_Content + 0x02;
            break;
        case ALCC_Pin_disabled:
            LTC2943_Control_REG_Content = LTC2943_Control_REG_Content + 0x00;
            break;
    }
    
    if(LTC2943_Shutdown){
        LTC2943_Control_REG_Content = LTC2943_Control_REG_Content + 0x01;
    } else{
        LTC2943_Control_REG_Content = LTC2943_Control_REG_Content + 0x00;
    }
    
}