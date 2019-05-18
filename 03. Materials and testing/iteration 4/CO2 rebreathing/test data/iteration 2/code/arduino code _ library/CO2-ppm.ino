// The load resistance on the board
#define RLOAD 22.0
// Calibration resistance at atmospheric CO2 level
#define RZERO 879.13 
#include "MQ135.h" 
MQ135 gasSensor = MQ135(A6); 
int val; 
int sensorPin = A6; 
int sensorValue = 0; 
int sl=0;
void setup() { 
  Serial.begin(9600);
  pinMode(sensorPin, INPUT); 
} 

void loop() { 
  Serial.print (sl);
  val = analogRead(A6); 
  Serial.print ("raw = "); 
  Serial.print (" \t");
  Serial.print (val);
  Serial.print (" \t");
  float zero = gasSensor.getRZero(); 
  Serial.print ("rzero: "); 
  Serial.print (" \t");
  Serial.print (zero); 
  Serial.print (" \t");
  float ppm = 0;
  for (int i=0; i<5000; i++){
    ppm = ppm + gasSensor.getPPM();
  }
  ppm = ppm/5000;
  Serial.print ("CO2 ppm: "); 
  Serial.print (" \t");
  Serial.print (ppm); 
  Serial.print (" \t");
  Serial.println (); 
  sl++;
  delay(100); 
}
