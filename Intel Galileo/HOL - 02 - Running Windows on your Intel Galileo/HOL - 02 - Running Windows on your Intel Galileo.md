<a name="Title" />
## HOL - 02 - Running Windows on your Intel Galileo ##

In the "HOL - 01 - Unboxing and Running Your Galileo for the First Time" we walked step-by-step through the process of unboxing, setting up, and using your Galileo the for the first time.  

The Galileo board ships with a version of Linux flashed onto an onboard ROM. However, you can also boot the Galileo to another OS including various linux distributions as well as a free version of Windows from the "[Windows Developer Program for IoT](http://windowsondevices.com)".  

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

1. 	Download the latest versions of both the **"Windows Developer Program for IoT - Windows Image (WIM)"** and **"Windows Developer Program for IoT - Apply" from the [Windows Developer Program for Iot Downloads Page](https://connect.microsoft.com/windowsembeddedIoT/Downloads)

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
	
1. Once the Galileo has booted, run the **"GalieoWatcher.exe"** that was installed on your PC previously when we [installed the **"Windows Developer Program for IoT - Microsoft Installer (MSI)"** in Task 3](#InstallMSI):

	![04040-RunGalileoWatcher](images/04040-rungalileowatcher.png?raw=true "Run Galileo Watcher")

1. The first time you run it, you should be prompted to allow **GalileoWatcher.exe** to communicate with the network.  You likely want to permit this on all networks.  If you are concerned with that, be more restrictive.  Make sure to at least enable private networks:

	![04050-AllowNetworkCommunication](images/04050-allownetworkcommunication.png?raw=true "Allow Network Communication")

1. When the **"Galileo Watcher"** first opens, it should not "see" any Galileos, and the list should be empty:

	![04060-EmptyGalileoWatcher](images/04060-emptygalileowatcher.png?raw=true "Empty Galileo Watcher")

1. However, after your Galileo has been booted for a while, it should start to multicast messages that include it's hostname, IPv4, and IPv6 addresses.  **"Galileo Watcher"** listens for those multicast messages, and once it see it, will display details about your Galileo.  You can right click on an entry to perform actions like Telnet with your Galielo as well:

	![04070-GalileoWatcherActions](images/04070-galileowatcheractions.png?raw=true "Galileo Watcher Actions")

	> **Note:  Getting your Galileo to appear in Galileo Watcher is problematic for a new image of Windows on the Galileo.  It will likely take a couple of re-boots of your Galileo before it appears in Galileo Watcher.  Let your Galileo boot completely. Wait another two minutes or so for things to stabilize, then pull the power cord on the Galileo, wait a few seconds, and plug it in again.  It typically takes a couple of re-boots before the Galileo appears in Galileo Watcher.**

1.  Ok, once the Galileo is appearing in the Galileo Watcher, we can try connecting to it a few different ways.  First, let's try Telnet.  Right click on your Galileo in the **"Galileo Watcher"** and select **"Telnet Here"** from the pop-up menu:

	![04080-TelnetHere](images/04080-telnethere.png?raw=true "Telnet Here")

1. In the Telnet window, login using:
	- **User Name:** Administrator
	- **Password:** The password you specified when you ran apply-BootMedia previously

	![04090-TelnetLogin](images/04090-telnetlogin.png?raw=true "Telnet Login")

1. 	Run some commands to investigate the Windows OS on your Galileo, then close the Telnet window when you are done.  Some interesting commands include:

	- **net start** to see the services that are running.  Try other **net &lowast;** other net commands like **net user** to view users, **net share** to view shares, etc.
	- **tlist -t** to list the tree view of processes running on the Galileo
	- **kill** - Don't run this unless needed, but can kill a process.  Just speicify the PID found in **tlist** for the process you want to kill.
	- **netstat -a -n -b** to see the ports it is lisetening to and what processes are listening

1.  Back in **Galileo Watcher** right click on your Galileo, and select 

	![04100-WebBrowserHere](images/04100-webbrowserhere.png?raw=true "Web Browser Here")

1. Follow the various links to try the different features hosted by the Galileo's web server. The **"File List"** option doesn't appear to be function, but the other's give you some interesting info:

	![04110-WebPages](images/04110-webpages.png?raw=true "Web Pages")