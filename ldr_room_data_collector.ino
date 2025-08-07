#include <ConsentiumThings.h>
const int ldr = 34;

// Define firmware version
#define FIRMWARE_VERSION "0.1"

// Create ConsentiumThings object with firmware version
ConsentiumThingsDalton board(FIRMWARE_VERSION);

// WiFi credentials
const char *ssid = "YOUR_WIFI_SSID";       // Replace with your WiFi SSID
const char *pass = "YOUR_WIFI_PASSWORD";   // Replace with your WiFi password

// API keys
const char *SendApiKey = "5e4fca227ad0dbfd7c507588cdc8567b";       // API key for sending data
const char *ReceiveApiKey = "e02849241ffd7355779ef91fcc522db5";    // API key for receiving OTA updates
const char *BoardApiKey = "7295367328c7c33e"; // API key for the board

// Data transmission and update intervals
constexpr int interval = 10000;        // Data transmission interval (10 seconds)
const int updateInterval = 10;       // Check for OTA updates every 100 cycles

// Loop cycle counter
int loopCounter = 0;

void setup() {
  Serial.begin(115200);
  // Consentium IoT branding message
  Serial.println("Consentium IoT - Edge Board Library");
  Serial.println("-----------------------------------------");
  Serial.println("Initializing ConsentiumThings Board...");

  // Begin WiFi connection
  board.initWiFi(ssid, pass);

  // Initialize the board for sending data
  board.beginSend(SendApiKey, BoardApiKey);

  // Enable OTA updates
  board.beginOTA(ReceiveApiKey, BoardApiKey);

  Serial.println("ConsentiumThings Board Initialized!");
  Serial.println("-----------------------------------------");
  Serial.println();
}

void loop() {
  // Prepare sample sensor data
  double light = analogRead(ldr);
  Serial.println(light); // Sample temperature data
  vector<double> sensorValues = {light}; // Sensor data vector
  const char* sensorInfo[] = {"Light Intencity"}; // Sensor information array


  board.sendData(sensorValues, sensorInfo, LOW_PRE); // Send with low precision

  // Increment the loop counter
  loopCounter++;

  // Check for OTA updates periodically
  if (loopCounter >= updateInterval) {
    Serial.println("[Consentium IoT] Checking for OTA updates...");
    board.checkAndPerformUpdate(); // Check and perform OTA updates
    loopCounter = 0; // Reset the counter after checking for updates
  }

  // Wait before the next data transmission
  delay(interval);
}
