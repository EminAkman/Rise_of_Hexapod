#include <HexapodControl.h>
/***********************************************************************************************/
#define BLYNK_TEMPLATE_ID "TMPL6-OLETinU"
#define BLYNK_TEMPLATE_NAME "RiseOfHexapod"
#define BLYNK_AUTH_TOKEN "tfT5DuBz_9RAiowy9zauI2DdAaWzqARI"

/***********************************************************************************************/

char ssid[] = "EMIN"; //  PCA dan sonra bunun initialitionu için gerekli kodu yazmalıyım.
char pass[] = "ozanozanozan";

/***********************************************************************************************/

bool Once = true;

/***********************************************************************************************/

/*

                                Rise of Hexapod
                                  _____
---(Servo7)---(Servo4)---(Servo1)|     |(Servo10)---(Servo13)---(Servo16)---
                                 |     |
---(Servo8)---(Servo5)---(Servo2)|     |(Servo11)---(Servo14)---(Servo17)---
                                 |     |
---(Servo9)---(Servo6)---(Servo3)|_____|(Servo12)---(Servo15)---(Servo18)---


*/

void BlynkInit()
{

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  if (Blynk.connected())
  {
    Serial.println("Blynk connection is successful.");
  }
  delay(100);
}

void RunBlnykyRun()
{
  Blynk.run();
}

void standUp()
{
}

void turnClockWise()
{
}
void turnCounterClockWise()
{
}
void goStraight()
{
}
void goBack()
{
}

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();

  if (pinValue == 1 && Once == true)
  {

    Once = false;
    standUp();
  }
  if (pinValue == 0)
  {
    Once = true;
  }
}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();

  if (pinValue == 1 && Once == true)
  {

    Once = false;
    turnClockWise();
  }
  if (pinValue == 0)
  {
    Once = true;
  }
}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();

  if (pinValue == 1 && Once == true)
  {

    Once = false;
    turnCounterClockWise();
  }
  if (pinValue == 0)
  {
    Once = true;
  }
}

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();

  if (pinValue == 1 && Once == true)
  {

    Once = false;
    goStraight();
  }
  if (pinValue == 0)
  {
    Once = true;
  }
}

BLYNK_WRITE(V3)
{
  int pinValue = param.asInt();

  if (pinValue == 1 && Once == true)
  {

    Once = false;
    goBack();
  }
  if (pinValue == 0)
  {
    Once = true;
  }
}

BLYNK_WRITE(V4)
{
  int pinValue = param.asInt();

  if (pinValue == 1 && Once == true)
  {

    Once = false;
    turnCounterClockWise();
  }
  if (pinValue == 0)
  {
    Once = true;
  }
}