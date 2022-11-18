#include "priority_queue.h"

void max_heap(int n){

	element *arr = (element*)calloc(n+1,sizeof(element)),dummy;

	arr[0].priority = 0;

	int front = 0, position = 0;

	FILE* fp = fopen("testcases.txt","r"), *fpp = fopen("max_heap.txt","w");
	
	for(int i = 0; i<n; ++i){
		fscanf(fp,"%d %s",&(dummy.priority), dummy.data);
		position = front+1;
		while(1){
			if(arr[position].priority){
				
				if(arr[position-1].priority >= dummy.priority ){
					
					arr[position].priority = dummy.priority;
					strcat(arr[position].data, dummy.data);
					front += 1;
					break;
				
				}else{

					arr[position].priority = arr[position/2].priority;
					strcat(arr[position].data, arr[position/2].data);
					position /= 2;

				}
			
			}
			else {

				arr[position].priority = dummy.priority;
				strcat(arr[position].data,dummy.data);
				front = position;
				break;

			}
		}
	}
	
	fclose(fp);
	
	for(int i = 1; i < n+1; ++i)fprintf(fpp, "%d %s\n", arr[i].priority, arr[i].data);
	
	fclose(fpp);

	free(arr);
}
