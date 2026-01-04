#include <WiFi.h>
#include <HTTPClient.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// WiFi credentials
const char* ssid = "ESP_32_WiFi";
const char* password = "08012005";

// ThingSpeak
const char* apiKey = "JSEREE28LGU1O9TO";
const char* server = "http://api.thingspeak.com/update";

// DHT setup
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Timing
unsigned long lastUpdate = 0;
const unsigned long updateInterval = 16000;

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (millis() - lastUpdate >= updateInterval) {
    lastUpdate = millis();

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity)) {
      Serial.println("Failed to read from DHT sensor");
      return;
    }

    Serial.printf("Temperature: %.2f °C | Humidity: %.2f %%\n",
                  temperature, humidity);

    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;

      String url = String(server) +
                   "?api_key=" + apiKey +
                   "&field1=" + String(temperature, 2) +
                   "&field2=" + String(humidity, 2);

      http.begin(url);
      int httpCode = http.GET();

      if (httpCode > 0) {
        Serial.println("Data sent to ThingSpeak successfully");
      } else {
        Serial.println("HTTP request failed");
      }

      http.end();
    } else {
      Serial.println("WiFi disconnected, reconnecting...");
      WiFi.begin(ssid, password);
    }
  }
}
