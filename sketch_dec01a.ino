/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 1 Dec 2017
  by Rob Culliton

  This example code is in the public domain.

*/

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_B4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_E4,
  NOTE_B4, NOTE_E4, NOTE_FS4,NOTE_FS4,NOTE_G4, NOTE_A4, NOTE_G4, NOTE_FS4,NOTE_E4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  1, 2, 1, 1, 2, 2, 2, 2, 1, 1,
  1, 1, 1, 1, 1, 2, 2, 2, 1
};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 19; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(11, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(11);
  }
}

void loop() {
  // no need to repeat the melody.
}
