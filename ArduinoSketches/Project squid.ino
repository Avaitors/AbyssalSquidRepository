#include <LiquidCrystal.h>
#include <Stepper.h>

// --- LCD SETUP ---
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// --- STEPPER SETUP ---
const int stepsPerRevolution = 2048;
// Sequence updated to 8, 9, 10, 11 for standard 28BYJ-48 stepper drivers (ULN2003)
Stepper squidMotor(stepsPerRevolution, 8, 10, 9, 11); 

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
const long updateInterval = 500; // Sample every 500ms

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(alertLED, OUTPUT);
  pinMode(statusLED, OUTPUT);

  digitalWrite(statusLED, HIGH);

  // Set motor speed to a functional rate (10-15 RPM is standard for 28BYJ-48)
  squidMotor.setSpeed(12);

  // Startup Splash Screen
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Abyssal Squid");
  lcd.setCursor(0, 1);
  lcd.print("Initiating...");
  
  tone(buzzerPin, 1200, 200);
  delay(2000); // Kept short only for initialization display visibility
  lcd.clear();
}

void loop() {
  unsigned long currentMillis = millis();

  // Run sensor checks and display updates at regular intervals without stopping code execution
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
      
      // Step the motor. Note: Large step values here will briefly pause sensor tracking.
      squidMotor.step(128); 
    } else {
      digitalWrite(alertLED, LOW);
      noTone(buzzerPin);
    }

    // Serial Logging
    logToSerial(turbidityRaw, distance, pollutionDetected);
  }
}

// --- CORE FUNCTIONS ---

int readAverageTurbidity() {
  long total = 0;
  for (int i = 0; i < 10; i++) {
    total += analogRead(turbidityPin);
    delayMicroseconds(500); // Reduced delay to prevent execution lag
  }
  return total / 10;
}

long getDistanceCM() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Standard trigger pulse width is 10 microseconds
  digitalWrite(trigPin, LOW);

  // Timeout added at 30000µs (~500cm max range) to avoid infinite lockups if echo fails
  long duration = pulseIn(echoPin, HIGH, 30000); 
  if (duration == 0) return -1; // Out of range flag

  return duration * 0.034 / 2;
}

void updateDisplay(long dist, int turb, bool alert) {
  // Line 1: Real-time Data
  lcd.setCursor(0, 0);
  lcd.print("D:");
  if (dist > 0) {
    lcd.print(dist);
    lcd.print("cm ");
  } else {
    lcd.print("Error ");
  }
  
  lcd.print("T:");
  lcd.print(turb);
  lcd.print("    "); // Padding clears old residual numbers

  // Line 2: System Status
  lcd.setCursor(0, 1);
  if (alert) {
    lcd.print("PLASTIC DETECTED");
  } else {
    lcd.print("Water Stable    "); // Padding clears "PLASTIC DETECTED" string length
  }
}

void logToSerial(int turb, long dist, bool alert) {
  Serial.print("Turbidity: ");
  Serial.print(turb);
  Serial.print(" | Distance: ");
  Serial.print(dist);
  Serial.print(" cm");
  if (alert) Serial.print(" | DETECTED");
  Serial.println();
}
