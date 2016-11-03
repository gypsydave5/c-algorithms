CXX=g++
CXXFLAGS=-std=c++14 -Wall -pedantic -g3 -O2
PERF=-pg

at: build
	cram test.t

build: bfs.o
	$(CXX) $(CXXFLAGS) -o bfs.bin $^

main.o: bfs.cpp

clean:
	$(RM) *.bin *.o
