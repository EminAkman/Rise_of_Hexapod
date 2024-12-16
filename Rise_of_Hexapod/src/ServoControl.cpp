#include "ServoControl.h"

/************************************************************************************/

Adafruit_PWMServoDriver PCAServoControlLeft(0x40);
Adafruit_PWMServoDriver PCAServoControlRight(0x41);

/************************************************************************************/

ServoControl Servos[SERVOCOUNT]; // Sero Control struct to keep values to store correctly.
int ServoNums[SERVOCOUNT];       // The array in which the motors that are desired to move are kept.
int Count = 0;

void InitPCADevices()
{

    for (int i = 0; i < SERVOCOUNT; i++)
    {
        ServoNums[i] = -1;
    }

    /***********************I2C AND SERIAL BUS START********************************/
    Wire.begin(SDA_PIN, SCL_PIN);
    Serial.begin(115200);

    /********************************PCA INIT***************************************/

    PCAServoControlLeft.begin();
    PCAServoControlLeft.setPWMFreq(50);
    PCAServoControlRight.begin();
    PCAServoControlRight.setPWMFreq(50);
}

/****************************SERVO TEST FUNC********************************/

void TestServos()
{
    for (int i = 0; i < 16; i++)
    {
        PCAServoControlLeft.setPWM(i, 0, 75);
        delay(100);
    }

    for (int i = 0; i < 16; i++)
    {
        PCAServoControlLeft.setPWM(i, 0, 300);
        delay(100);
    }

    for (int i = 0; i < 16; i++)
    {
        PCAServoControlLeft.setPWM(i, 0, 535);
        delay(100);
    }
}

/*****************************PCA ANGLE CALCULATOR****************************/

int PcaAngleCalculator(int ang)
{
    return map(ang, 0, 180, SERVO_MAX, SERVO_MIN);
}

void ServosToInitial()
{

    for (int i = 0; i < SERVOCOUNT; i++)
    {
        Servos[i].servoNum = i;
    }

    /*********************************************************/

    PCAServoControlLeft.setPWM(0, 0, PcaAngleCalculator(SERVOGROUP1));
    PCAServoControlLeft.setPWM(1, 0, PcaAngleCalculator(SERVOGROUP1));
    PCAServoControlLeft.setPWM(2, 0, PcaAngleCalculator(SERVOGROUP1));
    PCAServoControlRight.setPWM(0, 0, PcaAngleCalculator(SERVOGROUP1));
    PCAServoControlRight.setPWM(1, 0, PcaAngleCalculator(SERVOGROUP1));
    PCAServoControlRight.setPWM(2, 0, PcaAngleCalculator(SERVOGROUP1));

    for (int i = 0; i < 3; i++)
    {
        Servos[i].currentServoDeg = 90;
        Servos[i].desiredServoDeg = 90;
    }

    for (int i = 9; i < 12; i++)
    {
        Servos[i].currentServoDeg = 90;
        Servos[i].desiredServoDeg = 90;
    }

    /*********************************************************/

    PCAServoControlLeft.setPWM(3, 0, PcaAngleCalculator(SERVOGROUP2));
    PCAServoControlLeft.setPWM(4, 0, PcaAngleCalculator(SERVOGROUP2));
    PCAServoControlLeft.setPWM(5, 0, PcaAngleCalculator(SERVOGROUP2));
    PCAServoControlRight.setPWM(3, 0, PcaAngleCalculator(SERVOGROUP2));
    PCAServoControlRight.setPWM(4, 0, PcaAngleCalculator(SERVOGROUP2));
    PCAServoControlRight.setPWM(5, 0, PcaAngleCalculator(SERVOGROUP2));

    for (int i = 3; i < 6; i++)
    {
        Servos[i].currentServoDeg = 0;
        Servos[i].desiredServoDeg = 0;
    }

    for (int i = 12; i < 15; i++)
    {
        Servos[i].currentServoDeg = 0;
        Servos[i].desiredServoDeg = 0;
    }

    /*********************************************************/

    PCAServoControlLeft.setPWM(6, 0, PcaAngleCalculator(SERVOGROUP3));
    PCAServoControlLeft.setPWM(7, 0, PcaAngleCalculator(SERVOGROUP3));
    PCAServoControlLeft.setPWM(8, 0, PcaAngleCalculator(SERVOGROUP3));
    PCAServoControlRight.setPWM(6, 0, PcaAngleCalculator(SERVOGROUP3));
    PCAServoControlRight.setPWM(7, 0, PcaAngleCalculator(SERVOGROUP3));
    PCAServoControlRight.setPWM(8, 0, PcaAngleCalculator(SERVOGROUP3));

    for (int i = 6; i < 9; i++)
    {
        Servos[i].currentServoDeg = 0;
        Servos[i].desiredServoDeg = 0;
    }

    for (int i = 15; i < 18; i++)
    {
        Servos[i].currentServoDeg = 0;
        Servos[i].desiredServoDeg = 0;
    }

    Serial.println("Servo initialization is completed.");
}

