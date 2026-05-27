# 🫥 Main Tab

# Project MICROPLASTIC:

- [ ] Make video (See this link for guidelines:[LG Centum System™ USP Film](https://www.youtube.com/watch?v=Mj2CQJWqLho))   
- [x] ~~MAKE AN ARDUINO THAT WORKS and can IDENTIFY MICROPLASTICS~~

# 👏 Arduino: Project DEVIN and PRATYUSH

| Arduino |  |  |
| :---- | :---- | :---- |
| ![No type][image1] Parts | ![No type][image1] Description | ![Dropdowns][image2] On hand? |
| Arduino UNO R3+ | Our Main Hub, the entire code system | Yes |
| Ultrasonic Sensor | Detects large plastics | Yes |
| Turbidity Sensor | Detects fogginess and cloudiness | Yes |
| Buzzer | Beeps when pollution detection boolean is true | Yes |
| LCD 16x2 Display | Displays status text using `lcd.print()` | Yes |
| Breadboard | Used in place of soldering, due to the showing being a prototype | Yes |

* **Turbidity Sensor (SKU:SEN0189):** This is the most common tool. It uses an LED and a phototransistor to measure how much light is blocked by particles in the water.  
* **Micro SD Card Module:** Essential for recording data if you are testing a river or lake over several hours.

### **2\. Plumbing & Sample Handling**

You need a way to pass the water through the sensors without frying the electronics.

* **1" PVC Pipe & Caps:** To build a "test chamber." You’ll drill holes in the sides of the pipe to mount your sensors.  
* **Clear Glass/Acrylic Tubing:** Use this *inside* your test chamber so the light from your sensors can pass through the water.  
* **Waterproof Silicone Sealant:** To keep the water inside the tube and away from the Arduino.  
* **Fine Mesh Sieve (0.3mm):** To pre-filter large debris like sticks or leaves, so your sensor only "sees" micro-sized particles.

### **3\. Construction & Hardware Tools**

* **Soldering Iron & Solder:** To ensure your connections don't vibrate loose if you're taking the device outdoors.  
* **Breadboard & Jumper Wires:** For testing the circuit before you make it permanent.  
* **Heat Shrink Tubing:** To waterproof your wire connections.  
* **Multimeter:** To troubleshoot power issues and check if your sensors are sending the right voltage.  
* **9V Battery or Power Bank:** To make the device portable for field testing.

If you’re using an **Arduino Uno R3**, the biggest thing to know is this:

**An Arduino alone can’t truly identify microplastics** the way a lab instrument can.  
What it *can* do is control sensors, lights, pumps, and collect data for a **basic detection setup**.

## **What you’d need**

### **Core Arduino parts**

* **Arduino Uno R3**  
* **Breadboard**  
* **Jumper wires**  
* **USB cable**  
* **5V power supply** or battery pack if portable

### **Sensing / detection parts**

For a real microplastics project, you’ll usually need one of these approaches:

#### **Option 1: Optical detection setup**

Good for a school project or prototype.

* **High-intensity LED light**  
  * white LED, UV LED, or blue LED depending on method  
* **Light sensor / photodiode / phototransistor**  
* **Resistors**  
* **Optional: small camera module** or external camera  
* **Lens / magnifier** if you want to observe particles  
* **Color filter** or optical filter if using fluorescence

#### **Option 2: Fluorescence-based detection**

Some plastics glow under UV after staining.

* **UV LED**  
* **Fluorescent dye** such as Nile Red  
* **Photodiode or camera**  
* **Dark enclosure** so outside light doesn’t interfere

#### **Option 3: Sample movement / water testing**

If you want to test water samples:

* **Small pump**  
* **Tubing**  
* **Filter membrane**  
* **Small container / sample chamber**  
* **Stirrer or magnetic stirrer** if needed

## **Helpful extra tools**

* **Microscope** or **digital microscope**  
* **3D-printed holder or case**  
* **Black box/enclosure** to block light  
* **Computer with Arduino IDE**  
* **Multimeter**  
* **Soldering iron** and solder if you’re building a more permanent version

## **If you want actual microplastic detection, the best setup is usually**

* **UV/blue light source**  
* **Sample chamber**  
* **Filter/dye system**  
* **Photodiode or camera**  
* **Arduino Uno** to control the LEDs and read sensor values

## **Important note**

If your goal is to **really identify microplastics**, Arduino Uno is mainly for:

* controlling the system  
* reading sensor signals  
* logging data

The “smart” part usually comes from:

* a **camera \+ image processing**  
* or a **specialized optical sensor**  
* or a **lab method like spectroscopy**

## **Simple project version**

If you want a beginner-friendly version, get:

* Arduino Uno R3  
* breadboard \+ jumper wires  
* UV LED  
* photodiode  
* resistors  
* small dark box  
* sample cup/filter  
* laptop with Arduino IDE

If you want, I can also make yo

To build the "SquidClean" prototype using an Arduino Uno R3, you will need a mix of electronics, sensors, and hardware components.

Here is a comprehensive shopping list broken down by category, along with exactly why you need each item based on your code:

---

## **1\. Core Microcontroller & Power**

* **Arduino Uno R3:** The brain of your project.  
* **USB A-to-B Cable:** To upload your code from your computer to the Arduino.  
* **9V Power Adapter or Battery Clip:** To power the project when it isn't plugged into a computer (critical for running the motor).

---

## **2\. Sensors (The "Eyes")**

* **Liquid Turbidity Sensor (e.g., TSW-20M or SEN0189):** This measures water cloudiness. It includes a small sensor probe and an adapter board that connects to your analog pin (A0).  
* **HC-SR04 Ultrasonic Distance Sensor:** This uses sonar to detect objects (like floating plastic) up to 4 meters away. It plugs into pins A1 and A2.

---

## **3\. Actuators & Outputs (The "Body")**

* **28BYJ-48 Stepper Motor with ULN2003 Driver Board:** This is the exact 2048-steps-per-revolution motor your code is configured for. The small green ULN2003 driver board is *required* because the Arduino cannot safely provide enough current to spin the motor directly.  
* **16x2 Character LCD Display (with HD44780 driver):** The standard screen to display your "SquidClean" messages.  
  💡 *Tip:* Buy one **without** an I2C backpack interface, as your current code is written for a direct, 6-pin parallel connection.  
* **10k Ohm Potentiometer:** Crucial for adjusting the contrast of the LCD screen. Without this, your screen might just look blank or completely blocked out.  
* **Active or Passive Piezo Buzzer:** To make the 1200Hz and 1500Hz alarm tones (pin 12).  
* **5mm LEDs (1x Red, 1x Green/Blue):** One for the alert status (pin 13) and one for the power/status indicator (pin A3).

---

## **4\. Prototyping Essentials**

* **Full-Sized Solderless Breadboard:** Gives you plenty of room to map out all your connections safely.  
* **Male-to-Male Jumper Wires:** For connecting the Arduino to the breadboard.  
* **Male-to-Female Jumper Wires:** Necessary for connecting the ultrasonic sensor, turbidity board, and motor driver.  
* **Resistors (220-ohm or 330-ohm):** You will need at least **3** of these (two to protect your LEDs from burning out, and one for the LCD backlight pin).

---

## **https://app.arduino.cc/sketches/386be83c-f076-43b4-9b32-0d08a1df6a30?view-mode=preview**

# inosketch

**`#include <LiquidCrystal.h>`**  
**`#include <Stepper.h>`**

**`// --- LCD SETUP ---`**  
**`LiquidCrystal lcd(2, 3, 4, 5, 6, 7);`**

**`// --- STEPPER SETUP ---`**  
**`const int STEPS_PER_REV = 2048;`**  
**`// Corrected sequence 8-10-9-11 for 28BYJ-48 stepper drivers like ULN2003`**  
**`Stepper squidMotor(STEPS_PER_REV, 8, 10, 9, 11);`**

**`// --- PIN DEFINITIONS ---`**  
**`const int TURBIDITY_PIN = A0;`**  
**`const int TRIG_PIN      = A1;`**  
**`const int ECHO_PIN      = A2;`**  
**`const int BUZZER_PIN    = 12;`**  
**`const int ALERT_LED     = 13;`**  
**`const int STATUS_LED    = A3;`**

**`// --- CALIBRATION THRESHOLDS ---`**  
**`const int TURBIDITY_THRESHOLD = 500;`**  
**`const int DISTANCE_THRESHOLD  = 20;`**

**`// --- STATE MANAGEMENT ---`**  
**`bool lastPollutionState = false;`**  
**`unsigned long lastUpdateTimes = 0;`**  
**`const unsigned long REFRESH_INTERVAL = 500; // Non-blocking loop rate (ms)`**

**`void setup() {`**  
  **`Serial.begin(9600);`**  
  **`lcd.begin(16, 2);`**

  **`pinMode(TRIG_PIN, OUTPUT);`**  
  **`pinMode(ECHO_PIN, INPUT);`**  
  **`pinMode(BUZZER_PIN, OUTPUT);`**  
  **`pinMode(ALERT_LED, OUTPUT);`**  
  **`pinMode(STATUS_LED, OUTPUT);`**

  **`digitalWrite(STATUS_LED, HIGH);`**

  **`// Fixed: Removed the setSpeed(0) bug that disabled the motor`**  
  **`squidMotor.setSpeed(12); // ~12 RPM is optimal for 28BYJ-48 motors`**

  **`// Splash Screen`**  
  **`lcd.clear();`**  
  **`lcd.setCursor(0, 0);`**  
  **`lcd.print("SquidCleanInnov");`**  
  **`lcd.setCursor(0, 1);`**  
  **`lcd.print("Initializing...");`**  
    
  **`tone(BUZZER_PIN, 1200, 200);`**  
  **`delay(3000); // Kept for initial sensor stabilization`**  
  **`lcd.clear();`**  
**`}`**

**`void loop() {`**  
  **`// Non-blocking timer instead of delay(500)`**  
  **`if (millis() - lastUpdateTimes >= REFRESH_INTERVAL) {`**  
    **`lastUpdateTimes = millis();`**

    **`int turbidityRaw = readAverageTurbidity();`**  
    **`long distance = getDistanceCM();`**

    **`// 1. Optimized LCD Refresh (Prevents Flickering)`**  
    **`lcd.setCursor(0, 0);`**  
    **`lcd.print("D:");`**  
    **`lcd.print(distance);`**  
    **`lcd.print("cm   "); // Extra spaces overwrite old leftover characters`**

    **`// 2. Evaluation Logic`**  
    **`bool pollutionDetected = (turbidityRaw > TURBIDITY_THRESHOLD) ||`**   
                             **`(distance < DISTANCE_THRESHOLD && distance > 0);`**

    **`// 3. State-Change Driven Output Actions`**  
    **`if (pollutionDetected) {`**  
      **`digitalWrite(ALERT_LED, HIGH);`**  
      **`tone(BUZZER_PIN, 1500);`**

      **`// Only clear and rewrite the row if the status actually changed`**  
      **`if (!lastPollutionState) {`**  
        **`lcd.setCursor(0, 1);`**  
        **`lcd.print("PLASTIC DETECTED");`**  
      **`}`**

      **`// Stepper Action (Runs smoothly inside the timed interval)`**  
      **`squidMotor.step(256);`**   
    **`}`**   
    **`else {`**  
      **`digitalWrite(ALERT_LED, LOW);`**  
      **`noTone(BUZZER_PIN);`**

      **`if (lastPollutionState) {`**  
        **`lcd.setCursor(0, 1);`**  
        **`lcd.print("Water Stable    "); // Spaces clear out "PLASTIC DETECTED"`**  
      **`}`**  
    **`}`**

    **`lastPollutionState = pollutionDetected;`**

    **`// 4. Structured Serial Logging`**  
    **`logSystemData(turbidityRaw, distance, pollutionDetected);`**  
  **`}`**  
**`}`**

**`// --- CORE UTILITY FUNCTIONS ---`**

**`int readAverageTurbidity() {`**  
  **`long total = 0;`**  
  **`for (int i = 0; i < 10; i++) {`**  
    **`total += analogRead(TURBIDITY_PIN);`**  
    **`delayMicroseconds(100); // Shorter non-blocking friendly delay`**  
  **`}`**  
  **`return total / 10;`**  
**`}`**

**`long getDistanceCM() {`**  
  **`digitalWrite(TRIG_PIN, LOW);`**  
  **`delayMicroseconds(2);`**  
  **`digitalWrite(TRIG_PIN, HIGH);`**  
  **`delayMicroseconds(10); // Standard precise trigger pulse duration`**  
  **`digitalWrite(TRIG_PIN, LOW);`**

  **`// Added timeout (30000us max) to prevent code hanging if sensor disconnects`**  
  **`long duration = pulseIn(ECHO_PIN, HIGH, 30000);`**   
  **`if (duration == 0) return -1; // Error fallback state`**

  **`return duration * 0.034 / 2;`**  
**`}`**

**`void logSystemData(int turbidity, long distance, bool anomaly) {`**  
  **`Serial.print("Turbidity: ");`**  
  **`Serial.print(turbidity);`**  
  **`Serial.print(" | Distance: ");`**  
  **`Serial.print(distance);`**  
  **`Serial.print(" cm");`**  
  **`if (anomaly) Serial.print(" | [!] DETECTED");`**  
  **`Serial.println();`**  
**`}`**

# wiring

# **🦑 SQUIDCLEAN — FULL SYSTEM WIRING MAP (FINAL BUILD VERSION)**

## **🧠 CORE CONTROLLER**

Arduino Uno R3

---

# **🔌 POWER DISTRIBUTION (IMPORTANT FOUNDATION)+**

### **Breadboard Rails:**

* Arduino **5V → Breadboard \+ (red rail)**  
* Arduino **GND → Breadboard – (blue rail)**

### **Rule:**

All components MUST share **common ground**

---

# **🌊 SENSOR SYSTEM**

## **1\. Turbidity Sensor**

DFRobot Turbidity Sensor

| Pin | Connection |
| ----- | ----- |
| VCC | 5V rail |
| GND | GND rail |
| AO | Arduino A0 |

📌 Function: Water clarity / pollution detection

---

## **2\. Ultrasonic Distance Sensor**

HC-SR04 Ultrasonic Sensor

| Pin | Connection |
| ----- | ----- |
| VCC | 5V rail |
| GND | GND rail |
| TRIG | Arduino A1 |
| ECHO | Arduino A2 |

📌 Function: Object / surface detection

---

# **🖥️ DISPLAY SYSTEM**

## **LCD Display (16x2 Parallel)**

C1602A LCD

### **Power:**

| LCD Pin | Connection |
| ----- | ----- |
| VSS | GND rail |
| VDD | 5V rail |
| VO | Middle pin of potentiometer  |

### **Control Pins:**

| LCD Pin | Arduino |
| ----- | ----- |
| RS | D2 |
| E | D3 |

### **Data Pins (4-bit mode):**

| LCD Pin | Arduino |
| ----- | ----- |
| D4 | D4 |
| D5 | D5 |
| D6 | D6 |
| D7 | D7 |

### **Backlight:**

| Pin | Connection |
| ----- | ----- |
| A | 5V via 100Ω or 300Ω resistor |
| K | GND |

---

### **Potentiometer (LCD contrast)**

* Left → 5V rail  
* Right → GND rail  
* Middle → LCD VO pin

---

# **⚙️ MOVEMENT SYSTEM**

## **Stepper Motor \+ Driver**

28BYJ-48 Stepper Motor  
 ULN2003 driver board

### **ULN2003 → Arduino**

| Driver Pin | Arduino Pin |
| ----- | ----- |
| IN1 | D8 |
| IN2 | D10 |
| IN3 | D9 |
| IN4 | D11 |

### **Power:**

| Pin | Connection |
| ----- | ----- |
| VCC | 5V rail |
| GND | GND rail |

📌 Motor plugs directly into driver board

---

# **🔊 OUTPUT SYSTEM**

## **1\. Buzzer**

piezo buzzer

| Pin | Connection |
| ----- | ----- |
| \+ | D12 |
| – | GND rail |

📌 Function: Alarm when plastic detected

---

## **2\. Alert LED**

| Pin | Connection |
| ----- | ----- |
| Anode (+) | D13 (via 100Ω resistor) |
| Cathode (–) | GND rail |

📌 Function: Visual pollution warning

---

## **3\. Status LED**

| Pin | Connection |
| ----- | ----- |
| Anode (+) | A3 |
| Cathode (–) | GND rail |

📌 Function: System ON indicator

[image1]: <data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABQAAAAQAQMAAAAs1s1YAAAABlBMVEUAAABER0byc6G0AAAAAXRSTlMAQObYZgAAAB9JREFUeF5jYEAD9h8YmEA0MwOYZmSWWQjhs4H56BgAT4ECDeGaeV4AAAAASUVORK5CYII=>

[image2]: <data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABQAAAAQCAYAAAAWGF8bAAAAx0lEQVR4Xu2TYRHCMAyFKwEJSEBCjyVpXIAEHIATJCBhEpCAhEkA0tEtTVcod/zku8ufvDR7fduc+/NTmHkNge6t1QU82x0TQHRMg8i4t7rGI266QJc0b3Xt7Gq1d3jvV69zQyZUn9QAMHg5K8vnpuTBtFNzXzEawj5rKL0AmE7pFku3KXrR8jPHeaRELy00m2NhuYIstT1hPB8OqoF9dKmDbQQD3ZZcTznIJ2S1GmlZ5k4DhENa3FrbDz+Bk5eTIqhVdFbJ8wG0lJX5M/zhmwAAAABJRU5ErkJggg==>