#pragma once

#include <vector>
#include "IInput.hpp"

class InputsManager{
private:
    std::vector<IInput*> inputs;

public:
    void Setup();
    void Loop();
    void Print();
    void AddInput(IInput* input);
};