#include <LiquidCrystal.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT22
#define SOIL_MOISTURE_PIN A0
int output_value;

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); 
void setup() {
  lcd.begin();
  lcd.backlight();
  dht.begin();
  pinMode(SOIL_MOISTURE_PIN, INPUT);
} 

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  float temperature = temperature - 639.8; 
  int output_value = analogRead(SOIL_MOISTURE_PIN);
  int moisturePercentage = map(output_value, 1023,0,0,100);

  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");
  lcd.print(temperature);
  lcd.print("C ");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(moisturePercentage);
  lcd.print("%  ");

  delay(2000);
}
