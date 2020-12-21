/*
 * RandomServos
 * 
 * Guide for moving two servo motors using IR remote
 * 
 * Check out the language refrence for more information:
 * https://www.arduino.cc/reference/en/
 */

#include <Servo.h>
#include <IRremote.h>

// Create servo object to control a servo
Servo xServo;
Servo yServo;

// Create IR receiver
IRrecv IrReceiver(11);

// Variable to store the servo position
int xPos = 100;
int yPos = 100;

int leftCode = 19;
int leftLongCode = 2067;
int rightCode = 18;
int rightLongCode = 2066;
int upCode = 22;
int upLongCode = 2070;
int downCode = 23;
int downLongCode = 2071;

int stepSize = 3;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    IrReceiver.enableIRIn();  // Start the receiver
    IrReceiver.blink13(true); // Enable feedback LED
}

void loop() {
    // Try to decode an IR value
    if (IrReceiver.decode()) {
        int irValue = IrReceiver.results.value;
        bool valueChanged = false;
        
        if (irValue == leftCode || irValue == leftLongCode) {
            xPos -= stepSize;
            valueChanged = true;
        } else if (irValue == rightCode || irValue == rightLongCode) {
            xPos += stepSize;
            valueChanged = true;
        } else if (irValue == upCode || irValue == upLongCode) {
            yPos += stepSize;
            valueChanged = true;
        } else if (irValue == downCode || irValue == downLongCode) {
            yPos -= stepSize;
            valueChanged = true;
        }

        // Tell the servo to go to position in variables
        if (valueChanged) {
            // Attaches the servo on pin 9 to the servo object
            xServo.attach(9);
            yServo.attach(10);

            // Write position
            xServo.write(xPos);
            yServo.write(yPos);

            // Wait for servo to move and then detach them to avoid jitter
            delay(25);
            xServo.detach();
            yServo.detach();
        }

        // Receive the next value
        IrReceiver.resume();
    }
}
