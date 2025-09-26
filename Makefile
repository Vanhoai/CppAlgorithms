DESTINATION=theory/02_data_structures/arrays_difference_array

run-destination:
	cd build && ./$(DESTINATION)

run:
	g++ -o main main.cpp -std=c++20 && ./main

build-and-run:
	make build-ninja && make run-destination

build-ninja:
	cd build && cmake .. -G Ninja && ninja

ctest:
	make build-ninja && cd build && ctest --output-on-failure

clear:
	rm -rf build/*
