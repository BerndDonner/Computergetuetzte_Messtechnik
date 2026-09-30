#include <CapacitiveSensor.h>

CapacitiveSensor Sensor = CapacitiveSensor(4, 6);

const int ledPin = 12;
const long threshold = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Messwert des kapazitiven Sensors einlesen
  long val = Sensor.capacitiveSensor(30);
  Serial.println(val);

  // LED bei Berührung einschalten
  if (val >= threshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(10);
}
