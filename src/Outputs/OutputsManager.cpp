#include "Outputs/OutputData.hpp"
#include "Outputs/OutputsManager.hpp"
#include <Servo.h>
#include <cstdint>
#include <Arduino.h>

OutputManager::OutputManager(){}

void OutputManager::ApplayOutputs(OutputData& outputData){
    servoController.write(EnginePin, map(outputData.throttle, -100, 100, 0, 180));

    servoController.write(RollPin, map(outputData.pitch, -100, 100, 45, 135));
    servoController.write(YawPin, map(outputData.yaw, -100, 100, 45, 135));
    servoController.write(PitchPin, map(outputData.roll, -100, 100, 45, 135) + 30);

    

    // Serial.print("throttle: ");
    // Serial.print(outputData.throttle);
    // Serial.print("  ");

    // Serial.print("yaw: ");
    // Serial.print(outputData.yaw);
    // Serial.print("  ");

    // Serial.print("pitch: ");
    // Serial.print(outputData.pitch);
    // Serial.print("  ");


    // Serial.print("roll: ");
    // Serial.println(outputData.roll);
    // Serial.print("  ");

}
