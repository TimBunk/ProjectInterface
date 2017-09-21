#include <Encoder.h>

Encoder encoder(16,17);
long rotation  = -999;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  long newRot;
  Serial.println(encoder.read());
  newRot = encoder.read();
  if (newRot != rotation) {
    Serial.print("Rotation = ");
    Serial.println(newRot);
    rotation = newRot;
  }
  // if a character is sent from the serial monitor,
  // reset both back to zero.
  if (Serial.available()) {
    Serial.read();
    Serial.println("Reset both knobs to zero");
    encoder.write(0);
  }
}
