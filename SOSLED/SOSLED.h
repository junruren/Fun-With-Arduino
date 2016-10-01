/**
 * Header file for SOSLED.ino
 * Author: Junru (Thomas) Ren
 * Date: Oct 01, 2016
 */
#ifndef SOSLED_H
#define SOSLED_H

/* Constants */
#define PINOUT_LED 9            // Initialize the LED pinout to be Pin 9
#define UNIT 300               // Define the duration of one Morse Unit
#define DURATION_DOT UNIT       // A dot is one UNIT
#define DURATION_DASH UNIT*3    // A dash is three UNITs
#define DURATION_PARTS UNIT     // The space between parts of the same letter is one UNIT
#define DURATION_LETTERS UNIT*3 // The space between letters are three UNITs
#define DURATION_WORDS UNIT*7   // The space between words is seven UNITs

/* Function headers */
void morse_S();
void morse_O();

#endif /* SOSLED_H */
