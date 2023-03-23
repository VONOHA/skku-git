#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv){
	int x, pid, wpid;
	
	pid = fork();
	
	if(pid<0){
		printf("fork() didn't work.\n");
		exit(1);
	}else if(pid == 0){
		close(STDOUT_FILENO);
		printf("not closed!\n");
	}else{
		wpid = waitpid(pid,NULL,0);
		printf("surprise!");
	}
	exit(1);
}
