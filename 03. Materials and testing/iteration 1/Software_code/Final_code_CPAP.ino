#define DHTTYPE DHT11   // DHT 11         
#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to
#define DHTPIN1 3
#define DHTPIN2 4 
DHT dht(DHTPIN, DHTTYPE);
DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);

void MQ5calculation();   
float Rs5 = 0.0 ;
float RS5_air = 0.0; 
float Ro5 = 0.0;
float sensor_volt = 0.0;
float sensor_volt1 = 0.0;
float sensor_volt2 = 0.0;
float sensorValue=0;
float sensorValue1=0;
float sensorValue2=0;

void MQ2calculation();
float Rs2 = 0.0 ;
float RS2_air = 0.0; 
float Ro2 = 0.0;

void MQ135calculation();
float Rs135 = 0.0 ;
float RS135_air = 0.0; 
float Ro135 = 0.0;

void setup() {
 Serial.begin(115200);
  Serial.print("\n");
  dht.begin();
  dht1.begin();
  dht2.begin();
  voltcalc();
}
void voltcalc()
{
Serial.print(" Calibrating.......");
for(int x = 0 ; x < 32000 ; x++)
    {
        sensorValue = sensorValue + analogRead(A0);
        sensorValue1 = sensorValue1 + analogRead(A1);
        sensorValue2 = sensorValue2 + analogRead(A2);
        
    }
    sensorValue = (sensorValue/32000.0);
    sensorValue1 = (sensorValue1/32000.0);
     sensorValue2 = (sensorValue2/32000.0);

    sensor_volt = (sensorValue/1024)*5.0;
    sensor_volt1 = (sensorValue1/1024)*5.0;
    sensor_volt2 = (sensorValue2/1024)*5.0;

//    MQ5 Calculation
//---------------------------------------------------------------------------------------------       
    Rs5= (5.0-sensor_volt)/sensor_volt; // omit *RL
    Ro5 = Rs5/6.5; // The ratio of RS/R0 is 9.8 in a clear air from Graph (Found using WebPlotDigitizer)
//-------------------------------------------------------------------------------------------------

// MQ2 Calculation
//--------------------------------------------------------------------------------------------
   Rs2= (5.0-sensor_volt1)/sensor_volt1; // omit *RL
   Ro2 = Rs2/9.83; // The ratio of RS/R0 is 9.8 in a clear air from Graph (Found using WebPlotDigitizer)
//---------------------------------------------------------------------------------------------

//  MQ135 Calculation
//--------------------------------------------------------------------------------------------------
 Rs135= (5.0-sensor_volt2)/sensor_volt2; // omit *RL
 Ro135 = Rs135/3.6; // The ratio of RS/R0 is 9.8 in a clear air from Graph (Found using WebPlotDigitizer)

//--------------------------------------------------------------------------------------------------

    delay(100);
}

