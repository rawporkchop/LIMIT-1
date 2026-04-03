CMAKE_DIR = cmake
XCODE_DIR = cmake/LIMIT1.xcodeproj
SCHEME = LIMIT1
SIMULATOR = generic/platform=iOS Simulator

.PHONY: all generate build open clean reset init

all: generate build

generate:
	mkdir -p $(CMAKE_DIR)
	cmake -S . -B $(CMAKE_DIR) -G Xcode \
		-DCMAKE_SYSTEM_NAME=iOS \
		-DCMAKE_OSX_DEPLOYMENT_TARGET=16.0 \
		-DCMAKE_OSX_ARCHITECTURES=arm64

build:
	xcodebuild -project $(XCODE_DIR) \
		-scheme $(SCHEME) \
		-destination "$(SIMULATOR)" \
		-configuration Debug \
		build

open:
	open $(XCODE_DIR)

clean:
	xcodebuild -project $(XCODE_DIR) \
		-scheme $(SCHEME) \
		clean

reset:
	rm -rf $(CMAKE_DIR)

init:
	git submodule update --init --recursive
