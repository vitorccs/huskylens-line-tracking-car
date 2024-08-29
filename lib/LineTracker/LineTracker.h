#ifndef LINE_TRACKER_H
#define LINE_TRACKER_H
#include <Arduino.h>
#include <HUSKYLENS.h>
#include <Car.h>
#include <PIDManager.h>

class LineTracker
{
private:
    Car car;
    HUSKYLENS huskylens;
    HUSKYLENSResult result;
    PIDManager pidManager;

    int16_t left = 0;
    int16_t right = 0;
    uint8_t ID1 = 1;
    uint8_t defaultSpeed;

    void driveCar();
    void printResult();

public:
    LineTracker(Car &c,
                HUSKYLENS &hlens,
                PIDManager &pManager,
                int8_t defSpeed);
    void init();
    void loop();
};
#endif