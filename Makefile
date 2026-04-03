CMAKE_DIR = cmake
SCHEME = LIMIT1
SIMULATOR = generic/platform=iOS Simulator

-include .env
export

.PHONY: all generate build open clean reset init

all: generate build

generate:
	mkdir -p $(CMAKE_DIR)
	cmake -S . -B $(CMAKE_DIR) -G Xcode \
		-DCMAKE_SYSTEM_NAME=iOS \
		-DCMAKE_OSX_DEPLOYMENT_TARGET=16.0 \
		-DCMAKE_OSX_ARCHITECTURES=arm64

build:
	xcodebuild -project $(CMAKE_DIR)/$(SCHEME).xcodeproj \
		-scheme $(SCHEME) \
		-destination "$(SIMULATOR)" \
		-configuration Debug \
		build

open:
	open $(CMAKE_DIR)/$(SCHEME).xcodeproj

clean:
	xcodebuild -project $(CMAKE_DIR)/$(SCHEME).xcodeproj \
		-scheme $(SCHEME) \
		clean

reset:
	rm -rf $(CMAKE_DIR)

init:
	git submodule update --init --recursive
