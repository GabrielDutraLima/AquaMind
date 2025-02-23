#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define LED_PIN1 4  // LED no pino D4

BLECharacteristic ledChar("1237", BLECharacteristic::PROPERTY_WRITE);

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN1, OUTPUT);

    BLEDevice::init("ESP32_Aquario_LED");
    BLEServer *server = BLEDevice::createServer();
    BLEService *service = server->createService("1234");

    service->addCharacteristic(&ledChar);

    class LEDCallback : public BLECharacteristicCallbacks {
        void onWrite(BLECharacteristic *pCharacteristic) {
            if (pCharacteristic->getLength() > 0) {
                uint8_t brilho = pCharacteristic->getData()[0]; 
                brilho = constrain(brilho, 0, 255);
                Serial.print("Brilho recebido: ");
                Serial.println(brilho);
                analogWrite(LED_PIN1, brilho);
            }
        }
    };

    ledChar.setCallbacks(new LEDCallback());
    service->start();

    BLEAdvertising *advertising = BLEDevice::getAdvertising();
    advertising->addServiceUUID("1234");
    advertising->start();

    Serial.println("Servidor BLE do LED Iniciado!");
}

void loop() {
    delay(100);
}
