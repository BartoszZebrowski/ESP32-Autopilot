#pragma once

#include "FlyModes/IMode.hpp"

class ManualMode : IMode{
public:
    ManualMode();
    OutputData& Run() override;
};