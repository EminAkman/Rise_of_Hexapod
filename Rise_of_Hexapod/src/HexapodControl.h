#include <ServoControl.h>
#include <WiFi.h>
#include <esp_now.h>

void standUp();
void turnClockWise();
void turnCounterClockWise();
void goStraight(int xPos, int yPos);
void goBack(int xPos, int yPos);
