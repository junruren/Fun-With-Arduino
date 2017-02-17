/**
 * Header file for Morse-Code-LED.ino
 * Author(s): Junru (Thomas) Ren, Yi Hui (Michael) Chen
 * Date: Feb 16, 2017
 */
#include "MorseCode.h"

/* (If you've been using C for awhile) Surprise! Arduino C does support String
 * object like Java!
 */
String userInput = "";

void setup() {
  pinMode(LED, OUTPUT);
  // Start serial port at given data rate in bps
  Serial.begin(SERIAL_PORT_BPS);
  // Prompt the user to input a color via Serial Monitor
  Serial.print("Please input your message that you wish to translate into Morse Code:");
}

void loop() {
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
    // Convert the message into upper case characters
    userInput.toUpperCase();
    Serial.println("\n" + userInput); // Print user's input to the Serial Monitor
  }

  for (unsigned int i = 0; i < userInput.length(); i++) {
    char tempChar = userInput.charAt(i);
    switch (tempChar) {
      case 'A':
        enCode(morseA);
        break;
      case 'B':
        enCode(morseB);
        break;
      case 'C':
        enCode(morseC);
        break;
      case 'D':
        enCode(morseD);
        break;
      case 'E':
        enCode(morseE);
        break;
      case 'F':
        enCode(morseF);
        break;
      case 'G':
        enCode(morseG);
        break;
      case 'H':
        enCode(morseH);
        break;
      case 'I':
        enCode(morseI);
        break;
      case 'J':
        enCode(morseJ);
        break;
      case 'K':
        enCode(morseK);
        break;
      case 'L':
        enCode(morseL);
        break;
      case 'M':
        enCode(morseM);
        break;
      case 'N':
        enCode(morseN);
        break;
      case 'O':
        enCode(morseO);
        break;
      case 'P':
        enCode(morseP);
        break;
      case 'Q':
        enCode(morseQ);
        break;
      case 'R':
        enCode(morseR);
        break;
      case 'S':
        enCode(morseS);
        break;
      case 'T':
        enCode(morseT);
        break;
      case 'U':
        enCode(morseU);
        break;
      case 'V':
        enCode(morseV);
        break;
      case 'W':
        enCode(morseW);
        break;
      case 'X':
        enCode(morseX);
        break;
      case 'Y':
        enCode(morseY);
        break;
      case 'Z':
        enCode(morseZ);
        break;
      case '1':
        enCode(morse1);
        break;
      case '2':
        enCode(morse2);
        break;
      case '3':
        enCode(morse3);
        break;
      case '4':
        enCode(morse4);
        break;
      case '5':
        enCode(morse5);
        break;
      case '6':
        enCode(morse6);
        break;
      case '7':
        enCode(morse7);
        break;
      case '8':
        enCode(morse8);
        break;
      case '9':
        enCode(morse9);
        break;
      case '0':
        enCode(morse0);
        break;
      case ' ':
        Serial.print("  ");
        delay(DURATION_WORDS);
        break;
      default:
        // Don't blink if an unsupported character appears
        Serial.print("(Unsupported Char)");
        break;
    } // End Switch
  } // End Loop
  userInput = ""; // Clear the user input buffer to prevent the message being re-translated
}

void enCode(const int code []) {
  int i = 0;
  while (code[i] != -1) {
    if (code[i] == 1) {
      Serial.print("-");
      digitalWrite(LED, HIGH);
      delay(DURATION_DASH);
      digitalWrite(LED, LOW);
      delay(DURATION_PARTS);
    } else if (code[i] == 0) {
      Serial.print(".");
      digitalWrite(LED, HIGH);
      delay(DURATION_DOT);
      digitalWrite(LED, LOW);
      delay(DURATION_PARTS);
    }
    i++;
  }
  Serial.print(" ");
  delay(DURATION_LETTERS);
}
