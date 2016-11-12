CXX=g++
CXXFLAGS=-std=c++14 -Wall -pedantic -g3 -O2
PERF=-pg

at: build
	cram test.t

at-naive: build-naive
	cram test.t

build: shortest_paths.o
	$(CXX) $(CXXFLAGS) -o shortest_paths.bin $^

shortest_paths.o: shortest_paths.cpp

clean:
	$(RM) *.bin *.o
