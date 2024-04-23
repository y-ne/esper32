#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Assign I2C Pin, comment if using default pin
// #define I2C_SDA 33
// #define I2C_SCL 32

#define SCREEN_I2C_ADDR 0x3C // or 0x3D
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RST_PIN -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST_PIN);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_I2C_ADDR);

  hello();
}

void loop() {
  
}

void hello() {
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);

    display.println("Youne");
    display.display();
}