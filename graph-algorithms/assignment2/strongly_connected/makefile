CXX=g++
CXXFLAGS=-std=c++14 -Wall -pedantic -g3 -O2
PERF=-pg

at: build
	cram test.t

build: strongly_connected.o
	$(CXX) $(CXXFLAGS) -o strongly_connected.bin $^

main.o: strongly_connected.cpp

clean:
	$(RM) *.bin *.o
