#include <Arduino.h>
#include <SSD1306.h>

SSD1306 display(0x3c, 4, 5, GEOMETRY_128_32);

int val = 0; // AD 변환값을 저장할 변수
void setup() {
Serial.begin(115200); 
 display.init();
 display.flipScreenVertically();
 display.setFont(ArialMT_Plain_16);
 display.drawString(10, 10, "brightness");
 display.display();
}
void loop() {
  
  display.display();
  display.setColor(BLACK);
  display.fillRect(10,10 ,100,33);
  display.setColor(WHITE);
  val = analogRead(0); // 아날로그 0번 핀 (VR) 값을 입력
  String v = (String)val;
  display.drawString(10,10,v);
  Serial.println(val);
  delay(500); 
}