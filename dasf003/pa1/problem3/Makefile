# Write your makefile here
# Build an executable binary named "guessGame"

CC = g++
F = -W -Wall

all : guessGame

OBJS = guess.o main.o

guessGame: $(OBJS)
	$(CC) $(F) -o $@ $^

main.o: main.cc
	$(CC) $(F) -c -o $@ $^

guess.o: guess.cc
	$(CC) $(F) -c -o $@ $^

clean:
	rm -rf *.o guessGame
