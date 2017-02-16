/*
 * Make 8 LEDs light up and dim successively, using Pin 2-9 of Arduino Uno
 * Author: Junru (Thomas) Ren
 * Date: Feb 15, 2017
 * Remark: Be sure to have a resister connected in series with a LED to 
 *         protect the circuit.
 */


const int PIN_LOWEST  = 2; // The lowest one attach to pin 2
const int PIN_HIGHEST = 9; // The highest one attach to pin 9
const int DELAY_GAP = 100; // The delay gap (in ms)

void setup()
{
  // Initialize Pin 2 through Pin 9 as output pins
  for (int thisPin = PIN_LOWEST; thisPin <= PIN_HIGHEST; thisPin++)
  {
    pinMode(thisPin, OUTPUT);
  }
}

void loop()
{
  // Turn the LED on from lowest to the highest
  for (int thisPin = PIN_LOWEST; thisPin <= PIN_HIGHEST; thisPin++)
  {
    digitalWrite(thisPin, HIGH);
    delay(DELAY_GAP);
  }
  // Fade from the lowest to the highest
  for (int thisPin = PIN_LOWEST; thisPin <= PIN_HIGHEST; thisPin++)
  {
    digitalWrite(thisPin, LOW);
    delay(DELAY_GAP);
  }
  // Turn the LED on from highest to the lowest
  for (int thisPin = PIN_HIGHEST; thisPin >= PIN_LOWEST; thisPin--)
  {
    digitalWrite(thisPin, HIGH);
    delay(DELAY_GAP);
  }
  // Fade from the highest to the lowest
  for (int thisPin = PIN_HIGHEST; thisPin >= PIN_LOWEST; thisPin--)
  {
    digitalWrite(thisPin, LOW);
    delay(DELAY_GAP);
  }
}
