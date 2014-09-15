// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "arduino.h"

int _tmain(int argc, _TCHAR* argv[])
{
  return RunArduinoSketch();
}

int joystickPin = 0; //The joystick buttons are all connected to analog pin 0 (A0).
//Just use 0 though, A0 seems to bug out the Galileo

int buzzerPin = 8;   //The buzzer is hard wired to digital pin 8

//Read the value from the joystick and return a number
//representing which button was pressed
// 0 = Not Pressed
// 1 = Right Button Pressed
// 2 = Up Button Pressed
// 3 = Left Button Pressed
// 4 = Down Button Pressed
// 5 = Center Button Pressed
int readJoystick() {
  //Read the analog value from the pin
  int value = analogRead(joystickPin);
  int result = 0;

  //Depending on the value read, 
  //determine which button was pressed
  //The buttons are all connected to a different
  //value resistor which causes them to each return
  //a number within a different range.  The ranges
  //used here were determine by experimentation
  //and just monitoring the range of values returned
  //when each button was pressed, then mapping them
  //to the desired return values based on that number
  if (value < 70)
    result = 1;  //right
  else if (70 <= value && value < 235)
    result = 5;  //push
  else if (235 <= value && value < 420)
    result = 2;  //up
  else if (420 <= value && value < 620)
    result = 3;  //left
  else if (620 <= value && value < 800)
    result = 4;  //down
  else
    result = 0;  //not pressed

  return result;
}

void setup()
{
  //Setup the joystick pin as input
  pinMode(joystickPin, INPUT);

  //Setup the buzzer pin as output
  pinMode(buzzerPin, OUTPUT);

  //Make sure the buzzer is silent
  digitalWrite(buzzerPin, LOW);
}

// the loop routine runs over and over again forever:
void loop()
{
  //read the state of the joystick
  int joystick = readJoystick();

  //If anybutton on the Joystick was pressed
  if (joystick != 0)
    //Buzz the buzzer
    digitalWrite(buzzerPin, HIGH);
  //Otherwise
  else
    //Silence the buzzer
    digitalWrite(buzzerPin, LOW);
}
