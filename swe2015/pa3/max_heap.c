#include "priority_queue.h"

void max_heap(int n){

	element *arr = (element*)calloc(n+1,sizeof(element));
	element dummy,tmp;
	arr[0].priority = 0;

	FILE *fp = fopen("./textfile/testcases.txt","r"), *fpp = fopen("./textfile/max_heap.txt","w");
	
	int front = 0, parent, child;
	for(int i = ++front; i<n+1; i = ++front){
		fscanf(fp,"%d %s", &(dummy.priority),dummy.data);
		while( (i!=1) && (dummy.priority > arr[i/2].priority) ){
			arr[i] = arr[i/2];
			i /= 2;
		}
		arr[i] = dummy;
	}
	
	while(front){
		dummy = arr[1];
		tmp = arr[front--];
		parent = 1, child = 2;
		while(child <= front){
			
			if( (child < front) && (arr[child].priority < arr[child+1].priority)  ) ++child;
			
			if( tmp.priority >= arr[child].priority ) break;
			
			arr[parent] = arr[child];
			parent = child;
			child *= 2;
		
		}
		
		arr[parent] = tmp;
		
		fprintf(fpp,"%d %s\n", dummy.priority,dummy.data);
	}

	fclose(fp);
	fclose(fpp);
}
