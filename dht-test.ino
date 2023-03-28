#include "Adafruit_DHT.h"

// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#define DHTPIN 2     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11		// DHT 11 
//#define DHTTYPE DHT22		// DHT 22 (AM2302)
//#define DHTTYPE DHT21		// DHT 21 (AM2301)
int led = D7; 
// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
	Serial.begin(9600); 
	Serial.println("DHTxx test!");
  digitalWrite(led, HIGH); 
	dht.begin();
}

void loop() {

	float f = dht.getTempFarenheit();
	
  
// Check if any reads failed and exit early (to try again).
	if ( isnan(f)) {
		Serial.println("Failed to read from DHT sensor!");
		return;
	}
	else if (!isnan(f)) {
    // Convert the temperature to a String data type and publish to the Particle cloud
    String temp = String(f);
    Particle.publish("temp", temp, PRIVATE);
  }
    
  delay(30000);               // Wait for 30 seconds

  digitalWrite(led, LOW);    // Turn OFF the LED
  delay(30000);               // Wait for 30 seconds




}

