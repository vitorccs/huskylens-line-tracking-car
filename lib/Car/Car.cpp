/***************************************************
  For use with a L293D Adafruit Motor Shield (v1)

  Source:
  https://learn.adafruit.com/adafruit-motor-shield/overview

 ****************************************************/
#include <Arduino.h>
#include <AFMotor.h>
#include <Car.h>

Car::Car(AF_DCMotor &lm,
         AF_DCMotor &rm) : leftMotor(lm),
                           rightMotor(rm)
{
    leftMotor = lm;
    rightMotor = rm;
}

// Left and Right motor speed, whose range is (-255 ~ 255)
void Car::move(int16_t leftSpeed,
               int16_t rightSpeed)
{
    if (leftSpeed < 0)
    {
        leftMotor.run(BACKWARD);
        leftSpeed = abs(leftSpeed);
    }
    else
    {
        leftMotor.run(FORWARD);
    }

    if (rightSpeed < 0)
    {
        rightMotor.run(BACKWARD);
        rightSpeed = abs(rightSpeed);
    }
    else
    {
        rightMotor.run(FORWARD);
    }

    if (leftSpeed > 255)
    {
        leftSpeed = 255;
    }

    if (rightSpeed > 255)
    {
        rightSpeed = 255;
    }

    leftMotor.setSpeed(leftSpeed);
    rightMotor.setSpeed(rightSpeed);
}

void Car::stop()
{
    leftMotor.run(RELEASE);
    rightMotor.run(RELEASE);
}
