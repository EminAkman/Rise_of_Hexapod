
#include <Arduino.h>
#include <ESP32Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
          


Adafruit_PWMServoDriver PWM_Driver = Adafruit_PWMServoDriver();

Servo Servo1;
Servo Servo2;

/*

  TODO:
  1- Servoları ekleme ++
  2- PCA için gerekli olan haberleşme kodunun yazılması
  3- Bylnk ile haberleşmek için gereken kodunun yazılması
  4-  

*/

void setup() {

  Serial.begin(115200);

  Servo1.attach(4);
  Servo1.attach(5);

  PWM_Driver.begin();
  PWM_Driver.setPWMFreq(50);


}

void loop() {

  for (int i = 0; i < 16; i++) {
    int pulse = map(90, 0, 180, 102, 512); // 90 dereceyi orta konuma ayarlama
    PWM_Driver.setPWM(i, 0, pulse);
  }
  
}
