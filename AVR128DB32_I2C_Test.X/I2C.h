
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

uint8_t Current_LTC2943_ADC_Mode = Sleep_Mode;
uint8_t Current_LTC2943_Prescalar_Mode = M_4096;
uint8_t Current_LTC2943_ALCC_Pin_Mode = Alert_Mode;
bool LTC2943_Shutdown = 0;

uint8_t LTC2943_Control_REG_Content = 0x3C;

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
            return(Set_LTC2943_REG_16(Address));
            break;
    }
}

bool Get_Active_Alerts(){
    uint8_t Full_Status_REG = Get_LTC2943_REG_8(Status_REG);
    
    bool Status_Array[7] = {0};
    
    Status_Array[6] = Full_Status_REG && 0x40; //Current Alert
    
    Status_Array[5] = Full_Status_REG && 0x20; //Accumulated Charge OVer/Underflow
    
    Status_Array[4] = Full_Status_REG && 0x10; //Temperature Alert
    
    Status_Array[3] = Full_Status_REG && 0x08; //Charge High Alert
    
    Status_Array[2] = Full_Status_REG && 0x04; //Charge Low Alert
    
    Status_Array[1] = Full_Status_REG && 0x02; //Voltage Alert
    
    Status_Array[0] = Full_Status_REG && 0x01; //Under Voltage Lockout Alert
    
    return(*Status_Array);
}

void Set_Control_REG(){
    
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
    
}