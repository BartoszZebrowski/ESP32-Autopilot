#include <vector>
#include "IInput.hpp"
#include "Arduino.h"
#include "InputsManager.hpp"

void InputsManager::Setup(){
    for (IInput* input : inputs){
        input->Setup();
    }
}

void InputsManager::Loop(){
    for (IInput* input : inputs){
        input->Loop();
    }
}

void InputsManager::Print(){
    for (IInput* input : inputs){
        input->Print();
    }
}

void InputsManager::AddInput(IInput* input){
    inputs.push_back(input);
}