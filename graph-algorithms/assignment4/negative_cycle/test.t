CXX=g++
CXXFLAGS=-std=c++14 -Wall -pedantic -g3 -O2
PERF=-pg

at: build
	cram test.t

build: negative_cycle.o
	$(CXX) $(CXXFLAGS) -o negative_cycle.bin $^

negative_cycle.o: negative_cycle.cpp

clean:
	$(RM) *.bin *.o
