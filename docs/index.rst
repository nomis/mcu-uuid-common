mcu-uuid-common
===============

Description
-----------

Microcontroller common utilities library

Purpose
-------

The primary purpose of this library is to maintain a common 64-bit uptime in
milliseconds with overflow handling, as long as the loop function is called
regularly. Thread-safe on the ESP32 but cannot be used from an interrupt
context.


Contents
--------

.. toctree::
   :titlesonly:
   :maxdepth: 1

   usage

Resources
---------

.. toctree::
   :titlesonly:
   :maxdepth: 1

   Source code <https://github.com/nomis/mcu-uuid-common>
   Releases <https://github.com/nomis/mcu-uuid-common/releases>
   Namespace reference <https://mcu-doxygen.uuid.uk/namespaceuuid.html>
   PlatformIO library <https://registry.platformio.org/libraries/nomis/uuid-common>
   changelog
   Issue tracker <https://github.com/nomis/mcu-uuid-common/issues>
