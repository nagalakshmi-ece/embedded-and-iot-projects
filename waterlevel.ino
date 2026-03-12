#define BLYNK_TEMPLATE_ID "TMPL32Xb7jcFB"
#define BLYNK_TEMPLATE_NAME "Waterlevel"
#define BLYNK_AUTH_TOKEN "WaqawGqEOS8CKTDU7gDyBQDRA0WtlivM"
#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_DEVICE_NAME "SmartHome"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char ssid[] = "Nagalakshmi";
char pass[] = "nannakuthuru";

#define DHTPIN 4
#define DHTTYPE DHT11

#define trig 5
#define echo 18

#define redLED 23
#define greenLED 22
#define yellowLED 21
#define buzzer 19

DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

void sensorData()
{
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, hum);

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  int distance = duration * 0.034 / 2;

  int percentage = map(distance, 30, 5, 0, 100);
  percentage = constrain(percentage,0,100);

  Blynk.virtualWrite(V2, percentage);

  if(percentage > 80)
  digitalWrite(buzzer, HIGH);
  else
  digitalWrite(buzzer, LOW);
}

BLYNK_WRITE(V3)
{
  digitalWrite(redLED, param.asInt());
}

BLYNK_WRITE(V4)
{
  digitalWrite(greenLED, param.asInt());
}

BLYNK_WRITE(V5)
{
  digitalWrite(yellowLED, param.asInt());
}

void setup()
{
  Serial.begin(9600);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  dht.begin();

  timer.setInterval(2000L, sensorData);
}

void loop()
{
  Blynk.run();
  timer.run();
}