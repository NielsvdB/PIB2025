//Defines die moeten gebeuren om te laten werken
#define Max_Voltage_LTC2943 20 //20 V voor LTC2943, 60 V voor LTC2943
#define Shunt_Resistor_Value 5 //In miliOhm
#define Total_Battery_Capacity 3600 //In mAh


#ifndef I2C_H
#define I2C_H

#define LTC2943_ADDR 0x64

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

//Control Register==================================================
enum LTC2943_ADC_Mode{
    Automatic_Mode,
    Scan_Mode,
    Manual_Mode,
    Sleep_Mode,
};

enum LTC2943_Prescalar_Mode{
    M_1,
    M_4,
    M_16,
    M_64,
    M_256,
    M_1024,
    M_4096,
};

enum LTC2943_ALCC_Pin_Mode{
    Alert_Mode,
    Charge_Complete_Mode,
    ALCC_Pin_disabled,
};

extern uint8_t Current_LTC2943_ADC_Mode;
extern uint8_t Current_LTC2943_Prescalar_Mode;
extern uint8_t Current_LTC2943_ALCC_Pin_Mode;
extern bool LTC2943_Shutdown;

extern uint8_t LTC2943_Control_REG_Content;

//Write to Registers================================================
void Set_LTC2943_REG(uint8_t Address, uint16_t Data);

void Write_Control_REG();

//Read From Registers===============================================
uint16_t Get_LTC2943_REG(uint8_t Address);

void Get_Active_Alerts();

extern bool LTC2943_Error_Status_Array[7];

//Read converted Values=============================================
float Get_Battery_Charge_In_mAh();

float Get_Batteru_Voltage();

float Get_Battery_Current();

float Get_LTC2943_Tempature();

#endif
