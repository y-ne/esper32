#include "DHT.h"

#define DHTPIN 4

//#define DHTTYPE DHT11
#define DHTTYPE DHT22
//#define DHTTYPE DHT21

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    Serial.println(F("DHTxx Test"));

    dht.begin();
}

void loop() {
    delay(1000);

    float h = dht.readHumidity();
    
    // Celsius
    float t = dht.readTemperature();
    // Fahrenheit
    float f = dht.readTemperature(true);

    if (isnan(h) || isnan(t) || isnan(f)) {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }

    // Heat Index in Fahrenheit
    float hif = dht.computeHeatIndex(f, h);

    // Heat Index in Celsius
    float hic = dht.computeHeatIndex(t, h, false);

    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.print(f);
    Serial.print(F("°F  Heat index: "));
    Serial.print(hic);
    Serial.print(F("°C "));
    Serial.print(hif);
    Serial.println(F("°F"));
}