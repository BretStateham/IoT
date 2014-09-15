<a name="Title" />
# HOL - 03 - Using the Accessory Shield on Galileo with Windows #

Now that you have an Intel Galileo running Windows, you'll probably want to play around with something a little more interesting that just blinking and LED.  To get more out of your gallieo, you'll want to use some additional sensors and components. 

In this lab, we will help you get started using the cool "[Accessory Shield](http://www.dfrobot.com/index.php?route=product/product&product_id=1045)" from dfrobot.  This shield is sold as an accessory for an Arduino compatible board from dfrobot called the Bluno (an arduino with bluetooth built in), but it will work just fine on any other Arduino, or compatible board like the Galileo.

![00010-AccessoryShield](images/00010-accessoryshield.png?raw=true "Accessory Shield") 

There are issues with the current version of the Galileo-SDK and the DHT11 Temperature and Humidity Sensor on the Accessory Shield, as well as with the OLED Display (bummer).  It is expected that these issues will be resolved in the future, but for now those features aren't functional with the current release of the Galileo-SDK for Windows.  The other components work though:

- Relay
- Potentiometer
- RGB LED
- Buzzer

If you have a regular arduino and want to play around with this shield on that, you can get the arduino source code from here: https://github.com/DFRobot/BlunoAccessoryShieldDemo

You can also get a schematic of the components to help determine the pins that are used for each from here: http://www.dfrobot.com.cn/download/DFR0267/BLEduino_sheild.pdf

<a name="pre-requisites" />
## Pre-Requisites ##

This lab assumes that you have completed ***both*** of the previous labs

- "HOL - 01 - Unboxing and Running Your Galileo for the First Time" 
- "HOL - 02 - Running Windows on your Intel Galileo"

It is also assumed that you have a dfrobot "[Accessory Shield v1.0](http://www.dfrobot.com/index.php?route=product/product&product_id=1045)"

<a name="Tasks" />
## Tasks ##

