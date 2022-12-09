all: skku_sh

skku_sh: Directory.o Entry.o File.o main.o
	g++ -W -Wall -o $@ $^

clear:
	rm -rf skku_sh *.o
