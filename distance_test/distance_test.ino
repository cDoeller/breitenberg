// simple HC SR 04 Lib Test

#include <Arduino.h>
#include <Simple_HCSR04.h>

const int ECHO_PIN = 2; /// the pin at which the sensor echo is connected
const int TRIG_PIN = 3; /// the pin at which the sensor trig is connected

Simple_HCSR04 *sensor;

void setup()
{
  Serial.begin(9600);

  // create sensor object
  sensor = new Simple_HCSR04(ECHO_PIN, TRIG_PIN);
}

void loop()
{
  unsigned long distance = sensor->measure()->cm();

  Serial.print("distance: ");
  Serial.print(distance);
  Serial.print("cm\n");
}
