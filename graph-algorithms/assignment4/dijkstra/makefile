CXX=g++
CXXFLAGS=-std=c++14 -Wall -pedantic -g3 -O2
PERF=-pg

at: build
	cram test.t

at-naive: build-naive
	cram test.t

build: dijkstra.o
	$(CXX) $(CXXFLAGS) -o dijkstra.bin $^

build-naive: dijkstra_naive.o
	$(CXX) $(CXXFLAGS) -o dijkstra.bin $^

dijkstra.o: dijkstra.cpp
dijkstra_naive.o: dijkstra_naive.cpp

clean:
	$(RM) *.dijkstra *.o
