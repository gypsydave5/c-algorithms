CXX=g++
CXXFLAGS=-std=c++14 -Wall -pedantic -g3 -O2
PERF=-pg

at: build
	cram test.t

at-naive: build-naive
	cram test.t

build: trie_matching_extended.o
	$(CXX) $(CXXFLAGS) -o trie_matching_extended.bin $^

trie_matching_extended.o: trie_matching_extended.cpp

clean:
	$(RM) *.connecting_points *.o
