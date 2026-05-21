#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD address
LiquidCrystal_I2C lcd(0x27, 16, 2);

// IR sensor pin
int irPin = 2;

// LED pins
int led1 = 7;
int led2 = 8;

// Counter
int count = 0;

// Previous sensor state
int previousState = HIGH;

void setup() {

  // Sensor pin
  pinMode(irPin, INPUT);

  // LED pins
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  // LED 1 always ON
  digitalWrite(led1, HIGH);

  // Serial Monitor
  Serial.begin(9600);

  // LCD setup
  lcd.init();
  lcd.backlight();

  // Initial display
  lcd.setCursor(0, 0);
  lcd.print("Count:");

  lcd.setCursor(0, 1);
  lcd.print(count);

  // Serial Monitor initial value
  Serial.print("Count: ");
  Serial.println(count);
}

void loop() {

  int currentState = digitalRead(irPin);

  // IR sensor detects object
  // Most IR sensors give LOW when object detected

  if (currentState == LOW) {
    digitalWrite(led2, HIGH);
  }
  else {
    digitalWrite(led2, LOW);
  }

  // Count only once for each detection
  if (currentState == LOW && previousState == HIGH) {

    count++;

    if (count > 1000) {
      count = 1000;
    }

    // Update LCD
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Count:");

    lcd.setCursor(0, 1);
    lcd.print(count);

    // Serial Monitor
    Serial.print("Count: ");
    Serial.println(count);

    delay(300);
  }

  // Save state
  previousState = currentState;
}