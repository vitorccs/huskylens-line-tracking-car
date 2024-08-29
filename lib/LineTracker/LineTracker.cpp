#include <Arduino.h>
#include <HUSKYLENS.h>
#include <LineTracker.h>
#include <Car.h>
#include <PIDLoop.h>

LineTracker::LineTracker(Car &c,
                         HUSKYLENS &hlens,
                         PIDManager &pManager,
                         int8_t defSpeed) : car(c),
                                            huskylens(hlens),
                                            pidManager(pManager)
{
    car = c;
    huskylens = hlens;
    pidManager = pManager;
    defaultSpeed = defSpeed;
}

void LineTracker::init()
{
    car.stop();

    Wire.begin();

    while (!huskylens.begin(Wire))
    {
        Serial.println(F("Begin failed!"));
        Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protol Type>>I2C)"));
        Serial.println(F("2.Please recheck the connection."));
        delay(100);
    }

    huskylens.writeAlgorithm(ALGORITHM_LINE_TRACKING);
}

void LineTracker::loop()
{
    if (!huskylens.request(ID1))
    {
        Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
        car.stop();
        return;
    }

    if (!huskylens.isLearned())
    {
        Serial.println(F("Nothing learned, press learn button on HUSKYLENS to learn one!"));
        car.stop();
        return;
    }

    if (huskylens.available())
    {
        driveCar();
        return;
    }

    car.stop();
    Serial.println(F("No block or arrow appears on the screen!"));
}

void LineTracker::driveCar()
{
    result = huskylens.read();
    printResult();

    // Calculate the error:
    int32_t error = (int32_t)result.xTarget - (int32_t)160;

    // Perform PID algorithm.
    pidManager.update(error);

    // separate heading into left and right wheel velocities.
    left = pidManager.m_command;
    right = -pidManager.m_command;

    left += defaultSpeed;
    right += defaultSpeed;

    Serial.println(String() + left + "," + right);
    car.move(left, right);
}

void LineTracker::printResult()
{
    if (result.command == COMMAND_RETURN_BLOCK)
    {
        Serial.println(String() + F("Block:xCenter=") + result.xCenter + F(",yCenter=") + result.yCenter + F(",width=") + result.width + F(",height=") + result.height + F(",ID=") + result.ID);
        return;
    }

    if (result.command == COMMAND_RETURN_ARROW)
    {
        Serial.println(String() + F("Arrow:xOrigin=") + result.xOrigin + F(",yOrigin=") + result.yOrigin + F(",xTarget=") + result.xTarget + F(",yTarget=") + result.yTarget + F(",ID=") + result.ID);
        return;
    }

    Serial.println("Object unknown!");
}
