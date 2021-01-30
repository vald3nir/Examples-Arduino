void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    //R = Serial.readStringUntil(',').toInt();
  }
}
