#include "types.h"
#include "user.h"
#include "stat.h"

int main(int argc, char** argv){
	if(argc<2)
	{
		printf(1,"enter the options!");
		exit();
	}
	if(!setnice(atoi(argv[1]),atoi(argv[2])))
		printf(1,"SUCCESS!\npid %d priority changed into %d\n",atoi(argv[1]),atoi(argv[2]));
	else
		printf(1,"FAIL\n");
	exit();
}
