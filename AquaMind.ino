#include <Wire.h> //I2C para OLED
#include <Adafruit_GFX.h> // COntrole do Display
#include <Adafruit_SSD1306.h> // COntrole do Display
#include <BLEDevice.h> // Servidor BLE
#include <BLEUtils.h>
#include <BLEServer.h>
#include <OneWire.h>
#include <DallasTemperature.h> // SEnsor DS18B20

#define SCREEN_WIDTH 128
#define SCREEN_HEIGTH 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);
//serviço BLE
#define SERVICE_UUID "1234"
#define TEMP_CHAR_UUID "1235"
#define AMONIA_CHAR_UUID "1236"
#define LED_CHAR_UUID "1237"


BLECharacteristic tempChar(TEMP_CHAR_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
BLECharacteristic amoniaChar(AMONIA_CHAR_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
BLECharacteristic ledChar(LED_CHAR_UUID, BLECharacteristic::PROPERTY_WRITE);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
