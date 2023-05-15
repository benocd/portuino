#include <Arduino.h>
#include <SPI.h>

// Define the pins used by the Portuino
const int LED_PIN = 13; // The pin that the LED is connected to
const int SENSOR_PIN = A0; // The pin that the sensor is connected to

// Define the wavelength of light that the Portuino is sensitive to
const float WAVELENGTH = 532.0; // In nanometers

// Define the calibration constants
const float CALIBRATION_CONSTANT = 1.0; // This constant is used to convert the sensor output to a concentration

// The setup() function is called once when the Arduino is turned on
void setup() {
  // Initialize the serial port
  Serial.begin(9600);

  // Initialize the LED
  pinMode(LED_PIN, OUTPUT);

  // Initialize the sensor
  pinMode(SENSOR_PIN, INPUT);
}

// The loop() function is called repeatedly
void loop() {
  // Read the sensor output
  float sensor_output = analogRead(SENSOR_PIN);

  // Calculate the concentration
  float concentration = sensor_output * CALIBRATION_CONSTANT;

  // Print the concentration to the serial port
  Serial.println(concentration);

  // Turn on the LED for 1 second
  digitalWrite(LED_PIN, HIGH);
  delay(1000);

  // Turn off the LED
  digitalWrite(LED_PIN, LOW);

  // Wait 1 second before the next measurement
  delay(1000);
}
