# **Wiring Diagram**


| External Pin / Component | Arduino Pin | Breadboard / Notes |
| :--- | :--- | :--- |
| **Power Infrastructure** | | |
| N/A | 5V pin | + rail (hereby referred to as “5V rail”) |
| N/A | GND pin next to 5V pin | - rail (hereby referred to as “GND rail”) |
| **Turbidity Sensor** | | |
| + Pin | N/A | 5V rail |
| - Pin | N/A | GND rail |
| D/A Pin | A0 analog pin | N/A |
| **HC-SR04 Ultrasonic Sensor** | | |
| VCC | N/A | 5V rail |
| GND | N/A | GND rail |
| TRIG | A1 analog pin | N/A |
| ECHO | A2 analog pin | N/A |
| **16x2 LCD (Non-I2C)** | | |
| VSS | N/A | GND rail |
| VCC | N/A | 5V rail |
| VO | N/A | Pot 2 of potentiometer |
| RS | Digital 2 | N/A |
| E | Digital 3 | N/A |
| D4 | Digital 4 | N/A |
| D5 | Digital 5 | N/A |
| D6 | Digital 6 | N/A |
| D7 | Digital 7 | N/A |
| A | N/A | 5V rail (connect through 330 Ω resistor) |
| K | N/A | GND rail |
| **Potentiometer** | | |
| Pot 1 | N/A | 5V rail |
| Pot 2 | N/A | Connected to LCD VO pin |
| Pot 3 | N/A | GND rail |
| **Piezo Buzzer** | | |
| + | Digital 12 | N/A |
| - | N/A | GND rail |
| **Alert LED** | | |
| Anode (+) | Digital 13 | Connect through 220 Ω resistor |
| Cathode (-) | N/A | GND rail |
| **Status LED** | | |
| Anode (+) | A3 analog pin | Connect through 220 Ω resistor |
| Cathode (-) | N/A | GND rail |
| **Stepper Motor 1 Driver (ULN2003)** | | |
| VCC (+) | N/A | 5V rail (External 5V supply recommended) |
| GND (-) | N/A | GND rail |
| IN1 | Digital 8 | N/A |
| IN2 | Digital 9 | N/A |
| IN3 | Digital 10 | N/A |
| IN4 | Digital 11 | N/A |
| **Stepper Motor 2 Driver (ULN2003)** | | |
| VCC (+) | N/A | 5V rail (External 5V supply recommended) |
| GND (-) | N/A | GND rail |
| IN1 | A4 analog pin (Digital 18) | N/A |
| IN2 | A5 analog pin (Digital 19) | N/A |
| IN3 | Digital 0 (RX) | N/A |
| IN4 | Digital 1 (TX) | N/A |
