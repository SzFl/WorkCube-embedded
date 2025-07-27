#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

//===================================================

Adafruit_MPU6050 mpu;

#define uS_TO_S_FACTOR 1000000
#define TIME_TO_SLEEP  10

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

RTC_DATA_ATTR bool isOn = false;
RTC_DATA_ATTR int wallNumber = 0;

//===================================================

void setup()
{
  //Seting up serial
  Serial.begin(115200);
  delay(3000);
  
  Serial.println("Serial connected.");
  wakeUpManager();

//  sendMessageDeviceStatus("Wall 0");
//  delay(5000);
//  esp_deep_sleep_start();
}


void loop()
{
  delay(5000);
  //tmp();
}
