void relaySetup()
{
  pinMode(relayPin,OUTPUT);
}

void handleRelay(bool act)
{
  digitalWrite(relayPin, act);
}