/* FreqMeasure - Example with serial output
 * http://www.pjrc.com/teensy/td_libs_FreqMeasure.html
 *
 * This example code is in the public domain.
 */
#include <FreqMeasure.h>

void setup() {
  Serial.begin(57600);
  FreqMeasure.begin();
  digitalWrite(49,HIGH);
}

double sum=0;
int count=0;

void loop() {
  // Serial.println(digitalRead(49));
  if (FreqMeasure.available()) {
    // average several reading together
    sum = sum + FreqMeasure.read();
    count = count + 1;
    if (count > 30) {
      double frequency = F_CPU / (sum / count);
      Serial.println(frequency);
      sum = 0;
      count = 0;
    }
  }
}

