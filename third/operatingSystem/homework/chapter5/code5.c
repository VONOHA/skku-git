#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv){
	int x, pid, wpid;

	x = 100;
	pid = fork();
	
	if(pid<0){
		printf("fork() didn't work.\n");
		exit(1);
	}else if(pid == 0){
		x = 10;
		wpid = waitpid(pid,NULL,0);
		printf("waitpid returns %d in child precess\n",wpid);
		printf("chid pid : %d\n", getpid());
	}else{
		wpid = waitpid(pid,NULL,0);
		x = 20;
		printf("waitpid returns %d\n", wpid);
		printf("parent pid : %d\n", getpid());
	}
	exit(1);
}
