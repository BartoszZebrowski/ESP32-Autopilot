#include "Outputs/OutputData.hpp"
#include "Outputs/OutputsManager.hpp"
#include <Servo.h>
#include <cstdint>



void OutputManager::ApplayOutputs(OutputData& outputData){
    servoController.write(enginePin, outputData.throttle);
    // servoController.write(rudderPin, outputData.yaw);
    // servoController.write(elevatorsPin, outputData.pitch);
    // servoController.write(aileronPin, outputData.roll);
    // servoController.write(flapsPin, outputData.pitch);
}
