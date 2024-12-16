#include <Arduino.h>
#include "ServoControl.h"
#include <Wire.h>
#include <HexapodControl.h>

void setup()
{
  Serial.begin(115200);

  /*************************************************************/

  InitPCADevices();
  delay(10);

  /*************************************************************/

  ServosToInitial();
  delay(500);

  /*************************************************************/

}


void loop()
{

  RunBlnykyRun();

}
