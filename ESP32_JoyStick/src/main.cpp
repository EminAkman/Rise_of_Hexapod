// Robot mac adresi E4:65:B8:D9:F8:78

#include <esp_now.h>
#include <WiFi.h>
#include <Wire.h>

#define JOYSTICK_X_PIN 34 // Joystick'in X cıkışı
#define JOYSTICK_Y_PIN 32 // Joystick'in Y cıkışı

#define I2C_SDA 21
#define I2C_SCL 22
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 240

typedef struct
{
    int xValue;
    int yValue;
    bool Switch1;
    bool Switch2;
    bool Switch3;
    bool Switch4;
    bool Switch5;
} JoystickData;

JoystickData joystickData;

// Alıcının MAC adresi
uint8_t receiverMAC[] = {0xE4, 0x65, 0xB8, 0xD9, 0xF8, 0x78}; // Alıcının MAC adresini buraya yazın
esp_now_peer_info_t peerInfo;

void setup()
{
    Serial.begin(115200);

    // Wi-Fi'yi başlat ve ESP-NOW'u etkinleştir
    WiFi.mode(WIFI_STA);
    if (esp_now_init() != ESP_OK)
    {
        Serial.println("ESP-NOW başlatılamadı");
        return;
    }

    // Alıcı cihazı kaydet
    memcpy(peerInfo.peer_addr, receiverMAC, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    if (esp_now_add_peer(&peerInfo) != ESP_OK)
    {
        Serial.println("Peer eklenemedi");
        return;
    }

    // Joystick pinlerini yapılandır
    pinMode(JOYSTICK_X_PIN, INPUT);
    pinMode(JOYSTICK_Y_PIN, INPUT);
    pinMode(35, INPUT);
    pinMode(18, INPUT_PULLDOWN);
    pinMode(14, INPUT_PULLDOWN);
    pinMode(27, INPUT_PULLDOWN);
    pinMode(26, INPUT_PULLDOWN);
    pinMode(25, INPUT_PULLDOWN);
}

void loop()
{
    // Joystick değerlerini oku

    int xValue = map(analogRead(JOYSTICK_X_PIN), 0, 4095, 0, 180);
    int yValue = map(analogRead(JOYSTICK_Y_PIN), 0, 4095, 0, 180);

    if (xValue <= 78)
    {
        joystickData.xValue = map(xValue, 0, 78, 0, 90);
    }

    if (xValue > 78)
    {
        joystickData.xValue = map(xValue, 78, 180, 90, 180);
    }

    if (yValue <= 83)
    {
        joystickData.yValue = map(yValue, 0, 83, 0, 90);
    }

    if (yValue > 83)
    {
        joystickData.yValue = map(yValue, 83, 180, 90, 180);
    }

    joystickData.Switch1 = digitalRead(18);
    joystickData.Switch2 = digitalRead(14);
    joystickData.Switch3 = digitalRead(27);
    joystickData.Switch4 = digitalRead(26);
    joystickData.Switch5 = digitalRead(25);

    // Veriyi gönder
    esp_err_t result = esp_now_send(receiverMAC, (uint8_t *)&joystickData, sizeof(joystickData));

    delay(100); // Verici döngüsü
}
