#pragma once
#include "../Outputs/OutputData.hpp"
#include "../Inputs/InputData.hpp"


class IMode{
    virtual void Run(OutputData& outputData);
};