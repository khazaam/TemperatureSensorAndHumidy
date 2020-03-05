#include <dht.h>

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
dht DHT;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

#define DHT11_PIN 7

 void setup(){

  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  //lcd.print("TESTITESTITESTI");

  delay(1000);

  
    Serial.begin(9600);
  }

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0, 0);
    // print the number of seconds since reset:
  lcd.print(millis()/1000);
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(100);
  
  
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  
  delay(1000);
}
