/*
 * IR
 * 
 * Guide for reading from IR remote.  
 * 
 * See Circuit.png image for wiring
 * 
 * Check out the language refrence for more information:
 * https://www.arduino.cc/reference/en/
 */

#include <IRremote.h>

// Create IR receiver
IRrecv IrReceiver(11);

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);

    Serial.println("Enabling IRin");
    IrReceiver.enableIRIn();  // Start the receiver
    IrReceiver.blink13(true); // Enable feedback LED
}

void loop() {
    // Try to decode an IR value
    if (IrReceiver.decode()) {
        // Print the IR value
        Serial.println(IrReceiver.results.value);

        // Receive the next value
        IrReceiver.resume();
    }
    delay(100);
}
