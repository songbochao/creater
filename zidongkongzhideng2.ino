#include <IRremote.h>
#include <Servo.h> 
int RECV_PIN = 10;   //红外线接收器OUTPUT端接在pin 10
IRrecv irrecv(RECV_PIN);//定义IRrecv对象来接收红外线信号
Servo myservo; 
decode_results results;   //解码结果放在decode_results构造的对象results里
int pos1 = 60;   //两种状态用于开关灯
int pos2 =110;
void setup(){
  Serial.begin(9600);
  myservo.attach(9);
  irrecv.enableIRIn(); // 启动红外解码
}
void loop() {
  myservo.write(pos1);
  if (irrecv.decode(&results)) {      //解码成功，收到一组红外线信号，控制舵机开灯
    
    myservo.write(pos2);
    delay(3000);                      //延迟一段时间后抬起
    irrecv.resume(); //  接收下一个值
  }
}
