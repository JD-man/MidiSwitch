#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();


#define BUTTON 2
#define BAUDRATE 31250

bool isMidiActivating = false;

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
    Serial.println("버튼 클릭"); // 미디 활성화 함수 넣기
    isMidiActivating = true;
  }
}