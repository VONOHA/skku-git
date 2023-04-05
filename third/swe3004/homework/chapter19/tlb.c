#include <bits/types/struct_timeval.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char **argv)
{
	if(argc<4)
	{
		// 1 for pages;
		// 2 for trials;
		// 3 for result file name;
		printf("Invalid Arguments\n");
		exit(1);
	}

	int pages, trial, *arr;
	long pagesize, jump;
	FILE *fp;

	pagesize = sysconf(_SC_PAGESIZE);
	jump = pagesize/sizeof(int);
	
	pages = atoi(argv[1]);
	trial = atoi(argv[2]);

	fp = fopen(argv[3], "a");

	arr = (int *)malloc((size_t)pages * (size_t)pagesize);
	
	struct timeval startTime, endTime;

	double difftime;
	
	difftime = 0;
	for(int j = 0; j<trial; ++j)
	{
		gettimeofday(&startTime, NULL);
		for(int i = 0; i < pages; i += jump)
		{
			arr[i] = i;
		}
		gettimeofday(&endTime, NULL);
		
		difftime += (endTime.tv_sec - startTime.tv_sec)*1000000000\
							 + (endTime.tv_usec - startTime.tv_usec);
	}

	fprintf(fp, "%d, %.9f\n", pages, difftime/(trial));

	fclose(fp);

	free(arr);

	return 0;
}
