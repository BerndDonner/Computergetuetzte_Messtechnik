#include <CapacitiveSensor.h> 

CapacitiveSensor Sensor = CapacitiveSensor(4, 6); /* sendpin 3; receivepin 5 */
int ledPinBlue = 13; /* LED auf Pin 2 */
bool anwesend = false;



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

  
  
  
  if ((anwesend == true) && (val < 70))
  {
    digitalWrite(ledPinBlue, LOW);   // sets the LED off
    anwesend = false;
  }
  else if ((anwesend == false) && (val >= 150))
  {
    
    //digitalWrite(ledPinBlue, !digitalRead(ledPinBlue));
    //Wenn an  dann ausschalten und 500ms warten,
    //Wenn aus dann einschalten und 500ms warten,
  
    if (digitalRead(ledPinBlue) == HIGH)
    {
      digitalWrite(ledPinBlue, LOW);
    } else {
      digitalWrite(ledPinBlue, HIGH);
    }
    delay(500);
    anwesend = true;
  }
  else if ((anwesend == true) && (val >= 70))
  {
    if (digitalRead(ledPinBlue) == HIGH)
    {
      digitalWrite(ledPinBlue, LOW);
    } else {
      digitalWrite(ledPinBlue, HIGH);
    }
    delay(500);
  }

  delay(10); 
}
