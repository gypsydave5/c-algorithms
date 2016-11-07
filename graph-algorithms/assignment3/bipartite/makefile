CXX=g++
CXXFLAGS=-std=c++14 -Wall -pedantic -g3 -O2
PERF=-pg

at: build
	cram test.t

build: bipartite.o
	$(CXX) $(CXXFLAGS) -o bipartite.bin $^

main.o: bipartite.cpp

clean:
	$(RM) *.bin *.o
