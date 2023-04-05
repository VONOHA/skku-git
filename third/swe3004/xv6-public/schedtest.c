#include "types.h"
#include "user.h"
#include "stat.h"

int main(int argc, char** argv){

	setnice(getpid(),5);

	printf(1,"=== test 0 begin ===\n");

	char *_argv[] = {"./ps","0"}; 
	int childpid = fork();

	if(!childpid)
	{
		setnice(getpid(),35);
		exec(_argv[0],_argv);
	}

	printf(1,"=== test 1 begin ===\n");

	ps(0);

	wait();
	exit();
}
