#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void){
	char *argv[] = {"-al"};
	int pid = fork();

	if(pid<0){
		printf("fork error\n");
		exit(1);
	}else if(!pid){
		char *myargs[3];
		myargs[0] = strdup("/bin/ls");
		myargs[1] = strdup("-al");
		myargs[2] = NULL;
		execv(myargs[0],myargs);
		exit(1);
	}else{
		wait(NULL);
		exit(1);
	}
}
