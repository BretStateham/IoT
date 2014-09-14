<a name="Title" />
## HOL - 02 - Running Windows on your Intel Galileo ##

In the "HOL - 01 - Unboxing and Running Your Galileo for the First Time" lab we walked step-by-step through the process of unboxing, setting up, and using your Galileo the for the first time.  

The Galileo board ships with a version of Linux flashed onto an onboard ROM. However, you can also boot the Galileo to different off the Micro SD card, including various linux distributions as well as a free version of Windows from the "[Windows Developer Program for IoT](http://windowsondevices.com)". 

There is a video online that walks through the steps (albeit slightly differently) here: http://youtu.be/yrRMomesBKM 

<a name="why" />
## Why run Windows on your Galileo?##

If you went through the first lab, "HOL - 01 - Unboxing and Running Your Galileo for the First Time", you have seen that the Galileo is fully functional out of the box with the Linux image that is flashed on it. So Why would you install Windows on it? Here are some answers to that question: 

1. The "Windows on Devices" program is in its early stages, yet already it is supported on multiple boards including the **[Galileo](http://www.intel.com/content/www/us/en/do-it-yourself/galileo-maker-quark-board.html), [Minnowboard Max](http://www.minnowboard.org/), and [Sharks Cove](http://www.sharkscove.org/)**.  Microsoft is committed to supporting Windows across a variety of embedded devices now. So its not just about the Galileo, but installing Windows on the Galileo now helps you to "get in on the ground floor" so to speak with the "Windows on Devices" program. 

1. Microsoft announced at build, that the version of windows that runs on embedded devices will be FREE.  As well as a free version of Windows for devices with screens less than 9"

1. By putting Windows on the Galileo, existing Windows developer can use familiar development tools and APIs to develop embedded applications.  We'll see later in the HOL that you can use Visual Studio 2013, Visual C++, and Win32 APIs to create apps that run on the Galileo.

1. Visual Studio Express 2013 for Windows Desktop can be used to develop Win32 apps for Windows running on Devices. Microsoft is also making it possible to install the "Windows Driver Kit (WDK)" for use in Visual Studio Express. 

1. Microsoft has announced a renewed focus and effort on the [.NET Micro Framework](http://www.netmf.com/)

1. At //BUILD/ in April 2014, it was announced that the team is working to extend the Universal App model to "Windows on Devices".  There were some other sessions at BUILD that talked about  

	- [Day 1 Keynote](http://channel9.msdn.com/Events/Build/2014/KEY01) at about [02:03:16](http://channel9.msdn.com/Events/Build/2014/KEY01#time=2h03m16s) - Terry Myerson talks about IoT, the Galileo, and [the Piano demo](http://channel9.msdn.com/Events/Build/2014/KEY01#time=2h04m26s).  Then at about [02:10:35](http://channel9.msdn.com/Events/Build/2014/KEY01#time=2h10m35s), Terry talks about "Windows for the Internet of Things" being free, as well as free on phones and tablets with screen sizes less than 9 inches. 
	- [Day 2 Keynote](http://channel9.msdn.com/Events/Build/2014/KEY02) at about [02:02:18](http://channel9.msdn.com/Events/Build/2014/KEY02#time=2h02m18s) - Steve Guggenhiemer talks about .NET MicroFramework and Embedded Devices
	- [Windows and the Internet of Things](http://channel9.msdn.com/Events/Build/2014/2-511)
	- [Simplifying Hardware Development for Windows Platforms](http://channel9.msdn.com/Events/Build/2014/2-536)
	- [Internet of Things with Azure Service Bus](http://channel9.msdn.com/Events/Build/2014/3-635)

<a name="Prerequisites" />
## Prerequisites ##

This lab assumes you have completed the "HOL - 01 - Unboxing and Running Your Galileo for the First Time" lab.  If you haven't completed that lab, do so before continuing with this one. 

At a minimum you need to have previously: 

- Downloaded the "[Arduino Software 1.5.3 for Windows](http://downloadmirror.intel.com/24272/eng/arduino-windows-1.0.3.7z "Arduino Software 1.5.3 for Windows Download")" for Galileo from the "[Software package release version 1.0.3](https://communities.intel.com/docs/DOC-22226 "Software package release version 1.0.3 Downloads")" 
- Installed the Driver for your Intel Galileo
- Updated the firmware on the Galileo to the latest version.  

In addition, you need to have completed the registration for the "[Windows Developer Program for IoT](http://windowsondevices.com)". 

<a name="anchor-name-here" />
## Required Hardware ##

You will need a few things for this lab.  You should already have the Galileo and the Power Supply from the first lab.  But now you will need to add a Micro SD Card, Adapter and Reader/Writer, as well as an Ethernet Cable:

![00010-Hardware](images/00010-hardware.png?raw=true "Hardware")

1. Galileo 
1. Power Supply
1. Micro SD Card, Adapter and Reader/Writer
1. An Ethernet Cable (regular patch cable)

> **Note:** It is also assumed that you have an ethernet port on your computer that you can connect the Ethernet cable to.  

<a name="Tasks" />
## Tasks ##

1. [Registering for the "Windows Developer Program for IoT"](#Task1)
1. [Installing the Windows on your Micro SD Card](#Task2)
1. [Setting up your Windows PC](#Task3)
1. [Booting the Galileo to Windows](#Task4)
1. [Running your first "Wiring App" on the Galileo](#Task5)
1. [Shutting Down your Galileo](#Task6)

<a name="Task1" />
## Registering for the "Windows Developer Program for IoT" ##

In order to get access to the free windows version for the Galileo, as well as for the other downlaods, you need to first complete the registration for the "Windows Developer Program for IoT"

1. Open your web browser and navigate to http://windowsondevices.com . Then click the "R[egister to be a Windows IoT Developer today](https://www.windowsondevices.com/signup.aspx)" link

	![01010-RegistrationLink](images/01010-registrationlink.png?raw=true "Registration Link")

1. Complete the registration form:

	![01020-RegistrationForm](images/01020-registrationform.png?raw=true "Registration Form")

1. You should eventually receive an email at the address you used during your registration that looks similar to the following:

	![01030-RegisrationEmail](images/01030-regisrationemail.png?raw=true "Registration Email")

1. When you follow the link in the email and complete the process, you will receive another email.

	![01040-ThankYou](images/01040-thankyou.png?raw=true "ThankYou")

1. Next, Sign up for the "[Windows Embedded Pre-Release Program](https://connect.microsoft.com/windowsembeddediot/SelfNomination.aspx?ProgramID=8558)"(https://connect.microsoft.com/windowsembeddediot/SelfNomination.aspx?ProgramID=8558) . Then follow the **"MICROSOFT WINDOWS FOR WINDOWS DEVELOPER PROGRAM FOR IOT EULA"**: 

	![01042-SignupLink](images/01042-signuplink.png?raw=true "Sign Up Link")

1. Read, and agree to the EULA:

	![01044-Eula](images/01044-eula.png?raw=true "EULA")

1. You should end up on the "Thank You" page: 

	![01046-ThankYou](images/01046-thankyou.png?raw=true "Thank You")

1. Finally, you should be able to open the "[Windows Embedded Pre-Release Programs Home](https://connect.microsoft.com/windowsembeddedIoT)" page on Microsoft Connect.  From there you can click the **"Downloads"** link:

	> **Note:** If this is your first time using Microsoft Connect, you may need to complete an initial Connect registration.  The steps to sign up for connect should be pretty straight forward, but if you need assistance check out the [Signing into Microsoft Connect](http://ms-iot.github.io/content/SigninMSConnect.htm) page.

	![01050-WdpIotConnect](images/01050-wdpiotconnect.png?raw=true "Windows Developer Program for IoT on Connect")

1. And finally, you can get the [downloads](https://connect.microsoft.com/windowsembeddedIoT/Downloads) needed to install the tools on your PC, and Windows on your Galileo:

	![01060-Downloads](images/01060-downloads.png?raw=true "Downloads Page")

<a name="Task2" />
## Installing the Windows on your Micro SD Card ##

Next, we'll apply the Windows Image from the **"Windows Developer Program for Iot" downlaods to the Micro SD card.  

1. First, let's prepare the Micro SD Card.  Put the Micro SD card into it's Adapter, then into your SD Card Reader/Writer, and connect the SD Card Reader/Writer to your PC.

	![03002-MicroSDCardParts](images/03002-microsdcardparts.png?raw=true "Mico SD Card Hardware")

1. Open your File Explorer, right-click on the newly inserted Micro SD Card, and select **"Format..."** from the pop-up menu:

	![03004-DriveMenu](images/03004-drivemenu.png?raw=true "Drive Menu")

1. Make sure to format it as **FAT32** and to choose **"Quick Format"** (otherwise it takes a while).  I also like to give it a **"Volume Name"** like **"GALILEO_WIN"** so I can identify the disk more easily in the future:

	![03006-FormatSDCard](images/03006-formatsdcard.png?raw=true "Format Micro SD Card")

1. 	Download the latest versions of both the **"Windows Developer Program for IoT - Windows Image (WIM)"** and **"Windows Developer Program for IoT - apply-bootmedia.cmd"** from the [Windows Developer Program for Iot Downloads Page](https://connect.microsoft.com/windowsembeddedIoT/Downloads)

	> **Note:** in just a bit, we'll need the **"Windows Developer Program for IoT - Microsoft Installer (MSI)"** files as well.  If you want to download the latest versions of that now as well go ahead.  We'll still document it's download later though. For all of these downloads **MAKE SURE TO GET THE LATEST VERSION**.

	[![03010-Downloads](images/03010-downloads.png?raw=true "Downloads")](https://connect.microsoft.com/windowsembeddedIoT/Downloads)

1. Copy the **.wim** and the **.cmd** files to same directory on your machine (I created a folder named **"C:\Galileo"** and copied them there):

	![03020-FilesInFolder](images/03020-filesinfolder.png?raw=true "Copy Files to the Same Folder")

1. Next, open a command prompt as administrator: 

	![03030-OpenAdminPrompt](images/03030-openadminprompt.png?raw=true "Open Command Prompt as Administrator")

1. Change into the directory where you copied the files above

	![03040-ChangeDirectory](images/03040-changedirectory.png?raw=true "Change into Galileo Directory")

1. Now, run the **apply-BootMedia.cmd** batch file with the following options:

	- **-destination**  :  Specify the path to the root of the Micro SD card (**d:&#x5C;** in my case)
	- **-image** : Specify the full **&lowast;.wim** file name.  **You can press the "TAB" key to complete the file name**.  Much easier than typing it all. 
	- **-hostname** : The hostname that will be used for the Windows image on the Galileo.  It is recommended that you use **mygalileo** because the Visual Studio project templates default to that.  You can use a different name, you will just need to update the name in the visual studio templates. 
	- **-password** : The password for the built-in **"Administrator"** account.  You will use this to authenticate to the Galileo.  I used **admin***

	![03050-ApplyBootMedia](images/03050-applybootmedia.png?raw=true "Apply Boot Media")

1. The process could take ten minutes or longer to complete.  While it runs, you can move on to the next task.  **JUST MAKE SURE NOT TO REBOOT YOUR MACHINE IF PROMPTED UNTIL THE APPLY-BOOTMEDIA.CMD BATCH FILE COMPLETES!**.  It would be unfortunate if you had to repeat these steps. 

1.  **LEAVE THIS BATCH FILE WINDOW OPEN WHILE IT RUNS. WE'LL RETURN TO IT LATER.**

<a name="Task3" />
## Setting Up Your PC ##

1. Ensure that you have a copy of Visual Studio 2013 installed.  If not, you can download a free copy of **"[Visual Studio Express 2013 for Windows Desktop](http://www.visualstudio.com/downloads/)"**

	[![02010-VSExpressDownload](images/02010-vsexpressdownload.png?raw=true "VSExpressDownload")](http://www.visualstudio.com/downloads/)

<a name="InstallMSI" />

1. Download the ***latest version*** of the **"Windows Developer Program for IoT - Microsoft Installer (MSI)"** from the connect [downloads page](https://connect.microsoft.com/windowsembeddedIoT/Downloads).  

	>**Note:** If you downloaded this file previously while downloading the **&lowast;.wim** and **apply-BootMedia.cmd** files, you can obviously skip this step.

	[![02020-DownloadMSI](images/02020-downloadmsi.png?raw=true "Download MSI")](https://connect.microsoft.com/windowsembeddedIoT/Downloads)

1. Once downloaded, run the installer.  This adds the **"Galileo Wiring App"** project template to Visual Studio 2013, and install the **""Galileo Watcher"** utility to help you manage the Galileo's on your network. Accept the license agreement, and click **"Install"**, then Follow the prompts to complete the installation:

	![02030-RunInstaller](images/02030-runinstaller.png?raw=true "Run Installer")

1. When the installation is complete, **CLEAR** the **"Launch Galileo Watcher Application"**.  We'll run that later when we need it. Click **"Finish"** to complete the installation.

	![02035-FinishInstall](images/02035-finishinstall.png?raw=true "Finish Install")

1. Finally, you need to install the Windows Telnet Client.  This is included with Windows, but not installed by default.  To install it, open **"Programs and Features"** from the Windows **"Control Panel"**, and click the "Turn Windows features on or off" link along the left hand side:

	![02040-WindowsFeatures](images/02040-windowsfeatures.png?raw=true "Turn Windows features on or off")

1. Then, in the **"Windows Features"** window, scroll down and turn ON the checkbox next to the **"Telnet Client"**, then click **"OK"** to install it.  It should just take a minute or two to install.  

	![02050-InstallTelnetClient](images/02050-installtelnetclient.png?raw=true "Install Telnet Client")

<a name="Task4" />
## Booting the Galileo to Windows ##

We are ready to boot the Galileo up to windows.  You'll your Galileo, Power Supply, Micro SD Card, and Ethernet Cable.  We'll start with a direct connection betwen your galileo and PC using the Ethernet Cable.  Later, you can connect them more in-directly using a network.  We won't cover those steps in the lab though:

![04002-Hardware](images/04002-hardware.png?raw=true "Hardware")

1. Ensure that the **apply-BootMedia.cmd** batch file completed successfully.  If not, repeat the steps in **[Task 2](#Task2)** .  Otherwise, make sure to note the details shown at the end of the **apply-BootMedia.cmd**'s output.  You'll need these details to connect to your Galileo.  You can close the command prompt when you are sure you have the values noted:

	![04010-ApplyBootMediaOutput](images/04010-applybootmediaoutput.png?raw=true "Apply Boot Media Output")

1.  Next, extect the Micro SD card from your computer:

	![04020-EjectMicroSD](images/04020-ejectmicrosd.png?raw=true "Eject Micro SD Card")

1. Finally, let's connect it all up, and boot the Galileo:

	1. Insert the Micro SD Card into the Micro SD Card slot on the Galileo
	2. Plug the Ethernet cable into the Galileo, as well as into your PC (a direct connection).  Yes, this works with a regular patch cable.  It doesn't need to be a cross-over cable. 
	3. Connect the power to the Galileo

	> **Note:** The boot process will take a couple of minutes.  As suggested in the diagram above, you should see the SD light on the Galileo (right next to the Micro SD Card slot) will flicker.  Once it settles down after a couple of minutes, the Galileo should be booted.

	![04030-Connections](images/04030-connections.png?raw=true "04030-Connections")
	
1. **AFTER THE GALILEO HAS BOOTED (THE SD LIGHT CARD STOPS FLICKERING) CYCLE THE POWER ON YOUR GALILEO BY UNPLUGGING IT, THEN PLUGGING IT BACK IN AGAIN.**  WHY? Well, there is a known issue with the Galileo not "announcing" itself on the network the first time it boots.  Doing the power-cycle now increases your odds of the **"Galileo Watcher"** (which we are about to run) being able to see you Galileo.  If the Galileo isn't announcing it self, the Galileo Watcher can't see it.  The power-cycle is to help overcome a bug in the software on the Galileo that prevents it from announcing itself on the first boot.  

	
1. Once the Galileo has booted, run the **"GalieoWatcher.exe"** that was installed on your PC previously when we [installed the **"Windows Developer Program for IoT - Microsoft Installer (MSI)"** in Task 3](#InstallMSI):

![04040-RunGalileoWatcher](images/04040-rungalileowatcher.png?raw=true "Run Galileo Watcher")

1. The first time you run it, you should be prompted to allow **GalileoWatcher.exe** to communicate with the network.  You likely want to permit this on all networks.  If you are concerned with that, be more restrictive.  Make sure to at least enable private networks:

	![04050-AllowNetworkCommunication](images/04050-allownetworkcommunication.png?raw=true "Allow Network Communication")

1. When the **"Galileo Watcher"** first opens, it should not "see" any Galileos, and the list should be empty:

	![04060-EmptyGalileoWatcher](images/04060-emptygalileowatcher.png?raw=true "Empty Galileo Watcher")

1. However, after your Galileo has been booted for a while, it should start to multicast messages that include it's hostname, IPv4, and IPv6 addresses.  **"Galileo Watcher"** listens for those multicast messages, and once it see it, will display details about your Galileo.  You can right click on an entry to perform actions like Telnet with your Galielo as well:

	![04070-GalileoWatcherActions](images/04070-galileowatcheractions.png?raw=true "Galileo Watcher Actions")

	> **Note:  Getting your Galileo to appear in Galileo Watcher is problematic for a new image of Windows on the Galileo.  It will likely take a couple of re-boots of your Galileo before it appears in Galileo Watcher.  Let your Galileo boot completely. Wait another two minutes or so for things to stabilize, then pull the power cord on the Galileo, wait a few seconds, and plug it in again.  It typically takes a re-boot or two before the Galileo appears in Galileo Watcher.  The team is aware of the issues and is actively working to resolve them.  You can periodically update your SD card to the latest Windows Image as well as updating the client tools to make sure you have the latest version.**

1. If your Galileo appeared in **Galileo Watcher** you can skip this step.  However, if your Galileo **DOES NOT APPEAR** in **Galileo Watcher**, you can attempt to telnet directly to it using it's hostname.  To do so, open a command prompt and run **telnet mygalileo**.  Then, when prompted login as **Administrator** with the password you specified when you are apply-BootMedia.cmd previously.  Finally, you can run **ipconfig** to get the IP Address of your Galileo:

	![04095-ManualTelnet](images/04095-manualtelnet.png?raw=true "Manual Telnet")


1.  Ok, once the Galileo is appearing in the Galileo Watcher, we can try connecting to it a few different ways.  First, let's try Telnet.  Right click on your Galileo in the **"Galileo Watcher"** and select **"Telnet Here"** from the pop-up menu:

	![04080-TelnetHere](images/04080-telnethere.png?raw=true "Telnet Here")

	> **Note:** As mentioned above, If your Galileo isn't appearing in the Galileo Watcher, you can just open a command prompt and type **telnet mygalileo** to telnet to your board

1. In the Telnet window, login using:
	- **User Name:** Administrator
	- **Password:** The password you specified when you ran apply-BootMedia previously

	![04090-TelnetLogin](images/04090-telnetlogin.png?raw=true "Telnet Login")

	> **Note:** You could also of course just run the Telnet client and telnet directly to your galileo's host name or IP Address.  In addition, you can use other terminal programs like [PuTTY](http://www.putty.org) to telnet into your Galileo.  You do not have to initiate operations from Galileo Watcher.  It just makes it easier to do so. 

1. 	Run some commands to investigate the Windows OS on your Galileo, then close the Telnet window when you are done.  Some interesting commands include:

	- **net start** to see the services that are running.  Try other **net &lowast;** other net commands like **net user** to view users, **net share** to view shares, etc.
	- **tlist -t** to list the tree view of processes running on the Galileo
	- **kill** - Don't run this unless needed, but can kill a process.  Just speicify the PID found in **tlist** for the process you want to kill.
	- **netstat -a -n -b** to see the ports it is lisetening on and what processes are doing the listening

1.  Back in **Galileo Watcher** right click on your Galileo, and select 

	![04100-WebBrowserHere](images/04100-webbrowserhere.png?raw=true "Web Browser Here")

	> **Note:** If your Galileo isn't appearing in **Galileo Watcher** you can simply open a browser window and navigate to **http://mygalileo**

1. Follow the various links to try the different features hosted by the Galileo's web server. The **"File List"** option doesn't appear to be function, but the other's give you some interesting info.  Close the browser when you are done:

	![04110-WebPages](images/04110-webpages.png?raw=true "Web Pages")

1. Lastly, back in **Galileo Watcher**, right click on your Galileo, and select **"Open Network Share"** from the pop-up menu:

	![04120-OpenNetworkShare](images/04120-opennetworkshare.png?raw=true "Open Network Share")

	> **Note:** If your Galileo isn't appearing in **Galileo Watcher** you can open a File Explorer window, and navigate to **\\mygalileo\c$** 

1. You should be prompted to authenticate, again use the **Administrator** user name and the **password you specified when you ran apply-BootMedia.cmd**:

	![04130-Authenticate](images/04130-authenticate.png?raw=true "Authenticate")

1. Once authenticated you should see the contents of your Galileo's SD card.  **Poke around CAREFULLY**, and **close the explorer window when you are done**:

	![04140-GalileoFiles](images/04140-galileofiles.png?raw=true "Galileo Files")

1. There is actually an FTP service running on the Galileo as well, but the Galileo Watcher doesn't have a shortcut to it.  You can use the ftp client of your choice to FTP into the Galileo, again using the **Administrator** username and password you specified during apply-BootMedia.cmd.  

	![04150-FTPClient](images/04150-ftpclient.png?raw=true "FTP Client")

<a name="running-your-first-wiring-app-on-the-galileo" />
## Running your first "Wiring App" on the Galileo ##

Now that our Galileo is setup and running windows, we can use Visual Studio to write a C++ console app to run on it.  However, the "Windows Devloper Program for IoT - Microsoft Installer (MSI)" file put a project template on our system that we can use that allows us to not only write a C++ console app, but to also leverage the Gallileo-SDK and the Wiring APIs.  That means that our C++ app can interact with the digital and analog pins on the the board as well.  In this task, we'll create the Visual Studio version of the Arduino "Blink" app we ran in the first lab.  

1. Open Visual Studio 2013 (or Visual Studio Express 2013 for Windows Desktop).  From the menu bar select **"File"** | **"New"** | **"Project..."**. 

1. In the **"New Project"** window, in the tree of **"Installed Templates"** along the left, , find and expand **"Visaul C++"** | **"Windows for IoT"**, and select the **"Galileo Wiring App"** project template.  Give the project a name (I Used **"HelloGalileo"** and a location), and click **"OK"** to create the project:

	![05010-NewGalileoWiringApp](images/05010-newgalileowiringapp.png?raw=true "New Galileo Wiring App")

1. In the **Solution Explorer** window, right click on the **HelloGalileo** project (or whatever you called your project) and select **"Manage NuGet Packages..." from the pop-up menu:

	![05020-ManageNuGetPackages](images/05020-managenugetpackages.png?raw=true "Manage NuGet Packages")


1. In the **"HelloGalileo - Manage NuGet Packages"** window, expand **"Installed packages"** and select **"All"**. Notice that the **"Galileo C++ SDK"** NuGet Package has already been installed.  This adds the **"Wiring API"** for the Intel Galileo to what would otherwise be a normal C++ console application. **Close the NuGet Package Manager**. 
	![05030-GalileoSDKPackage](images/05030-galileosdkpackage.png?raw=true "Galileo-SDK Package")

1. Again, right-click on the **"HelloGalileo"** Project in the Solution Explorer and select **"Properties"** from the pop-up menu:

	![05040-PropertiesMenu](images/05040-propertiesmenu.png?raw=true "Properties Menu Item")

1. In the **"HelloGalileo Property Pages"** window, along the left hand side, expand **"Configuration Properties"** | **"Debugging"** and review the remote debugging configuration.  Note that the **"Remote Server Name"** defaults to **"mygalileo"**.  If you named your Galileo something different when you ran **apply-BootMedia.cmd"** previously, you'll want to change the **"Remote Server Name"** to match your Galileo's hostname.  Regardless, close the **"HelloGalileo Property Pages"** window when you are done. 

	![05050-DebuggingConfiguration](images/05050-debuggingconfiguration.png?raw=true "Remote Debugging Configuration")

1.  Next, in the **Solution Explorer** window, under the **"HelloGalileo"** project, expand **"Source Files"** and double click on **"Main.cpp"** to open it:

	![05060-MainCPP](images/05060-maincpp.png?raw=true "Main.CPP")

1. Here is the default code for Main.cpp, notice that it has a lot of similarities to the Arduino Blink sketch we ran in the first lab.  The biggest differences are:

	- The **#include**s at the top of the file that pull in the C++ precompiled headers as well as the arduino functionality fro the Galileo-SDK.  

	- the **"_tmain()** method.  This is the main entry point.  It calls **RunArduinoSketch()** which in turn initializes the Arduino funcationality, calls the **setup()** method, and setups up an infite loop that calls the **loop()** method repeatedly.  

	- The **Log()** method is used to log messages to STDOUT as well as to a debugger if one is attached. That means that when we are debugging in Visual Studio, we'll see the **Log()** messages in the **Output** window.  

	- Otherwise, the code is identitcal to the Arduino "Blink" sketch.

	<!-- mark:4-11,27,30 -->
	````C++
	// Main.cpp : Defines the entry point for the console application.
	//

	#include "stdafx.h"
	#include "arduino.h"

	int _tmain(int argc, _TCHAR* argv[])
	{
		 return RunArduinoSketch();
	}

	int led = 13;  // This is the pin the LED is attached to.

	void setup()
	{
		 // TODO: Add your code here
		 
		 pinMode(led, OUTPUT);       // Configure the pin for OUTPUT so you can turn on the LED.
	}

	// the loop routine runs over and over again forever:
	void loop()
	{
		 // TODO: Add your code here

		 digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
		 Log(L"LED OFF\n");
		 delay(1000);               // wait for a second
		 digitalWrite(led, HIGH);   // turn the LED on by making the voltage HIGH
		 Log(L"LED ON\n");
		 delay(1000);               // wait for a second
	}
	````

1. If you have a physical LED you can connect to pin 13 and ground just as we did at the very end of the first lab, you can run the defualt **Main.cpp** code as is.  However, if you want to blink the **ON BOARD LED** we need to make some changes.  Why?  Well the current Gallieo_SDK doesn't map the onboard LED to pin 13 the way the default implementation does.   To blink the onboard LED, we need to access the boards "General Purpose IO" or GPIO pins directly.  


1. Replace the contents of the **"Main.cpp"** file with the following code.  This code is very similar to the default **"Main.cpp"** with a few exceptions:

	- On line 12 we map the led variable to **LED_BUILTIN** instead of 13.  This maps to the GPIO pin that the onboard LED is connected to. 

	- on line 18, we use the **GpioSetDir()** method instead of **pinMode()** to set the ***direction*** (INTPUT or OUTPUT) of the pin.  

	- on lines 26 and 29, we use the **GpioWrite()** method instead of **digitalWrite()** to send a signal to the pin.  **GpioWrite()** uses a different pin mapping that the arduino **digitalWrite()**.


	<!-- mark:12,18,26,29 -->
	````C++
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
	````

	> **Note:** There is a completed Visual Studio Solution you can use in the **.\End\HelloGalileo** folder for this lab. 

1. Ok, let's run it.  In the Visual Studio 2013 toolbar, click the **"Remote Windows Debugger"** button to debug the program on the Galileo:

	![05070-RemoteWindowsDebugger](images/05070-remotewindowsdebugger.png?raw=true "Remote Windows Debugger")
 
1. If you monitor the status bar along the bottom of Visual Studio, you can see it change from **"Deploy Started..."** to **"Deploy Succeeded"**, then in the **Output** window, you should start to see the **Log()** messages coming in:

	![05080-DeployStarted](images/05080-deploystarted.png?raw=true "Deploy Started")

	![05082-DeploySucceeded](images/05082-deploysucceeded.png?raw=true "Deploy Succeeded")

	![05084-OutputWindow](images/05084-outputwindow.png?raw=true "Log Messages in Output Window")

1. And of course if you look on the Galileo, you should see the onboard LED blinking on and off:

	![05100-LEDOff](images/05100-ledoff.png?raw=true "LED Off")

	![05090-LEDOn](images/05090-ledon.png?raw=true "LED On")

<a name="Task6" />
## Shutting Down your Galileo ##

Just like any other Windows computer, your Galileo will be much happier in general if you shut it down properly, rather than just pulling the power cord out. Shutting it down properly will help it boot faster next time as a scan of the Micro SD card won't be needed. 

1. Telnet into your Galileo using the techniques described above. 

1. From the telnet prompt issue the following command to shutdown your galileo immediately:

	-The **/s** command line switch does a shutdown.  The Galileo should in fact be powered off when it is done.  If you prefer to resetart, use **/r**

	-The **/t 0** command line switch sets the "time" to "0" seconds meaning that it will shutdown immediately, with no delay.  

	````PowerShell
	shutdown /s /t 0
	````

	![05110-Shutdown](images/05110-shutdown.png?raw=true "Shutdown")

1. When the shutdown process completes, the Galileo should power off.  If it doesn't just pull the power cord.  

