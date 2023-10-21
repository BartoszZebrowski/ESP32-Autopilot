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
protected: 

  static InputData* instance;
  InputData();

public: 
  InputData(const InputData&) = delete;
  void operator=(const InputData &) = delete;

  bfs::SbusData controllerData;
  AcceleroscopeData acceleroscopeData; //x,y,z
  GyroscopeData gyroscopeData; //x,y,z

  static InputData *Get();
};