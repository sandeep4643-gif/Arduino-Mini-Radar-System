# Arduino-Mini-Radar-System
A simulation-based Mini Radar System built using Arduino Uno, HC-SR04 ultrasonic sensor, SG90 servo motor, I2C LCD, and buzzer in Tinkercad Circuits. Features 180° scanning, real-time distance and angle display, object detection, and proximity alerts.
# Arduino Mini Radar System V3.0

A simulation-based Mini Radar System developed using Arduino Uno and Tinkercad Circuits. The project detects nearby objects using an ultrasonic sensor mounted on a servo motor, measures their distance, and provides real-time feedback through an I2C LCD and buzzer.

## Project Overview

The Mini Radar System simulates the basic working principle of a radar by continuously scanning its surroundings through a 180° servo movement.

An HC-SR04 ultrasonic sensor measures the distance of objects at different angles. The Arduino processes the sensor readings and displays the detected object's distance, angle, and detection status on an LCD.

A buzzer provides an audio alert when an object enters the defined proximity zone.

## Features

- 180° servo-based scanning.
- Ultrasonic distance measurement using HC-SR04.
- Real-time distance and angle display.
- Object detection and proximity monitoring.
- I2C LCD status display.
- Buzzer-based proximity alert.
- Serial Monitor output for sensor readings.

## Components Used

| Component | Purpose |
|---|---|
| Arduino Uno R3 | Main controller |
| HC-SR04 Ultrasonic Sensor | Distance measurement |
| SG90 Servo Motor | Sensor movement and scanning |
| 16×2 I2C LCD | Display information |
| Buzzer | Audio alert |
| Breadboard | Circuit connections |
| Jumper Wires | Interconnections |

## Circuit Connections

| Component | Arduino Pin |
|---|---|
| HC-SR04 TRIG | D9 |
| HC-SR04 ECHO | D10 |
| Servo Signal | D6 |
| Buzzer Positive | D7 |
| LCD SDA | A
