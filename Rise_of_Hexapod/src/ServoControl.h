#ifndef SERVOCONTROL_H
#define SERVOCONTROL_H

/***********************************************************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

/***********************************************************************************************/

#define SDA_PIN 22
#define SCL_PIN 23

/***********************************************************************************************/

#define SERVOCOUNT 18
#define STEPDEGREE 5

/***********************************************************************************************/

#define SERVO_MAX 535
#define SERVO_MIN 75

/***********************************************************************************************/

#define SERVOGROUP1 90
#define SERVOGROUP2 0
#define SERVOGROUP3 0

/***********************************************************************************************/

extern Adafruit_PWMServoDriver PCAServoControlLeft;
extern Adafruit_PWMServoDriver PCAServoControlRight;

/***********************************************************************************************/

typedef struct
{
    int servoNum;
    int currentServoDeg;
    int desiredServoDeg;
} ServoControl;

/***********************************************************************************************/

void InitPCADevices();
void ServosToInitial();
void SetServoDeg(int ServoNum, int DesiredServoDeg);
void MoveServos();
int PcaAngleCalculator(int ang);
void TestServos();

#endif // SERVOCONTROL_H
