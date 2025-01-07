#include <HexapodControl.h>
#include <ServoControl.h>

/*

                              Rise of Hexapod
                                  _____
---(Servo7)---(Servo4)---(Servo1)|     |(Servo10)---(Servo13)---(Servo16)---
                                 |     |
---(Servo8)---(Servo5)---(Servo2)|     |(Servo11)---(Servo14)---(Servo17)---
                                 |     |
---(Servo9)---(Servo6)---(Servo3)|_____|(Servo12)---(Servo15)---(Servo18)---

*/

void standUp()
{

  SetServoDeg(4, 115);
  SetServoDeg(5, 115);
  SetServoDeg(6, 115);

  SetServoDeg(13, 75);
  SetServoDeg(14, 75);
  SetServoDeg(15, 75);

  MoveServos();

  delay(1000);

}

void turnClockWise()
{

  SetServoDeg(4, 145);
  SetServoDeg(6, 145);
  SetServoDeg(14, 45);

  SetServoDeg(1, 60);
  SetServoDeg(11, 60);
  SetServoDeg(3, 60);

  MoveServos();

  SetServoDeg(4, 105);
  SetServoDeg(6, 105);
  SetServoDeg(14, 75);

  MoveServos();

  SetServoDeg(13, 45);
  SetServoDeg(15, 45);
  SetServoDeg(5, 145);

  SetServoDeg(10, 60);
  SetServoDeg(12, 60);
  SetServoDeg(2, 60);

  MoveServos();

  SetServoDeg(1, 90);
  SetServoDeg(11, 90);
  SetServoDeg(3, 90);

  MoveServos();

  SetServoDeg(13, 75);
  SetServoDeg(15, 75);
  SetServoDeg(5, 105);

  MoveServos();

  SetServoDeg(4, 145);
  SetServoDeg(6, 145);
  SetServoDeg(14, 45);

  MoveServos();

  SetServoDeg(10, 90);
  SetServoDeg(12, 90);
  SetServoDeg(2, 90);

  MoveServos();
  
}
void turnCounterClockWise()
{
  
  SetServoDeg(4, 145);
  SetServoDeg(6, 145);
  SetServoDeg(14, 45);

  SetServoDeg(1, 120);
  SetServoDeg(11, 120);
  SetServoDeg(3, 120);

  MoveServos();

  SetServoDeg(4, 105);
  SetServoDeg(6, 105);
  SetServoDeg(14, 75);

  MoveServos();

  SetServoDeg(13, 45);
  SetServoDeg(15, 45);
  SetServoDeg(5, 145);

  SetServoDeg(10, 120);
  SetServoDeg(12, 120);
  SetServoDeg(2, 120);

  MoveServos();

  SetServoDeg(1, 90);
  SetServoDeg(11, 90);
  SetServoDeg(3, 90);

  MoveServos();

  SetServoDeg(13, 75);
  SetServoDeg(15, 75);
  SetServoDeg(5, 105);

  MoveServos();

  SetServoDeg(4, 145);
  SetServoDeg(6, 145);
  SetServoDeg(14, 45);

  MoveServos();

  SetServoDeg(10, 90);
  SetServoDeg(12, 90);
  SetServoDeg(2, 90);

  MoveServos();
  
}

void goStraight(int xPos, int yPos)
{

  SetServoDeg(4, 145);
  SetServoDeg(6, 145);
  SetServoDeg(14, 45);

  SetServoDeg(1, 95 + map(xPos,95,180,0,15));
  SetServoDeg(11, 85 - (map(xPos,95,180,0,15) + map(yPos,-90,90,-15,15)));
  SetServoDeg(3, 95 + map(xPos,95,180,0,15));

  MoveServos();

  SetServoDeg(4, 105);
  SetServoDeg(6, 105);
  SetServoDeg(14, 75);

  MoveServos();

  SetServoDeg(13, 45);
  SetServoDeg(15, 45);
  SetServoDeg(5, 145);

  SetServoDeg(10, 85 - (map(xPos,95,180,0,15) + map(yPos,-90,90,-15,15)));
  SetServoDeg(12, 85 - (map(xPos,95,180,0,15) + map(yPos,-90,90,-15,15)));
  SetServoDeg(2, 95 + map(xPos,95,180,0,15));

  MoveServos();

  SetServoDeg(1, 90);
  SetServoDeg(11, 90);
  SetServoDeg(3, 90);

  MoveServos();

  SetServoDeg(13, 75);
  SetServoDeg(15, 75);
  SetServoDeg(5, 105);

  MoveServos();

  SetServoDeg(4, 145);
  SetServoDeg(6, 145);
  SetServoDeg(14, 45);

  MoveServos();

  SetServoDeg(10, 90);
  SetServoDeg(12, 90);
  SetServoDeg(2, 90);

  MoveServos();
}
void goBack(int xPos, int yPos)
{

  SetServoDeg(4, 145);
  SetServoDeg(6, 145);
  SetServoDeg(14, 45);

  SetServoDeg(1, 85 - map(xPos,0,95,0,15));
  SetServoDeg(11, 95 + (map(xPos,0,95,0,15) + map(yPos,-90,90,-15,15)));
  SetServoDeg(3, 85 - map(xPos,0,95,0,15));

  MoveServos();

  SetServoDeg(4, 105);
  SetServoDeg(6, 105);
  SetServoDeg(14, 75);

  MoveServos();

  SetServoDeg(13, 45);
  SetServoDeg(15, 45);
  SetServoDeg(5, 145);

  SetServoDeg(10, 95 + (map(xPos,0,95,0,15) + map(yPos,-90,90,-15,15)));
  SetServoDeg(12, 95 + (map(xPos,0,95,0,15) + map(yPos,-90,90,-15,15)));
  SetServoDeg(2, 75 - map(xPos,0,95,0,15));

  MoveServos();

  SetServoDeg(1, 90);
  SetServoDeg(11, 90);
  SetServoDeg(3, 90);

  MoveServos();

  SetServoDeg(13, 75);
  SetServoDeg(15, 75);
  SetServoDeg(5, 105);

  MoveServos();

  SetServoDeg(4, 145);
  SetServoDeg(6, 145);
  SetServoDeg(14, 45);

  MoveServos();

  SetServoDeg(10, 90);
  SetServoDeg(12, 90);
  SetServoDeg(2, 90);

  MoveServos();
}
