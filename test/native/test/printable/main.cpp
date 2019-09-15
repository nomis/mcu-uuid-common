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

#include <Arduino.h>
#include <unity.h>

#include <uuid/common.h>

static unsigned long fake_millis;

unsigned long millis() {
	return fake_millis;
}

class Test: public ::Printable {
public:
	Test() = default;
	~Test() = default;

	size_t printTo(Print &print) const override {
		size_t len = 0;

		len += print.print("Hello");
		len += print.print(' ');
		len += print.print("World");
		len += print.print('!');

		return len;
	}
};

static void test_convert_to_string() {
	Test test;

	TEST_ASSERT_EQUAL_STRING("Hello World!", uuid::printable_to_string(test).c_str());
}

static void test_append_to_string1() {
	std::string output;
	Test test;

	TEST_ASSERT_EQUAL_INT(12, uuid::print_to_string(test, output));

	TEST_ASSERT_EQUAL_STRING("Hello World!", output.c_str());
}

static void test_append_to_string2() {
	std::string output{"... "};
	Test test;

	TEST_ASSERT_EQUAL_INT(12, uuid::print_to_string(test, output));

	output += " and ";

	TEST_ASSERT_EQUAL_INT(12, uuid::print_to_string(test, output));

	output += " again";

	TEST_ASSERT_EQUAL_STRING("... Hello World! and Hello World! again", output.c_str());
}

int main(int argc, char *argv[]) {
	UNITY_BEGIN();
	RUN_TEST(test_convert_to_string);
	RUN_TEST(test_append_to_string1);
	RUN_TEST(test_append_to_string2);
	return UNITY_END();
}
