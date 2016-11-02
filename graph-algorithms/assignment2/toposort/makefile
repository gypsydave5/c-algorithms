CXX=g++
CXXFLAGS=-std=c++14 -Wall -pedantic -g3 -O2
PERF=-pg

at: build
	cram test.t

build: toposort.o
	$(CXX) $(CXXFLAGS) -o toposort.bin $^

main.o: toposort.cpp

clean:
	$(RM) *.bin *.o
