 .PHONY: all clean build run complete

BIN_DIR = public\wasm

all:
	make -s clean
	make -s build

clean:
	if exist $(BIN_DIR) rd /s /q $(BIN_DIR)

build:
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	python3 build.py

run:
	cd public
	python3 -m http.server 8080
