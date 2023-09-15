#pragma once

#include "FlyModes/IMode.hpp"

class ManualMode : IMode{

    ManualMode(){}

    OutputData Run(const InputData& inputData) override{}
};