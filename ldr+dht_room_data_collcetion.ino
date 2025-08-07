#include <ConsentiumThings.h>
#include <DHT.h>

#define DHT_PIN 4
#define DHT_TYP DHT11
const int ldrPin = 34;

// Create ConsentiumThings object
ConsentiumThingsDalton board;

// DHT11 SETUP
DHT dht(DHT_PIN, DHT_TYP);

// WiFi credentials
const char *ssid = "VENOM";       // Replace with your WiFi SSID
const char *pass = "RDrdRDrd!^16";   // Replace with your WiFi password

// API keys
const char *SendApiKey = "5e4fca227ad0dbfd7c507588cdc8567b";       // API key for sending data
const char *BoardApiKey = "312df72b15e7cfdb"; // API key for the board

// Data transmission and update intervals
constexpr int interval = 5000;        // Data transmission interval (10 seconds)

void setup() {
  Serial.begin(115200);
  // Consentium IoT branding message
  Serial.println("Consentium IoT - Edge Board Library");
  Serial.println("-----------------------------------------");
  Serial.println("Initializing ConsentiumThings Board...");

  // Begin WiFi connection
  board.initWiFi(ssid, pass);

  //Initialise the board for sending data
  board.beginSend(SendApiKey, BoardApiKey);

  dht.begin();

  Serial.println("ConsentiumThings Board Initialized!");
  Serial.println("-----------------------------------------");
  Serial.println();
}

void loop() 
{
  // Prepare sample sensor data
  float ldr = analogRead(ldrPin);
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  
  if (isnan(t) || isnan(h))
  {
    Serial.println("ERROE !");
    return;
  }
  Serial.print("light:");
  Serial.println(ldr);
  Serial.print("Temp:");
  Serial.println(t);
  Serial.print("Humidity:");
  Serial.println(h);

  vector<double> sensorValues = {ldr, t, h}; // Sensor data vector
  const char* sensorInfo[] = {"Light Intensity", "Temperature", "Humidity"}; // Sensor information array


  board.sendData(sensorValues, sensorInfo, LOW_PRE); // Send with low precision

  // Wait before the next data transmission
  delay(interval);
}
