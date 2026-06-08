#include <CapacitiveSensor.h>

constexpr uint8_t SEND_PIN = 4;
constexpr uint8_t RECEIVE_PIN = 6;
constexpr uint8_t LED_PIN = 13;

constexpr int32_t SCHWELLWERT = 1000;
constexpr uint32_t BLINK_INTERVAL_MS = 1000;

CapacitiveSensor sensor(SEND_PIN, RECEIVE_PIN);

bool blinkAktiv = false;
uint32_t letzteBlinkZeit = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  int32_t messwert = sensor.capacitiveSensor(30);

  Serial.println(messwert);

  if (messwert >= SCHWELLWERT) {
    blinkeLed();
  } else {
    schalteLedAus();
  }

  delay(10);
}

void blinkeLed()
{
  uint32_t aktuelleZeit = millis();

  if (!blinkAktiv) {
    letzteBlinkZeit = aktuelleZeit;
    blinkAktiv = true;
  }

  if (aktuelleZeit - letzteBlinkZeit >= BLINK_INTERVAL_MS) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    letzteBlinkZeit = aktuelleZeit;
  }
}

void schalteLedAus()
{
  blinkAktiv = false;
  digitalWrite(LED_PIN, LOW);
}



