# Write your makefile here

-std = c++14

all : calculator

calculator: calculator.o main.o
	g++ -W -Wall -o $@ $^

clean: 
	rm -rf *.o calculator
