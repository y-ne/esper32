#define LED LED_BUILTIN

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  Serial.begin(115200);
  Serial.println("Start Blink Sketch");
}

void loop() {
  ledON();
  delay(200);

  ledOFF();
  delay(200);
}

void ledON() {
  Serial.println("Build-In LED: ON");
  digitalWrite(LED, LOW);
}

void ledOFF() {
  Serial.println("Build-In LED: OFF");
  digitalWrite(LED, HIGH);
}