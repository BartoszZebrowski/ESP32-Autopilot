#include "Outputs/OutputData.hpp"
#include <Servo.h>
#include <cstdint>

// Servo servoController;

//pins
uint8_t enginePin = 0;

uint8_t rudderPin = 0; // yaw
uint8_t elevatorsPin = 0; // pitch - down-up
uint8_t aileronPin = 0; //roll - left-right

uint8_t flapsPin = 0;

class OutputManager{
    void applayOutputs(OutputData outputData){
        // servoController.write(enginePin, outputData.throttle);
        // servoController.write(rudderPin, outputData.yaw);
        // servoController.write(elevatorsPin, outputData.pitch);
        // servoController.write(aileronPin, outputData.roll);
        // servoController.write(flapsPin, outputData.pitch);
    }
};