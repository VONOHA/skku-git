#include "priority_queue.h"


void binary_search_tree(int n){
	
	FILE* fp = fopen("testcases.txt","r"), *fpp = fopen("binary_search_tree.txt","w");
	
	element genesis;

	element *position = 0, *parent = 0;

	genesis.priority = 0;
	genesis.next = (element*)calloc(1,sizeof(element));
	genesis.prev = (element*)calloc(1,sizeof(element));

	int p;
	char d[101];

	for(int i = 0; i<n; ++i){

		fscanf(fp, "%d %s", &p, d);
		position = genesis.next;
		while(position->priority){

			if(p > position->priority) position = position->next;
			else position = position->prev;
		}

		position->priority = ++p;
		strcat(position->data,d);
		position->next = (element*)calloc(1,sizeof(element));
		position->prev = (element*)calloc(1,sizeof(element));
	}

	while(genesis.next){

		parent = &genesis, position = &genesis;

		while(position->next)	parent = position, position = position->next;
		
		if(position->priority)	fprintf(fpp,"%d %s\n",-- position->priority,position->data);
		
		if(position->prev) parent->next = position->prev;
		else parent->next = 0;

	}
	
	fclose(fp);
	fclose(fpp);
}
