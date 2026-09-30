#include <CapacitiveSensor.h> 

CapacitiveSensor Sensor = CapacitiveSensor(XXX, XXX); /* Die richtigen Werte für XXX einsetzen */

void setup() { 
  Serial.begin(9600); 
} 
 
void loop() { 
  /* durch Berührung soll im folgenden eine blaue LED eingeschaltet werden */

  val = Sensor.capacitiveSensor(30);
  delay(10); 
}
