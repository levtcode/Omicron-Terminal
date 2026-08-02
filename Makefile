# Wrapper del flujo de CMake. Igual en macOS y en Linux.
# Uso: make | make test | make run ARGS="-- /bin/sh" | make clean

BUILD_DIR ?= build
BUILD_TYPE ?= Debug
CMAKE ?= cmake
CTEST ?= ctest
JOBS ?= $(shell nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)

.PHONY: all configure build test run clean rebuild help

all: build

configure: $(BUILD_DIR)/CMakeCache.txt

$(BUILD_DIR)/CMakeCache.txt:
	$(CMAKE) -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=$(BUILD_TYPE)
	ln -sf $(BUILD_DIR)/compile_commands.json compile_commands.json

build: configure
	$(CMAKE) --build $(BUILD_DIR) --parallel $(JOBS)

test: build
	$(CTEST) --test-dir $(BUILD_DIR) --output-on-failure

run: build
	./$(BUILD_DIR)/omicron $(ARGS)

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean build

help:
	@echo "make          compila"
	@echo "make test     compila y corre los tests"
	@echo "make run      ARGS=\"--allow-rw /tmp -- /bin/sh\""
	@echo "make clean    borra $(BUILD_DIR)/"
