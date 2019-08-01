/*buzzer GND = arduino GND
 * buzzer 5v = arduino A2
 * loop pin 1 = A1
 * loop pin 2 = A4
 * Arduino LCD Keypad Shield Has Been Used
 * https://wiki.dfrobot.com/Arduino_LCD_KeyPad_Shield__SKU__DFR0009_
 */
#include <LiquidCrystal.h>
#include <DFR_LCD_Keypad.h>
LiquidCrystal lcd(8,9,4,5,6,7);
DFR_LCD_Keypad keypad(A0, &lcd);
int last_key, key;

int touch=15;
int wire=0;
int buzzer=16;
int score=500;
int over=17;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  pinMode(18,OUTPUT);
  digitalWrite(18,0);
  
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  
  pinMode(touch,INPUT);
  pinMode(over,INPUT);
  pinMode(buzzer,OUTPUT);
  lcd.setCursor(0,0);
  lcd.print("YOUR SCORE IS :");
  for(;;){
    if (digitalRead(touch)==0)
    break;
    }
    for(int i=0;i<1;i++){
      buz(1);
      delay(1000);
      buz(0);
      delay(100);
      }
}
void loop() {
 
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    score--;
    }
  if (score<100){
    lcd.setCursor(2,1);
     lcd.print(" ");
    }  
  lcd.setCursor(0,1);
  lcd.print(score);
  
  Serial.println(score);
  wire=digitalRead(touch);
  buz(wire);
  
  if(wire==1){
    score=score-5;
    delay(150);
    Serial.println(wire);
    }

  if (score<0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("GAME OVER");
    for(int i=0;i<50;i++){
      buz(1);
      delay(50);
      buz(0);
      delay(50);
      }
     for(;;){}
    }
   if (digitalRead(over)==1){
    lcd.setCursor(0,0);
    lcd.print("CONGRATZZZ     ");
    lcd.setCursor(0,1);
    lcd.print("SCORE: ");
    lcd.setCursor(8,1);
    lcd.print(score);
    for(int i=0;i<20;i++){
      buz(1);
      delay(50);
      buz(0);
      delay(50);
      }
    for(;;){}
    }
 
}
 void buz(int a){
  digitalWrite(buzzer,a);
  }
