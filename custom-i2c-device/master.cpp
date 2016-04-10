#include <Arduino.h>
#include <Wire.h>

#define SERIAL_BAUD 9600

#define I2C_SLAVE_ADDRESS 8

void setup () {
	Wire.begin();
	Serial.begin(SERIAL_BAUD);
}

void getFromState (unsigned char state) {
	Wire.beginTransmission(I2C_SLAVE_ADDRESS);
	Wire.write(state);
	Wire.endTransmission();

	int success = Wire.requestFrom(I2C_SLAVE_ADDRESS, 1);

	if (success == 0) {
		Serial.println("failed");
	} else {
		int c = (unsigned char) Wire.read();
		Serial.println(c);
	}
}

void loop () {
	Serial.print("Brightness: ");
	getFromState(0);
	delay(1000);
	Serial.print("Motion: ");
	getFromState(1);
	delay(1000);
}
