#include "guess.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomNum = 0;

cpe::Result cpe::guess(int num) { 
  //write your code here!
	if(num > randomNum) return Result::LARGE;
	else if (num<randomNum) return Result::SMALL;

  return Result::CORRECT; 
}

void cpe::genRandomNum(){
	srand(time(nullptr));
	randomNum = rand()%100;
	//cout<<randomNum<<endl;
}
  //Implement genRandomNum function here
  //This generate random number and store it into randomNum variable
  //reference guess.h file for the function signature
  
