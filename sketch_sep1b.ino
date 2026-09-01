int led=13;
void setup() {
  pinMode(led ,OUTPUT);

  for (int i = 0; i < 10; i++) {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  }
}

void loop() {
  // Nothing here
}