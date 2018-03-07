#include "U8glib.h"
#include "DS3231.h"

DS3231  rtc(SDA, SCL);
Time t;



U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);                     // I2C / TWI 1.3

void draw(void) {
  u8g.setFont(u8g_font_fub35n); 
  u8g.drawStr(0, 38, rtc.getTimeStr(FORMAT_SHORT)); 
  u8g.setFont(u8g_font_helvB14);
  
  u8g.drawStr(80, 62, "C"); 
  if (rtc.getTemp() > 0) {
    u8g.drawStr(30, 62, "+"); 
    u8g.setPrintPos(40, 62); 
    u8g.print(rtc.getTemp(), 1); 
  }
}

void setup(void) {
  Serial.begin(9600);
  rtc.begin();
}

void loop(void) {
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");
  Serial.println(rtc.getTimeStr(FORMAT_SHORT));
  Serial.print("Current Unixtime.........................: ");
  Serial.println(rtc.getUnixTime(rtc.getTime()));
  Serial.print("Temperature: ");
  Serial.print(rtc.getTemp());
  Serial.println(" C");

  u8g.firstPage(); 
  do { 
    draw();
  } while( u8g.nextPage() ); 
  
  delay(10000); 
}

