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
#define MAX 100
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

byte income[MAX]={0};
char S[4]={S1,S2,S3,S4};
int n=0,y=0;

void loop()
{
    digitalWrite(LT,HIGH);
    digitalWrite(BT,HIGH);
    
    digitalWrite(S1,HIGH);
    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    digitalWrite(S4,HIGH);
    
    while(Serial.available()>0)
    { 
      income[n]=Serial.read();
      income[n]=income[n]-'0';
      n++;
    }
    while(1)
    {
      for(int i=0;i<n;i++)
      {
		for(int j=i;j<i+4;j++)        
        {
		  int x=j;
          if(x>=n);
          {
            x=x-n;
          }
          digitalWrite(S[y],LOW);
          digitalWrite(IN1,income[x]&0x1);
          digitalWrite(IN2,(income[x]>>1)&0x1);
          digitalWrite(IN3,(income[x]>>2)&0x1);
          digitalWrite(IN4,(income[x]>>3)&0x1);
          digitalWrite(S[y],HIGH);
  	      delay(10);
          y++;
        }
        y=0;
        delay(500);
   	  }
    }   
}


