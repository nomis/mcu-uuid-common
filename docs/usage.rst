Usage
=====

.. code:: c++

   #include <uuid/common.h>

Call ``uuid::loop()`` regularly and then call ``uuid::get_uptime_ms()`` when
the uptime is required.

Example
-------

.. literalinclude:: ../examples/Uptime.cpp
