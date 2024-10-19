#include <PID_v1.h>
#include "IMode.hpp"
#include <vector>

class FlyStraightMode : IMode{
private:
    int8_t PitchMultiplier = 50;
    double PitchKP=1.5, PitchKI=0.0, PitchKD=0.2;
    double PitchInput, PitchOutput, PitchSetpoint = 0;
    PID PitchPID = PID(&PitchInput, &PitchOutput, &PitchSetpoint, PitchKP, PitchKI, PitchKD, DIRECT);
    std::vector<double> MovingAvaragePitchData;
    
    int8_t RollMultiplier = 50;
    double RollKP=1.5, RollKI=0.0, RollKD=0.2;
    double RollInput, RollOutput, RollSetpoint = 0;
    PID RollPID = PID(&RollInput, &RollOutput, &RollSetpoint, RollKP, RollKI, RollKD, DIRECT);
    std::vector<double> MovingAvarageRollData;

    float GetMovingAverage(const double &value, std::vector<double> &data);
public:
    FlyStraightMode();
    void Run(OutputData& outputData) override;

};