# Write your makefile here
# Build an executable binary named "wordProcess"

all : wordProcess

wordProcess: main.o wordProcess.o
	g++ -W -Wall -o $@ $^

main.o: main.cc
	g++ -W -Wall -c -o $@ $^

wordProcess.o: wordProcess.cc
	g++ -W -Wall -c -o $@ $^

clean:
	rm -rf *.o wordProcess
