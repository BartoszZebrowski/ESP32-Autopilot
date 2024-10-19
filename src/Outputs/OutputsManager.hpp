#pragma once

#include <cstdint>
#include "Outputs/OutputData.hpp"
#include <Servo.h>

class OutputManager{
private:
    Servo servoController;

    uint8_t RollPin = GPIO_NUM_13; //1
    uint8_t PitchPin = GPIO_NUM_12; //2
    uint8_t YawPin = GPIO_NUM_14; //3 
    uint8_t EnginePin = GPIO_NUM_33; //4

public:
    OutputManager();
    void ApplayOutputs(OutputData& outputData);
};