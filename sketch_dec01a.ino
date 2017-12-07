#include "pitches.h"

int speakerPin = 11;                // choose the pin for the speaker
int inputPin = 2;               // choose the input pin (for PIR sensor)
int val = 0;                    // variable for reading the pin status

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

void playSong(){
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 19; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(speakerPin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerPin);
  }

}

void misty (int val) {
   if (val == HIGH) {            
    playSong(); 
  }
}

void setup() {
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(speakerPin, OUTPUT);      // declare LED as output
}

void loop() {
  val = digitalRead(inputPin);  // read input value
  misty(val);
}
