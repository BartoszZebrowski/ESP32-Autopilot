#include "IMode.hpp"
#include "ManualMode.hpp"
#include "Inputs/InputData.hpp"
#include <Arduino.h>


ManualMode::ManualMode(){}

void ManualMode::Run(OutputData& outputData)
{
    InputData& inputData = *InputData::Get();

    outputData.throttle = map(inputData.controllerData.ch[2], 172 , 1811, 0, 100);
    outputData.pitch = map(inputData.controllerData.ch[0], 172 , 1811, -100, 100);
    outputData.roll = map(inputData.controllerData.ch[1], 172 , 1811, -100, 100);
    outputData.yaw = map(inputData.controllerData.ch[3], 172 , 1811, -100, 100);
}

