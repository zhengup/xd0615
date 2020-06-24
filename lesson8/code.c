const int numReadings = 10; // 静态常量，不可改变；共读取10个数据

int readings[numReadings];      // 存储引脚读取数据
int readIndex = 0;              // 记录当前读取数据的下标
int total = 0;                  // 记录读取数据的总和
int average = 0;                // 记录读取数据的平均值

int inputPin = A0;

void setup() {
   
  Serial.begin(9600); // 串口初始化

  for (int thisReading = 0; thisReading < numReadings; thisReading++) { // 将readings数组元素全部置0
    readings[thisReading] = 0;
  }
}

void loop() {

  total = total - readings[readIndex]; //total减去第一个数据值

  readings[readIndex] = analogRead(inputPin); // 从A0引脚读取模拟电位，存储到readings数组下标对应位置

  total = total + readings[readIndex]; // 将数据值加到total上

  readIndex = readIndex + 1; // 下标加一，指向下一位置

  if (readIndex >= numReadings) { // 最大下标时，将数据下标置零，防止溢出

    readIndex = 0;
  }


  average = total / numReadings; // 计算10个数据的平均值

  Serial.println(average); // 将平均值输出到串行监视器上
  
  delay(1);        // 每次读取之间增加延迟，确保程序稳定
}