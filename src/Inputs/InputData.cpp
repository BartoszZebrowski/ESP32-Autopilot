#include <cstdint>
#include "sbus.h"
#include "InputData.hpp"

InputData::InputData(){
    if( inputData != nullptr)
        inputData = new InputData();
}

InputData* InputData::GetInstance(){
    if( inputData != nullptr)
        inputData = new InputData();
    return inputData;
}
