CXX=g++
CXXFLAGS=-std=c++14 -Wall -pedantic -g3 -O2
PERF=-pg

at: build
	cram test.t

at-naive: build-naive
	cram test.t

build: connecting_points.o
	$(CXX) $(CXXFLAGS) -o connecting_points.bin $^

connecting_points.o: connecting_points.cpp

clean:
	$(RM) *.connecting_points *.o
