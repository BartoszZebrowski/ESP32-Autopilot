#pragma once

#include <cstdint>

struct OutputData
{
    int8_t throttle = 0; //0-100
    int8_t pitch = 0; //-100-100
    int8_t roll = 0; //-100-100
    int8_t yaw = 0; //-100-100

    bool isArmed = false; 
    bool isConnected = false;
};