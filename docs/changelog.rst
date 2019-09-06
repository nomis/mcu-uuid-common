Change log
==========

Unreleased_
-----------

Changed
~~~~~~~

* Put each function in a separate file to improve linker behaviour.

1.0.2_ |--| 2019-08-16
----------------------

Fix example.

Fixed
~~~~~

* Example now prints the time part of the uptime instead of ignoring it.

1.0.1_ |--| 2019-08-15
----------------------

Update example and add tests.

Added
~~~~~

* Test builds of the example.
* Unit tests of the uptime overflow handling.

Changed
~~~~~~~

* Exclude the test directory from exports of the library source code.

Fixed
~~~~~

* Remove use of ``Serial.printf()`` from the example (which does not
  exist in the standard Arduino library).

1.0.0_ |--| 2019-08-11
----------------------

First stable release.

Added
~~~~~

* Function ``void uuid::loop()`` that should be called regularly.
* Function ``uint64_t uuid::get_uptime_ms()`` to get the current uptime
  as a 64-bit milliseconds value.
* Function ``std::string uuid::read_flash_string(const __FlashStringHelper *flash_str)``
  to convert flash strings to ``std::string``.
* Type ``uuid::flash_string_vector`` for a ``std::vector`` of flash strings.

.. |--| unicode:: U+2013 .. EN DASH

.. _Unreleased: https://github.com/nomis/mcu-uuid-common/compare/1.0.2...HEAD
.. _1.0.2: https://github.com/nomis/mcu-uuid-common/compare/1.0.1...1.0.2
.. _1.0.1: https://github.com/nomis/mcu-uuid-common/compare/1.0.0...1.0.1
.. _1.0.0: https://github.com/nomis/mcu-uuid-common/commits/1.0.0