#include <stdio.h>
#include <sys/time.h>
#define MAX_TIMES 10000


int main(void)
{
	struct timeval time[MAX_TIMES];

	for(int i = 0; i<MAX_TIMES; ++i)
		gettimeofday(time+i, NULL);

	printf("%f", (time[MAX_TIMES-1].tv_usec - time[0].tv_usec)/(float)MAX_TIMES);
	return 0;
}
