#include <Arduino.h>

/*
  Serial Event example

  When new serial data arrives, this sketch adds it to a String.
  When a newline is received, the loop prints the string and clears it.

  A good test for this is to try it with a GPS receiver that sends out
  NMEA 0183 sentences.

  NOTE: The serialEvent() feature is not available on the Leonardo, Micro, or
  other ATmega32U4 based boards.

  created 9 May 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/SerialEvent
*/

char receivedChar;
bool isBufferFull = false; // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
}

void loop() {
  // print the string when a newline arrives:
  if (isBufferFull) {
    Serial.printf("Received: \t%#04X", receivedChar);
    if (receivedChar > 31) {
      Serial.printf(" '%c'", receivedChar);
    }
    Serial.println();
    isBufferFull = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  const auto inData = Serial.read();
  if (inData < 0 || isBufferFull) {
    return;
  } else {
    receivedChar = static_cast<char>(inData);
    isBufferFull = true;
  }
}