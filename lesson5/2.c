#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define S1 8
#define S2 9
#define S3 10
#define S4 11

#define LT 6
#define BT 7
void setup()
{
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(S1, OUTPUT);//片选1
  pinMode(S2, OUTPUT);//片选2
  pinMode(S3, OUTPUT);//片选3
  pinMode(S4, OUTPUT);//片选4
  
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐
  Serial.begin(9600);
}

byte income[4]={0};

void loop()
{
    digitalWrite(LT,HIGH);
    digitalWrite(BT,HIGH);
    
    digitalWrite(S1,HIGH);
    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    digitalWrite(S4,HIGH);
    
    for(int i=0;i<4;i++)
    {
      char S[4]={S1,S2,S3,S4};
      if(Serial.available()>0)
      { 
		income[i]=Serial.read();
        income[i]=income[i]-'0';
		digitalWrite(S[i],LOW);
        digitalWrite(IN1,income[i]&0x1);
        digitalWrite(IN2,(income[i]>>1)&0x1);
        digitalWrite(IN3,(income[i]>>2)&0x1);
        digitalWrite(IN4,(income[i]>>3)&0x1);
        digitalWrite(S[i],HIGH);
  	    delay(10);   
   	  }
	}
}


