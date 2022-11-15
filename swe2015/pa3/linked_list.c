#include "priority_queue.h"

typedef struct element{
	
	int priority;
	char data[101];
	element* next;

}element;

void linked_list(int n){
	
	// p for input priority
	int p;

	// d for input data
	char d[101];

	//genesis is default node of list, which will always on the rear
	//'node' is a place where the input value will be stored
	element rear = {.priority = -1, .next = 0}, *node = 0, *previous_node = 0, *now = 0, *front = &rear;
	
	//fp is file of testcases
	//ffp is file for result
	FILE* fp = fopen("testcases.txt","r"), *fpp = fopen("result.txt","w");

	for(int i = 0; i<n; ++i){
		
		//pointer for current input
		now = (element*)malloc(sizeof(element)), now->next = 0;
		
		//current input that mentioned
		fscanf(fp, "%d %s", &(now->priority), now->data);
		
		//starting position
		node = front;
		
		while(1){
		
			if(node->priority >= now->priority ) previous_node = node, node = node->next;
			else if(node == front){
				now->next = front;
				front = now;
			}
			else {
				
				now->next = node;
				previous_node->next = now;
				break;
			
			}
		
		}
		
		free(now);
	
	}
	
	fclose(fp);

	while(front->next) {
		fprintf(fpp,"%d %s\n",front->priority, front->data);
		front = front->next;
	}
}
