// int ledPin = 2;

// void setup() {
//   pinMode(ledPin, OUTPUT);
// }

// // Convert Hz → delay time (ms) for on/off half-cycle
// int hzToDelay(float hz) {
//   float period = 1000.0 / hz;    // total period in milliseconds
//   return (int)(period / 2.0);    // half period for on/off each
// }

// void loop() {
//   float freq = 20.0;              // ← change this to your target Hz
//   int delayTime = hzToDelay(freq);

//   digitalWrite(ledPin, HIGH);
//   delay(delayTime);
//   digitalWrite(ledPin, LOW);
//   delay(delayTime);
// }

#include "spike_data1.h"
#include <avr/pgmspace.h>

int ledPins[] = {2,3,4,5,6,7,8,9,10,11};
const uint16_t frame_delay_ms = 25;

void setup() {
  for (int i = 0; i < num_neurons; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int t = 0; t < num_timesteps; t++) {
    for (int n = 0; n < num_neurons; n++) {
      uint8_t val = pgm_read_byte(&(spike_data[t][n]));
      digitalWrite(ledPins[n], val);
    }
    delay(frame_delay_ms);
  }

  for (int i = 0; i < 10; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  delay(2000);
}
