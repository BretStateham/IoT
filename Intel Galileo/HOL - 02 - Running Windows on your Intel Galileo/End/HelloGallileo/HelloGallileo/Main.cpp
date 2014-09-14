// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "arduino.h"

int _tmain(int argc, _TCHAR* argv[])
{
  return RunArduinoSketch();
}

int led = LED_BUILTIN;  // LED_BUILTIN is a C++ #define macro that maps to the onboard LED

void setup()
{
  // TODO: Add your code here

  GpioSetDir(led, OUTPUT);       // Configure the pin for OUTPUT so you can turn on the LED.
}

// the loop routine runs over and over again forever:
void loop()
{
  // TODO: Add your code here

  GpioWrite(led, LOW);    // turn the LED off by making the voltage LOW
  Log(L"LED OFF\n");
  delay(1000);               // wait for a second
  GpioWrite(led, HIGH);   // turn the LED on by making the voltage HIGH
  Log(L"LED ON\n");
  delay(1000);               // wait for a second
}
