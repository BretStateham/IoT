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

int knobPin = 1;     //The potentiometer (knob) is wired to analog pin 1 (A1).
//Just use 1 though, not A1.  A1 seems to bug out the Galileo

//Read the value from the Accessory Shield's Potentiometer (Knob)
int readKnob(void){
  //The analogRead() method will return a value between 0 and 1023
  //depending on the current value of the potentiometer.
  //The pot reads high when it is all the way left, and 
  //low when it is all the way right. That is counter intuitive
  //So we'll invert it by subtracting it's value from 1023. 
  return (1023 - analogRead(knobPin));
}

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

  //Setup the potentiometer as an input
  pinMode(knobPin, INPUT);

  //initialze all pins to off
  setRgbLed(0, 0, 0);
}

// the loop routine runs over and over again forever:
void loop()
{
  //Get the value of the potentiomemter
  int knob = readKnob();

  //map the knob value of 0-1023 to a PWM value of 1-255
  //Using 1 as a minimum PWM value to prevent divide by zero errors
  //when generating random values with the modulus operator (%)
  knob = map(knob, 0, 1023, 1, 255);

  //Pick a random color between 0 and the knob PWM value for red green and blue.
  //Knob values of 255 will result in brighter colors
  //Knob values of 0 will result in no color
  //Knob values between 1 and 255 will result in varying brightness
  int red = rand() % knob;
  int green = rand() % knob;
  int blue = rand() % knob;

  //Set the RGB led to the random values we just generated
  setRgbLed(red, green, blue);

  //wait for 100 miliseconds (.1 second)
  delay(100);
}