void loop() 
{
 float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  float h1 = dht1.readHumidity();
  // Read temperature as Celsius (the default)
  float t1 = dht1.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f1 = dht1.readTemperature(true);


  float h2 = dht2.readHumidity();
  // Read temperature as Celsius (the default)
  float t2 = dht2.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f2 = dht2.readTemperature(true);
  // Check if any reads failed and exit early (to try again).

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

    float hif1 = dht1.computeHeatIndex(f, h1);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic1 = dht1.computeHeatIndex(t, h1, false);

  float hif2 = dht.computeHeatIndex(f, h2);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic2 = dht.computeHeatIndex(t, h2, false);
  
  Serial.print("Humidity: ");
  Serial.print(" %\t");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(" %\t");
  Serial.print(t);
  Serial.print(" %\t");
  Serial.println(" *C ");

   Serial.print("Humidity1: ");
  Serial.print(" %\t");
  Serial.print(h1);
  Serial.print(" %\t");
  Serial.print("Temperature1: ");
  Serial.print(" %\t");
  Serial.print(t1);
  Serial.print(" %\t");
  Serial.println(" *C ");

   Serial.print("Humidity2: ");
  Serial.print(" %\t");
  Serial.print(h2);
  Serial.print(" %\t");
  Serial.print("Temperature2: ");
  Serial.print(" %\t");
  Serial.print(t2);
  Serial.print(" %\t");
  Serial.println(" *C ");
MQ5calculation();
MQ2calculation();
MQ135calculation();

 delay(100);
}
void MQ5calculation()
{
float MQ5volt;
float ratio;
float Rs5_air;

int MQ5value = analogRead(A0);
MQ5volt= (float)MQ5value / 1024*5.0;
Rs5_air = (5.0-MQ5volt)/MQ5volt;
ratio = Rs5_air/Ro5;
 float COcurve []  = { 2.3, 0.60, -0.13 } ; 
 float Alcurve [] = {2.3, 0.54, -0.2} ;   
 float Hcurve [] = {2.3, 0.25, -0.25};
 float Hppm =  pow(10,( ((log(ratio)-Hcurve[1])/Hcurve[2])+ Hcurve[0]));
 float COppm = pow(10,( ((log(ratio)-COcurve[1])/COcurve[2]) + COcurve[0]));
 float Alppm = pow(10,( ((log(ratio)-Alcurve[1])/Alcurve[2])+ Alcurve[0]));
 Serial.print("    Carbon Monoxide ppm:\t");
 Serial.print(COppm);
 Serial.print("    Alcohol Content ppm: \t");
 Serial.print(Alppm);
 Serial.print("    Hydrogen Content ppm: ");
 Serial.println(Hppm);
}

void MQ2calculation()
{
float MQ2volt;
float ratio1;
float Rs2_air;

int MQ2value = analogRead(A1);
MQ2volt= (float)MQ2value / 1024*5.0;
Rs2_air = (5.0-MQ2volt)/MQ2volt;
ratio1 = Rs2_air/Ro2;
 float COcurve []  = { 2.3, 0.7, -0.31 } ; 
 float Scurve [] = {2.3, 0.54, -0.44} ;   
 float LPcurve [] = {2.3, 0.23, -0.47};
 float Sppm =  pow(10,( ((log(ratio1)-Scurve[1])/Scurve[2])+ Scurve[0]));
 float COppm = pow(10,( ((log(ratio1)-COcurve[1])/COcurve[2]) + COcurve[0]));
 float LPppm = pow(10,( ((log(ratio1)-LPcurve[1])/LPcurve[2])+ LPcurve[0]));
 Serial.print("    Carbon MonoxideMQ2 ppm:\t");
 Serial.print(COppm);
 Serial.print("    Smoke ContentMQ2 ppm: \t");
 Serial.print(Sppm);
 Serial.print("    LPG ContentMQ2 ppm: ");
 Serial.println(LPppm);
}

void MQ135calculation()
{
float MQ135volt;
float ratio2;
float Rs135_air;

int MQ135value = analogRead(A2);
MQ135volt= (float)MQ135value / 1024*5.0;
Rs135_air = (5.0-MQ135volt)/MQ135volt;
ratio2 = Rs135_air/Ro135;
 float COcurve []  = { 1, 0.45, -0.23 } ; 
 float NH4curve [] = {1, 0.41, -0.4} ;   
 float C6H6curve [] = {1, 0.18, -0.31};
 float NH4ppm =  pow(10,( ((log(ratio2)-NH4curve[1])/NH4curve[2])+ NH4curve[0]));
 float COppm = pow(10,( ((log(ratio2)-COcurve[1])/COcurve[2]) + COcurve[0]));
 float C6H6ppm = pow(10,( ((log(ratio2)-C6H6curve[1])/C6H6curve[2])+ C6H6curve[0]));
 Serial.print("    Carbon MonoxideMQ135 ppm:\t");
 Serial.print(COppm);
 Serial.print("    NH4 ContentMQ135 ppm: \t");
 Serial.print(NH4ppm);
 Serial.print("    Acetone/Benzene ContentMQ135 ppm: ");
 Serial.println(C6H6ppm);
}

