Usage
=====

.. code:: c++

   #include <uuid/common.h>

Call |uuid::loop()|_ regularly and then call |uuid::get_uptime_ms()|_ when
the uptime is required.

Example
-------

.. literalinclude:: ../examples/Uptime.cpp

Output
~~~~~~

.. literalinclude:: ../examples/Uptime.txt

.. |uuid::loop()| replace:: ``uuid::loop()``
.. _uuid::loop(): https://mcu-doxygen.uuid.uk/namespaceuuid.html#ae79301ba196893006f82ee49ed75c2d7

.. |uuid::get_uptime_ms()| replace:: ``uuid::get_uptime_ms()``
.. _uuid::get_uptime_ms(): https://mcu-doxygen.uuid.uk/namespaceuuid.html#aa75052ec6341f0b7d7e2c1e67f80278d
