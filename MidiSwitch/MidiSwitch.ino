#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

enum AmpChannel {
  clean,
  gain
};

#define BUTTON 2
#define BAUDRATE 31250

bool isMidiActivating = false;
AmpChannel ampChannel = clean;

void setup() {
  pinMode(BUTTON, INPUT);
  MIDI.begin();
  Serial.begin(BAUDRATE);
}

void loop() {
  buttonClicked();
}

void buttonClicked() {
  const int buttonRead = digitalRead(BUTTON);
  if (buttonRead == LOW) {
    isMidiActivating = false;
    return;
  } else {
    if (isMidiActivating) { return; }
    sendMidiSignal();
    isMidiActivating = true;
  }
}

void sendMidiSignal() {
  if (ampChannel == clean) {
    MIDI.sendProgramChange(1, 1);
    ampChannel = gain;
  } else {
    MIDI.sendProgramChange(0, 1);
    ampChannel = clean;
  }
}