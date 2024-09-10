#define HORIZONTAL 4
#define VERTICAL 5

int x_val = 0;
int y_val = 0;

// Function to map values to percentage
int mapToPercentage(int value, bool invert) {
  if (invert) {
    return map(value, 0, 4095, 100, 0);
  } else {
    return map(value, 0, 4095, 0, 100);
  }
}

void setup() {
  Serial.begin(115200);
}

void loop() {
  x_val = analogRead(HORIZONTAL);
  y_val = analogRead(VERTICAL);
  
  int left_right = mapToPercentage(x_val, false);
  int up_down = mapToPercentage(y_val, false);
  
  Serial.print("Left: ");
  Serial.print(left_right > 50 ? (left_right - 50) * 2 : 0);
  Serial.print("% | Right: ");
  Serial.print(left_right < 50 ? (50 - left_right) * 2 : 0);
  Serial.print("% | Up: ");
  Serial.print(up_down > 50 ? (up_down - 50) * 2 : 0);
  Serial.print("% | Down: ");
  Serial.print(up_down < 50 ? (50 - up_down) * 2 : 0);
  Serial.println("%");
  
  delay(100);
}