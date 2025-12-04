#include "mcc_generated_files/system/system.h"
/*
    Main application
*/
extern comms_i2c_interface_t LTC2943_Comms;

uint8_t LTC2943_Write(uint16_t address, uint8_t *data, size_t dataLength){
    uint8_t returnStat = LTC2943_I2C_ERROR;
    if (MCP9808_Comms.Write(address, data, dataLength)){
        while (MCP9808_Comms.IsBusy()){
            if (MCP9808_Comms.isInterruptDriven != true){
                MCP9808_Comms.Tasks();
            }
        }
        returnStat = MCP9808_I2C_NO_ERROR;
    }
    return returnStat;
}
int main(void)
{
    SYSTEM_Initialize();

    while(1)
    {
        
        uint8_t MCP9808_Read(uint16_t address, uint8_t *registerAddress, size_t addressLength, uint8_t *readData, size_t readLength);
    }    
}