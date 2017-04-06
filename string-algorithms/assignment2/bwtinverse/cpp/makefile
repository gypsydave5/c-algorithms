CXX=g++
CXXFLAGS=-std=c++14 -Wall -pedantic -g3 -O2
PERF=-pg
NAME=bwtinverse

at: build
	cram test.t

at-naive: build-naive
	cram test.t

build: $(NAME).o
	$(CXX) $(CXXFLAGS) -o $(NAME) $^

$(NAME).o: $(NAME).cpp

clean:
	$(RM) *.o $(NAME) *.err
