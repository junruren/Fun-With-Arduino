/**
 * Blinking LED via Digital Pin 9 of Arduino Uno. Blink "digitally" by default,
 * code for blinking "analogly" provided but commented
 * Author(s): Junru (Thomas) Ren, Zhimin Lin
 * Last Update: Feb 12, 2017
 * Remark: Be sure to have a resister connected in series with the LED to 
 *         protect the circuit.
 *         analogWrite() only available for Pin 3, 5, 6, 8, 10, and 11 on most Arduino boards
 */

/* Constant Data Field */
const int PIN_LED = 9;          // Initialize the LED pinout to be Pin 9
const int ANALOG_DELAY = 5;     // Delay between each increment/decrement step of the LED
const int DELAY_GAP = 500;      // The delay gap (in ms)
const int MAX_DUTY_CYCLE = 255; // Maximum output value allowed for analogWrite()

void setup() {
  // Initialize the output pin
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  /* Digital Blink */
  // Turn on the LED
  digitalWrite(PIN_LED, HIGH);
  delay(DELAY_GAP);
  // Turn off the LED
  digitalWrite(PIN_LED, LOW);
  delay(DELAY_GAP);

  /* Analog Blink */
  /*
  int dutyCycle = 0;
  // Turning on the LED gradually
  while (dutyCycle <= MAX_DUTY_CYCLE){
    analogWrite(PIN_LED, dutyCycle);    //Increment the lightness of the LED
    dutyCycle++;
    delay(ANALOG_DELAY);
  }
  delay(DELAY_GAP);
  // Turning off the LED gradually
  while (dutyCycle >= 0){
    analogWrite(PIN_LED, dutyCycle);    //Decrement the lightness of the LED
    dutyCycle--;
    delay(ANALOG_DELAY);
  }
  delay(DELAY_GAP);
  */
}
