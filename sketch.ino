#include <Servo.h>

const byte TRIG_PIN = 7;
const byte ECHO_PIN = 6;
const byte SERVO_PIN = 9;
const byte GREEN_LED = 4;
const byte RED_LED = 3;
const byte BUZZER_PIN = 5;

const float STOP_DISTANCE_CM = 15.0;
const float RESUME_DISTANCE_CM = 18.0;

Servo diverter;
bool objectDetected = false;
bool buzzerAlreadyUsed = false;

float readDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000UL);
  if (duration == 0) return 400.0;  // No echo = treat as clear
  return duration / 58.0;
}

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  diverter.attach(SERVO_PIN);
  diverter.write(0);

  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);
  noTone(BUZZER_PIN);

  Serial.println("SMART CONVEYOR BELT SYSTEM");
  Serial.println("Adjust the HC-SR04 distance slider to test.");
}

void loop() {
  float distance = readDistanceCm();

  // Hysteresis helps prevent rapid switching around the threshold.
  if (!objectDetected && distance <= STOP_DISTANCE_CM) {
    objectDetected = true;
    buzzerAlreadyUsed = false;
  } else if (objectDetected && distance >= RESUME_DISTANCE_CM) {
    objectDetected = false;
    buzzerAlreadyUsed = false;
  }

  if (objectDetected) {
    // Stop simulated belt and activate sorting gate.
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    diverter.write(90);

    if (!buzzerAlreadyUsed) {
      tone(BUZZER_PIN, 1200, 250);
      buzzerAlreadyUsed = true;
    }

    Serial.print("OBJECT DETECTED - BELT STOPPED | Distance: ");
    Serial.print(distance, 1);
    Serial.println(" cm");
  } else {
    // Belt is clear: resume.
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    diverter.write(0);
    noTone(BUZZER_PIN);

    Serial.print("BELT RUNNING | Distance: ");
    Serial.print(distance, 1);
    Serial.println(" cm");
  }

  delay(250);
}


