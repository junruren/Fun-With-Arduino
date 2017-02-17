/*
 * Read user's input via Serial Monitor and turn on the corresponding LED, 
 * using Pin 2 (Green LED), 3 (Yellow LED), and 4 (Red LED) of Arduino Uno
 * Author(s): Junru (Thomas) Ren
 * Date: Feb 16, 2017
 * Remark: Be sure to have a resister connected in series with a LED to 
 *         protect the circuit.
 *         Learn more about Arduino Serial: 
 *         https://www.arduino.cc/en/Reference/Serial
 */

const int PIN_LED_GREEN = 2;  // Map the green led pin to Pin 2
const int PIN_LED_YELLOW = 3; // Map the yellow led pin to Pin 3
const int PIN_LED_RED = 4;    // Map the red led pin to Pin 4

const int SERIAL_PORT_BPS = 9600; // The data rate (in bits per second) for 
                                  // serial data transmission
                                  // Usually choose 9600 

/* (If you've been using C for awhile) Surprise! Arduino C does support String
 * object like Java!
 */
String userInput = "";

void setup()
{
  // Initialize the LED Pins as output pins
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_LED_RED, OUTPUT);
  // Start serial port at given data rate in bps
  Serial.begin(SERIAL_PORT_BPS);
  // Prompt the user to input a color via Serial Monitor
  Serial.print("Please input the color of LED that you wish to turn on:\n");
}
void loop()
{
  // Read user's input from Serial Monitor
  if (Serial.available() > 0)
  {
    userInput = "";
    while (Serial.available() > 0)
    {
      // Concatenate the newly read character to the String
      userInput += char(Serial.read());
      delay(2);
    }
    Serial.println(userInput); // Print user's input to the Serial Monitor
  }
  // Turn on corresponding LED according to user's input
  /* Q: Why not using switch statement?
   * A: Expressions in switch statements must have an integral or enumerated 
   * type (e.g. int, char, enum). Thus comparison between two String objects is
   * not supported.
   */
  if (userInput == "red")
  {
    // If user entered "red", turn on only Red LED
    digitalWrite(PIN_LED_RED, HIGH);
    digitalWrite(PIN_LED_GREEN, LOW);
    digitalWrite(PIN_LED_YELLOW, LOW);
  }
  else if (userInput == "yellow")
  {
    // If user entered "yellow", turn on only Yellow LED
    digitalWrite(PIN_LED_RED, LOW);//turn the red led off
    digitalWrite(PIN_LED_GREEN, LOW);//turn the green led off
    digitalWrite(PIN_LED_YELLOW, HIGH);//turn the yellow led on
  }
  else if (userInput == "green")
  {
    // If user entered "green", turn on only Green LED
    digitalWrite(PIN_LED_RED, LOW);//turn the red led off
    digitalWrite(PIN_LED_GREEN, HIGH);//turn the green led on
    digitalWrite(PIN_LED_YELLOW, LOW);//turn the yellow led off
  }
  else
  {
    // If user entered anything other than "red", "yellow" or "green", turn off
    // all LEDs
    digitalWrite(PIN_LED_RED, LOW);
    digitalWrite(PIN_LED_GREEN, LOW);
    digitalWrite(PIN_LED_YELLOW, LOW);
  }
}
