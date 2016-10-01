/**
 * Blinking "SOS" in Morse Code via LED at connected to Pin 9
 * Author: Junru (Thomas) Ren
 * Date: Oct 01, 2016
 * WARNING: be sure to have a resister connected in series with the LED to protect the circuit
 */
#include "SOSLED.h" // Include the header file where some constants are defined

void setup()
{
  pinMode(PINOUT_LED, OUTPUT); //initialize the digital pin as an output
}

void loop()
{
  morse_S();
  delay(DURATION_LETTERS);
  morse_O();
  delay(DURATION_LETTERS);
  morse_S();
  delay(DURATION_WORDS);
}

void morse_S()
{
  digitalWrite(PINOUT_LED, HIGH); //turn the LED on
  delay(DURATION_DOT);
  digitalWrite(PINOUT_LED, LOW); //turn the LED off
  delay(DURATION_PARTS);

  digitalWrite(PINOUT_LED, HIGH); //turn the LED on
  delay(DURATION_DOT);
  digitalWrite(PINOUT_LED, LOW); //turn the LED off
  delay(DURATION_PARTS);

  digitalWrite(PINOUT_LED, HIGH); //turn the LED on
  delay(DURATION_DOT);
  digitalWrite(PINOUT_LED, LOW); //turn the LED off
}

void morse_O()
{
  digitalWrite(PINOUT_LED, HIGH); //turn the LED on
  delay(DURATION_DASH);
  digitalWrite(PINOUT_LED, LOW); //turn the LED off
  delay(DURATION_PARTS);

  digitalWrite(PINOUT_LED, HIGH); //turn the LED on
  delay(DURATION_DASH);
  digitalWrite(PINOUT_LED, LOW); //turn the LED off
  delay(DURATION_PARTS);

  digitalWrite(PINOUT_LED, HIGH); //turn the LED on
  delay(DURATION_DASH);
  digitalWrite(PINOUT_LED, LOW); //turn the LED off
  delay(DURATION_PARTS);
}

