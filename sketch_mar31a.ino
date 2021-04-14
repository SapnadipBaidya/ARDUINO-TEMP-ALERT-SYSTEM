#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
const int sensor=A0;
float tempc;
float vout;
const int led = 8;
const int ledB = 9;
const int sound = 10;
void setup()
{
  pinMode(sound,OUTPUT);
 pinMode(led,OUTPUT);
 pinMode(ledB,OUTPUT);  
pinMode(sensor,INPUT);
Serial.begin(9600);
lcd.begin(16,2);
delay(500);  
}

void loop()
{
 vout=analogRead(sensor);
 vout=(vout*500)/1023;
 tempc=vout;

 if(vout>60)
 {
  digitalWrite(led,HIGH);
  delay(300);
  digitalWrite(led,LOW);
    delay(300);
  digitalWrite(sound,HIGH);
  delay(300);
  digitalWrite(sound,LOW);
    delay(300);
    digitalWrite(ledB,HIGH);
  delay(200);
  digitalWrite(ledB,LOW);
    delay(200);
  lcd.clear();
  lcd.setCursor(0,0);
 lcd.print(tempc);
 lcd.print(" too HOT");
  lcd.setCursor(0,1);
 
 lcd.print("  cool PC ");
  
  }

else
{
  digitalWrite(led,LOW);
  digitalWrite(ledB,HIGH);
   lcd.setCursor(0,0);
 lcd.print(tempc);
 lcd.print(" DEGREE C");

 lcd.setCursor(0,1);
 lcd.print("LPU IS BEST");
}

  
 delay(100);

}
