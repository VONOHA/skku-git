#include "types.h"
#include "user.h"
#include "stat.h"

int main(){
	printf(1,"calling getnice syscall \n");
	printf(1,"getnice : %d\n",getnice(getpid()));
	printf(1, "setting nice to 24 \n");
	printf(1,"setnice : %s\n",setnice(getpid(),24)?"FAIL":"SUCCESS");
	printf(1,"recalling getnice syscall \n");
	printf(1,"getnice : %d\n",getnice(getpid()));
	printf(1,"calling ps syscall in current process\n");
	ps(getpid());
	printf(1,"view everything\n");
	ps(0);
	exit();
}
