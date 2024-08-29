/***************************************************
 Huskylens Line Tracking Car
 by vitorccs

 Optimized for a 2WD car chassis and a L293D Adafruit
 Motor Shield (v1)

 Based on:
 https://github.com/HuskyLens/HUSKYLENSArduino
 By [Angelo qiao](Angelo.qiao@dfrobot.com)

 ****************************************************/
#include <Arduino.h>
#include <Car.h>
#include <HUSKYLENS.h>
#include <SoftwareSerial.h>
#include <PIDManager.h>
#include <LineTracker.h>

#define DEFAULT_SPEED 150   // Default motor speed for driving
#define PID_PGAIN 200       // PID Proportional
#define PID_IGAIN 0         // PID Integral
#define PID_DGAIN 0         // PID Derivative
#define PID_SERVO false     // PID Servo

HUSKYLENS huskylens; // SDA (green, PIN A4) SCL (blue, PIN A5)
AF_DCMotor rightMotor(3);
AF_DCMotor leftMotor(4);
Car car(leftMotor, rightMotor);
PIDManager pidManager(PID_PGAIN, PID_IGAIN, PID_DGAIN, PID_SERVO);
LineTracker lineTracker(car, huskylens, pidManager, DEFAULT_SPEED);

void setup()
{
  Serial.begin(115200);

  lineTracker.init();
}

void loop()
{
  lineTracker.loop();
}
