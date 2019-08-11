#include <Arduino.h>
#include <uuid/common.h>

void setup() {
	Serial.begin(115200);
}

void loop() {
	uuid::loop();

	Serial.printf("Uptime: %llu\r\n", uuid::get_uptime_ms());

	delay(1000);
}
