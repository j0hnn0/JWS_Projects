// Date and time functions using a DS1307 RTC connected via I2C and Wire lib

#include <Wire.h>     // I2C Library
#include "RTClib.h"   // DS1307 Real time clock library from Adafruit Github

int led=13;
int led2=2;
RTC_DS1307 rtc;
unsigned char i;
void setup () {

  pinMode(led, OUTPUT);
  pinMode(led2,OUTPUT);
  Serial.begin(57600);

#ifdef AVR
  Wire.begin();
#else
  Wire1.begin(); // Shield I2C pins connect to alt I2C bus on Arduino Due
#endif
  rtc.begin();
  
 //rtc.adjust(DateTime(__DATE__, __TIME__));  // Uncomment once and upload to reset time to host system time - remember to comment again and upload, battery backup wil retain time
  
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }
}

void loop () {
  
  for(i=0;i<5;i++) {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
    delay(975);   
    DateTime now = rtc.now();
    
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    digitalWrite(led, HIGH);
    digitalWrite(led2,LOW);
    Serial.print("\t\t");  
    
    delay(25);
  }
  Serial.println();    
}
