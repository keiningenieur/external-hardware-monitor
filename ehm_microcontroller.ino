#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

String srl;
String cputemp;
String cpuload;
String ramload;
String ramgb;
String gputemp;
String gpuload;
unsigned long starttime;
unsigned long endtime;

String split(String s, char parser, int index) {
  String rs="";
  int parserIndex = index;
  int parserCnt=0;
  int rFromIndex=0, rToIndex=-1;
  while (index >= parserCnt) {
    rFromIndex = rToIndex+1;
    rToIndex = s.indexOf(parser,rFromIndex);
    if (index == parserCnt) {
      if (rToIndex == 0 || rToIndex == -1) return "0.0";
      return s.substring(rFromIndex,rToIndex);
    } else parserCnt++;
  }
  return rs;
}

void setup() {
  Serial.begin(115200);
  
  Serial.println("OLED intialized");
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32

  display.display();
  delay(1000);

  // Clear the buffer.
  display.clearDisplay();
  display.display();

  // text display tests
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.clearDisplay();
}

void loop() { 
  while(Serial.available()) 
   {
      starttime = millis();
      endtime = starttime;
      while((endtime - starttime) <=5000) // do this loop for up to 1000mS
      {
      srl = Serial.readString();
      cputemp = split(srl, ':',1);
      cpuload = split(srl, ':',3);
      ramload = split(srl, ':',5);
      ramgb = split(srl, ':',7);
      gputemp = split(srl, ':',9);
      gpuload = split(srl, ':',11);
      display.setCursor(0, 0);
      display.print("CPU:");
      display.print(cputemp);
      display.print('C');
      display.setCursor(0, 16);
      display.print("    ");
      display.print(cpuload);
      display.println('%'); 
      display.fillRect(108, 0, 4, 4,SSD1306_WHITE);
      display.display();
      delay(2000);
      display.clearDisplay();      
      endtime = millis();
      }
      starttime = millis();
      endtime = starttime;
      while((endtime - starttime) <=5000) // do this loop for up to 1000mS
      {
      srl = Serial.readString();
      cputemp = split(srl, ':',1);
      cpuload = split(srl, ':',3);
      ramload = split(srl, ':',5);
      ramgb = split(srl, ':',7);
      gputemp = split(srl, ':',9);
      gpuload = split(srl, ':',11);
      display.setCursor(0, 0);
      display.print("GPU:");
      display.print(gputemp);
      display.print('C');
      display.setCursor(0, 16);
      display.print("    ");
      display.print(gpuload);
      display.println("%");
      display.fillRect(108, 0, 4, 4,SSD1306_WHITE);
      display.display();
      display.clearDisplay();
      endtime = millis();
      }
      starttime = millis();
      endtime = starttime;
      while((endtime - starttime) <=5000) // do this loop for up to 1000mS
      {
      srl = Serial.readString();
      cputemp = split(srl, ':',1);
      cpuload = split(srl, ':',3);
      ramload = split(srl, ':',5);
      ramgb = split(srl, ':',7);
      gputemp = split(srl, ':',9);
      gpuload = split(srl, ':',11);
      display.setCursor(0, 0);
      display.print("RAM:");
      display.print(ramload);
      display.print('%');
      display.setCursor(0, 16);
      display.print("    ");
      display.print(ramgb);
      display.println("GB");
      display.display();
      display.clearDisplay();
      endtime = millis();
      }
      display.clearDisplay();
   }
  delay(5000); 
}

   
