 void setup()
{ 
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
}

byte n[10]={0,1,2,3,4,5,6,7,8,9};

void loop()
{
  for(int i=0;i<10;i++)
  {
    digitalWrite(4,n[i]&0x1);
    digitalWrite(5,(n[i]>>1)&0x1);
    digitalWrite(6,(n[i]>>2)&0x1);
    digitalWrite(7,(n[i]>>3)&0x1);
    delay(1000);
  }
}	
