<a name="Title" />
# HOL - 03 - Using the Accessory Shield on Galileo with Windows #

Now that you have an Intel Galileo running Windows, you'll probably want to play around with something a little more interesting that just blinking and LED.  To get more out of your gallieo, you'll want to use some additional sensors and components. 

In this lab, we will help you get started using the cool "Accessory Shield" from dfrobot.  This shield is sold as an accessory for an Arduino compatible board from dfrobot called the Bluno (an arduino with bluetooth built in), but it will work just fine on any other Arduino, or compatible board like the Galileo.

![00010-AccessoryShield](images/00010-accessoryshield.png?raw=true "Accessory Shield") 

<a name="pre-requisites" />
## Pre-Requisites ##

This lab assumes that you have completed ***both*** of the previous labs

- "HOL - 01 - Unboxing and Running Your Galileo for the First Time" 
- "HOL - 02 - Running Windows on your Intel Galileo"

It is also assumed that you have a dfrobot "[Accessory Shield for Bluno](http://www.dfrobot.com/index.php?route=product/product&product_id=1045)"

<a name="Tasks" />
## Tasks ##

1. Read [Sensors, Components, Breadboards and Shields](#Task1)
1. [Connecting your Accessory Shield to the Galileo](T#ask2)
1. [Driving the RGB Led Digitally](#Task3)
1. [Driving the RGB Led with PWM](#Task4)
1. [Controlling the RGB LED speed with the Potentiometer](#Task5)
1. [Buzzing when you push a button](#Task6)

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


1. Ok, that's cool, but as it turns out, the LEDs can be more than just on (LOW) or off (HIGH).  The pins 9,10 and 3 to which the LED catchods are connected actually support **"Pulse Width Modulation"** (PWM).  A full explanation of PWM is beyond the scope of this lab, but you can red more [here](http://www.arduino.cc/en/Tutorial/PWM) if you like. Basically, PWM is a method for simulating an analog voltage by switching a digital signal on an off at frequencies that average out to a voltage between 0v and 5v.  To send a PWM signal to the pins, we'll use **analogWrite()** instead of **digitalWrite()**, and a value that ranges between 0 (totaly off, 0v) and 255 (totally on, 5v).  Values between 0 and 255 simulate a voltage between 0v and 5v and will cause that color to be dimmer (0) or brigther (255). 

1. Replace the setRgbLed() method with the following code:

<a name="Task4" />
## Driving the RGB Led with PWM ##
