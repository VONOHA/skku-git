#include<iostream>
#include<string>
#include "arrayModify.h"

int main(){
  //write your code here!
  //you should call arrayModify function to modify array
  //you should call printArray function to print array
	//using namespace std;	  
	int arr[10],index=-1;

	std::string s;
	
	//char check[2];
	
	std::getline(std::cin,s);
	
	if(s.length()!=19&&s.length()!=20){
		std::cout<<"Number must be between 0~9";
		return 0;
	}else if(s.length()==20){
		if(s[19]!=' ') std::cout<<"Number must be between 0~9";
	}
	int l = s.length();
	for(int i = 0; i<l; ++i){
		if(!(i%2)){
			if(s[i]<0x30||s[i]>0x39){
				std::cout<<"Number must be between 0~9";
				return 0;
			}
		}
		else if(s[i]!=' '){std::cout<<"Number must be between 0~9";
		return 0;}
		/*
		if((s[i]<'0'||s[i]>'9')&&s[i]!=' '){
			std::cout<<"Number must be between 0~9";
			return 0;
		}*/
		if(s[i]!=' '){
			arr[++index] = s[i];
			arr[index] -= 0x30;
		}
	}
	
	/*
	for(int i = 0; i< 10; ++i) {
		
		if((num = arr[i]) < 0 || num > 9){

			std::cout<<"Number must be between 0~9";
			
			return 0;

		}

	}*/

	arrayModify(arr,10);
	printArray(arr,10);
	
	return 0;
}
