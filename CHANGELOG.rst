Change log
==========

Unreleased_
-----------

Added
~~~~~

* Test builds of the example.

Changed
~~~~~~~

* Exclude the test directory from exports of the library source code.

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

.. _Unreleased: https://github.com/nomis/mcu-uuid-common/compare/1.0.0...HEAD
.. _1.0.0: https://github.com/nomis/mcu-uuid-common/commits/1.0.0
