#pragma once

#include "FlyModes/IMode.hpp"

class ManualMode : IMode{
public:
    ManualMode();
    void Run(OutputData& outputData) override;
};