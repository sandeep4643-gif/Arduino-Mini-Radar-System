
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

// LCD: I2C address 0x20
Adafruit_LiquidCrystal lcd(0x20);

// Pin definitions
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;
const int buzzerPin = 7;

// Servo object
Servo radarServo;

// Variables
long duration;
int distance;

// =================================
// SETUP
// =================================

void setup() {

  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(buzzerPin, LOW);

  radarServo.attach(servoPin);
  radarServo.write(90);

  // Initialize LCD
  lcd.begin(16, 2);
  lcd.setBacklight(1);

  lcd.setCursor(0, 0);
  lcd.print(" MINI RADAR V3 ");

  lcd.setCursor(0, 1);
  lcd.print(" SYSTEM READY ");

  delay(1500);
  lcd.clear();

  Serial.println("MINI RADAR V3.0 STARTED");
}

// =================================
// DISTANCE MEASUREMENT
// =================================

int measureDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 25000);

  if (duration == 0) {
    return -1;
  }

  distance = duration * 0.0343 / 2;

  return distance;
}

// =================================
// LCD AND ALERT SYSTEM
// =================================

void processReadings(int angle, int measuredDistance) {

  lcd.clear();

  if (measuredDistance == -1) {

    digitalWrite(buzzerPin, LOW);

    lcd.setCursor(0, 0);
    lcd.print("NO OBJECT");

    lcd.setCursor(0, 1);
    lcd.print("Angle:");
    lcd.print(angle);
    lcd.print(" deg");

  }

  else if (measuredDistance < 75) {

    digitalWrite(buzzerPin, HIGH);

    lcd.setCursor(0, 0);
    lcd.print("ALERT!!!!");

    lcd.setCursor(0, 1);
    lcd.print("D:");
    lcd.print(measuredDistance);
    lcd.print("cm A:");
    lcd.print(angle);

  }

  else if (measuredDistance <= 200) {

    digitalWrite(buzzerPin, LOW);

    lcd.setCursor(0, 0);
    lcd.print("SAFE DISTANCE");

    lcd.setCursor(0, 1);
    lcd.print("D:");
    lcd.print(measuredDistance);
    lcd.print("cm A:");
    lcd.print(angle);

  }

  else {

    digitalWrite(buzzerPin, LOW);

    lcd.setCursor(0, 0);
    lcd.print("ALL CLEAR");

    lcd.setCursor(0, 1);
    lcd.print("Angle:");
    lcd.print(angle);
    lcd.print(" deg");

  }

  // Serial Monitor
  Serial.print("Angle: ");
  Serial.print(angle);

  Serial.print(" | Distance: ");

  if (measuredDistance == -1) {

    Serial.println("No echo");

  }

  else {

    Serial.print(measuredDistance);
    Serial.print(" cm | ");

    if (measuredDistance < 75) {
      Serial.println("OBJECT DETECTED - ALERT!");
    }

    else if (measuredDistance <= 200) {
      Serial.println("SAFE DISTANCE");
    }

    else {
      Serial.println("ALL CLEAR");
    }
  }
}

// =================================
// MAIN RADAR SCANNING
// =================================

void loop() {

  // Forward scan: 0 to 180 degrees

  for (int angle = 0; angle <= 180; angle += 2) {

    radarServo.write(angle);
    delay(30);

    int measuredDistance = measureDistance();

    processReadings(angle, measuredDistance);
  }

  // Reverse scan: 180 to 0 degrees

  for (int angle = 180; angle >= 0; angle -= 2) {

    radarServo.write(angle);
    delay(30);

    int measuredDistance = measureDistance();

    processReadings(angle, measuredDistance);
  }
}
