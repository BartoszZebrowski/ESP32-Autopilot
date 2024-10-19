//liblares
#include "sbus.h"
#include <Servo.h>

//inputs
#include "Inputs/Controller.hpp"
#include "Inputs/GyroscopeAccelerometer.hpp"
#include "Inputs/InputsManager.hpp"

//flyModes
#include "FlyModes/ManualMode.hpp"
#include "FlyModes/FlyStraightMode.hpp"

//outputs
#include "Outputs/OutputsManager.hpp"
#include "Outputs/OutputData.hpp"

//settings
bool debug = false;

InputData* inputData;

Controller controler;
GyroscopeAccelerometer gyroscopeAccelerometer;

InputsManager inputsManager;
OutputManager outputManager;
OutputData outputData = OutputData();

ManualMode manualMode;
FlyStraightMode flyStraightMode;

void setup() {
  Serial.begin(115200);

  inputData = InputData::Get();
  inputsManager.AddInput(&controler);
  inputsManager.AddInput(&gyroscopeAccelerometer);

  inputsManager.Setup();
}

void loop () {
  inputsManager.Loop();

  if(inputData->controllerData.ch[8] > 1000)
    flyStraightMode.Run(outputData);
  else
    manualMode.Run(outputData);
  
  outputManager.ApplayOutputs(outputData);

  //inputsManager.Print();
}