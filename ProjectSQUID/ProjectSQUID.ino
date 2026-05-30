#include <LiquidCrystal.h>
#include <AccelStepper.h> // Switched to AccelStepper for non-blocking multi-motor control

// --- LCD SETUP ---
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// --- TWO STEPPER MOTORS SETUP ---
// Using FULL4WIRE mode (1) for 28BYJ-48 stepper motors
// Note pin sequence 8, 10, 9, 11 and 1, 3, 2, A4 due to how 28BYJ-48 coils pair
AccelStepper motor1(AccelStepper::FULL4WIRE, 8, 10, 9, 11);
AccelStepper motor2(AccelStepper::FULL4WIRE, 1, 3, 2, A4); // Repurposed pins for Motor 2

// --- SENSOR PINS ---
const int turbidityPin = A0;
const int trigPin = A1;
const int echoPin = A2;

// --- OUTPUT PINS ---
const int buzzerPin = 12;
const int alertLED = 13;
const int statusLED = A3;

// --- THRESHOLDS & CALIBRATION ---
const int turbidityThreshold = 500;
const int distanceThreshold = 20;

// --- TIMING VARIABLES (Non-blocking) ---
unsigned long lastUpdate = 0;
const long updateInterval = 500;    // Sample sensors & refresh LCD every 500ms

unsigned long lastSerialPrint = 0;
const long serialInterval = 15000;  // Print telemetry & advanced debug data every 15s

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(alertLED, OUTPUT);
  pinMode(statusLED, OUTPUT);

  digitalWrite(statusLED, HIGH);

  // Configure Motor 1 (Clockwise Continuous)
  motor1.setMaxSpeed(500.0);
  motor1.setSpeed(300.0); // Positive value means clockwise execution

  // Configure Motor 2 (Clockwise Continuous)
  motor2.setMaxSpeed(500.0);
  motor2.setSpeed(300.0); // Positive value means clockwise execution

  // Startup Splash Screen
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Abyssal Squid");
  lcd.setCursor(0, 1);
  lcd.print("Initiating...");
  
  tone(buzzerPin, 1200, 200);
  delay(2000); 
  lcd.clear();

  Serial.println(F("=========================================="));
  Serial.println(F("SYSTEM BOOT: Abyssal Squid Initialized"));
  Serial.println(F("=========================================="));
}

void loop() {
  // FASTEST LOOP: Keep both motors spinning constantly background style
  motor1.runSpeed();
  motor2.runSpeed();

  unsigned long currentMillis = millis();

  // 1. MID-SPEED LOOP: Sensor updates & Alert Handling (Every 500ms)
  if (currentMillis - lastUpdate >= updateInterval) {
    lastUpdate = currentMillis;

    int turbidityRaw = readAverageTurbidity();
    long distance = getDistanceCM();
    bool pollutionDetected = false;

    // Detection logic
    if (turbidityRaw > turbidityThreshold || (distance < distanceThreshold && distance > 0)) {
      pollutionDetected = true;
    }

    // Update Display Content
    updateDisplay(distance, turbidityRaw, pollutionDetected);

    // Hardware Actions
    if (pollutionDetected) {
      digitalWrite(alertLED, HIGH);
      tone(buzzerPin, 1500);
    } else {
      digitalWrite(alertLED, LOW);
      noTone(buzzerPin);
    }
  }

  // 2. SLOW LOOP: Advanced Serial Debug Reporting (Every 15 Seconds)
  if (currentMillis - lastSerialPrint >= serialInterval) {
    lastSerialPrint = currentMillis;
    
    // Grab latest readings safely for printing
    int debugTurbidity = readAverageTurbidity();
    long debugDistance = getDistanceCM();
    bool debugAlert = (debugTurbidity > turbidityThreshold || (debugDistance < distanceThreshold && debugDistance > 0));
    
    logAdvancedDebug(debugTurbidity, debugDistance, debugAlert, currentMillis);
  }
}

// --- CORE FUNCTIONS ---

int readAverageTurbidity() {
  long total = 0;
  for (int i = 0; i < 10; i++) {
    total += analogRead(turbidityPin);
    delayMicroseconds(500); 
  }
  return total / 10;
}

long getDistanceCM() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); 
  if (duration == 0) return -1; 

  return duration * 0.034 / 2;
}

void updateDisplay(long dist, int turb, bool alert) {
  lcd.setCursor(0, 0);
  lcd.print("D:");
  if (dist > 0) {
    lcd.print(dist);
    lcd.print("cm ");
  } else {
    lcd.print("Err  ");
  }
  
  lcd.print("T:");
  lcd.print(turb);
  lcd.print("    "); 

  lcd.setCursor(0, 1);
  if (alert) {
    lcd.print("PLASTIC DETECTED");
  } else {
    lcd.print("Water Stable    "); 
  }
}

// --- ADVANCED DEBUGGING FUNCTIONS ---

int getFreeRam() {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

void logAdvancedDebug(int turb, long dist, bool alert, unsigned long uptimeMs) {
  Serial.println(F("\n--- [ADVANCED SYSTEM DIAGNOSTICS] ---"));
  
  Serial.print(F("Uptime: "));
  Serial.print(uptimeMs / 1000);
  Serial.println(F(" seconds"));

  Serial.print(F("Sensors -> Turbidity Raw: "));
  Serial.print(turb);
  Serial.print(F(" (Threshold: "));
  Serial.print(turbidityThreshold);
  Serial.print(F(") | Distance: "));
  if(dist > 0) {
    Serial.print(dist);
    Serial.println(F(" cm"));
  } else {
    Serial.println(F("FAULT/OUT-OF-RANGE"));
  }

  Serial.print(F("System Status -> Threat Flag: "));
  Serial.print(alert ? F("CRITICAL [POLUTION DETECTED]") : F("NOMINAL"));
  Serial.print(F(" | Alert LED Pin 13: "));
  Serial.print(digitalRead(alertLED) ? F("HIGH") : F("LOW"));
  Serial.print(F(" | Status LED: "));
  Serial.println(digitalRead(statusLED) ? F("ACTIVE") : F("FAULT"));

  Serial.print(F("Memory Profile -> Free SRAM: "));
  Serial.print(getFreeRam());
  Serial.println(F(" Bytes"));
  
  Serial.println(F("--------------------------------------"));
}
