#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Wire.h> //Library for using I2C
#include <LiquidCrystal_I2C.h> //Library for using I2C type LCD display
#include <DHT.h> //Library for using DHT sensor

#define DHTPIN PA0
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27, 16, 2); // initilize object lcd for class LiquidCrystal_I2C with I2C address of 0x27 and 16x2 type LCD display

DHT dht(DHTPIN, DHTTYPE); // initilize object dht for class DHT with DHT pin with STM32 and DHT type as DHT11

void setup()

{

  // initialize the LCD
  Serial.begin(115200); // initialize serial port for communication with STM32 Must in DFU configuration mode
  lcd.init();
  dht.begin(); // Begins to receive Temperature and humidity values.
  lcd.backlight(); // Turn on the blacklight and print a welcome message.
  lcd.setCursor(0, 0);
  lcd.print("CD - Suman Saha");
  lcd.setCursor(0, 1);
  lcd.print("DHT11 with STM32");
  delay(3000);
  lcd.clear();
}

void loop()

{

  SerialUSB.println("Start");
  float h = dht.readHumidity(); // Gets Humidity value
  float t = dht.readTemperature(); // Gets Temperature value

/*   while(isnan(t) || isnan(h));
  {
    
    SerialUSB.println("Failed to read from DHT sensor!");
    lcd.setCursor(0, 0);
    lcd.autoscroll();
    lcd.print("Failed to read from DHT sensor!");
    delay(5000);
    //lcd.noBacklight();
  } */ // if humidity or temperature value is not a number, then it will print "Failed to read from DHT sensor!" and wait for 5 seconds and turn off the blacklight.
  
  
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print(" %");
  }
  
