#include "types.h"
#include "user.h"
#include "stat.h"

int main(int argc, char** argv){
	if(argc<2)
	{
		printf(1,"enter the options!");
		exit();
	}
	printf(1,"pid %d priority : %d\n",atoi(argv[1]),getnice(atoi(argv[1])));
	exit();
}
