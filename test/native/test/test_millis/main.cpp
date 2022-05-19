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

/**
 * Continuous increment test, no overflows so it should just return the
 * same value.
 */
static void test_increment1() {
	fake_millis = 0;

	TEST_ASSERT_EQUAL_UINT64((uint64_t)0, uuid::get_uptime_ms());

	fake_millis = 1;

	TEST_ASSERT_EQUAL_UINT64((uint64_t)1, uuid::get_uptime_ms());

	fake_millis = 2;

	TEST_ASSERT_EQUAL_UINT64((uint64_t)2, uuid::get_uptime_ms());
}

/**
 * Discontinuous increment test, no overflows so it should just return the
 * same value.
 */
static void test_increment2() {
	fake_millis = 42;

	TEST_ASSERT_EQUAL_UINT64((uint64_t)42, uuid::get_uptime_ms());

	fake_millis = 640;

	TEST_ASSERT_EQUAL_UINT64((uint64_t)640, uuid::get_uptime_ms());

	fake_millis = 819200;

	TEST_ASSERT_EQUAL_UINT64((uint64_t)819200, uuid::get_uptime_ms());
}

/**
 * Continuous increment test with overflow.
 */
static void test_overflow1() {
	fake_millis = 0xFFFFFFFEUL;

	TEST_ASSERT_EQUAL_UINT64((uint64_t)0xFFFFFFFEUL, uuid::get_uptime_ms());

	fake_millis = 0xFFFFFFFFUL;

	TEST_ASSERT_EQUAL_UINT64((uint64_t)0xFFFFFFFFUL, uuid::get_uptime_ms());

	fake_millis = 0;

	TEST_ASSERT_EQUAL_UINT64((uint64_t)0x100000000UL, uuid::get_uptime_ms());

	fake_millis = 1;

	TEST_ASSERT_EQUAL_UINT64((uint64_t)0x100000001UL, uuid::get_uptime_ms());
}

/**
 * Discontinuous increment test with overflow, taking into account the
 * previous test overflow during execution.
 */
static void test_overflow2() {
	fake_millis = 0xFFFFF000UL;

	TEST_ASSERT_EQUAL_UINT64((uint64_t)0x1FFFFF000UL, uuid::get_uptime_ms());

	fake_millis = 0xF000;

	TEST_ASSERT_EQUAL_UINT64((uint64_t)0x20000F000UL, uuid::get_uptime_ms());

	fake_millis = 0x10000;

	TEST_ASSERT_EQUAL_UINT64((uint64_t)0x200010000UL, uuid::get_uptime_ms());
}

int main(int argc, char *argv[]) {
	UNITY_BEGIN();
	RUN_TEST(test_increment1);
	RUN_TEST(test_increment2);
	RUN_TEST(test_overflow1);
	RUN_TEST(test_overflow2);
	return UNITY_END();
}
