CXX=g++
CXXFLAGS=-std=c++14 -Wall -pedantic -g3 -O2
PERF=-pg

at: build
	cram test.t

at-naive: build-naive
	cram test.t

build: bwt.o
	$(CXX) $(CXXFLAGS) -o bwt $^

bwt.o: bwt.cpp

clean:
	$(RM) *.o bwt
