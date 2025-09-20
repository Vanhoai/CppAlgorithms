run:
	g++ -std=c++20 -o main main.cpp && ./main

test:
	cd build && cmake .. -G Ninja && ninja && ctest