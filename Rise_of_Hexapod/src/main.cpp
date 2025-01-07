#include <ServoControl.h>
#include <HexapodControl.h>
#include <Boolean.h>

#define JOYSTICK_MAC "08:A6:F7:21:A2:94"

typedef struct
{
  int xValue;
  int yValue;

  bool buttonState1;
  bool buttonState2;
  bool buttonState3;
  bool buttonState4;
  bool buttonState5;

} JoystickDataReceived;

JoystickDataReceived joystickData;

bool servosInitial = servosNotInitialized;

void onReceiveData(const uint8_t *mac, const uint8_t *incomingData, int len);


void setup()
{
  Serial.begin(115200);

  servosInitial = servosNotInitialized;

  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK)
  {
    Serial.println("ESP-NOW başlatılamadı!");
    return;
  }

  esp_now_register_recv_cb(onReceiveData);
  Serial.println("ESP-NOW başlatıldı!");

  InitPCADevices();
  delay(10);

}

void loop()
{
  delay(100);
}


void onReceiveData(const uint8_t *mac, const uint8_t *incomingData, int len)
{
  if (len == sizeof(JoystickDataReceived))
  {
    memcpy(&joystickData, incomingData, sizeof(joystickData));

    joystickData.yValue = map(joystickData.yValue, 0, 180, -90, 90);

    if (joystickData.buttonState2 == on)
    {
      ServosToInitial();
      servosInitial = servosInitialized;
    }
    if (joystickData.buttonState3 == on  || (joystickData.xValue > 85 && joystickData.xValue < 95 && servosInitial == servosInitialized) && servosInitial == servosInitialized )
    {
      standUp();
    }
    if (joystickData.buttonState4 == on && servosInitial == servosInitialized)
    {
      turnClockWise();
    }
    if (joystickData.buttonState5 == on && servosInitial == servosInitialized)
    {
      turnCounterClockWise();
    }
    if (joystickData.xValue > 95 && servosInitial == servosInitialized)
    {
      goStraight(joystickData.xValue, joystickData.yValue);
    }
    if (joystickData.xValue < 85 && servosInitial == servosInitialized)
    {
      goBack(joystickData.xValue, joystickData.yValue);
    }
  }
}