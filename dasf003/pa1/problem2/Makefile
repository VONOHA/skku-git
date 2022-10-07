# Write your makefile here
# Build an executable binary named "arabians"

CC = g++
FLAG = -W -Wall
TARGET = arabians

all: $(TARGET)

$(TARGET): arabians.o display.o main.o
	$(CC) $(FLAG) -o $@ $^

arabians.o: arabians.cc
	$(CC) $(FLAG) -c -o $@ $^

display.o: display.cc
	$(CC) $(FLAG) -c -o $@ $^

main.o: main.cc
	$(CC) $(FLAG) -c -o $@ $^

clean:
	rm -rf *.o arabians
