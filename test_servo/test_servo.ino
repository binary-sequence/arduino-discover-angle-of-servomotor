// Test servomotor
// By sergiolindo.empresa@gmail.com
//
// It discover the maximal real angle that the servomotor can do.

#include <Servo.h>
#define SERVOMOTOR_PIN 9
#define SERIAL_BPS 9600

Servo myservo;

void setup() {
  int min_angular_pos = 0; // To store the minimum angle position of the servomotor.
  int max_angular_pos = 180; // To store the maximum angle position of the servomotor.
  int user_input;

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

  Serial.println();
  Serial.println("  Test begins");
  myservo.write(0);
  delay(500);
  user_input = ask_user_if_servo_moved(0);
  if (user_input == 'y' || user_input == 'Y') {
    Serial.println("    min_angular_pos found: 0");
  } else {
    if (get_min_angular_pos(&min_angular_pos) == true) {
      Serial.print("    min_angular_pos found: ");
      Serial.println(min_angular_pos);
    } else {
      Serial.println("    Warning: min_angular_pos not found.");
    }
  }
  Serial.println("  Test ends");

  Serial.println("setup ends");
  Serial.println("");
}


void loop() {}


int ask_user_if_servo_moved(int position) {
  Serial.print("    Did the servomotor move to ");
  Serial.print(position);
  Serial.println("? [y/N]");

  return read_user_input();
}


bool get_min_angular_pos(int *min_angular_pos) {
  bool no_errors = true;
  int user_input;
  int left_endpoint = 0;
  int right_endpoint = 90;

  while(right_endpoint - left_endpoint != 1) {
    *min_angular_pos = left_endpoint + (right_endpoint - left_endpoint) / 2;

    myservo.write(*min_angular_pos);
    delay(500);
    user_input = ask_user_if_servo_moved(*min_angular_pos);
    if (user_input == 'y' || user_input == 'Y') {
      right_endpoint = *min_angular_pos;
    } else {
      left_endpoint = *min_angular_pos;
    }
  }

  return no_errors;
}


int read_user_input() {
  while(Serial.available() == 0); // Wait for user input.

  return Serial.read();
}
