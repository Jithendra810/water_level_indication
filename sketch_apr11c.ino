// Pin setup
const int waterSensorPin = A0; // Analog pin connected to water sensor
const int ledLow = 13;         // LED for low level
const int ledMedium = 12;      // LED for medium level
const int ledHigh = 11;        // LED for high level
const int buzzer = 8;          // Optional buzzer

int waterLevel = 0;            // Variable to hold sensor reading

void setup() {
  Serial.begin(9600);          // Start Serial Monitor for debugging
  pinMode(ledLow, OUTPUT);
  pinMode(ledMedium, OUTPUT);
  pinMode(ledHigh, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  waterLevel = analogRead(waterSensorPin); // Read sensor value
  Serial.print("Water Level: ");
  Serial.println(waterLevel);              // Display value in Serial Monitor

  // Reset all outputs before setting levels
  digitalWrite(ledLow, LOW);
  digitalWrite(ledMedium, LOW);
  digitalWrite(ledHigh, LOW);
  digitalWrite(buzzer, LOW);

  // Level Logic (adjust thresholds based on your sensor readings)
  if (waterLevel >= 100) {
    digitalWrite(ledLow, HIGH); // Low level detected
  }

  if (waterLevel >= 300) {
    digitalWrite(ledMedium, HIGH); // Medium level detected
  }

  if (waterLevel >= 500) {
    digitalWrite(ledHigh, HIGH);   // High level detected
    digitalWrite(buzzer, HIGH);    // Alert at high water level
  }

  delay(500); // Delay for stability
}
