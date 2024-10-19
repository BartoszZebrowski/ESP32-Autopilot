#include <PID_v1.h>
#include "IMode.hpp"
#include "FlyStraightMode.hpp"


FlyStraightMode::FlyStraightMode() {
    RollPID.SetMode(AUTOMATIC);
    PitchPID.SetMode(AUTOMATIC);
    RollPID.SetOutputLimits(-255, 255);
    PitchPID.SetOutputLimits(-255, 255);
}

void FlyStraightMode::Run(OutputData& outputData) {
    InputData& inputData = *InputData::Get();
    
    RollInput = GetMovingAverage(inputData.gyroscopeData.x / 16384.0, MovingAvarageRollData);
    RollPID.Compute();

    PitchInput = GetMovingAverage(inputData.gyroscopeData.y / 16384.0, MovingAvaragePitchData);
    PitchPID.Compute();

    outputData.throttle = map(inputData.controllerData.ch[2], 172 , 990, 0, 100);
    outputData.roll = (RollOutput * RollMultiplier) + 90;
    outputData.pitch = (PitchOutput * PitchMultiplier) + 90;
    outputData.yaw = map(inputData.controllerData.ch[3], 172 , 1811, -100, 100);

    Serial.print(inputData.gyroscopeData.x / 16384.0);
    Serial.print('\t');
    Serial.print(inputData.gyroscopeData.y / 16384.0);
    Serial.print('\t');

    Serial.print(outputData.roll);
    Serial.print('\t');
    Serial.print(outputData.pitch);
    Serial.print('\t');

    Serial.print(RollOutput);
    Serial.print('\t');
    Serial.print(PitchOutput);
    Serial.print('\t');

    Serial.println("");
    // Serial.print('\t');

    //kurs
    //do punktu

    
}

float FlyStraightMode::GetMovingAverage(const double& value,  std::vector<double> &data){
    data.push_back(value);

    if(data.size() > 9)
        data.erase(data.begin());

    double sum = 0.0;
    for (double oneData : data)
        sum += oneData;

    return sum / data.size();
}