void wakeUpManager()
{
  esp_sleep_wakeup_cause_t wakeup_reason = esp_sleep_get_wakeup_cause();
  delay(5000);
  
  switch(wakeup_reason)
  {
    case ESP_SLEEP_WAKEUP_EXT0 : 
      Serial.println("Wakeup caused by external signal using RTC_IO");
      wakeupByExternalSignal();
      break;
    case ESP_SLEEP_WAKEUP_TIMER : 
      Serial.println("Wakeup caused by timer");
      wakeupByTimer();
      break;
    default : 
      Serial.println("Program starts.");
      esp_sleep_enable_ext0_wakeup(GPIO_NUM_18, LOW);
      esp_deep_sleep_start();
      break;
  }
}
