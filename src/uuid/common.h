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

#ifndef UUID_COMMON_H_
#define UUID_COMMON_H_

#include <Arduino.h>

#include <string>
#include <vector>

/**
 * Common utilities.
 *
 * - <a href="https://github.com/nomis/mcu-uuid-common/">Git Repository</a>
 * - <a href="https://platformio.org/lib/show/6624/uuid-common">PlatformIO library</a>
 */
namespace uuid {

/**
 * Read a string from flash and convert it to a std::string.
 *
 * The flash string must be stored with appropriate alignment for
 * reading it on the platform.
 *
 * @param[in] flash_str Pointer to string stored in flash.
 * @since 1.0.0
 */
std::string read_flash_string(const __FlashStringHelper *flash_str);

/**
 * Type definition for a std::vector of flash strings.
 *
 * @since 1.0.0
 */
using flash_string_vector = std::vector<const __FlashStringHelper*>;

/**
 * Loop function that must be called regularly to detect a 32-bit
 * uptime overflow.
 *
 * @since 1.0.0
 */
void loop();

/**
 * Get the current uptime as a 64-bit milliseconds value.
 *
 * @return The current uptime in milliseconds.
 * @since 1.0.0
 */
uint64_t get_uptime_ms();

} // namespace uuid

#endif
