#include <DHT.h>

#define DHT_PIN 4
#define DHT_TYP DHT11

const int ldrPin = 34;

int ldr = 0;

// DHT11 SETUP
DHT dht(DHT_PIN, DHT_TYP);

void setup() 
{
  Serial.begin(115200);
  dht.begin();
}

void loop() 
{
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  float ldr = analogRead(ldrPin);

  if (isnan(t) || isnan(h))
  {
    Serial.println("ERROE !");
    return;
  }
  
  Serial.print("Temp:");
  Serial.println(t);
  Serial.print("Humidity:");
  Serial.println(h);
  Serial.print("light:");
  Serial.println(ldr);
  
  delay(1000);
}
