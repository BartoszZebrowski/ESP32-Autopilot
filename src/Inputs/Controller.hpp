#pragma once

#include "IInput.hpp"
#include "InputData.hpp"

class Controller : public IInput{
private:
    InputData* inputData;
    bfs::SbusRx sbus_rx;
    bfs::SbusData data;

public:
    Controller();
    void Setup() override;
    void Loop() override;
    void Print() override;
};