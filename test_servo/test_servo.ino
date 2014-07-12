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
  Serial.begin(SERIAL_BPS); // Serial port communication at 9600 bps (baudios).
  Serial.println("setup begins");
  Serial.print("  Serial communication port opened at ");
  Serial.println(SERIAL_BPS);

  myservo.attach(SERVOMOTOR_PIN); // Enable pin and servo
  Serial.print("  Servo attached to pin ");
  Serial.println(SERVOMOTOR_PIN);

  Serial.println("  Set servo to 90 degrees.");
  myservo.write(90); // Set servo to 90 degrees.
  delay(500);

  Serial.print("read: ");
  Serial.println(read_user_input());

  Serial.println("setup ends");
  Serial.println("");
}


void loop() {}


int read_user_input() {
  while(Serial.available() == 0); // Wait for user input.

  return Serial.read();
}
