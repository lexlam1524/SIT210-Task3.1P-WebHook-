// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_Sensor.h>

#include <DHT.h>

const int DHTPIN = D2;     // Digital pin that the DHT11 is connected to
const int DHTTYPE = DHT11; // DHT11 sensor type

DHT dht(DHTPIN, DHTTYPE);

int led = D7;  // The on-board LED

void setup() {
  pinMode(led, OUTPUT);
  dht.begin();
}

void loop() {
  digitalWrite(led, HIGH);   // Turn ON the LED

  // Read the temperature value from the DHT11 sensor
  float temperature = dht.readTemperature();

// Check if the temperature value is valid
  if (!isnan(temperature)) {
    // Convert the temperature to a String data type and publish to the Particle cloud
    Particle.publish("temp", String(temperature), PRIVATE);
  }
  

  delay(30000);               // Wait for 30 seconds

  digitalWrite(led, LOW);    // Turn OFF the LED
  delay(30000);               // Wait for 30 seconds
}
