CXX=g++
CXXFLAGS=-std=c++14 -Wall -pedantic -g3 -O2
PERF=-pg

at: build
	cram test.t

build: dijkstra.o
	$(CXX) $(CXXFLAGS) -o dijkstra.bin $^

main.o: dijkstra.cpp

clean:
	$(RM) *.dijkstra *.o
