#include <CapacitiveSensor.h>

CapacitiveSensor Sensor = CapacitiveSensor(4, 6);

const int ledPin = 12;
const long thresholdOn = 1000;
const long thresholdOff = 800;

bool touched = false;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Messwert des kapazitiven Sensors einlesen
  long val = Sensor.capacitiveSensor(30);
  Serial.println(val);

  // Berührung mit Hysterese erkennen
  if (val >= thresholdOn) {
    touched = true;
  } else if (val <= thresholdOff) {
    touched = false;
  }

  // Bei Berührung LED blinken lassen
  if (touched) {
    digitalWrite(ledPin, !digitalRead(ledPin));
    delay(500);
  } else {
    digitalWrite(ledPin, LOW);
    delay(10);
  }
}
