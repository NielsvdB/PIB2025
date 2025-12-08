#include "mcc_generated_files/system/system.h"

#include "I2C.h"

void main(void)
{
    SYSTEM_Initialize();

    while(1)
    {
        Get_LTC2943_REG(Voltage_REG);
    }
}