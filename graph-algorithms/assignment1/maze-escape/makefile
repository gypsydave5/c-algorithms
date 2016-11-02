CXX=g++
CXXFLAGS=-std=c++14 -Wall -pedantic -g3 -O2
PERF=-pg

at: build
	cram test.t

build: main.o
	$(CXX) $(CXXFLAGS) -o reach.bin $^

main.o: main.cpp

clean:
	$(RM) *.bin *.o
