#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)

Adafruit_PCD8544 display=Adafruit_PCD8544(5,4,3);
char s[5];

void showNumber(int n) {
  display.clearDisplay();
  display.setCursor(5,10);
  sprintf(s,"%04d",n);
  display.print(s);
  display.display();
}

void setup() {
  pinMode(9,INPUT_PULLUP);
  display.begin();
  display.setContrast(50);
  display.setTextSize(3);
  showNumber(0);
}

int n=0;
void loop() {
  if (digitalRead(9)==LOW) {
    showNumber(n);
    if (++n>9999) n=0;
    while (digitalRead(9)==LOW);
  }
}
