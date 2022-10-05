#include "arrayModify.h"

int main(){
  //write your code here!
  //you should call arrayModify function to modify array
  //you should call printArray function to print array
	  
	int arr[10], num;
	
	char check[2];
	
	for(int i = 0; i<10; ++i) std::cin>>arr[i];
	
	std::cin.getline(check,2);
	
	if(check[0]!='\0'){
		
		std::cout<<"Enter 10 numbers";
		
		return 0;
	}

	for(int i = 0; i< 10; ++i) {
		
		if((num = arr[i]) < 0 || num > 9){

			std::cout<<"Number must be between 0~9";
			
			return 0;

		}

	}

	arrayModify(arr,10);
	printArray(arr,10);
	
	return 0;
}
