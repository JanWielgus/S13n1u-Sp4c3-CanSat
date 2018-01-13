#include <TinyGPS++.h>
#include <SoftwareSerial.h>

TinyGPSPlus gps;
SoftwareSerial ss(5, 4);

void setup()
{  Serial.begin(9600);
  ss.begin(9600);
}


void loop()
{
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    
    Serial.print("|S:");
    Serial.print(gps.satellites.value());
    Serial.println("|============");
    
    Serial.println(" vvvv coords vvvv");
    Serial.print(gps.location.lat(), 5);
    Serial.print(" ");
    Serial.println(gps.location.lng(), 5);
    Serial.println("-----------------");
    
    Serial.print("ALT=");
    Serial.print(gps.altitude.meters());
    Serial.println("m");
    Serial.print("SPD=");
    Serial.print(gps.speed.kmph());
    Serial.println("kph");
    
    smartDelay(950);


}

static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}
