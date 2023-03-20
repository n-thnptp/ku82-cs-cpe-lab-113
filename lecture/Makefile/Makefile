SHELL := bash

CXX = g++
CXXFLAGS = -g

run: main
	# ----- putting output to output1.txt ----- #
	./main.out > output1.txt
	# ----- opening file output1.txt in vscode ----- #
	code output1.txt

main: clean main.o				# "make main" = execute rule "clean" -> "main.o" -> "main"
	$(CXX) $(CXXFLAGS) main.o -o main.out

main.o:
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o main.out