void MoveServos()
{
    int sum = 0;
    Serial.print("Sum = ");
    Serial.println(sum);
    int gap = 0;

    while (sum > -16)
    {
        for (int i = 0; i < SERVOCOUNT; i++)
        {
            sum = 0;
            if (ServoNums[i] != -1)
            {
                /********************************************* Left Servo Movement *********************************************/

                if (ServoNums[i] <= 9)
                {

                    if (Servos[ServoNums[i] - 1].currentServoDeg == Servos[ServoNums[i] - 1].desiredServoDeg)
                    {
                        ServoNums[i] = -1;
                    }
                    if (Servos[ServoNums[i] - 1].desiredServoDeg > Servos[ServoNums[i] - 1].currentServoDeg)
                    {
                        gap = Servos[ServoNums[i] - 1].desiredServoDeg - Servos[ServoNums[i] - 1].currentServoDeg;

                        if (gap > STEPDEGREE)
                        {
                            PCAServoControlLeft.setPWM(ServoNums[i] - 1, 0, PcaAngleCalculator(Servos[ServoNums[i] - 1].currentServoDeg + STEPDEGREE));
                            Servos[ServoNums[i] - 1].currentServoDeg += STEPDEGREE;
                        }

                        if (gap <= STEPDEGREE)
                        {
                            PCAServoControlLeft.setPWM(ServoNums[i] - 1, 0, PcaAngleCalculator(Servos[ServoNums[i] - 1].desiredServoDeg));
                            Servos[ServoNums[i] - 1].currentServoDeg = Servos[ServoNums[i] - 1].desiredServoDeg;
                        }
                    }

                    if (Servos[ServoNums[i] - 1].desiredServoDeg < Servos[ServoNums[i] - 1].currentServoDeg)
                    {

                        gap = Servos[ServoNums[i] - 1].currentServoDeg - Servos[ServoNums[i] - 1].desiredServoDeg;

                        if (gap > STEPDEGREE)
                        {
                            PCAServoControlLeft.setPWM(ServoNums[i] - 1, 0, PcaAngleCalculator(Servos[ServoNums[i] - 1].currentServoDeg - STEPDEGREE));
                            Servos[ServoNums[i] - 1].currentServoDeg -= STEPDEGREE;
                        }

                        if (gap <= STEPDEGREE)
                        {
                            PCAServoControlLeft.setPWM(ServoNums[i] - 1, 0, PcaAngleCalculator(Servos[ServoNums[i] - 1].desiredServoDeg));
                            Servos[ServoNums[i] - 1].currentServoDeg = Servos[ServoNums[i] - 1].desiredServoDeg;
                        }
                    }
                }

                /********************************************* Right Servo Movement *********************************************/

                if (ServoNums[i] > 9)
                {
                    if (Servos[ServoNums[i] - 1].currentServoDeg == Servos[ServoNums[i] - 1].desiredServoDeg)
                    {
                        ServoNums[i] = -1;
                    }

                    if (Servos[ServoNums[i] - 1].desiredServoDeg > Servos[ServoNums[i] - 1].currentServoDeg)
                    {
                        gap = Servos[ServoNums[i] - 1].desiredServoDeg - Servos[ServoNums[i] - 1].currentServoDeg;
                        if (gap > STEPDEGREE)
                        {
                            PCAServoControlRight.setPWM(ServoNums[i] - 10, 0, PcaAngleCalculator(Servos[ServoNums[i] - 1].currentServoDeg + STEPDEGREE));
                            Servos[ServoNums[i] - 1].currentServoDeg += STEPDEGREE;
                        }
                        if (gap <= STEPDEGREE)
                        {
                            PCAServoControlRight.setPWM(ServoNums[i] - 10, 0, PcaAngleCalculator(Servos[ServoNums[i] - 1].desiredServoDeg));
                            Servos[ServoNums[i] - 1].currentServoDeg = Servos[ServoNums[i] - 1].desiredServoDeg;
                        }
                    }

                    if (Servos[ServoNums[i] - 1].desiredServoDeg < Servos[ServoNums[i] - 1].currentServoDeg)
                    {
                        gap = Servos[ServoNums[i] - 1].currentServoDeg - Servos[ServoNums[i] - 1].desiredServoDeg;
                        if (gap > STEPDEGREE)
                        {
                            PCAServoControlRight.setPWM(ServoNums[i] - 10, 0, PcaAngleCalculator(Servos[ServoNums[i] - 1].currentServoDeg - STEPDEGREE));
                            Servos[ServoNums[i] - 1].currentServoDeg -= STEPDEGREE;
                        }

                        if (gap <= STEPDEGREE)
                        {
                            PCAServoControlRight.setPWM(ServoNums[i] - 10, 0, PcaAngleCalculator(Servos[ServoNums[i] - 1].desiredServoDeg));
                            Servos[ServoNums[i] - 1].currentServoDeg = Servos[ServoNums[i] - 1].desiredServoDeg;
                        }
                    }
                }
            }

            // for (int i = 0; i < SERVOCOUNT; i++)
            // {
            //     Serial.print("[");
            //     Serial.print(ServoNums[i]);
            //     Serial.print("] ");
            // }

            // Serial.println(" ");

            for (int i = 0; i < 16; i++)
            {
                sum += ServoNums[i];
            }
        }
        Serial.print("devam");
    }
    Count = 0;
}

void SetServoDeg(int ServoNum, int DesiredServoDeg)
{
    Servos[ServoNum - 1].desiredServoDeg = DesiredServoDeg;
    ServoNums[Count] = ServoNum;
    Count++;
}