1. Read [Sensors, Components, Breadboards and Shields](#Task1)
1. [Connecting your Accessory Shield to the Galileo](T#ask2)

	***Running the following tasks in order makes the most sense, but you can pick and choose which ones to run, or run them in any order you like.  There is a Begin and an End solution for each of them.***  

1. [Driving the RGB Led Digitally](#Task3)
1. [Driving the RGB Led with PWM](#Task4)
1. [Controlling the RGB LED Speed with the Potentiometer](#Task5)
1. [Controlling the RGB LED Brightness with the Potentiometer](#Task6)
1. [Buzzing When You Push the Button](#Task7)

<a name="Task1" />
## Sensors, Components, Breadboards and Shields ##

Sensors read a physical quantity (light, sound, movement, tilt, etc.) and convert it into an electrical signal (voltage) or value (resistance). You can read those sensor values in the code that runs on the Galileo, and act on it. 

There are also a number of components like LEDs, Motors, Servo Moters, Displays, Speakers, etc. that you can connect to allow your Galileo to control the real world.  For example, you could convert the 

Sensors and other components come in various forms. There are discrete components, like single LEDs:

![01010-LED](images/01010-led.png?raw=true "LED")

Or you may find a set of components sold together on a single board, like the RGB LED with it's current limiting resistors already hooked up:

![01020-RGBLedBoard](images/01020-rgbledboard.png?raw=true "RGB Led Board")

Usually when you work with discrete components, or small boards, you build circuits using Breadboards.  Here's an example of an RGB and it's current limiting resistors on a breadboard with connections to the Galileo made via short jumper wires:

![01030-BreadboardCircuit](images/01030-breadboardcircuit.png?raw=true "Breadboard Circuit")

Or when you are working with the Arduino and compatible boards like the Galileo, you can get complete circuits full of functionality on special expansion boards called "Shields".  Sheilds are boards that have pins on them that match up perfectly with the headers on the Arduino (or Galileo in this case), allowing you to easily connect them together.  

Here is an example of a shield partially inserted into the headers on an Intel Galileo Gen 1 board (of course, you would insert the pins all the way, they are left partially inserted here so you can see the relationship between the shield and the Galileo:


![01040-ShieldOnGalileo](images/01040-shieldongalileo.png?raw=true "Shield on Galileo")

The dfrobot "Accessory Shield v1.0" has a number of sensors and components on it that you can use for your initial experiments with the Galileo, or any other Arduino.

![01050-accessoryshieldcomponents](images/01050-accessoryshieldcomponents.png?raw=true "Accessory Shield Components")

<a name="Task2" />
## Connecting your Accessory Shield to the Galileo ##

Ok, well this is pretty straight forward, and quick, but it's important that it be documented so:

1. Disconnect the power, and other connections from your Galileo. You don't want to cause a short by accident when you are inserting the shield.

1. Remove the dfrobot Accessory Shield from it's packaging (yes, you CAN remove the **"REMOVE SEAL AFTER WASHING"** sticker from the buzzer if you like.  That is there to keep the the buzzer from getting ruined while the flux is being washed off the board during manufacturing)

1. Carefully line the pins on the bottom of the Accessory Shield to the Arduino Headers on the Galileo Board. 

	![02010-LinePinsUpWithHeaders](images/02010-linepinsupwithheaders.png?raw=true "Line Pins Up With Headers")

1. Slowly push the pins into the corresponding holes in the headers.  Make sure that each pin is lined up properly, and don't force them.  A slight rocking motion from front to back can help the pins go in as well. Continue until the pins are fully inserted. 

	![02020-ShieldInstalled](images/02020-shieldinstalled.png?raw=true "Shield Installed")

1. You can now connect the power and other cables back up to your Galielo

<a name="Task3" />
## Driving the RGB Led Digitally ##

In this task, you'll play around with the RGB LED on the Accessory Shield:

![03010-RGBLed](images/03010-rgbled.png?raw=true "RGB Led")

The RGB LED on the dfRobot Accessory Shield is a ***"Common Anode"*** LED.  That means that there is a single pin on the LED that connects to positive voltage. The other pins are the cathodes for the internal Red, Green, and Blue LEDs.  

Because the LED already has 5 volts coming in, we actually turn each color on by connecting it to ground, or from a code perspective that means using **digitalWrite()** to drive the pins **LOW**.  

**That actually means our logic is inverted (HIGH=OFF, LOW=ON)**:

- **digitalWrite(colorPin,HIGH)** turns that color **OFF**
- **digitalWrite(colorPin, LOW)** turns that color **ON**

The cathode pins are hardwired on the shield to their corresponding pins on the Galileo:

- **Green - Digital Pin 10**
- **Red - Digital Pin 9**
- **Blue - Digital Pin 3**

Keep that in mind as we work through the code.  

1. Start a new Visual C++ **"Galileo Wiring App"** in Visual Studio 2013 (use the steps outlined in "HOL - 02 - Running Windows on your Intel Galileo" if you need a refresher).

1. Replace the contents of **Main.cpp** with the following code:

	````C++
	// Main.cpp : Defines the entry point for the console application.
	//

	#include "stdafx.h"
	#include "arduino.h"

	int _tmain(int argc, _TCHAR* argv[])
	{
		 return RunArduinoSketch();
	}

	void setup()
	{
		 // TODO: Add your code here
	}

	// the loop routine runs over and over again forever:
	void loop()
	{
		 // TODO: Add your code here
	}
````

1. just above the **void setup()** method definition, add the following variable declarations.   
	<!-- mark:1-3 -->
	````C++
	int greenLedPin = 10; //The green cathode of the RGB LED is wired to digital pin 10
	int redLedPin = 9;    //The red cathode of the RGB LED is wired to digital pin 9
	int blueLedPin = 3;   //The blue cathode of the RGB LED is wired to digital pin 3

	void setup()
	{
		 // TODO: Add your code here
	}
	````

1. Next, just below the pin variables you just added, but still above **void setup()**, add a method to make it easy to set all the pins at once:

	<!-- mark:5-10 -->
	````C++
	int redLedPin = 9;    //The red cathode of the RGB LED is wired to digital pin 9
	int greenLedPin = 10; //The green cathode of the RGB LED is wired to digital pin 10
	int blueLedPin = 3;   //The blue cathode of the RGB LED is wired to digital pin 3

	//A single method to set all three RGB LED pins at once...
	void setRgbLed(int red, int green, int blue) {
	  digitalWrite(redLedPin, red);
	  digitalWrite(greenLedPin, green);
	  digitalWrite(blueLedPin, blue);
	}

	void setup()
	{
		 // TODO: Add your code here
	}
	````


1. Next, modify the void setup() method, to initialize the RGB LED pins for OUTPUT, and to make sure the leds starts out with all colors off. 

	<!-- mark:1-12 -->
	````C++
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
	````


1. And finally modify the **loop()** method to show Red, the Green, then Blue with a one second delay between each color:

	<!-- mark:1-17 -->
	````C++
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
	}
	````


1. Just in case, here is the complete code **Main.cpp** so far:


	````C++
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
	}
	````

1. Deploy the code to the Galileo, and watch the RBG LED on the Accessory Shield. You should see it loop through the red, green, and blue colors:

	![03020-RedGreenBlue](images/03020-redgreenblue.png?raw=true "Red, Gree, Blue")

1. Of course, you can mix colors as well. add the following code in bold to the bottom of the **loop()** method to also show yellow and purple:

	<!-- mark:19-27 -->
	````C++
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
	````
1. Once again, here is the complete code for the **Main.cpp** file just in case you need it:

	````C++
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
	````

1. There is a completed version of this project in the **.End\AccessoryShield-RGBLedDigital** folder for this lab. 

<a name="Task4" />
## Driving the RGB Led with PWM ##

Ok, that's cool, but as it turns out, the LEDs can be more than just on (LOW) or off (HIGH).  The pins 9,10 and 3 to which the LED catchods are connected actually support **"Pulse Width Modulation"** (PWM).  A full explanation of PWM is beyond the scope of this lab, but you can red more [here](http://www.arduino.cc/en/Tutorial/PWM) if you like. 

Basically, PWM is a method for simulating an analog voltage by switching a digital signal on an off at frequencies that average out to a voltage between 0v and 5v.  

To send a PWM signal to the pins, we'll use **analogWrite()** instead of **digitalWrite()**, and a value that ranges between 0 (totaly off, 0v) and 255 (totally on, 5v).  Values between 0 and 255 simulate a voltage between 0v and 5v and will cause that color to be dimmer (0) or brigther (255). 

1. Open the starter project for this task from the **.\Begin\AccessoryShield-RGBLedPWM** folder for this lab.  This solution is the same as the "Driving the RGB Led with PWM" task's end solution.

1. Replace the code for the **setRgbLed()** method with the following code. This code uses **analogWrite()** instead of **digitalWrite()** and a **continuous value between 0 and 255** rather than the discrete **LOW** and **HIGH** values.  

	````C#
	//A single method to set all three RGB LED pins at once...
	void setRgbLed(int red, int green, int blue) {
	  //Use analog write to write a PWM signal to the pin
	  //Subtract the desired value from 255 to invert it
	  //An input of 0 results in 255-0 or 255 
	  //An input of 255 results in 255-255 or 0
	  //This is necessary because the RGB LED is a
	  //common anode LED and gets brighter as the voltage
	  //gets closer to 0. 
	  analogWrite(redLedPin, 255-red);
	  analogWrite(greenLedPin, 255-green);
	  analogWrite(blueLedPin, 255-blue);
	}
	````
1. Next, replace the **setup()** method code with the following.  The only difference here is that the **setRgbLed()** call uses 0's instead of HIGH to initialze each color to off.

	````C#
	void setup()
	{
	  //Set all of the RGB LED pins as OUTPUT
	  pinMode(redLedPin, OUTPUT);
	  pinMode(greenLedPin, OUTPUT);
	  pinMode(blueLedPin, OUTPUT);

	  //initialze all pins to off
	  setRgbLed(0,0,0);
	}
	````

1. Lastly, modify the code in the **loop()** method to randomly pick a value somewhere between 0 and 255 for each pin:

	````C#
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
	````
1. Here is the complete code for **Main.cpp**

````C#
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
  analogWrite(redLedPin, 255-red);
  analogWrite(greenLedPin, 255-green);
  analogWrite(blueLedPin, 255-blue);
}

void setup()
{
  //Set all of the RGB LED pins as OUTPUT
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);

  //initialze all pins to off
  setRgbLed(0,0,0);
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
````

1. Run the program and verify that the LED cycles between random colors, showing each for appx .1 seconds.  

<a name="Task5" />
## Controlling the RGB LED Speed with the Potentiometer ##

This task will use the potentiometer on the Accessory Shield to control how quickly (the speed) the RGB LED changes colors. If you turn the potentiometer's knob all the way left, the colors will change rapidly, if you turn it all the way right they will change very slowly.  Of course, positions in between will vary the speed. 

1. Open the starter project for this task from the **.\Begin\AccessoryShield-RGBLedSpeed** folder for this lab.  This solution is the same as the "Driving the RGB Led with PWM" task's end solution.

1. Just below the RGB led pin declarations, and the **setRgbLed()** definition, add a variable to indicate the analog pin the potentiometer is connected to. 

	<!-- mark:5-6 -->
	````C#
	int greenLedPin = 10; //The green cathode of the RGB LED is wired to digital pin 10
	int redLedPin = 9;    //The red cathode of the RGB LED is wired to digital pin 9
	int blueLedPin = 3;   //The blue cathode of the RGB LED is wired to digital pin 3

	int knobPin = 1;     //The potentiometer (knob) is wired to analog pin 1 (A1).
                         //Just use 1 though, not A1.  A1 seems to bug out the Galileo

	//A single method to set all three RGB LED pins at once...
	void setRgbLed(int red, int green, int blue) {
	  //...
	}
	````
1. Then, just below that variable, add a method to read the value from the potentiometer.  Use **anlaogRead()** to retrieve a value between 0 and 1023 from the pin, then invert it so that the low values are when the potentiometer is turned to the left, and hight values when turned to the right:
	<!-- mark:4-13 -->
	````C#
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
	  //...
	}

1. Next, modify the code in the **setup()** method to initialize the potentiometer pin as an input:
	<!-- mark:8-9 -->
	````C#
	void setup()
	{
	  //Set all of the RGB LED pins as OUTPUT
	  pinMode(redLedPin, OUTPUT);
	  pinMode(greenLedPin, OUTPUT);
	  pinMode(blueLedPin, OUTPUT);

	  //Setup the potentiometer as an input
	  pinMode(knobPin, INPUT);

	  //initialze all RBG LED pins to off
	  setRgbLed(0, 0, 0);
	}
	````

1. And finally in the **loop()** method, get the value of the potentiometer from the **readKnob()** method, and use it's value as the number of milliseconds in the **delay()** function.  Lower knob values will result in shorter delays, higher knob values will result in longer delays.

	````C#
	// the loop routine runs over and over again forever:
	void loop()
	{
	  //Pick a random color between 0 and 255 for red green and blue.
	  int red = rand() % 255;
	  int green = rand() % 255;
	  int blue = rand() % 255;

	  //Set the RGB led to the random values we just generated
	  setRgbLed(red, green, blue);

	  //Read the value of the potentiometer
	  int knob = readKnob();

	  //wait for 100 miliseconds (.1 second)
	  delay(knob);
	}
	````
1. Here is the complete code for **Main.cpp** if you need it:

	````C#
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

	  //initialze all RBG LED pins to off
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

	  //Read the value of the potentiometer
	  int knob = readKnob();

	  //wait for 100 miliseconds (.1 second)
	  delay(knob);
	}
	````
1. Run the program, and once deployed try turning the knob of the potentiometer and verify that as you turn it further to the left, the RGB led changes colors faster, and if you turn it to the right, the colors change slower (up to 1023 milliseconds, or just over 1 second per color).

<a name="Task6" />
## Controlling the RGB LED Brightness with the Potentiometer ##

This task will use the potentiometer on the Accessory Shield to control how bright the RGB LED colors are. If you turn the potentiometer's knob all the way left, the colors will disappear (ultimately dim), if you turn it all the way right they will be very bright.  Of course, positions in between will vary the brightness. 

1. Open the starter project for this task from the **.\Begin\AccessoryShield-RGBLedBright** folder for this lab.  This solution is the same as the "Driving the RGB Led with PWM" task's end solution.

1. Just below the RGB led pin declarations, and the **setRgbLed()** definition, add a variable to indicate the analog pin the potentiometer is connected to. 

	<!-- mark:5-6 -->
	````C#
	int greenLedPin = 10; //The green cathode of the RGB LED is wired to digital pin 10
	int redLedPin = 9;    //The red cathode of the RGB LED is wired to digital pin 9
	int blueLedPin = 3;   //The blue cathode of the RGB LED is wired to digital pin 3

	int knobPin = 1;     //The potentiometer (knob) is wired to analog pin 1 (A1).
                         //Just use 1 though, not A1.  A1 seems to bug out the Galileo

	//A single method to set all three RGB LED pins at once...
	void setRgbLed(int red, int green, int blue) {
	  //...
	}
	````
1. Then, just below that variable, add a method to read the value from the potentiometer.  Use **anlaogRead()** to retrieve a value between 0 and 1023 from the pin, then invert it so that the low values are when the potentiometer is turned to the left, and hight values when turned to the right:
	<!-- mark:4-13 -->
	````C#
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
	  //...
	}

1. Next, modify the code in the **setup()** method to initialize the potentiometer pin as an input:
	<!-- mark:8-9 -->
	````C#
	void setup()
	{
	  //Set all of the RGB LED pins as OUTPUT
	  pinMode(redLedPin, OUTPUT);
	  pinMode(greenLedPin, OUTPUT);
	  pinMode(blueLedPin, OUTPUT);

	  //Setup the potentiometer as an input
	  pinMode(knobPin, INPUT);

	  //initialze all RBG LED pins to off
	  setRgbLed(0, 0, 0);
	}
	````

1. And finally in the **loop()** method, get the value of the potentiometer from the **readKnob()** method, then use the Arduino **map()** method to map the knob value between 0 and 1023 to a valid PWM value between 1 and 255.  Finally use that PWM value as the divisor in the "rand() & " statements to control how bright the colors can be:

	````C#
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
	````
1.  Here is the complete code for **Main.cpp** in case you need it:

	````C#
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
	````
1. Run the program, and once deployed try turning the knob of the potentiometer and verify that as you turn it further to the left, the RGB colors get dimmer, and if you turn it to the right, the colors get brighter.

<a name="Task7" />
## Buzzing When You Push the Button ##

In this task, you'll use two of the components on the accessory shield: The Joystick Button, and the Buzzer.  

The Joystick button is actually 5 different different buttons:

- Up
- Down
- Left
- Right
- Center

They are all connected to the same analog pin (A0).  Each button is connected to a different resistor value, which results in different analogRead() values depending on which button was pressed.  We can use that to figure out which button was pressed.  In our case, we only really care if ANY of them was pressed.  

Then, the buzzer is connected to digital pin 8.  We can make it generate a tone if we simply send a voltage to the pin with **digitalWrite()**. HIGH = SOUND, LOW = SILENCE.

1. Start a new Visual C++ **"Galileo Wiring App"** in Visual Studio 2013 (use the steps outlined in "HOL - 02 - Running Windows on your Intel Galileo" if you need a refresher).

1. Replace the contents of **Main.cpp** with the following code:

	````C++
	// Main.cpp : Defines the entry point for the console application.
	//

	#include "stdafx.h"
	#include "arduino.h"

	int _tmain(int argc, _TCHAR* argv[])
	{
		 return RunArduinoSketch();
	}

	void setup()
	{
		 // TODO: Add your code here
	}

	// the loop routine runs over and over again forever:
	void loop()
	{
		 // TODO: Add your code here
	}
````

1. just above the **void setup()** method definition, add the following variable declaration to map the pin the Joystick Buttons are connected to to a variable, as well as mapping the pin the buzzer is connected to a variable:
	<!-- mark:6-9 -->
	````C#
	int _tmain(int argc, _TCHAR* argv[])
	{
	  return RunArduinoSketch();
	}

	int joystickPin = 0; //The joystick buttons are all connected to analog pin 0 (A0).
	                     //Just use 0 though, A0 seems to bug out the Galileo

	int buzzerPin = 8;   //The buzzer is hard wired to digital pin 8

	void setup()
	{
	  // TODO: Add your code here
	}
	````

1. Just below those variable declarations add a new method named **readJoystick()** to read the value from the analog joystickPin, and map the input value to the corresponding button that was pushed.  Finally, return a simple integer that represents which button was pressed:

	````C#
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
	````


1. Next modify the **setup()** method to set the joystick pin as INPUT and the buzzer pin as OUTPUT as well as to silence the buzzer by default:

	````C#
	void setup()
	{
	  //Setup the joystick pin as input
	  pinMode(joystickPin, INPUT);

	  //Setup the buzzer pin as output
	  pinMode(buzzerPin, OUTPUT);

	  //Make sure the buzzer is silent
	  digitalWrite(buzzerPin, LOW);
	}
	````

1. Finally, modify the **loop()** method.  Add code to read the joystick value, and if ANY of the joystick buttons was pressed, buzz the buzzer.  Otherwise, make sure the buzzer is silent:

	````C#
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
	````

1. Here is the complete code for **Main.cpp** if you need it:

	````C#
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
````

1. Run the program, and verify that when you push any of the joystick buttons, the buzzer buzzes!  
  