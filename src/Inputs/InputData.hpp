#pragma once

#include <cstdint>
#include "sbus.h"

struct GyroscopeData
{
  int16_t x, y, z;
};

struct AcceleroscopeData
{
  int16_t x, y, z;
};

class InputData{
private: 
  InputData();

public: 
  static InputData *inputData;
  
  bfs::SbusData controllerData;
  AcceleroscopeData acceleroscopeData; //x,y,z
  GyroscopeData gyroscopeData; //x,y,z

  static InputData* GetInstance();
};