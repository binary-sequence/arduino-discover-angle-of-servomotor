// Test servomotor
// By sergiolindo.empresa@gmail.com
//
// It discover the maximal real angle that the servomotor can do.

#include <Servo.h>

Servo myservo;

int min_angle_pos = 0; // To store the minimun angle position of the servomotor.
int max_angle_pos = 180; // To store the maximun angle position of the servomotor.

void setup() {
  myservo.attach(9); // Digital pin 9
}

void loop() {}
