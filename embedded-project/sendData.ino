

void sendMessageDeviceStatus(char messege[])
{
    Serial.println("Starting up BLE");
    
    BLEDevice::init("MyESP32");
    BLEServer *pServer = BLEDevice::createServer();
    BLEService *pService = pServer->createService(SERVICE_UUID);

    BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                     CHARACTERISTIC_UUID,
                                     BLECharacteristic::PROPERTY_READ |
                                     BLECharacteristic::PROPERTY_WRITE
                                     );

    pCharacteristic->setValue(messege);
    pService->start();
    
    //BLEAdvertising *pAdvertising = pServer->getAdvertising();
    //pAdvertising->start();

    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->setScanResponse(true);
    //pAdvertising->setMinPreferred(0x06);
    pAdvertising->setMinPreferred(0x12);
    BLEDevice::startAdvertising();

    Serial.println("Ble RUNs");
  
}
