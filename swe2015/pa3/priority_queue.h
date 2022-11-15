#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct element{
	
	int priority;
	char data[101];
	void* next;

}element;

void mk_tc(int n);
void array(int n);
void linked_list(int n);
//void max_heap(int n);
//void binary_search_tree(int n);
