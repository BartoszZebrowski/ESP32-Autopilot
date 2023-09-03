#include "sbus.h"
#include <Servo.h>
//#include <DFRobot_BMI160.h>

  void collectInputs();
    void printInputs();
  void runServo();
  void collectGyroscopeData();
    float convertRawGyro(int gRaw);
    void printGyroscopeData();
  bool isArmed();

Servo servoController;
bfs::SbusRx sbus_rx(&Serial2, GPIO_NUM_16, GPIO_NUM_17, true);

//data
bfs::SbusData data;

void setup() {
  Serial.begin(115200);
  sbus_rx.Begin();
}

void loop () {
  collectInputs();
  //collectGyroscopeData();

  //debug
  printInputs();
  //printGyroscopeData();

  if(isArmed()){
    runServo();
  }

}


void collectInputs(){
  if (sbus_rx.Read()) {
    data = sbus_rx.data();
  }
}

void collectGyroscopeData(){
}

void printGyroscopeData(){
}

float convertRawGyro(int gRaw) {
  return (gRaw * 250.0) / 32768.0;
}

void printInputs(){
    for (int8_t i = 0; i < data.NUM_CH; i++) {
      Serial.print(data.ch[i]);
      Serial.print("\t");
    }

    Serial.print(data.lost_frame);
    Serial.print("\t");
    Serial.println(data.failsafe);
}

void runServo(){
  servoController.write(GPIO_NUM_2, map(data.ch[3], 172 , 1811,0,90));
  servoController.write(GPIO_NUM_4, map(data.ch[2], 172 , 1811,1000,2000));
}

bool isArmed(){
  return data.ch[8] > 1000;
}