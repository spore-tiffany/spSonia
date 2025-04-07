void atomizerSetup()
{
  pinMode(atomizerPin,OUTPUT);
}

void handleAtomizer(int act)
{
  analogWrite(atomizerPin, act);
}