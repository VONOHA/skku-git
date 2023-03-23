#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv){
	int x, iPid, oPid, wpid, fd[2];
	char buf[1000];

	memset(buf,0,1000);

	pipe(fd);
	iPid = fork();

	if(iPid<0){
		printf("fork() didn't work.\n");
		exit(1);
	}else if(iPid == 0){
		close(fd[0]);
		dup2(fd[1],1);
		strcpy(buf,"changed!");
		printf("%s",buf);
		exit(0);
	}else{
		oPid = fork();
		if(!oPid){
			waitpid(iPid,NULL,0);
			close(fd[1]);
			dup2(fd[0],0);
			scanf("%s",buf);
			printf("message : %s (ipid: %d opid : %d)\n",buf,iPid,getpid());
			exit(0);
		}

	}
	exit(0);
}
