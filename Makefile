run:
	g++ -o main main.cpp -std=c++20 && ./main

build-ninja:
	cd build && cmake .. -G Ninja && ninja

ctest:
	make build-ninja && cd build && ctest --output-on-failure

clear:
	rm -rf build/*