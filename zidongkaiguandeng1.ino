#include <Servo.h> 
#include<IRremote.h>
int proximitySensor = 7;
const int TrigPin = 4; //发送超声波
const int EchoPin = 5; //接收超声波
float cm;
IRsend irsend;
Servo myservo;  // 电机控制初始化
 
int pos = 0;    
 
void setup() 
{ 
  Serial.begin(115200);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(proximitySensor, INPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() 
{ 
  int value = digitalRead(proximitySensor);
  // 产生一个10us的高电平脉冲去触发TrigPin
digitalWrite(TrigPin, LOW);
delayMicroseconds(2);
digitalWrite(TrigPin, HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin, LOW);
// 检测脉冲宽度，并计算出距离
cm = pulseIn(EchoPin, HIGH);   //红外测距获得距离
if(cm<7000&&cm>6100)          //判断，处于正常状态时关灯位置
 { myservo.write(125);
  irsend.sendNEC(0x234906F,32);}
else                         //若为正常区间外，通过舵机控制开灯，同时发出红外信号
 {myservo.write(90);
 irsend.sendNEC(0x234906F,32);
 //delay(10000);
 }
//通过串口监视器输出
Serial.print("Distance:"); Serial.println(cm);
delay(1000);

  }
