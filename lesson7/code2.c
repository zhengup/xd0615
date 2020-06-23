int pinInterrupt=2;
int x=0;
  
void RZ()
{
  x=0;
}

  
void setup()
{ 
  Serial.begin(9600);
  pinMode(pinInterrupt,INPUT);
 
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(8,LOW);
  
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), RZ, CHANGE);
}

byte n[10]={0,1,2,3,4,5,6,7,8,9};

void loop()
{
  for(x;x<10;x++)
  {
    digitalWrite(4,n[x]&0x1);
    digitalWrite(5,(n[x]>>1)&0x1);
    digitalWrite(6,(n[x]>>2)&0x1);
    digitalWrite(7,(n[x]>>3)&0x1);
    delay(1000);
  }
}