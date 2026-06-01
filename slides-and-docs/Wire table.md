# Abyssal Squid Wiring Diagram

| External Pin / Component | Arduino Pin | Breadboard / Notes |
| :--- | :--- | :--- |
| **Power Infrastructure** | | |
| N/A | 5V pin | + rail (5V rail) |
| N/A | GND pin | - rail (GND rail) |
| **Turbidity Sensor** | | |
| + Pin | N/A | 5V rail |
| - Pin | N/A | GND rail |
| Signal Pin | A0 analog pin | Analog input |
| **HC-SR04 Ultrasonic Sensor** | | |
| VCC | N/A | 5V rail |
| GND | N/A | GND rail |
| TRIG | A1 analog pin | |
| ECHO | A2 analog pin | |
| **16x2 LCD (Non-I2C)** | | |
| VSS (Pin 1) | N/A | GND rail |
| VDD (Pin 2) | N/A | 5V rail |
| VO (Pin 3) | N/A | Potentiometer center pin |
| RS (Pin 4) | Digital 2 | |
| RW (Pin 5) | N/A | GND rail |
| E (Pin 6) | Digital 3 | |
| D4 (Pin 11) | Digital 4 | |
| D5 (Pin 12) | Digital 5 | |
| D6 (Pin 13) | Digital 6 | |
| D7 (Pin 14) | Digital 7 | |
| A (Pin 15) | N/A | 5V rail through 220–330 Ω resistor |
| K (Pin 16) | N/A | GND rail |
| **10kΩ Potentiometer** | | |
| Pin 1 | N/A | 5V rail |
| Pin 2 (Center) | N/A | LCD VO pin |
| Pin 3 | N/A | GND rail |
| **Piezo Buzzer** | | |
| + | Digital 12 | |
| - | N/A | GND rail |

## Matching Stepper Definitions

```cpp
// Motor 1
AccelStepper motor1(
  AccelStepper::FULL4WIRE,
  8, 10, 9, 11
);

// Motor 2
AccelStepper motor2(
  AccelStepper::FULL4WIRE,
  A3, A5, A4, 13
);
```

## Power Layout

```text
Arduino 5V
 ├─ LCD VDD
 ├─ Turbidity Sensor +
 ├─ HC-SR04 VCC
 └─ Potentiometer Pin 1

Arduino GND
 ├─ LCD VSS
 ├─ LCD RW
 ├─ LCD K
 ├─ Turbidity Sensor -
 ├─ HC-SR04 GND
 ├─ Buzzer -
 └─ Potentiometer Pin 3

External 5V Supply (+)
 ├─ ULN2003 Driver #1 VCC
 └─ ULN2003 Driver #2 VCC

External 5V Supply (-)
 ├─ ULN2003 Driver #1 GND
 ├─ ULN2003 Driver #2 GND
 └─ Arduino GND
```
