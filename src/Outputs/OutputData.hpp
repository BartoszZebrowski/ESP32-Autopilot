#pragma once

#include <cstdint>

struct OutputData
{
    int throttle = 0; //0-100
    int pitch = 0; //-100-100
    int roll = 0; //-100-100
    int yaw = 0; //-100-100

    bool isArmed = false; 
    bool isConnected = false;
};