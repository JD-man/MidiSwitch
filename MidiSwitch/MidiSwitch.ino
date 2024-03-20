#define BUTTON 2

void setup() {
  pinMode(BUTTON, INPUT);
}

void loop() {
  buttonClicked();
}

void buttonClicked() {
  const bool isButtonLow = digitalRead(BUTTON) == LOW;
  if (isButtonLow) { return; }
  else {
    Serial.println("버튼 클릭");
  }
}