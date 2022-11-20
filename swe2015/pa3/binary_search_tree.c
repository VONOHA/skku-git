#include "priority_queue.h"


void binary_search_tree(int n){
	
	FILE* fp = fopen("testcases.txt","r"), *fpp = fopen("binary_serach_tree.txt","w");
	
	element genesis = {.priority = 0, .prev = 0, .next = 0}, *position = 0;

	int p;
	char d[101];

	for(int i = 0; i<n; ++i){

		fscanf(fp, "%d %s", &p, d);
		position = &genesis;
		
		do{

			if(p > position->priority) position = position->next;
			else position = position->prev;

		}while(position->next || position->prev);

		position->priority = p;
		strcat(position->data,d);
		position->next = 0;
		position->prev = 0;

	}

	fclose(fp);
	fclose(fpp);
}
