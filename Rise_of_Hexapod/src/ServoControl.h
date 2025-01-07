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

extern Adafruit_PWMServoDriver PCAServoControlLeft;
extern Adafruit_PWMServoDriver PCAServoControlRight;

/***********************************************************************************************/

typedef struct
{
    unsigned short int servoNum;
    unsigned short int currentServoDeg;
    unsigned short int desiredServoDeg;
} ServoControl;

/***********************************************************************************************/

void InitPCADevices();
void ServosToInitial();
void SetServoDeg(int ServoNum, int DesiredServoDeg);
void MoveServos();
int PcaAngleCalculator(int ang);
void TestServos();

#endif // SERVOCONTROL_H
