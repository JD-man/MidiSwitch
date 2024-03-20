#define BUTTON 2

bool isMidiActivating = false;

void setup() {
  pinMode(BUTTON, INPUT);
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