.PHONY: all build native

all: build native
	python3 version_check.py

build:
	rm -rf build/*/.pio
	platformio run -d build/example-Uptime

native:
	rm -rf native/.pio
	platformio test -d native
