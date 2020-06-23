void setup()
{
  int i;
  for(i=0;i<10;i++)
  pinMode(i, OUTPUT);
}

void loop()
{
  int i;
  for(i=0;i<10;i++)
  { 
    
  	digitalWrite(i, HIGH);
    digitalWrite(9-i, HIGH);
  	delay(500); // Wait for 1000 millisecond(s)
  	digitalWrite(i, LOW);
    digitalWrite(9-i, LOW);
  	delay(400); // Wait for 1000 millisecond(s)
  }
}