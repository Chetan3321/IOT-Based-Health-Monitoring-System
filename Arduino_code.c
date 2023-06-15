#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>
#define USE_ARDUINO_INTERRUPTS true   // Set-up low-level interrupts for most acurate BPM math
#include <PulseSensorPlayground.h> 
#define ONE_WIRE_BUS 2    // Includes the PulseSensorPlayground Library
SoftwareSerial nodemcu(7, 8); // nodemcu module connected here
OneWire oneWire(ONE_WIRE_BUS);	
DallasTemperature sensors(&oneWire);
int temp;
const int PulseWire = 0;       // 'S' Signal pin connected to A0
const int LED13 = 13;          // The on-board Arduino LED
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore
String myString;
String myString2;
String cmessage;
String cmessage2;  // complete message
char buff1[10];
char buff2[10];

PulseSensorPlayground pulseSensor;  // Creates an object
 
void setup()
{
  sensors.begin();
  Serial.begin(9600);
  nodemcu.begin(9600);
 
  // Configure the PulseSensor object, by assigning our variables to it
  pulseSensor.analogInput(PulseWire);
  pulseSensor.blinkOnPulse(LED13);       // Blink on-board LED with heartbeat
  pulseSensor.setThreshold(Threshold);
 
  // Double-check the "pulseSensor" object was created and began seeing a signal
  if (pulseSensor.begin())
  {
    Serial.println("PulseSensor object created!");
  }
}
 
void loop()
{
  temp=sensors.getTempCByIndex(0);
  sensors.requestTemperatures();
  //Serial.print("Temperature: ");
  //Serial.print(temp);//sensors.getTempCByIndex(0));
  //Serial.print((char)176);//shows degrees character
  //Serial.print(" C ");
  /*
  //print the temperature in Fahrenheit
  Serial.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
  Serial.print((char)176);//shows degrees character
  Serial.println("F"); */
  
  delay(500);

  int myBPM = pulseSensor.getBeatsPerMinute();      // Calculates BPM
 
  if (pulseSensor.sawStartOfBeat()) // Constantly test to see if a beat happened
  {
    //Serial.println("\n ♥  A HeartBeat Happened ! "); // If true, print a message
    //Serial.print("BPM: ");
    //Serial.println(myBPM);                        // Print the BPM value
    if(myBPM<50){
      myBPM = 00;
    }
    myString = dtostrf(myBPM, 3, 0, buff1);
    myString2 = dtostrf(temp, 3, 0, buff2);
    cmessage = cmessage + myString;
    //cmessage2 = cmessage2 + myString2 ;
    //nodemcu.println(cmessage);
    //Serial.println(cmessage);
    cmessage = cmessage + myString2;
    nodemcu.println(cmessage);
    Serial.println(cmessage);
    cmessage = "";
    //nodemcu.println(cmessage2);
    //Serial.println(cmessage2);
    //cmessage2 = "";
    Serial.println();
  }
  delay(1000);
}
