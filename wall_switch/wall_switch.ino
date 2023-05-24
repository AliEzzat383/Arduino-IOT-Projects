#include <Servo.h>
#include <SoftwareSerial.h>

Servo servo2;
int angle = 90;
void turnOff() {
  servo2.write(0);
  angle =120;
  servo2.write(angle);
  delay(2000);
  servo2.write(1);
  delay(2000);
}

SoftwareSerial bluetoothSerial(10, 11);  // RX=10, TX=11 pins for Bluetooth module

const char buttonChar = 'A';  // Character to be received as the button press signal

void setup() {
  Serial.begin(9600);
  bluetoothSerial.begin(9600);
  servo2.attach(9);
}

void loop() {
  
  if (bluetoothSerial.available()) {
    char receivedChar = bluetoothSerial.read();

    if (receivedChar == buttonChar) {
      Serial.println("The light is off");  // Changed Serial.write to Serial.println for text output
      Serial.println(angle);
      turnOff();
     
    }
  }
}
