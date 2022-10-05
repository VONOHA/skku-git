#include "arrayModify.h"

//implement these functions
void printArray(int *arr, int num){
  //write your code here!
	for(int i = 0; i<num; ++i){
		cout<<arr[i]<<" ";
	}
}
void arrayModify(int *arr, int num){
  //write your code here!
	void push(int *arr, int *top, int num){
		arr[++(*top)] = num;
	}

	int pop(int *arr, int *top){
		if(top<0) return -1;
		else{
			int value = arr[(*top)--];
			return value;
		}
	}


	int stack_0[10]. stack_1[10], top_0 = -1, top_1 = -1, stack[10], top = -1, value, n = arr[0];

	if(n%2) stack_0[++top_0] = n;
	else stack_[++top_1] = n;

	for(int i = 1; i<num; ++i){
		
		n = arr[i];
		
		if(n%2){
		
		while((value = pop(stack_0,&top_0))<n && value != -1) push(stack,&top,value);
		
		push(stack_0,&top_0,n);
		
		while((value = pop(stack,&top)!=-1) push(stack_0,&top_0,value);
		
				}else {
		
		while((value = pop(stack_1,&top_1))>n && value != -1) push(stack,&top,value);
		
		push(stack_1,&top_1,n);
		
		while((value = pop(stack,&top)!=-1) push(stack_1,&top_1,value);
				}
	}

	for(int i = 0; i<=top_1; ++i){
	
		arr[i] = stack_1[i];
	
		}
	
	for(int i = top_1 +1; i <= top_1+top_2+1; ++i){
		
		arr[i] = stack_0[i-top_1-1];
	
		}

}

