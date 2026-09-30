#include <CapacitiveSensor.h>

// XXX durch die verwendeten Arduino-Pins ersetzen
CapacitiveSensor Sensor = CapacitiveSensor(XXX, XXX);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Messwert des kapazitiven Sensors einlesen
  long val = Sensor.capacitiveSensor(30);

  // Hier soll später die Auswertung des Messwerts erfolgen.
  // Bei einer Berührung soll eine blaue LED eingeschaltet werden.

  delay(10);
}
