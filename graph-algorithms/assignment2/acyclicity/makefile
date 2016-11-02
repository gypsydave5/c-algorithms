CXX=g++
CXXFLAGS=-std=c++14 -Wall -pedantic -g3 -O2
PERF=-pg

at: build
	cram test.t

build: acyclicity.o
	$(CXX) $(CXXFLAGS) -o acyclicity.bin $^

main.o: acyclicity.cpp

clean:
	$(RM) *.bin *.o
