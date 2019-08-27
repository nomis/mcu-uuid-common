.PHONY: all build native

all: build native
	python3 version_check.py

build:
	rm -rf build/*/.pio
	platformio run -d build/example-Uptime
	build/example-Uptime/.pio/build/native/program >../examples/Uptime.txt

native:
	rm -rf native/.pio
	platformio test -d native
