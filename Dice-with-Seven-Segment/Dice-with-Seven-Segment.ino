/*
   Display a random number between 1 and 6 on the Common Anode Seven Segment
   Display every time the button is pressed, simulating a dice toss.
   Author: Junru (Thomas) Ren
   Date: Feb 12, 2017
   Remark: This code is written for Common Anode Seven Segment Display. That's
           why a segment is actually turned on when the digitalWrite() of a pin
           is set to LOW.
           If you wish to use a Common Cathode, flip all "HIGH" and "LOW" used
           in digitalWrite() for Seven Segment Display pins. Then, connect your
           "-" to GND rather than 3.3V on your Arduino
*/

// Map the pins of Seven Segment
const int a = 7;  // a of 7-segment attach to digital pin 7
const int b = 6;  // b of 7-segment attach to digital pin 6
const int c = 5;  // c of 7-segment attach to digital pin 5
const int d = 11; // d of 7-segment attach to digital pin 11
const int e = 10; // e of 7-segment attach to digital pin 10
const int f = 8;  // f of 7-segment attach to digital pin 8
const int g = 9;  // g of 7-segment attach to digital pin 9
const int dp = 4; // dp of 7-segment attach to digital pin 4
// Map the button to pin 2
const int buttonPin = 2;

// State trackers for button presses
int buttonState = 0;
int lastButtonState = 0;

void setup()
{
  // Set Seven Segment pins (pin 4 - 11) as OUTPUT
  for (int thisPin = 4; thisPin <= 11; thisPin++)
  {
    pinMode(thisPin, OUTPUT);
  }
  // Set Button pin as INPUT
  pinMode(buttonPin, INPUT);

  digitalWrite(dp, HIGH); // Turn off the dp (decimal point) on the Seven Segment

  randomSeed(analogRead(0)); // Create random seed using the noise read from Analog Pin 0
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    // Generate a random dice number
    int dice = random(1, 7);

    switch ( dice ) {
      case 1:
        digital_1();//diaplay 1 to the 7-segment
        break;
      case 2:
        digital_2();//diaplay 2 to the 7-segment
        break;
      case 3:
        digital_3();//diaplay 3 to the 7-segment
        break;
      case 4:
        digital_4();//diaplay 4 to the 7-segment
        break;
      case 5:
        digital_5();//diaplay 5 to the 7-segment
        break;
      case 6:
        digital_6();//diaplay 6 to the 7-segment
        break;
      default:
        digital_0();//diaplay 0 to the 7-segment
        break;
    }
  }
  delay(50); // Delay a little bit to avoid bouncing
  lastButtonState = buttonState; // Save the button state
}

void displayOff(void)
{
  for (int thisPin = 4; thisPin <= 11; thisPin++)
  {
    digitalWrite(thisPin, HIGH);
  }
}

void digital_0(void) //diaplay 0 to the 7-segment
{
  digitalWrite(a, LOW); //turn the a of the 7-segment on
  digitalWrite(b, LOW); //turn the b of the 7-segment on
  digitalWrite(c, LOW); //turn the c of the 7-segment on
  digitalWrite(d, LOW); //turn the d of the 7-segment on
  digitalWrite(e, LOW); //turn the e of the 7-segment on
  digitalWrite(f, LOW); //turn the f of the 7-segment on
  digitalWrite(g, LOW); //turn the g of the 7-segment on
}

void digital_1(void) //diaplay 1 to the 7-segment
{
  digitalWrite(c, LOW); //turn the c of the 7-segment on
  digitalWrite(b, LOW); //turn the b of the 7-segment on
  for (int j = 7; j <= 11; j++) //turn off the others
    digitalWrite(j, HIGH);
}
void digital_2(void) //diaplay 2 to the 7-segment
{
  digitalWrite(b, LOW);
  digitalWrite(a, LOW);
  for (int j = 9; j <= 11; j++)
    digitalWrite(j, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(f, HIGH);
}
void digital_3(void) //diaplay 3 to the 7-segment
{
  unsigned char j;
  digitalWrite(g, LOW);
  digitalWrite(d, LOW);
  for (j = 5; j <= 7; j++)
    digitalWrite(j, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(e, HIGH);
}
void digital_4(void) //diaplay 4 to the 7-segment
{
  digitalWrite(c, LOW);
  digitalWrite(b, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(a, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(d, HIGH);
}
void digital_5(void) //diaplay 5 to the 7-segment
{
  unsigned char j;
  for (j = 7; j <= 9; j++)
    digitalWrite(j, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(e, HIGH);
}
void digital_6(void) //diaplay 6 to the 7-segment
{
  unsigned char j;
  for (j = 7; j <= 11; j++)
    digitalWrite(j, LOW);
  digitalWrite(c, LOW);
  digitalWrite(b, HIGH);
}
void digital_7(void) //diaplay 7 to the 7-segment
{
  unsigned char j;
  for (j = 5; j <= 7; j++)
    digitalWrite(j, LOW);
  for (j = 8; j <= 11; j++)
    digitalWrite(j, HIGH);
}
void digital_8(void) //diaplay 8 to the 7-segment
{
  unsigned char j;
  for (j = 5; j <= 11; j++)
    digitalWrite(j, LOW);
}
void digital_9(void) //diaplay 9 to the 7-segment
{
  unsigned char j;
  for (j = 5; j <= 9; j++)
    digitalWrite(j, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
}
