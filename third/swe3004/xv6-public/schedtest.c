#include "types.h"
#include "user.h"
#include "stat.h"

int main(int argc, char** argv){

	setnice(getpid(),39);

	printf(1,"=== test 0 begin ===\n");

	int child;

	child = fork();

	if(!child)
	{
		setnice(getpid(),38);
		for(int i = 0; i < 1000; i++)
			getnice(getpid());
		for(int i = 0; i < 1000; i++)
			getnice(getpid());
		for(int i = 0; i < 1000; i++)
			getnice(getpid());
		if(!fork())
		{
			for(int i = 0; i < 1000; i++)
				getnice(getpid());
			for(int i = 0; i < 1000; i++)
				getnice(getpid());
			ps(0);
			exit();
		}


		for(int i = 0; i < 1000; i++)
			getnice(getpid());
		ps(0);
		wait();
		exit();
	}
	else {
		for(int i = 0; i < 1000; i++)
			getnice(getpid());
		for(int i = 0; i< 100000; ++i)
			getnice((getpid()));
		for(int i = 0; i< 100000; ++i)
			getnice(getpid());
		for(int i = 0; i< 100000; ++i)
			getnice(getpid());
		wait();
		ps(0);
	}
	exit();
}
