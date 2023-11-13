
/*
Servo orange an Pin D9
Servo braun an Pin GND
Seervo rot an Pin 5V
// --- //
Sensor GND an Pin GND
Sensor Echo an Pin 2
Sensor Trig an Pin 3
Sensor VCC an Pin 5V
*/

// DISTANZSENSOR
// distanzsensor bibliothek
#include <Arduino.h>
#include <Simple_HCSR04.h>

// sensor objekt erstellen
Simple_HCSR04 *sensor;

// sensor pins angeben
const int ECHO_PIN = 2;  /// the pin at which the sensor echo is connected
const int TRIG_PIN = 3;  /// the pin at which the sensor trig is connected

// wie oft gemessen wird in millisekunden
int delayTime = 250;
// wo wird gestoppt? schwellenwert in CM
int stopDist = 40;

// SERVOR MOTOR
// motor bibliothek
#include <Servo.h>

// werte für drehung rechts, links und mitte angeben
int right = 30;
int left = 180;
int middle = 100;

// ein servo objekt erstellen
Servo myservo;

void setup() {
  // serielle verbindung herstellen
  Serial.begin(9600);
  // servo objekt spezifizieren
  sensor = new Simple_HCSR04(ECHO_PIN, TRIG_PIN);
  // servo an pin 9 angeschlossen
  myservo.attach(9);
  // servo in position mitte bringen, ausgangspunkt
  delay(2500);
  myservo.write(middle);
}

void loop() {
  // MESSEN (default)
  // distanz messen
  unsigned long distance = sensor->measure()->cm();
  delay(delayTime);
  // print
  Serial.println(distance);

  // STOPPEN (special case)
  // schauen ob die distanz unter dem schwellenwert liegt
  if (distance < stopDist) {
    // RECHTS MESSEN
    // nach rechts drehen und messen
    myservo.write(right);
    delay(500);
    unsigned long distRight = sensor->measure()->cm();
    delay(delayTime);
    Serial.print("Rechts: ");
    Serial.println(distRight);
    // LINKS MESSEN
    // nach links drehen und messen
    myservo.write(left);
    delay(500);
    unsigned long distLeft = sensor->measure()->cm();
    delay(delayTime);
    Serial.print("Links: ");
    Serial.println(distLeft);
    // ZEICHEN GEBEN
    // messung ist komplett, jetzt wird entschieden
    myservo.write(110);
    delay(100);
    myservo.write(90);
    delay(100);
    myservo.write(110);
    delay(100);
    myservo.write(90);
    delay(100);
    // VERGLEICHEN UND ANZEIGEN
    // checken welche seite mehr Raum hat, dann für 5 sek dort hin zeigen
    if (distRight > distLeft) {
      myservo.write(right);
      delay(2500);
    } else if (distRight < distLeft) {
      myservo.write(left);
      delay(2500);
    } else {
      myservo.write(middle);
      delay(2500);
    }
    // RESET: wieder in die mitte zeigen und weiter mit dem programm
    myservo.write(middle);
    delay(500);
  }
}
