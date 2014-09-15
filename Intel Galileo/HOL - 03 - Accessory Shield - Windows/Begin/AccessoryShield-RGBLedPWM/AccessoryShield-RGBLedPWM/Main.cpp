// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "arduino.h"

int _tmain(int argc, _TCHAR* argv[])
{
  return RunArduinoSketch();
}

int greenLedPin = 10; //The green cathode of the RGB LED is wired to digital pin 10
int redLedPin = 9;    //The red cathode of the RGB LED is wired to digital pin 9
int blueLedPin = 3;   //The blue cathode of the RGB LED is wired to digital pin 3

//A single method to set all three RGB LED pins at once...
void setRgbLed(int red, int green, int blue) {
  digitalWrite(redLedPin, red);
  digitalWrite(greenLedPin, green);
  digitalWrite(blueLedPin, blue);
}

void setup()
{
  //Set all of the RGB LED pins as OUTPUT
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);

  //initialze all pins to off
  //REMEMBER LOW=ON, HIGH=OFF for our common anode RGB LED
  setRgbLed(HIGH, HIGH, HIGH);
}

// the loop routine runs over and over again forever:
void loop()
{
  //Set the LED to Red, and wait for 1 second
  //REMEMBER LOW=ON, HIGH=OFF for our common anode RGB LED
  setRgbLed(LOW, HIGH, HIGH);
  delay(1000);

  //Set the LED to Green, and wait for 1 second
  //REMEMBER LOW=ON, HIGH=OFF for our common anode RGB LED
  setRgbLed(HIGH, LOW, HIGH);
  delay(1000);

  //Set the LED to Blue, and wait for 1 second
  //REMEMBER LOW=ON, HIGH=OFF for our common anode RGB LED
  setRgbLed(HIGH, HIGH, LOW);
  delay(1000);

  //Set the LED to Yellow (Red & Green), and wait for 1 second
  //REMEMBER LOW=ON, HIGH=OFF for our common anode RGB LED
  setRgbLed(LOW, LOW, HIGH);
  delay(1000);

  //Set the LED to Purple (Red & Blue), and wait for 1 second
  //REMEMBER LOW=ON, HIGH=OFF for our common anode RGB LED
  setRgbLed(LOW, HIGH, LOW);
  delay(1000);
}
