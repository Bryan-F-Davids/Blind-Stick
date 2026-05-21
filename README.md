# Ultrasonic Distance Alert System using Arduino Uno

This project is an Ultrasonic Distance-Based Buzzer Alert System built using an Arduino Uno, HC-SR04 Ultrasonic Sensor, and an Active Buzzer. The system measures the distance of nearby objects and changes the buzzer alert speed based on how close the object is.

## Components Used

- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- Active Buzzer
- Jumper Wires
- Breadboard

## Pin Connections

| Component | Arduino Pin |
|---|---|
| Ultrasonic TRIG | Pin 9 |
| Ultrasonic ECHO | Pin 10 |
| Buzzer Positive (+) | Pin 7 |
| Buzzer Negative (-) | GND |
| Ultrasonic VCC | 5V |
| Ultrasonic GND | GND |

## Project Logic

The ultrasonic sensor continuously measures the distance between the sensor and an object.

### Buzzer Conditions

- Distance ≤ 21 cm  
  → Buzzer turns ON continuously.

- Distance between 22 cm and 26 cm  
  → Buzzer beeps 6 times per second.

- Distance between 27 cm and 30 cm  
  → Buzzer beeps 3 times per second.

- Distance > 30 cm  
  → Buzzer remains OFF.
