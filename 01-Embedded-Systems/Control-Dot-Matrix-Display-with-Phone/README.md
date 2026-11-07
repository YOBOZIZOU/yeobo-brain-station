## ESP32 Wi-Fi Controlled Dot Matrix Display

## Project Overview

This project demonstrates how to control a MAX7219 LED dot matrix display using an ESP32 microcontroller and a mobile phone or computer.

The ESP32 connects to a Wi-Fi network and hosts a web server. Users access a web interface through a browser, enter a text message and send it wirelessly to the LED matrix.

The display presents the received message as scrolling text.

## Project Objectives

1.Control an LED dot matrix display wirelessly.

2.Establish Wi-Fi communication using ESP32.

3.Develop a browser-based control interface.

3.Implement HTTP communication.

4.Display user-defined scrolling messages.

## Hardware Components

1.ESP32 development board.

2.MAX7219 FC16 4-in-1 LED dot matrix display.

3.Connecting wires.

4.USB programming cable.

4.Suitable power supply.
5.

## Software and Libraries

1.Arduino IDE.

2.ESP32 Wi-Fi Library.

4.WebServer Library.

5.MD_Parola by MajicDesigns.

5.MD_MAX72XX by MajicDesigns.

6.SPI Library.

## Hardware Connections


MAX7219                    ESP32
DIN                        GPIO 23
CLK                        GPIO 18
CS                          GPIO 5
VCC                          5V
GND                          GND

## System Architecture

Mobile Phone / Computer

↓

Wi-Fi Network

↓

ESP32 Web Server

↓

HTTP Request Processing

↓

MD_Parola and MD_MAX72XX

↓

MAX7219 LED Dot Matrix Display

## System Operation

ESP32 connects to the configured Wi-Fi network.

The ESP32 obtains an IP address.

The HTTP web server starts on port 80.

The user opens the ESP32 IP address in a browser.

A web interface allows the user to enter a message.

The browser sends the message to the ESP32.

The ESP32 updates the LED matrix display.

MD_Parola controls the scrolling animation.

## Engineering Concepts Demonstrated

ESP32 programming.

Wi-Fi communication.

HTTP client-server communication.

Embedded web server development.

SPI communication.

LED matrix interfacing.

## Hardware and software integration.

Future Improvements
Add password-protected web access.
Adjust scrolling speed.
Control display brightness from the browser.
Support multiple messages.
Improve the mobile interface.
Add Wi-Fi access point mode.
## Project Demonstration on YouTube channel: YeoboBrainStation
## Author: Joseph NZUNGIZE

Embedded Systems | IoT | Electronics | Automation
## we do it for you


Embedded Systems | IoT | Electronics | Automation

Smart Repairs, Smarter Futures.
