void setup()
{
  Serial.begin(9600);
  for(int i=6;i<10;i++)
  {
    pinMode(i,OUTPUT);
  }
  Serial.println("READY");
}

/* 'f':前进
   'b':后退
   'r':右停
   'l':左停
   's':停止 */
void loop()
{
  char ch;
  if(Serial.available()>0)
  {
  	ch=Serial.read();
    switch(ch)
    {
    case 'f':
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      break;
    case 'b':
      digitalWrite(7,LOW);
      digitalWrite(6,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(8,LOW);
      break;
    case 'r':
      digitalWrite(7,LOW);
      digitalWrite(6,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      break;
    case 'l':
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(9,LOW);
      digitalWrite(8,LOW);
      break;
    case 's':
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      break;
    default:
      break;
    }
  }
}
