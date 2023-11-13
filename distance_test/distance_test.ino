// simple HC SR 04 Lib Test

// library für Sensor einbetten
#include <Arduino.h>
#include <Simple_HCSR04.h>

// pins für den sensor, echo pin an pin D2, trig pin an pin D3
const int ECHO_PIN = 2;
const int TRIG_PIN = 3;

// sensor objekt erstellen
Simple_HCSR04 *sensor;

void setup() {
  // serielle verbindung starten
  Serial.begin(9600);
  // sensor objekt spezifizieren
  sensor = new Simple_HCSR04(ECHO_PIN, TRIG_PIN);
}

void loop() {
  // variable für distanz erstellen und sie mit dem messwert füllen
  unsigned long distance = sensor->measure()->cm();
  // den messwert über die serielle schnittstelle ausgeben
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.print("cm\n");
}
