#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "UbidotsESPMQTT.h"
#include <SoftwareSerial.h>

static int BPMvalue, TEMPvalue;
String myString;
String myString2; // complete message from arduino, which consistors of snesors data
char rdata; // received charactors
String myBPM,myTemp;
String temp;
 
#define TOKEN "BBFF-wCCJ78MsNOnDLmKtmicsvHBfyW04At" // Your Ubidots TOKEN
#define WIFINAME "Naruto" //Your SSID
#define WIFIPASS "8459369983" // Your Wifi Pass
 
#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels
#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 
Ubidots client(TOKEN);
 
void callback(char* topic, byte* payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}
 
void setup()
{
  client.setDebug(true); // Pass a true or false bool value to activate debug messages
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  display.display();
  delay(100);
  display.clearDisplay();
  client.wifiConnection(WIFINAME, WIFIPASS);
  client.begin(callback);
}
 
void loop()
{
  if (Serial.available() > 0 )
  {
    rdata = Serial.read();
    myString = myString + rdata;
    if ( rdata == '\n')
    {
      //Serial.println(myString);
      myBPM = getValue(myString, ' ', 1);
      myTemp = getValue(myString, ' ', 2);
      myString = "";
    }
    if (!client.connected())
    {
      client.reconnect();
    }
    BPMvalue = myBPM.toInt();
    if(BPMvalue>=40)
    {
      client.add("BPM", BPMvalue);
      TEMPvalue = myTemp.toInt();
      client.add("TEMP", TEMPvalue);
      client.ubidotsPublish("esp8266");
      client.loop();
    }
 
    Serial.println();
    delay(10);
  }
  if(BPMvalue>=40)
  {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(15, 10);
    display.print("BPM ");
    //display.setCursor(5, 40);
    display.print(BPMvalue);
    display.setCursor(15, 30);
    display.print("Temp ");
    //display.setCursor(5, 40);
    display.print(TEMPvalue);
    display.display();
  }
  delay(100);
}
 
String getValue(String data, char separator, int index)
{
  //Serial.println(data);
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;
 
  for (int i = 0; i <= maxIndex && found <= index; i++)
  {
    if (data.charAt(i) == separator || i == maxIndex)
    {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
