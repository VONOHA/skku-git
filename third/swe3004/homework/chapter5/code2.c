#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char **argv){
	int pid;
	char *child, *parent;
	register int status;

	child = "hello!\n", parent = "goodbye!\n";

	status = 1;
	pid = fork();
	
	if(pid < 0){
		printf("fork() didn't work.\n");
		exit(1);
	}else if(!pid){
		printf("%s",child);
		status = 0;
		exit(1);
	}else{
		printf("%s",parent);
		exit(1);
	}
}
