# Huskylens Line Tracking Car
Line Tracking Car using Arduino and Huskylends Board

<img src="https://github.com/user-attachments/assets/48bc1149-024b-4b59-a28c-7bf4ee14d11e" width="272">
<img src="https://github.com/user-attachments/assets/ce90f317-c7d4-4f08-b467-9794d9d8a392" width="272">
<img src="https://github.com/user-attachments/assets/6d1fca81-95e9-4b12-bad1-f2c7550e15f0" width="272">

## Schematics
![huskylens-line-tracking-car_bb](https://github.com/user-attachments/assets/f2197aad-0e55-4a8f-8209-4f984e901ebd)

## Components
* 01 - 2WD Car Chassis
* 02 - DC Motors (3v - 6v)
* 02 - Wheels
* 01 - Arduino UNO
* 01 - [L293D Adafruit Motor Shield (v1)](https://www.aliexpress.us/item/3256806925995549.html)
* 02 - 18650 batteries (3.7v - 4.2v)
* 01 - Battery support

## About PlatformIO IDE
This is a [Platform IO IDE](https://platformio.org/platformio-ide) project coded in C++. 

Platform IO is a plugin for Microsoft Virtual Studio Code. It is a more robust IDE compared to official Arduino IDE. It also allows us to easily create our own private libraries and use a more object oriented code.

## About the code
The parameters can be customized in the `main.cpp` 
```c++
#define DEFAULT_SPEED 150   // Default motor speed for driving
#define PID_PGAIN 200       // PID Proportional
#define PID_IGAIN 0         // PID Integral
#define PID_DGAIN 0         // PID Derivative
#define PID_SERVO false     // PID Servo
```

## About Car Chassis
This project was optimized for a 2WD car chassis. But a 4WD chassis by changing the motor and PID parameters.

### Reference 1 (Brazil):
<img src="https://github.com/user-attachments/assets/a9df5a34-d674-420d-8a0a-e778307f751a" width="300">

https://www.robocore.net/robotica-robocore/plataforma-robotica-falcon-v2


### Reference 2 (Brazil):
<img src="https://github.com/user-attachments/assets/af0bdffe-b05b-49c7-afa5-9310110f2eb8" width="300">

https://www.robocore.net/robotica-robocore/plataforma-robotica-rocket-tank

### Reference 3 (International):
<img src="https://github.com/user-attachments/assets/8843c2a8-3bd6-4c1b-b62e-6235c29c4a89" width="300">

https://www.aliexpress.us/item/3256801542172576.html

## About the Power Supply
I recommend to use high quality 18650 batteries (3.7v - 4.2v, 2200mAh, at least 2C of discharge rate).

## Fritzing file
The eletronic schematic was created in the [Fritzing](https://fritzing.org/) software and can be downloaded at
* [huskylens-line-tracking-car.zip](https://github.com/user-attachments/files/16801611/huskylens-line-tracking-car.zip)

