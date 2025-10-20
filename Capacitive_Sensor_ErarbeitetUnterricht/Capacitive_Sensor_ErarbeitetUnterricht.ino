#include <CapacitiveSensor.h> 

CapacitiveSensor Sensor = CapacitiveSensor(4, 6); /* sendpin 3; receivepin 5 */
int ledPinBlue = 13; /* LED auf Pin 2 */
bool anwesenheit = false;



void setup() 
{
  Serial.begin(9600);
  pinMode(ledPinBlue, OUTPUT);
} 
 
void loop() 
{ 
  /* Nur duch Berührung mit einem Metallstift soll im folgenden eine blaue LED eingeschaltet werden */
  long val = Sensor.capacitiveSensor(30);

  Serial.println(val);

  // die interne Logik
  if (val < 900)
  {
    anwesenheit = false;
  } else if (val >= 1100)
  {
    anwesenheit = true;
  }
  
  // die Darstellung
  if (anwesenheit == false) {
    digitalWrite(ledPinBlue, LOW);   // sets the LED off
  } else {
    digitalWrite(ledPinBlue, HIGH);   // sets the LED on
    delay(250);
    digitalWrite(ledPinBlue, LOW);   // sets the LED on
    delay(250);
  }


  delay(10); 
}
