#include <CapacitiveSensor.h>

CapacitiveSensor Sensor = CapacitiveSensor(4, 6);

const int ledPin = 12;
const long thresholdOn = 1000;
const long thresholdOff = 800;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Messwert des kapazitiven Sensors einlesen
  long val = Sensor.capacitiveSensor(30);
  Serial.println(val);

  // LED mit Hysterese schalten
  if (val >= thresholdOn) {
    digitalWrite(ledPin, HIGH);
  } else if (val <= thresholdOff) {
    digitalWrite(ledPin, LOW);
  }

  delay(10);
}
