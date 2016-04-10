#include <Arduino.h>
#include <Wire.h>

// basic settings
#define SERIAL_BAUD 9600
#define I2C_ADDRESS 8

// sensor settings

#define BRIGHTNESS_PIN 0
#define MOTION_PIN 2

// state
unsigned char state = 0;

// custom methods

void flush () {
	while (Wire.read() != -1);
}

void requestEvent () {
	Serial.print("Request ");
	unsigned char brightness;
	bool motion;
	switch (state) {
		case 0:
			brightness = map(analogRead(BRIGHTNESS_PIN), 0, 1024, 0,255);
			Wire.write(brightness);
			Serial.print("Brightness: ");
			Serial.println(brightness);
		break;
		case 1:
			motion = digitalRead(MOTION_PIN);
			Wire.write(motion);
			Serial.print("Motion: ");
			Serial.println(motion);
		break;
		default:
			Wire.write(255);
			Serial.println("unknown state");
	}
}

void receiveEvent (int amount) {
	state = (unsigned char) Wire.read();
	flush();
}

void setup() {
	// Sensors
	pinMode(BRIGHTNESS_PIN, INPUT);
	pinMode(MOTION_PIN, INPUT);

	// Serial
	Serial.begin(SERIAL_BAUD);

	// I²C
	Wire.begin(I2C_ADDRESS);
	Wire.onRequest(requestEvent);
	Wire.onReceive(receiveEvent);
}

void loop() {
	delay(10);
}
