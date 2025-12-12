#include "mcc_generated_files/system/system.h"

#include "Libraries/I2C.h"

void main(void)
{
    SYSTEM_Initialize();

    while(1)
    {
        int a = Get_LTC2943_REG(Voltage_REG);
        Set_LTC2943_REG(Control_REG, 0x00);
    }
}