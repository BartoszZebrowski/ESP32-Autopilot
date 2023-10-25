#include "Outputs/OutputData.hpp"
#include "Outputs/OutputsManager.hpp"
#include <Servo.h>
#include <cstdint>

OutputManager::OutputManager(){}

void OutputManager::ApplayOutputs(OutputData& outputData){
    servoController.write(enginePin, outputData.throttle);
    servoController.write(rudderPin, outputData.yaw);
    servoController.write(elevatorsPin, outputData.pitch);
    servoController.write(aileronPin, outputData.roll);
    servoController.write(flapsPin, outputData.pitch);

    Serial.print("throttle: ");
    Serial.print(outputData.throttle);
    Serial.print("  ");

    Serial.print("yaw: ");
    Serial.print(outputData.yaw);
    Serial.print("  ");

    Serial.print("pitch: ");
    Serial.print(outputData.pitch);
    Serial.print("  ");


    Serial.print("roll: ");
    Serial.println(outputData.roll);
    Serial.print("  ");

}
