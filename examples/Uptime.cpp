#include <Arduino.h>
#include <uuid/common.h>

class Uptime: public Printable {
public:
	Uptime(uint64_t timestamp_ms = uuid::get_uptime_ms())
			: timestamp_ms_(timestamp_ms) {

	}

	size_t printTo(Print &print) const override {
		unsigned long days;
		unsigned int hours, minutes, seconds, milliseconds;
		uint64_t timestamp_ms = timestamp_ms_;

		days = timestamp_ms / 86400000UL;
		timestamp_ms %= 86400000UL;

		hours = timestamp_ms / 3600000UL;
		timestamp_ms %= 3600000UL;

		minutes = timestamp_ms / 60000UL;
		timestamp_ms %= 60000UL;

		seconds = timestamp_ms / 1000UL;
		timestamp_ms %= 1000UL;

		milliseconds = timestamp_ms;

		size_t len = print.print(F("Uptime: "));
		len += print.print(days);
		len += print.print('+');

		char time[2 + 1 /* hours */
				  + 2 + 1 /* minutes */
				  + 2 + 1 /* seconds */
				  + 3 /* milliseconds */
				  + 1];
		int ret = snprintf_P(time, sizeof(time), PSTR("%02u:%02u:%02u.%03u"),
				hours, minutes, seconds, milliseconds);
		if (ret > 0) {
			len += ret;
		}
		return len;
	}

private:
	uint64_t timestamp_ms_;
};

void setup() {
	Serial.begin(115200);
}

void loop() {
	uuid::loop();

	Serial.println(Uptime());

	delay(1000);
}
