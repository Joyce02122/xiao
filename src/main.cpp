#include <Arduino.h> // Include Arduino library

#define ANALOG_PIN A0  // Define analog input pin
#define LED_D1 0       // Define LED D1 pin
#define LED_D2 1       // Define LED D2 pin

void setup() {
  pinMode(LED_D1, OUTPUT);  // Set D1 as output
  pinMode(LED_D2, OUTPUT);  // Set D2 as output
  Serial.begin(115200);     // Start the serial monitor
}

void loop() {
  int adcValue = analogRead(ANALOG_PIN); // Read analog input (0-4095)
  float voltage = (adcValue / 4095.0) * 3.3; // Convert to voltage (V)

  // Print ADC value and voltage
  Serial.print("ADC Value: ");
  Serial.print(adcValue);         // Display the ADC value
  Serial.print(", Voltage: ");
  Serial.print(voltage, 2);       // Display the voltage value with 2 decimal places
  Serial.println(" V");

  // Control LEDs based on voltage
  if (voltage > 2.0) {         // Voltage > 2V
    digitalWrite(LED_D1, HIGH); // Turn on D1
    digitalWrite(LED_D2, LOW);  // Turn off D2
  } else if (voltage > 1.0) {  // 1V < Voltage <= 2V
    digitalWrite(LED_D1, LOW);  // Turn off D1
    digitalWrite(LED_D2, HIGH); // Turn on D2
  } else {                     // Voltage <= 1V
    digitalWrite(LED_D1, LOW);  // Turn off both LEDs
    digitalWrite(LED_D2, LOW);
  }

  delay(500); // Wait 500ms
}
