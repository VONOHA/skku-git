#include "array.h"

void mk_tc(int n){
	
	int priority, *arr = 0, tmp, m;
	// n for number of inputs
	// priority is priority
	// arr is array for priority;
	// tmp&m for swapping
	char address[100];
	FILE* fp = fopen("testcases.txt","w");

	arr = (int*)calloc(n,sizeof(int));

	for(int i = 0; i<n; ++i) arr[i] = i;

	srand(time(NULL));

	for(int p = rand()%n, i = 0; i<p; ++i){
		m = rand()%n;
		tmp = arr[m];
		arr[m] = arr[n-1-m];
		arr[n-1-m] = tmp;
	}
	
	for(int i =0; i < n; ++i){
		priority = arr[i];
		fprintf(fp,"%d ",priority);
		for(int l = 0; l< 100; ++l) fprintf(fp,"%c",rand()%26 + 65);
		fprintf(fp,"\n");
	}

	fclose(fp);
}
