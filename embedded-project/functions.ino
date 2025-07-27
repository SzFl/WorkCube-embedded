void tmp()
{
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  double x = a.acceleration.x;
  double y = a.acceleration.y;
  double z = a.acceleration.z;

  Serial.print("X: ");
  Serial.print(x);
  Serial.print(", Y: ");
  Serial.print(y);
  Serial.print(", Z: ");
  Serial.println(z);
  delay(1000);
}

void wakeupByExternalSignal()
{
  if(isOn)
      {
        isOn = false;
        Serial.println("Turning OFF");//tmp
        sendMessageDeviceStatus("Cube is OFF");
        delay(5000);
        esp_sleep_enable_ext0_wakeup(GPIO_NUM_18, LOW);
        esp_deep_sleep_start();
      }
      else
      {
        isOn = true;
        setupOfMpu();
        wallNumber = whichWallIsChosen();
        Serial.print("Wall after start of program: ");//tmp
        Serial.println(wallNumber);//tmp
        //Przesłanie komunikatu
        switch(wallNumber)
        {
          case(0):
            sendMessageDeviceStatus("Wall 0");
            break;
          case(1):
            sendMessageDeviceStatus("Wall 1");
            break;
          case(2):
            sendMessageDeviceStatus("Wall 2");
            break;
          case(3):
            sendMessageDeviceStatus("Wall 3");
            break;
          case(4):
            sendMessageDeviceStatus("Wall 4");
            break;
          case(5):
            sendMessageDeviceStatus("Wall 5");
            break;
        }
        delay(5000);
        esp_sleep_enable_ext0_wakeup(GPIO_NUM_18, LOW);
        esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
        esp_deep_sleep_start();
      }
}

void wakeupByTimer()
{
  setupOfMpu();
  int myval = whichWallIsChosen();
  if(wallNumber != myval )
  {
    wallNumber = myval;
    Serial.print("There is new wall:");//tmp
    Serial.println(wallNumber);//tmp
    switch(wallNumber)
        {
          case(0):
            sendMessageDeviceStatus("Wall 0");
            break;
          case(1):
            sendMessageDeviceStatus("Wall 1");
            break;
          case(2):
            sendMessageDeviceStatus("Wall 2");
            break;
          case(3):
            sendMessageDeviceStatus("Wall 3");
            break;
          case(4):
            sendMessageDeviceStatus("Wall 4");
            break;
          case(5):
            sendMessageDeviceStatus("Wall 5");
            break;
        }
    delay(5000);//tmp
    //Przesłać info, że zmiana
  }
  else
  {
    Serial.print("Wall stays: ");//tmp
    Serial.println(wallNumber);//tmp
    delay(2000);//tmp
  }
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_18, LOW);
  esp_deep_sleep_start();
}
