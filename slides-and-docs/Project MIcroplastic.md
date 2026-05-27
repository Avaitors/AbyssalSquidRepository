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


[image1]: <data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABQAAAAQAQMAAAAs1s1YAAAABlBMVEUAAABER0byc6G0AAAAAXRSTlMAQObYZgAAAB9JREFUeF5jYEAD9h8YmEA0MwOYZmSWWQjhs4H56BgAT4ECDeGaeV4AAAAASUVORK5CYII=>

[image2]: <data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABQAAAAQCAYAAAAWGF8bAAAAx0lEQVR4Xu2TYRHCMAyFKwEJSEBCjyVpXIAEHIATJCBhEpCAhEkA0tEtTVcod/zku8ufvDR7fduc+/NTmHkNge6t1QU82x0TQHRMg8i4t7rGI266QJc0b3Xt7Gq1d3jvV69zQyZUn9QAMHg5K8vnpuTBtFNzXzEawj5rKL0AmE7pFku3KXrR8jPHeaRELy00m2NhuYIstT1hPB8OqoF9dKmDbQQD3ZZcTznIJ2S1GmlZ5k4DhENa3FrbDz+Bk5eTIqhVdFbJ8wG0lJX5M/zhmwAAAABJRU5ErkJggg==>
