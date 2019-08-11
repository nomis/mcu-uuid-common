Common utilities library
========================

The primary purpose of this library is to maintain a common 64-bit
uptime in milliseconds with overflow handling, as long as the loop
function is called regularly.

* `Change log <CHANGELOG.rst>`_

Usage
-----

Call ``uuid::loop()`` regularly and then call ``uuid::get_uptime_ms()``
when the uptime is required.
