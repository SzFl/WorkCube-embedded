void setupOfMpu()
{
  if (!mpu.begin()) 
  {
    Serial.println("Failed to connect with MPU6050 chip.");
    while (1) 
    {
      delay(10);
    }
  }
  Serial.println("MPU6050 chip found and connected.");
    
  //Setting up range of accelerometer
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  //Setting up filter bandwidth(this dictates accuracy)
  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
  
  Serial.println("Setup done");
}
