#include "priority_queue.h"


void binary_search_tree(int n){

	FILE* fp = fopen("./textfile/testcases.txt","r"), *fpp = fopen("./textfile/binary_search_tree.txt","w");
	
	element genesis;
	
	element *position = 0, *parent = 0;

	genesis.priority = -1;
	genesis.next = 0;
	genesis.prev = 0;

	int p,value;
	char d[101];

	for(int i = 0; i<n; ++i){
		fscanf(fp, "%d %s", &p, d);
		position = &genesis;
		value = 1;
		while(position){
			if(p > (position->priority)) parent = position, position = position->next, value = 1;
			else parent = position, position = position->prev, value = 0;
		}
		position = (element*)calloc(1,sizeof(element));
		position->priority = p;
		strcat(position->data,d);
		if(value) parent->next = position;
		else parent->prev = position;
	}

	while(genesis.next){

		parent = &genesis, position = genesis.next;
		while(position->next){	
			parent = position, position = parent->next;
		}

		fprintf(fpp,"%d %s\n", position->priority,position->data);
		parent->next = position->prev;

	}
	
	fclose(fp);
	fclose(fpp);
}
