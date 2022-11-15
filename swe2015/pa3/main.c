#include "priority_queue.h"

int main(void){
	
	int n;
	double result;
	time_t start,end;
	
	printf("Insert the number of inputs: ");
	scanf("%d",&n);
	
	//making testcases
	mk_tc(n);
	//CASE1: ARRAY
	start = clock();
	
	array(n);
	
	end = clock();
	
	result = (double)(end - start);
	
	printf("array: %f(ms)\n", result);
	//CASE2: LINKED_LIST
	start = clock();
	
	linked_list(n);
	
	end = clock();
	
	result = (double)(end - start);
	
	printf("linked list: %f(ms)\n", result);

	return 0;
}
