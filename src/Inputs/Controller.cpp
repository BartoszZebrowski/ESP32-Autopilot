#include "sbus.h"
#include "Controller.hpp"
#include "InputData.hpp"

Controller::Controller() : sbus_rx(&Serial2, GPIO_NUM_16, GPIO_NUM_17, true) {}

void Controller::Setup(){

    sbus_rx.Begin();
}

void Controller::Loop(){
    if (sbus_rx.Read())
        inputData->controllerData = sbus_rx.data();
}

void Controller::Print(){
    Serial.print("Controller: ");
    bfs::SbusData data = inputData->controllerData;

    for (byte i = 0; i < data.NUM_CH; i++) {
        Serial.print(data.ch[i]);
        Serial.print("\t");
    }

    Serial.print(data.lost_frame);
    Serial.print("\t");
    Serial.println(data.failsafe);
}