// The load resistance on the board
#define RLOAD 22.0
// Calibration resistance at atmospheric CO2 level
#define RZERO 879.13
#include "MQ135.h"
MQ135 gasSensor = MQ135(A6); // creating gasSensor object in-Circuit
MQ135 gasSensor1 = MQ135(A7); // creating gasSensor object ambient
int val;
int ambCo2 = A7;  // for ambient CO2 sensing
int incCo2 = A6;   // for in-circuit CO2 sensing
int sensorValue = 0;
int sl = 0;
void setup() {
  Serial.begin(9600);
  pinMode(ambCo2, INPUT);
  pinMode(incCo2, INPUT);
}

void loop() {
  float ppm = 0;
  float zero = 0;
  Serial.print (sl);
  sl++;
  Serial.print (" \t");
  ////////////////////////////////////////////////////Ambient CO2 measurement////////////////////////////////
  delay(200);
  val = 0;
  val = analogRead(ambCo2);
  Serial.print ("raw = ");
  Serial.print (" \t");
  Serial.print (val);
  Serial.print (" \t");
  zero = gasSensor1.getRZero();
  for (int i = 0; i < 50; i++) {
    ppm = ppm + gasSensor1.getPPM();
    delay(5);
  }
  ppm = ppm / 50;
  Serial.print ("CO2 ppm: ");
  Serial.print (" \t");
  Serial.print (ppm);
  Serial.print (" \t");
  Serial.print (" \t");
//////////////////////////////////// In-circuit CO2 measurement/////////////////////////
  delay(200);
  val = 0;
  val = analogRead(incCo2);
  Serial.print ("raw = ");
  Serial.print (" \t");
  Serial.print (val);
  Serial.print (" \t");
  zero = gasSensor.getRZero();
  for (int i = 0; i < 50; i++) {
    ppm = ppm + gasSensor.getPPM();
    delay(5);
  }
  ppm = ppm / 50;
  Serial.print ("CO2 ppm: ");
  Serial.print (" \t");
  Serial.print (ppm);
  Serial.print (" \t");
  Serial.println ();
  delay(100);
}

