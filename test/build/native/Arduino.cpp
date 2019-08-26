/*
 * uuid-common - Microcontroller common utilities
 * Copyright 2019  Simon Arlott
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifdef ENV_NATIVE

#include <Arduino.h>

NativeConsole Serial;

static unsigned long __millis = 0;

int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused))) {
	setup();
	while (millis() <= 10 * 1000) {
		loop();
	}
	return 0;
}

unsigned long millis() {
	return __millis;
}

void delay(unsigned long millis) {
	__millis += millis;
}

void yield(void) {

}

#endif
