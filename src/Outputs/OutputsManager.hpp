#pragma once

#include <cstdint>
#include "Outputs/OutputData.hpp"
#include <Servo.h>

class OutputManager{
private:
    Servo servoController;

    //pins
    uint8_t enginePin = GPIO_NUM_33;

    uint8_t rudderPin = 0; // yaw
    uint8_t elevatorsPin = 0; // pitch - down-up
    uint8_t aileronPin = 0; //roll - left-right

    uint8_t flapsPin = 0;

public:
    OutputManager();
    void ApplayOutputs(OutputData& outputData);
};