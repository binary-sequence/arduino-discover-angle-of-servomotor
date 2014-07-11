// Test servomotor
// By sergiolindo.empresa@gmail.com
//
// It discover the maximal real angle that the servomotor can do.

#include <Servo.h>
#define SERVOMOTOR_PIN 9
#define SERIAL_BPS 9600

Servo myservo;

int min_angular_pos = 0; // To store the minimum angle position of the servomotor.
int max_angular_pos = 180; // To store the maximum angle position of the servomotor.

void setup() {
  myservo.attach(SERVOMOTOR_PIN); // Enable pin and servo
}

void loop() {}
