#include <dht11.h>
#include <Wire.h> 
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 10, 9, 8, 7, 6);
dht11 DHT11;
const byte dataPin = 2;
void setup() {
  lcd.begin(16, 2);       // 初始化 LCD
}
void loop() {
  int chk = DHT11.read(dataPin);
  //if (chk == 0)
    lcd.setCursor(4, 0);
    lcd.print("Temp");
    lcd.setCursor(0, 1);
    lcd.print("Humidity");
    lcd.setCursor(9, 0);   // 显示溫度
    lcd.print((float)DHT11.temperature, 2);
    lcd.print((char) 0xDF);
    lcd.print("C");
    lcd.setCursor(9, 1);   // 显示湿度
    lcd.print((float)DHT11.humidity, 2);
    lcd.print("%");
    delay(1000);  
    }
