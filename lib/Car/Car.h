#ifndef THE_CAR_H
#define THE_CAR_H
#include <Arduino.h>
#include <AFMotor.h>

class Car
{
private:
    AF_DCMotor leftMotor;
    AF_DCMotor rightMotor;

public:
    Car(AF_DCMotor &lm, AF_DCMotor &rm);
    void move(int16_t left, int16_t right);
    void stop();
};
#endif