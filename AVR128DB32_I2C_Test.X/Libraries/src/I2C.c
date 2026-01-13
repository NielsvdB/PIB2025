#include "../../mcc_generated_files/system/system.h"

#include "../I2C.h"

uint8_t Current_LTC2943_ADC_Mode = Sleep_Mode;
uint8_t Current_LTC2943_Prescalar_Mode = M_4096;
uint8_t Current_LTC2943_ALCC_Pin_Mode = Alert_Mode;
bool LTC2943_Shutdown = 0;

uint8_t LTC2943_Control_REG_Content = 0x3C;

bool LTC2943_Error_Status_Array[7] = {0};

//Conversion Constants==============================================
#define Max_Value_uint16_t 65535
#define Max_Value_int16_t 32767

#define Default_Shunt_Resistor_Value 50 // in miliohm
#define Default_Prescaler_Value 4096

const float LTC2943_Capacity_Conversion_Constant = 0.340; //in mAh
const float LTC2943_Voltage_Conversion_Constant = 23.6;   //in Volt
const float LTC2943_Current_Conversion_Constant = 0.06;   //in Volt
#define     LTC2943_Tempature_Conversion_Constant 510   //in Kelvin

//Write to Registers================================================

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

void Write_Control_REG(){
    
    LTC2943_Control_REG_Content = 0;
    
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
    Set_LTC2943_REG(Control_REG, LTC2943_Control_REG_Content);
}

//Read From Registers===============================================

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

void Clear_LTC2943_Alert(){
    
    uint8_t Return_Value = 0;
    
    while(!LTC2943_Read(LTC2943_ARA_ADDR, &Return_Value, 1));
    while(LTC2943_IsBusy());
    
    return(Return_Value);
}

//Read converted Values=============================================
float Get_Battery_Charge_In_mAh(){
    
    uint16_t Raw_Battery_Charge = Max_Value_uint16_t - Get_LTC2943_REG(Current_REG);
    
    uint16_t Current_LTC2943_Prescalar_Mode_For_Math;
    
    switch(Current_LTC2943_Prescalar_Mode){
        case M_1:
            Current_LTC2943_Prescalar_Mode_For_Math = 1;
            break;
        case M_4:
            Current_LTC2943_Prescalar_Mode_For_Math = 4;
            break;
        case M_16:
            Current_LTC2943_Prescalar_Mode_For_Math = 16;
            break;
        case M_64:
            Current_LTC2943_Prescalar_Mode_For_Math = 64;
            break;
        case M_256:
            Current_LTC2943_Prescalar_Mode_For_Math = 256;
            break;
        case M_1024:
            Current_LTC2943_Prescalar_Mode_For_Math = 1024;
            break;
        case M_4096:
            Current_LTC2943_Prescalar_Mode_For_Math = 4096;
            break;
    }
    
    float Value_Least_significant_Bit = LTC2943_Capacity_Conversion_Constant * (Default_Shunt_Resistor_Value/Shunt_Resistor_Value) * (Current_LTC2943_Prescalar_Mode_For_Math/Default_Prescaler_Value);
    
    float mAh_Charge_Missing = Value_Least_significant_Bit * (Max_Value_uint16_t - Raw_Battery_Charge);
    
    float mAh_Charge = Total_Battery_Capacity - mAh_Charge_Missing;
    
    return(mAh_Charge); // Geeft de overige capaciteit van de batterij in mAh
}

float Get_Battery_Voltage(){
    uint16_t Raw_Battery_Voltage = Get_LTC2943_REG(Voltage_REG);
    float Converted_Battery_Voltage = LTC2943_Voltage_Conversion_Constant * (Raw_Battery_Voltage / Max_Value_uint16_t);
    return(Converted_Battery_Voltage); // Geeft het batterij voltage in Volt
}

float Get_Battery_Current(){
    uint16_t Raw_Battery_Current = Get_LTC2943_REG(Current_REG);
    float Converted_Battery_Current = (LTC2943_Current_Conversion_Constant / Shunt_Resistor_Value) * ((Raw_Battery_Current - Max_Value_int16_t) / Max_Value_int16_t);
    return(Converted_Battery_Current); // Geeft de stroom door de batterij in Amp. Bij een positief resultaat is de batterij aan het laden, bij een negatief resultaat is de batterij aan het ontladen
}

float Get_LTC2943_Tempature(){
    uint16_t Raw_LTC2943_Tempature = Get_LTC2943_REG(Temperature_REG);
    float Converted_LTC2943_Tempature = LTC2943_Tempature_Conversion_Constant * (Raw_LTC2943_Tempature / Max_Value_uint16_t);
    return(Converted_LTC2943_Tempature); // Geeft de tempratuur in Kelvin
}