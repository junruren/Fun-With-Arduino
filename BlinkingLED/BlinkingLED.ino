/**
 * Blinking LED via Pin 9
 * Author: Junru (Thomas) Ren
 * Date: Oct 01, 2016
 * WARNING: be sure to have a resister connected in series with the LED to protect the circuit
 */

/* Constant Data Field */
const int PINOUT_LED = 9; // Initialize the LED pinout to be Pin 9

void setup() {
  // Initialize the output pin
  pinMode(PINOUT_LED, OUTPUT);
}

void loop() {
  // Turn on the LED
  digitalWrite(PINOUT_LED, HIGH);
  delay(500);
  // Turn off the LED
  digitalWrite(PINOUT_LED, LOW);
  delay(500);
}
