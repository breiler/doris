/*
 * RandomServos
 * 
 * Guide for moving two servo motors randomly.
 * 
 * Check out the language refrence for more information:
 * https://www.arduino.cc/reference/en/
 */

#include <Servo.h>

// Create servo object to control a servo
Servo xServo;
Servo yServo;

// Variable to store the servo position
int xPos = 0;
int yPos = 0;
int xDest = 0;
int yDest = 0;

void setup() {
  // Attaches the servo on pin 9 to the servo object
  xServo.attach(9);
  yServo.attach(10);
}

void loop() {

  // Randomize new positions
  if(xPos == xDest) {
    xDest = random(20, 160);
  }

  if(yPos == yDest) {
    yDest = random(20, 160);
  }

  // Move towards destination
  if(xPos < xDest) {
    xPos++;
  } else {
    xPos--;
  }

    // Move towards destination
  if(yPos < yDest) {
    yPos++;
  } else {
    yPos--;
  }

  // Tell the servo to go to position in variables
  xServo.write(xPos);
  yServo.write(yPos);

  delay(100);
}
