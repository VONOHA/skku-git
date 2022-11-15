#include "array.h"

typedef struct{
	
	int priority;
	char data[101];

}element;

void array(int n){
	
	element *arr = (element*)calloc(n,sizeof(element));
	
	FILE* fp = fopen("testcases.txt","r"), *fpp = fopen("result.txt","w");
	
	int min_i = -1, min_p = -1, length;
	
	for(int i = 0; i<n; ++i){
		fscanf(fp,"%d %s",&(arr[i].priority), arr[i].data);
	}
	
	fclose(fp);
		
	for(int i = 0; i<n; ++i){
		
		min_i = -1, min_p = -1;
		
		for(int l = 0;l <n; ++l){
			if(min_p <  arr[l].priority) min_p = arr[l].priority, min_i = l;
		}
		
		fprintf(fpp, "%d %s\n", arr[min_i].priority, arr[min_i].data);
		
		arr[min_i].priority = -1;
		length = strlen(arr[min_i].data);

		for(int j = 0; j<length; ++j) arr[min_i].data[j] = '\0';
	
	}

}
