/*
 * uuid-common - Microcontroller common utilities
 * Copyright 2019,2022  Simon Arlott
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

#if __has_include(<mutex>)
# include <mutex>
#endif
#include <string>
#include <vector>

#if __has_include(<mutex>) && (!defined(_GLIBCXX_MUTEX) || defined(_GLIBCXX_HAS_GTHREADS))
# define UUID_COMMON_STD_MUTEX_AVAILABLE 1
#else
# define UUID_COMMON_STD_MUTEX_AVAILABLE 0
#endif

#if defined(DOXYGEN) || defined(ARDUINO_ARCH_ESP32) || UUID_COMMON_STD_MUTEX_AVAILABLE
# define UUID_COMMON_THREAD_SAFE 1
#else
# define UUID_COMMON_THREAD_SAFE 0
#endif

/**
 * Common utilities.
 *
 * - <a href="https://github.com/nomis/mcu-uuid-common/">Git Repository</a>
 * - <a href="https://mcu-uuid-common.readthedocs.io/">Documentation</a>
 */
namespace uuid {

/**
 * Thread-safe status of the library.
 *
 * @since 1.1.2
 */
#if UUID_COMMON_THREAD_SAFE
static constexpr bool thread_safe = true;
#else
static constexpr bool thread_safe = false;
#endif

/**
 * Read a string from flash and convert it to a std::string.
 *
 * The flash string must be stored with appropriate alignment for
 * reading it on the platform.
 *
 * @param[in] flash_str Pointer to string stored in flash.
 * @return A string copy of the flash string.
 * @since 1.0.0
 */
std::string read_flash_string(const __FlashStringHelper *flash_str);

/**
 * Append to a std::string by printing a Printable object.
 *
 * @param[in] printable Printable object.
 * @param[in,out] output String to append to.
 * @return The number of bytes that were written.
 * @since 1.1.0
 */
size_t print_to_string(const Printable &printable, std::string &output);

/**
 * Create a std::string from a Printable object.
 *
 * @param[in] printable Printable object.
 * @return A string containing the printed output.
 * @since 1.1.0
 */
std::string printable_to_string(const Printable &printable);

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
