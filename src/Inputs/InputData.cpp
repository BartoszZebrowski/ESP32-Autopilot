#include <cstdint>
#include "sbus.h"
#include "InputData.hpp"

InputData* InputData::instance = nullptr;

InputData::InputData() {}

InputData* InputData::Get(){
    if(instance == nullptr){
        instance = new InputData();
    }

    return instance;
}