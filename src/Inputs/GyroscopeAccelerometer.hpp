#pragma once

#include <DFRobot_BMI160.h>
#include "IInput.hpp"
#include "InputData.hpp"

class GyroscopeAccelerometer : public IInput{
private:
  DFRobot_BMI160 bmi160;
  const int8_t i2c_addr = 0x69;
  int16_t gyroscopeAccelerometerData[6]={0};
  InputData *inputData;

public:
  void Setup() override; 
  void Loop() override;
  void Print() override;
};