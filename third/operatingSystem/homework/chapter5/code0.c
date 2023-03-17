#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv){
	int x, pid;

	x = 100;
	pid = fork();
	
	if(pid<0){
		printf("fork() didn't work.\n");
		exit(1);
	}else if(pid == 0){
		x = 10;
		printf("chid : x is %d\n", x);
	}else{
		wait(NULL);
		x = 20;
		printf("parent : x is %d\n", x);
	}
	exit(1);
}
