//liblares
#include "sbus.h"
#include <Servo.h>

#include "Inputs/Controller.hpp"
#include "Inputs/GyroscopeAccelerometer.hpp"
#include "Inputs/InputsManager.hpp"

Controller controler;
//GyroscopeAccelerometer gyroscopeAccelerometer;

InputsManager inputsManager;

Servo servoController;

void setup() {
  Serial.begin(115200);

  Serial.println("-----Setup-----");

  inputsManager.AddInput(&controler);
  // inputsManager.AddInput(&gyroscopeAccelerometer);

  inputsManager.Setup();
  

  Serial.println("-----Loop-----");
}

void loop () {
  inputsManager.Loop(); 

  Serial.println("-----In Loop-----");

  inputsManager.Print();
}