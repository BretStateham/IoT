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
  //Use analog write to write a PWM signal to the pin
  //Subtract the desired value from 255 to invert it
  //An input of 0 results in 255-0 or 255 
  //An input of 255 results in 255-255 or 0
  //This is necessary because the RGB LED is a
  //common anode LED and gets brighter as the voltage
  //gets closer to 0. 
  analogWrite(redLedPin, 255 - red);
  analogWrite(greenLedPin, 255 - green);
  analogWrite(blueLedPin, 255 - blue);
}

void setup()
{
  //Set all of the RGB LED pins as OUTPUT
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);

  //initialze all pins to off
  setRgbLed(0, 0, 0);
}

// the loop routine runs over and over again forever:
void loop()
{
  //Pick a random color between 0 and 255 for red green and blue.
  int red = rand() % 255;
  int green = rand() % 255;
  int blue = rand() % 255;

  //Set the RGB led to the random values we just generated
  setRgbLed(red, green, blue);

  //wait for 100 miliseconds (.1 second)
  delay(100);
}
