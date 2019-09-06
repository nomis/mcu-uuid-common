.PHONY: all build native doxygen

all: build native doxygen
	python3 version_check.py

build:
	rm -rf build/*/.pio
	platformio run -d build/example-Uptime
	build/example-Uptime/.pio/build/native/program >../examples/Uptime.txt

native:
	rm -rf native/.pio
	platformio test -d native

doxygen:
	wget https://raw.githubusercontent.com/nomis/mcu-uuid-doxygen/master/Doxyfile -O Doxyfile
	rm -rf doxygen
	doxygen
