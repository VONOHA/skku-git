# Write your makefile here

CC=g++
F = -W -Wall

all: fraction

fraction: fraction.o main.o
	$(CC) $(F) -o $@ $^

clean:
	rm -rf *.o fraction
