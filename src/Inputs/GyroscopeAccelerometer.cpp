#include "InputData.hpp"
#include "IInput.hpp"
#include "GyroscopeAccelerometer.hpp"

#include <DFRobot_BMI160.h>
#include <Arduino.h>

GyroscopeAccelerometer::GyroscopeAccelerometer() {}

void GyroscopeAccelerometer::Setup(){
  if (bmi160.softReset() != BMI160_OK){
    Serial.println("reset false");
    while(1);
  }
  if (bmi160.I2cInit(i2c_addr) != BMI160_OK){
    Serial.println("init false");
    while(1);
  }
}

void GyroscopeAccelerometer::Loop(){
  bmi160.getAccelGyroData(gyroscopeAccelerometerData);
  
  inputData->acceleroscopeData.x = gyroscopeAccelerometerData[0];
  inputData->acceleroscopeData.y = gyroscopeAccelerometerData[1];
  inputData->acceleroscopeData.z = gyroscopeAccelerometerData[2];
  inputData->gyroscopeData.x = gyroscopeAccelerometerData[3];
  inputData->gyroscopeData.y = gyroscopeAccelerometerData[4];
  inputData->gyroscopeData.z = gyroscopeAccelerometerData[5];

  //this->Print();
}

void GyroscopeAccelerometer::Print(){
  for(byte i = 0;i < 3;i++){
     Serial.print(gyroscopeAccelerometerData[i]);Serial.print("\t"); // accelerometer to multiply in future
  }
  for(byte i = 3;i < 6;i++){
    Serial.print(gyroscopeAccelerometerData[i]/180);Serial.print("\t");
  }

  Serial.println();
}