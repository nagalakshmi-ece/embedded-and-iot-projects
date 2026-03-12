#define BLYNK_TEMPLATE_ID "TMPL3glD_c-x-"
#define BLYNK_TEMPLATE_NAME "DEMO"
#define BLYNK_AUTH_TOKEN "OZ6xre-o_k3v36C4ZQL3yGH9HHvaspeV"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char hotspotname[] = "Nagalakshmi";
char hotspotpass[] = "nannakuthuru";

DHT dht(23, DHT11);  // DHTPIN, DHTTYPE



void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, hotspotname, hotspotpass);
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  Blynk.run();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("H= ");
  Serial.println(h);
  Serial.print("T= ");
  Serial.println(t);
  Blynk.virtualWrite(V1, h);
  Blynk.virtualWrite(V0, t);

}