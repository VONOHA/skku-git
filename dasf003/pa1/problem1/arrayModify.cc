#include "arrayModify.h"
#include <iostream>
//implement these functions
void printArray(int *arr, int num){
	//write your code here!
	for(int i = 0; i< num ; ++i) std::cout<<arr[i]<<" ";
}
void arrayModify(int *arr, int num){
	//write your code here!
	/*std::cout<<"In ";
	printArray(arr,num);
	std::cout<<"\n";*/
	int stack_0[10]={0}, stack_1[10]={0}, stack[10]={0}, top_0 = -1, top_1 = -1, top = -1, index = 0, n, value;
	
	for(int i = 0; i<num; ++i){
		//printArray(stack_0,10);std::cout<<"\n";
		//printArray(stack_1,10);std::cout<<"\n";
		//printArray(stack,10);std::cout<<"\n";
		n = arr[i];
		//std::cout<<n<<std::endl;
		if( n%2 == 0 ){
			//std::cout<<n<<std::endl;	
			while (1){
				if(top_0>-1){
					value = stack_0[top_0--];
					if(value > n){
						stack[++top] = value;
					}else{ 
						stack_0[++top_0]=value;
						break;
					}
				}else break;
				
			}

			stack_0[++top_0]=n;
			//printArray(stack_0,10); std::cout<<std::endl;	
			while( top > -1 ) stack_0[++top_0] = stack[top--];
			
		}else{
			//std::cout<<n<<std::endl;
			while(1){
				if(top_1>-1){
					value = stack_1[top_1--];
					if(value<n){
						stack[++top] = value;
					}else{
						stack_1[++top_1] = value;
						break;
					}
				}else break;
				
			}
			stack_1[++top_1]= n;
			//printArray(stack_1,10);std::cout<<std::endl;
			while( top > -1) stack_1[++top_1] = stack[top--];
		}
	}

	while(top_1>-1) arr[index++] = stack_1[top_1--];
	while(top_0>-1) arr[index++] = stack_0[top_0--];
}

