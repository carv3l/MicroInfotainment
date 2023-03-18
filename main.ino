#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RTClib.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

RTC_DS3231 rtc;
char time[16];
char date[16];


void setup() {
  Serial.begin(115200);
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));


  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  
  // Display static text
  
}

void loop() {
  DateTime now = rtc.now();
  sprintf(time, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());
  sprintf(date, "%02d/%02d/%02d", now.day(), now.month(), now.year());
  //Serial.print(F("Date/Time: "));
  //Serial.println(t);
  display.setTextSize(2,2);
  display.setCursor(10, 10);
  display.print(time);
  display.display();
  display.setTextSize(1);
  display.setCursor(10, 30);
  display.print(date);
  display.display();

  delay(1000);
  display.clearDisplay();
  
}
