#include <iostream>
#include <string>
#include "guess.h"


int main()
{
  //write your code here
  //call genRandomNum function to generate a random number.
  //Use while loop here to start the game.
  //call guess function to check whether a user entered the correct target number.
  	cpe::genRandomNum();
	cpe::Result r;
	std::string num_s;
	int length,num;
	char c;
	do{
		INVALID:
		std::getline(std::cin,num_s);
		length = num_s.length();
		for(int i = 0; i<length; ++i) {
			c = num_s[i];
			if( c>'9'|| c<'0' ){
				std::cout<<"Enter 0-99"<<std::endl;
				goto INVALID;
			}
		} num = std::stoi(num_s);
		if(num<0 || num>99){
			std::cout<<"Enter 0-99"<<std::endl;
			goto INVALID;
		}
		r = cpe::guess(num);
		//std::cout<<(r==cpe::Result::LARGE)<<std::endl;
		if(r == cpe::Result::SMALL) std::cout<<"More Larger"<<std::endl;
		else if(r == cpe::Result::LARGE) std::cout<<"More Smaller"<<std::endl;
		else {std::cout<<"You Won"<<std::endl;break;}
	}while(1);
	return 0; 
}
