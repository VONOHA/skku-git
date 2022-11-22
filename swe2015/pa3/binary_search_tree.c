#include "priority_queue.h"


void binary_search_tree(int n){
	
	FILE* fp = fopen("./textfile/testcases.txt","r"), *fpp = fopen("./textfile/binary_search_tree.txt","w");
	
	element genesis;

	element *position = 0, *parent = 0;

	genesis.priority = 0;
	genesis.next = (element*)calloc(1,sizeof(element));
	genesis.prev = 0;

	int p;
	char d[101];

	for(int i = 0; i<n; ++i){

		fscanf(fp, "%d %s", &p, d);
		position = genesis.next;
		while(position->next){

			if(p > position->priority) position = position->next;
			else position = position->prev;
			if(!position) position = (element*)calloc(1,sizeof(element));
			position->next = 0, position->prev = 0;
		}

		position->priority = p;
		strcat(position->data,d);
		position->next = 0;
		position->prev = 0;
	}

	while(genesis.next){

		parent = &genesis, position = genesis.next;
		printf("genesis.next: %d %p prev: %p next: %p\n", position->priority, position, position->prev, position->next);
		while(position->next){	
			printf("parent:%d position:%d\n",parent->priority,position->priority);
			parent = position, position = position->next;
		}

		fprintf(fpp,"%d %s\n", position->priority,position->data);
		
		parent->next = position->prev;

	}
	
	fclose(fp);
	fclose(fpp);
}
