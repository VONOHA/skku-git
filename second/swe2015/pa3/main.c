#include "priority_queue.h"

int main(void){
	
	int n = 100;
	double result;
	time_t start,end;

	FILE *fp = fopen("./textfile/result.txt","w");
	
	//while((n+=50)< 50000){
	//making testcases
	mk_tc(n);
	
	//CASE1: ARRAY
	start = clock();
	
	array(n);
	
	end = clock();
	
	result = (double)(end - start);
	
	printf(fp,"array: %0.4f\n", result);
	
	//CASE2: LINKED_LIST
	start = clock();
	
	linked_list(n);
	
	end = clock();
	
	result = (double)(end - start);
	
	fprintf(fp,"linked_list: %0.4f\n", result);

	//CASE3: MAX_HEAP
	start = clock();
	
	max_heap(n);
	
	end = clock();
	
	result = (double)(end - start);
	
	fprintf(fp,"max_heap: %0.4f\n", result);
	
	//CASE4: BINARY_SEARCH_TREE
	start = clock();
	
	binary_search_tree(n);

	end = clock();
	
	result = (double)(end - start);
	
	fprintf(fp,"binary_search_tree: %0.4f\n", result);
	
	return 0;
}
