//liblares
#include "sbus.h"
#include <Servo.h>

//inputs
#include "Inputs/Controller.hpp"
#include "Inputs/GyroscopeAccelerometer.hpp"
#include "Inputs/InputsManager.hpp"

//flyModes
#include "FlyModes/ManualMode.hpp"

//outputs
#include "Outputs/OutputsManager.hpp"
#include "Outputs/OutputData.hpp"

//settings
bool debug = false;

Controller controler;
GyroscopeAccelerometer gyroscopeAccelerometer;

InputsManager inputsManager;
OutputManager outputManager;
OutputData outputData;

ManualMode manualMode;

void setup() {
  Serial.begin(115200);
  outputData = OutputData();

  inputsManager.AddInput(&controler);

  inputsManager.Setup();
}

void loop () {
  inputsManager.Loop(); 
  manualMode.Run(outputData);
  outputManager.ApplayOutputs(outputData);

  //inputsManager.Print();
}