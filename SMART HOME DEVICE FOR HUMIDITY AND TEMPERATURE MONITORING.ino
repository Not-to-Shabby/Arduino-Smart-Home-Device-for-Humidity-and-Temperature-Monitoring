#include <DHT.h>

#define DHTPIN 5       // DHT11 data pin
#define REDPIN 9       // RGB LED red pin
#define GREENPIN 10    // RGB LED green pin
#define BLUEPIN 11     // RGB LED blue pin
#define DHTTYPE DHT11  // DHT sensor type

DHT dht(DHTPIN, DHTTYPE);
bool isBlinking = false;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Map temperature from 15-35°C to LED intensity
  int tempIntensity = map(constrain(temperature, 15, 35), 15, 35, 0, 255);
  // Map humidity from 30-90% to LED intensity
  int humidIntensity = map(constrain(humidity, 30, 90), 30, 90, 0, 255);

  // Normal conditions
  if (temperature >= 20 && temperature <= 25 && humidity >= 40 && humidity <= 60) {
    // Comfortable - steady green with humidity-based intensity
    setColor(0, humidIntensity, 0);
    isBlinking = false;
  }
  // Hot conditions
  else if (temperature > 25) {
    if (temperature > 32) {
      // Very hot - blink red
      isBlinking = true;
      blinkColor(tempIntensity, 0, 0);
    } else {
      // Warm - red-yellow gradient
      setColor(tempIntensity, tempIntensity/2, 0);
      isBlinking = false;
    }
  }
  // Cold conditions
  else if (temperature < 25) {
    if (temperature < 20) {
      // Very cold - blink blue
      isBlinking = true;
      blinkColor(0, 0, tempIntensity);
    } else {
      // Cool - blue-green gradient
      setColor(0, tempIntensity/2, tempIntensity);
      isBlinking = false;
    }
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C, Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  
  if (!isBlinking) {
    delay(2000);
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(REDPIN, red);
  analogWrite(GREENPIN, green);
  analogWrite(BLUEPIN, blue);
}

void blinkColor(int red, int green, int blue) {
  setColor(red, green, blue);
  delay(500);
  setColor(0, 0, 0);
  delay(500);
}
