#include <M5StickCPlus.h>
#include "DHT.h"
#define DHTTYPE DHT22

const int DHTPIN = 26;

DHT dht(DHTPIN, DHTTYPE);

void setup(){
  M5.begin();
  M5.Lcd.setTextSize(2);
  M5.Lcd.setRotation(3);

  Serial.begin(115200);
  dht.begin();
}


void loop() {

   // Wait a few seconds between measurements.
   delay(2000);
   M5.Lcd.fillScreen(BLACK);
   M5.Lcd.setCursor(0, 15);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float humidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  // Compute heat index in Celsius (isFahreheit = false)
  float heatIndex = dht.computeHeatIndex(temperature, humidity, false);

  M5.Lcd.print(F("Humidity: "));
  M5.Lcd.print(humidity);
  M5.Lcd.println(F("%"));
  M5.Lcd.println();
  M5.Lcd.print(F("Temperature: "));
  M5.Lcd.print(temperature);
  M5.Lcd.println(F(" C"));
  M5.Lcd.println();
  M5.Lcd.print(F("Heat index: "));
  M5.Lcd.print(heatIndex);
  M5.Lcd.println(F(" C"));

  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(temperature);
  Serial.print(F("°C "));
  Serial.print(F(" Heat index: "));
  Serial.print(heatIndex);
  Serial.println(F("°C"));
}
