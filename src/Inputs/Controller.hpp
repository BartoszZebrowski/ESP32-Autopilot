#pragma once

#include "IInput.hpp"
#include "InputData.hpp"
#include "sbus.h"

class Controller : public IInput{
private:
    InputData* inputData = InputData::Get();
    bfs::SbusRx sbus_rx;
    bfs::SbusData data;

public:
    Controller();
    void Setup() override;
    void Loop() override;
    void Print() override;
};