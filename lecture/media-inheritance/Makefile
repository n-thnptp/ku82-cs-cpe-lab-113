SHELL := bash

CXX = g++
CXXFLAGS = -g

run: main
	./main.out

main: clean Media.o Image.o Video.o main.o
	# combining Media.o, Image.o, and main.o to main.out...
	$(CXX) $(CXXFLAGS) Media.o Image.o Video.o main.o -o main.out

main.o:
	# compiling main.cpp to main.o...
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Media.o:
	# compiling Media.cpp to Media.o... 
	$(CXX) $(CXXFLAGS) -c Media.cpp -o Media.o

Image.o:
	# compiling Image.cpp to Image.o...
	$(CXX) $(CXXFLAGS) -c Image.cpp -o Image.o

Video.o:
	# compiling Video.cpp to Video.o...
	$(CXX) $(CXXFLAGS) -c Video.cpp -o Video.o

clean:
	# cleaning old files...
	rm -f *.o main.out