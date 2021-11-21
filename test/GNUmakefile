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
	wget https://raw.githubusercontent.com/nomis/mcu-uuid-doxygen/main/Doxyfile -O Doxyfile
	rm -rf html
	(cat Doxyfile; echo INPUT += ../src) | doxygen - 1>doxygen.out 2>doxygen.err
	cat doxygen.err
	cmp /dev/null doxygen.err
