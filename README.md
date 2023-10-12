# Blynk-DoorGarageOpener
Blynk 2.0

Introduction
    
This code uses Blynk 2.0 (2023) to control the gates in your home from anywhere.
It uses Blynk library and virtual pins that controls a relay connected to arduino.

The motor controller from the garage door should have two pins that accept an external command that will open and close the door.
Our project will close a circuit for a very short time, creating a short at these pins and the door will know to open or close.

You can use and modify this code as you want to satisfy your needs.

Goals
    
At the end of this guide you will learn how to use blynk dashboard, how to code the Arduino board and how to use the relays for opening from the app the gates.

Requirements
    
An Arduino Uno 
Arduino Ethernet Shield 
Relay board x3
Arduino IDE
Blynk dashboard

Step 1: 

Install Arduino IDE Libraries
If you are not familiar with Arduino IDE please start here: [https://www.arduino.cc/en/Guide/HomePage](https://www.arduino.cc/en/Guide)
Download and install the BLYNK app to your phone and libraries to your PC for Arduino IDE. Tutorial here: [http://www.blynk.cc/getting-started/](https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk)

Step 2:

Create blynk datastreams and create the buttons in the phone app.

Step 3: 

Set-up IDE and Program
In IDE, open the project downloaded from github.
In IDE, Copy and Paste the "auth key", "project template" and "device name" from blynk dashboard

In IDE, go to tools - boards - "arduino uno"
Plug FTDI into computer.
Pick your COM port in IDE software.
Load sketch to your arduino.

