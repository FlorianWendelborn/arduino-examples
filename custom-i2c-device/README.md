# Custom I²C Device

This code allows you to connect two Arduino Nanos using I²C and implements a state-based return system in which the master can send the slave what sensor he wishes to query and the slave then answeres the next request with the required data.

![Slave Device](https://i.imgur.com/jbbwcIm.jpg)

## Hardware

I used 2 Arduino Nanos, connected via I²C (GND ↔ GND, A4 ↔ A4 + 1kΩ pull-up resistor to 5V, A5 ↔ A5 + 1kΩ pull-up resistor to 5V)

As example sensors I used a PIR connected to D2 and a photoresistor connected to A0 (both on slave device).

## Images

View all available images on [imgur](https://imgur.com/a/pZYMF).
