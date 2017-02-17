/**
 * Header file for Morse-Code-LED.ino
 * Author(s): Junru (Thomas) Ren, Yi Hui (Michael) Chen
 * Date: Feb 16, 2017
 */
#ifndef MORSECODE_H
#define MORSECODE_H

/* Constants */
const int PIN_LED = 9;               // Initialize the LED pinout to be Pin 9
const int UNIT = 300;                // Define the duration of one Morse Unit
const int DURATION_DOT = UNIT;       // A dot is one UNIT
const int DURATION_DASH = UNIT*3;    // A dash is three UNITs
const int DURATION_PARTS = UNIT;     // The space between parts of the same letter is one UNIT
const int DURATION_LETTERS = UNIT*2; // The space between letters are three UNITs
const int DURATION_WORDS = UNIT*6;   // The space between words is seven UNITs
// Multipliers are one off because one additional UNIT would be delayed by a DOT or DASH

const int morseA [] =    {0, 1, -1};
const int morseB [] =    {1, 0, 0, 0, -1};
const int morseC [] =    {1, 0, 1, 0, -1};
const int morseD [] =    {1, 0, 0, -1};
const int morseE [] =    {0, -1};
const int morseF [] =    {0, 0, 1, 0, -1};
const int morseG [] =    {1, 1, 0, -1};
const int morseH [] =    {0, 0, 0, 0, -1};
const int morseI [] =    {0, 0, -1};
const int morseJ [] =    {0, 1, 1, 1, -1};
const int morseK [] =    {1, 0, 1, -1};
const int morseL [] =    {0, 1, 0, 0, -1};
const int morseM [] =    {1, 1, -1};
const int morseN [] =    {1, 0, -1};
const int morseO [] =    {1, 1, 1, -1};
const int morseP [] =    {0, 1, 1, 0, -1};
const int morseQ [] =    {1, 1, 0, 1, -1};
const int morseR [] =    {0, 1, 0, -1};
const int morseS [] =    {0, 0, 0, -1};
const int morseT [] =    {1, -1};
const int morseU [] =    {0, 0, 1, -1};
const int morseV [] =    {0, 0, 0, 1, -1};
const int morseW [] =    {0, 1, 1, -1};
const int morseX [] =    {1, 0, 0, 1, -1};
const int morseY [] =    {1, 0, 1, 1, -1};
const int morseZ [] =    {1, 1, 0, 0, -1};
const int morse1 [] =    {0, 1, 1, 1, 1, -1};
const int morse2 [] =    {0, 0, 1, 1, 1, -1};
const int morse3 [] =    {0, 0, 0, 1, 1, -1};
const int morse4 [] =    {0, 0, 0, 0, 1, -1};
const int morse5 [] =    {0, 0, 0, 0, 0, -1};
const int morse6 [] =    {1, 0, 0, 0, 0, -1};
const int morse7 [] =    {1, 1, 0, 0, 0, -1};
const int morse8 [] =    {1, 1, 1, 0, 0, -1};
const int morse9 [] =    {1, 1, 1, 1, 0, -1};
const int morse0 [] =    {1, 1, 1, 1, 1, -1};

const int LED = 9;
const int SERIAL_PORT_BPS = 9600; // The data rate (in bits per second) for 
                                  // serial data transmission
                                  // Usually choose 9600
void enCode(const int code []);
#endif /* MORSECODE_H */
