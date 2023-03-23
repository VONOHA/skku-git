#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv){
	
	char *child, *parent;
	int pid, fp;
	
	child = "operating\n", parent = "system";
	fp = open("example.txt", O_RDWR);

	pid = fork();

	if(pid < 0){
		printf("fork() didn't work.\n");
		exit(1);
	}else if(!pid){
		write(fp, child, strlen(child));
		exit(1);
	}else{
		wait(NULL);
		write(fp, parent, strlen(parent));
		exit(1);
	}
}
