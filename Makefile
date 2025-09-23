run:
	g++ -std=c++20 -o main main.cpp && ./main

build-ninja:
	cd build && cmake .. -G Ninja && ninja

test:
	cd build && cmake .. -G Ninja && ninja && ctest
