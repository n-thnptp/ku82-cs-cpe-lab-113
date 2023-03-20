SHELL := bash

CXX = g++
CXXFLAGS = -g

run: main
	./run

main: clean Animal.o Bird.o Pet.o OwnedBird.o main.o
	$(CXX) $(CXXFLAGS) Animal.o Bird.o Pet.o OwnedBird.o main.o -o main

main.o:
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Animal.o: 
	$(CXX) $(CXXFLAGS) -c Animal.cpp -o Animal.o

Bird.o:
	$(CXX) $(CXXFLAGS) -c Bird.cpp -o Bird.o

Pet.o:
	$(CXX) $(CXXFLAGS) -c Pet.cpp -o Pet.o

OwnedBird.o:
	$(CXX) $(CXXFLAGS) -c OwnedBird.cpp -o OwnedBird.o

clean:
	rm -f *.o run