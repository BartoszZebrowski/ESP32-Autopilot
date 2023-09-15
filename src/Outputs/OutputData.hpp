#pragma once

#include <cstdint>

struct OutputData
{
    int8_t throttle; //0-100
    int8_t pitch; //-100-100
    int8_t roll; //-100-100
    int8_t yaw; //-100-100
    int8_t flaps; //0-100 ????

    bool isArmed; 
    bool isConnected;
};