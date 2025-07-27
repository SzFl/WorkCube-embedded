int whichWallIsChosen()
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

  if( abs(y) < abs(x) && abs(z)<abs(x) )
  {
    if(0<x)
    {
      return 4;
    }
    else
    {
      return 5;
    }
  }
  else if(abs(x) < abs(y) && abs(z)<abs(y))
  {
    if(0<y)
    {
      return 3;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    if(0<z)
    {
      return 0;
    }
    else
    {
      return 2;
    }
  }
}
