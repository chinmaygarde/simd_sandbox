.PHONY: build

bench: build
	./build/merle_benchmarks

test: build
	./build/merle_tests

build: build/build.ninja
	ninja -C build

build/build.ninja:
	mkdir -p build
	cmake -G Ninja -B build -DCMAKE_BUILD_TYPE=Release

clean:
	rm -rf build

sync:
	git submodule update --init --recursive --jobs 8
