#include "arduino_secrets.h"
#include "thingProperties.h"
#include <Servo.h>

Servo servo1;

void setup() {
  Serial.begin(9600);
  delay(1500);
  servo1.attach(12);
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  pinMode(LED_BUILTIN, OUTPUT);  // Set the LED pin as an output
}

void loop() {
  ArduinoCloud.update();
  // Your code here
}

void onPowerChange() {
  if (!power) {
    turnOff();
    digitalWrite(LED_BUILTIN, HIGH);  // Turn on the LED
  } else {
    Serial.println("lights on");
    digitalWrite(LED_BUILTIN, LOW);  // Turn off the LED
  }
}

void turnOff() {
  int angle = 90;
  servo1.write(0);
  angle = 120;
  servo1.write(angle);
  delay(2000);
  servo1.write(1);
  delay(2000);
}
