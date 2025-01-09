/*
  hello_xiao
  A first sketch for the Seeeduino XIAO in PlatformIO
  
  This example code is in the public domain.
  
  Michel Deslierres  June 15, 2020
*/

#include <Arduino.h> // needed in PlatformIO

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
}

void loop() {
  // Print "Hello XIAO!" every 2 seconds
  Serial.println("Hello XIAO!");
  delay(2000);
}
