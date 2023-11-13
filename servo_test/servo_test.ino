
// dervo library einbetten
#include <Servo.h>
// servo objekt erstellen
Servo myservo;

void setup() {
  // servo motor an pin 9 anschliessen
  myservo.attach(9);
}

void loop() {
  // servo auf 30 grad fahren
  myservo.write(30);
  // eine sekunde warten
  delay(1000);
  // servo auf 100 grad fahren
  myservo.write(100);
  // eine sekunde warten
  delay(1000);
  //servo auf 180 grad fahren
  myservo.write(180);
  // eine sekunde warten
  delay(1000);
