<a name="Title" />
# HOL - 01 - Unboxing and Running Your Galileo for the First Time #

Welcome to the Intel Galileo!  In this HOL, we'll walkthrough the steps for taking your Intel Galileo out of the box, installing the necessary tools on your computer, and running your first Sketch.

> **Note:** ***Currently, this document refers to the Galileo Gen 1 Boards.  The steps documented here may well work identically with a Gen 2 board, but they have not yet been tested with a Gen 2 board.***

> **Note:** There is a video that walks you through these same steps here: https://www.youtube.com/watch?v=zUZmWe8nrc4

## Tasks: ##
1. [Unboxing your Intel Galileo](#Task1)
1. [Downloading and Extracting the Arduino IDE for Galileo](#Task2)
1. [Connecting your Galileo and Installing the Driver](#Task3)
1. [Updating the Galileo's Firmware](#Task4)
1. [Running the "Blink" sketch on your Galileo](#Task5)
1. [Extra Credit - Using an External LED with Blink](#Task6)

---

<a name="Task1" />
## Task 1 Unboxing your Intel Galileo ##

Unboxing your Galileo should be pretty straight forward.  About the only gotcha is that there is **NO USB CABLE** supplied with your Galileo.  You will need to locate your own USB-A Male to USB Micro Male cable to connect your Galileo with your host pc.  

1. Open up your box!  
1. Pull the Galileo out of it's Static Sheild Bag
1. Remove the top/bottom divider from the box, and pull out the power adapter, power cable, and the appropriate electrical outlet connector for your electrical service. 
1. Connect the pieces of the power supply (Outlet connector, power supply, cable) together. 

	![01010-UnboxedGalileo](images/01010-unboxedgalileo.png?raw=true "Unboxed Galileo")

1. As mentioned above, you will need to locate a "USB-A Male to USB Micro Male" cable that you will use to connect the Galileo to your PC. If your phone has a micro usb connection, you can use the same cable you use to connect your phone to your pc.   

	![01020-USBCable](images/01020-usbcable.png?raw=true "USB A Male to USB Micro Male Cable")

1. Ok, before you plug it all together, let's download the software you'll need. 

<a name="Task2" />
## Downloading and Extracting the Arduino IDE for Galileo ##

Initially, when you write code for your Galileo, you will use a customized version of the Arduino IDE from intel.  You can right regular arduino "Sketches" and run them on your Galileo.  This is because the Galileo is an "[Arduino Certified](http://arduino.cc/en/ArduinoCertified/Products "Arduino Certified Product Page")" board.  

1. Intel has a customized version of the Arduino IDE as part of their "[Software package release version 1.0.3](https://communities.intel.com/docs/DOC-22226 "Software package release version 1.0.3 Downloads")".  There are versions for multiple operating systems.  Here, we'll assume the "[Arduino Software 1.5.3 for Windows](http://downloadmirror.intel.com/24272/eng/arduino-windows-1.0.3.7z "Arduino Software 1.5.3 for Windows Download")". This is a 159MB File. 

	> **Note:** It's ok if you already have another version of the Arduino IDE installed or extracted to your machine.  We will extract this to it's own folder, and it won't overwrite or impact existing installs.  Just make sure that when you are working with Sketches that you want to run on the Galileo, that you run the version of the Arduino IDE from this download.  

	[![02010-ArduinoIDEDownload](images/02010-arduinoidedownload.png?raw=true "Aruduino 1.5.3 IDE Download for Galileo and Windows")](http://downloadmirror.intel.com/24272/eng/arduino-windows-1.0.3.7z)

1. Once you have download the .zip file, make sure to "Unblock" it before you extract it.  Right click on the file, then select **"Properties"** from the pop-up menu.  Then int the **"arduino-windows-1.0.3.zip Properties" window, click the **"Unblock"** button, then &&"OK"&&. 

	![02020-UnblocckZip](images/02020-unblocckzip.png?raw=true "Unblock Zip")

1. Next, extract the downloaded .zip file to a folder off the root of your C:\ (or the drive of your choice).  Make sure to extract to a folder as close to the root as possible:

	![02030-ExtractZip](images/02030-extractzip.png?raw=true "Extract Zip File To Root")

	> **Note:** If you don't extract to a folder close to the root you run the risk of encountering "Path too long" errors like the following.  If this happens, cancel the extraction, delete the extracted folder, and repeat the extraction, this time choosing a folder closer to the root of the drive.  

	![02040-PathTooLong](images/02040-pathtoolong.png?raw=true "Path Too Long Error")

1. Rename the extracted folder **"Arduino 1.5.3"**.  

	> **Note:** This isn't required, but the subsequent steps will assume this folder name.  If you extracted your .zip file to a different path, or named it something different, keep that path in mind during subsequent steps.  

	![02050-RenameFolder](images/02050-renamefolder.png?raw=true "Rename Folder")

1. Great, we are getting closer, but first, we need to install the USB driver for the Galileo on our machine and make sure that our Galileo's firmware is up to date.  

<a name="Task3" />
## Connecting your Galileo and Installing the Driver ##

1.  You are ready to connect your Galileo to power, and then to your PC.  FIRST connect to the power supply to the Galielo:

	![03010-ConnectPower](images/03010-connectpower.png?raw=true "Connect Power")

1. Wait until the **"USB"** LED on the Galileo board lights up, then connect the Micro USB cable you located previously to the Galileo's **"USB Client"** port, and then connect the other end of the cable to your PC. 

	![03020-ConnectUSBCable](images/03020-connectusbcable.png?raw=true "Connect USB Cable")

1. When you connect the USB cable to your PC, you are likely to see the standard attempt to load the device driver, however, it likely won't find the driver:

	![03030-DriverInstallationAttempt](images/03030-driverinstallationattempt.png?raw=true "Driver Installation Attempt")

1. To load the driver, open your computers "Device Manager"

	![03040-DeviceManager](images/03040-devicemanager.png?raw=true "Open Device Manager")
	
1. Then, under the **"Other Devices"** category, you should see a **"Gadget Serial v2.4"** device.  Right click on that device and select **"Update Driver Software..."** from the pop-up menu:

	![03050-UpdateDriver](images/03050-updatedriver.png?raw=true "Update Driver")

1. In the **"Update Driver Software - Gadget Serial v2.4" window, select **"Browse my computer for driver software"** 

	![03060-Browse](images/03060-browse.png?raw=true "Browser for Driver")

1. On the **"Browser for driver software on your compter" page, browse the the **"C:\arduino-1.5.3\hardware\arduino\x86\tools"** folder and click **"Next"** 

	> **Note:** Remember to modify the path if you extracted the Intel Galileo Ardunio software to a different path

	![03070-BrowserToFolder](images/03070-browsertofolder.png?raw=true "Browse to the Tools Folder")

1. If all went well, the Galileo driver should have been installed. Click **"Close"**. 

	![03080-DriverInstalled](images/03080-driverinstalled.png?raw=true "Driver Successfully Installed")

1. Back in the **"Device Manager"**, you should now see your Galileo under the **"Ports (COM & LPT)"** category, you should now see your Galileo listening on a specific COM port.  The USB connection creates a virtual COM port that you can use to communicate with your Galileo. 

	> **Note:** The screenshot below shows the Galileo listening on COM4. ***Your Galileo may well be on a different port***.  Remember the COM port your Galileo is listening on.  You will want to make sure to use that same COM port in the Arduino IDE.

	![03090-GalileoCOMPort](images/03090-galileocomport.png?raw=true "Galileo on COM Port")

<a name="Task4" />
## Updating the Galileo's Firmware ##

The team at Intel is constantly working to improve the Galileo.  As such, you should make sure to update your Galileo to the latest firmware version.  

1. Ensure that your Galileo is connected and listening on a COM port as described in the previous step. 

1. Open the "C:\aruduino-1.5.3" folder that you extracted the Arduino Software for the Intel Galileo to earlier (use the appropriate path if you extracted to a different directory), and run **"arduino.exe"** to launch the Arduino IDE:

	![04010-RunArduinoIDE](images/04010-runarduinoide.png?raw=true "Run Arduino IDE")

1. First, we need to let the Arduino IDE know what kind of board we are using.  In the Arduino IDE, from the menu bar select **"Tools"** | **"Board"** | **"Intel Galileo"** (this is for a Intel Galileo Gen 1 board).

	![04020-SetBoard](images/04020-setboard.png?raw=true "Set Board")

1. Next, we need to tell the Arduino IDE what COM port the board is listening on.  From the menu bar select **"Tools"** | **"Serial Port"** | **"&lt;The COM Port Your Galileo Is Listening On&gt;"** (from the previous task, COM4 in this case).

	![04030-SelectPort](images/04030-selectport.png?raw=true "Select Port")

1. Next, start the firmware update by selecting **"Help"** | **"Galileo Firmware Update"** from the menu bar:

	![04040-GalileoFirmwareUpdate](images/04040-galileofirmwareupdate.png?raw=true "Galileo Firmware Update")

1. Click **"OK"** to confirm the warning about external power:

	![04050-ExtnernalPowerWarning](images/04050-extnernalpowerwarning.png?raw=true "External Power Warning")

1. If your Galileo's firmware needs updating you will be shown the current version and the target version.  Click **"Yes"** to confirm the firmware update:

	![04050-ConfirmUpdate](images/04050-confirmupdate.png?raw=true "Confirm Firmware Update")

	> **Note:** If your firmware is already up to date, you will see a prompt similar to the following (although your version number may be different).  You don't need to update your firmware unless you feel there is a problem with it's current installation:

	![04055-FirmwareAlreadyUpToDate](images/04055-firmwarealreadyuptodate.png?raw=true "Firmware Already Up To Date")

1. You will see a number of status prompts, and eventually one letting you know that the update could take as long as five minutes.  You will also likely hear your system's USB "Connect" and "Disconnect" sounds as the update proceeds:

	![04060-UpdatePrompt01](images/04060-updateprompt01.png?raw=true "Update Prompt")

	![04070-UpdatePrompt02](images/04070-updateprompt02.png?raw=true "Update Prompt")

	![04080-UpdatePrompt03](images/04080-updateprompt03.png?raw=true "Update Prompt")

1. Eventually, the update should complete. Click **"OK"** to close the prompt:

	![04090-UpdateComplete](images/04090-updatecomplete.png?raw=true "Firmware Update Complete")
	
<a name="Task5" />
## Running the "Blink" sketch on your Galileo ##

You are finally ready to create and run your first "Sketch" (Arduino programs are called "Sketches").  The canonical "Hello, World" sample for the Arduino is to blink an LED.  The Galileo actually has an LED on board so you don't even need to go get an LED for this.  

The Arduino (as well as the Galileo) has a number of "pins" that you can use to interact with other devices.  In this case we will use a "[Digital Pin](http://arduino.cc/en/Tutorial/DigitalPins "Arduino Digital Pins Documentation")". Digital Pins can be used for INPUT (reading signals from external devices IN to the Galileo) or OUTPUT (writing digital signals OUT to external devices).  Whether set to INPUT or OUTPUT, a digital pin can have two states, LOW (0v) or HIGH (5V).  

![05010-DigitalPinsOnGalileo](images/05010-digitalpinsongalileo.png?raw=true "Digital Pins on the Galileo")

In the "Blink Sketch" we will use digital pin #13.  We will set it to OUTPUT so that we can send digital signals OUT to an LED.  As it turns out, the Galileo's on board LED maps to the Galileo's digital pin 13 so we don't even really need a physical LED for this. 

1. If not already open, open the Arduino IDE you downloaded and extracted previously

	![04010-RunArduinoIDE](images/04010-runarduinoide.png?raw=true "Run Arduino IDE")

1. From the menu bar select **"File"** | **"Examples"** | **"01.Basics"** | **"Blink"**

	![05020-OpenBlinkSketch](images/05020-openblinksketch.png?raw=true "Open Example Blink Sketch")

1. A new instance of the Arduino IDE will open with the "Blink" sketch loaded. 

	![05030-BlinkSketchLoaded](images/05030-blinksketchloaded.png?raw=true "Blink Sketch Loaded")

1. The code for the blink sketch should be similar to this: 

	````C++
	/*
	  Blink
	  Turns on an LED on for one second, then off for one second, repeatedly.
	 
	  This example code is in the public domain.
	 */
	 
	// Pin 13 has an LED connected on most Arduino boards.
	// give it a name:
	int led = 13;

	// the setup routine runs once when you press reset:
	void setup() {                
	  // initialize the digital pin as an output.
	  pinMode(led, OUTPUT);     
	}

	// the loop routine runs over and over again forever:
	void loop() {
	  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
	  delay(1000);               // wait for a second
	  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
	  delay(1000);               // wait for a second
	}
	````

1. Let's take a closer look at the code.  First, it defines an integer variable that represents the digital pin we want to work with (13 in this case).  As the comments suggest, the Galileo has an on board LED that is mapped to digital pin 13:

	````C++
	// Pin 13 has an LED connected on most Arduino boards.
	// give it a name:
	int led = 13;
	````
1. An Arduino Sketch has to required methods, ***setup()** and ***loop()***.  The ***setup()*** method is called once at at the beginning of the sketch's execution.  In this case, we simply set the led pin up for OUTPUT.  

	````C++
	// the setup routine runs once when you press reset:
	void setup() {                
	  // initialize the digital pin as an output.
	  pinMode(led, OUTPUT);     
	}
	````

1. finally the **loop()** method is called repeatedly while the sketch executes. In this sketch, we use the **digitalWrite()** method to set the led pin HIGH (to 5V) which turns ON the on board led connected to pin 13.  Then we wait for 1 second (1000 milliseconds), then turn the led LOW (0v), and wait for 1 second.  This occurrs each time the **loop()** method is called.  The end result is an LED that blinks ON and OFF repeatedly:

	````C++
	// the loop routine runs over and over again forever:
	void loop() {
	  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
	  delay(1000);               // wait for a second
	  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
	  delay(1000);               // wait for a second
	}
	````

1. Ok, now that we know what the code does, let's upload it to the Galileo.  From the Arduino IDE's toolbar, click the "Upload" button:

	> **Note:** Make sure that you have selected the proper board type and serial port from the Arduino IDE's **"Tools"** menu as described previously

	![05040-UploadButton](images/05040-uploadbutton.png?raw=true "Upload Button")

1. Then at the bottom of the Arduino IDE, verify that the code was compiled and uploaded to the Galileo successfully:

	![05050-TransferComplete](images/05050-transfercomplete.png?raw=true "Transfer Complete")

1. And if you look at the Galileo, the on board LED should be blinking on and off at one second intervals (on for one second, off for one second, ...):

	![05060-LEDOn](images/05060-ledon.png?raw=true "LED On")

	![05070-LEDOff](images/05070-ledoff.png?raw=true "LED Off")

1. Congratulations! 

<a name="Task6" />
## Extra Credit - Using an External LED with Blink ##

Ok, this isn't really "Extra Credit".  In fact, it's really not a big deal, but if you haven't played with electronics before, this extra step might give you a little more sense of accomplishment.  

In the last task, we toggled digital pin 13 on and off, and we could see the on board LED blinking on and off when we did so.  That worked because Intel "piggy backed" an onboard LED on digital pin 13.  This is a common technique used on most Arduino compatible boards.  It just make it easy to run the "Blink" demo without having to have any extra parts.  

If you have access to an external LED though, you can blink it as well.  Since we already have a sketch that toggles digital pin 13, we'll go ahead and use that same pin, but first, let's talk about LEDs.

LED's are **"[Light-emitting Diodes](http://en.wikipedia.org/wiki/Light-emitting_diode)"**.  Diodes are semiconductors that only allow current to flow in one direction.  LEDs are a special type of diode that emit light when current is passed through them.  

Because LED's only allow current to flow in a single direction, you have to make sure that you hook them up correctly.  The part of the LED that is connected closer to the voltage source (positive) is called the "Anode". The part of the LED that is connected closer to ground (negative) is the "Cathode".  You can tell the which "leg" of an LED is the Anode or the Cathode using a number of methods. The following diagram outlines those methods for you:

![06010-LEDPolarity](images/06010-ledpolarity.png?raw=true "LED Polarity")

If you have a brand new LED, the "long leg" is the "anode" and the "short leg" is the cathode.  If your LED isn't new, or if the legs have been cut short, you can use some of the other indicators from the diagram above to determine it's polarity. 

Technically, you should use a **"[Current Limiting Resistor](https://www.sparkfun.com/tutorials/219)"** when using an LED, but we are going to skip that in this quick demo.  The current we put through the LED shouldn't harm most LEDs for short term use, and if it does blow our LED, well, LEDs are cheap.  Super cheap. 

So, with that said, here's how we are going to hook up our LED:

![06020-FritzingBlinkDiagram](images/06020-fritzingblinkdiagram.png?raw=true "Fritzing Blink Diagram")

> **Note:** That awesome diagram was created using a free tool called Fritzing.  Get it, and learn more about it at fritzing.org

1. Based on the information above, connect your LED to the Galileo by placing the "anode" (long leg) of the LED into Digital Pin 13 on the Galileo, and the "cathode" (short leg) into the GND (ground) pin that is immediately adjacent to digital pin 13 (isn't that convenient). 

1. If you still have your sketch running from before, your LED should start blinking immediately.  If not, use the steps described in the previous task to deploy the "Blink" sketch to your Galileo.  Once done, you should see the external LED blinking.

	![06030-LEDOn](images/06030-ledon.png?raw=true "LED On")

	![06040-LEDOff](images/06040-ledoff.png?raw=true "LED Off")