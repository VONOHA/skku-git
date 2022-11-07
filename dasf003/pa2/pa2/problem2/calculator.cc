#include "calculator.h"
#include <iostream>

using namespace std;

//Implement Member Functions

int calculator::input(){
	
	char letter, num[100], index = 0;
	double *ptr;

	while( (letter = cin.get()) != '\n' ){
		if((letter <= '9' && letter >= '0') || letter == '.') num[index++] = letter;
		else if( letter == 'x') ptr = &x;
		else if( letter == 'y') ptr = &y;
		else if( letter == 'z') ptr = &z;

	}

}	
