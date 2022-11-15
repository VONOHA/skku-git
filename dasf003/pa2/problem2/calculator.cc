#include "calculator.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//Implement Member Functions

void Calculator::start(void){
	int pos;
	instruction = "";
	string front, rear;

	//get  input
	cout<<"Enter your equation to calcuate: ";
	getline(cin,instruction);
		
	//remove all blanks
	while((pos = instruction.find(' '))!=string::npos) instruction.erase(pos,1);
	
	// determine which operation required
	for(auto it = ops.cbegin(); it != ops.cend(); ++it){
		if((pos = instruction.find(*it)) != string::npos) break;
	}
		
	//declaration
	if(pos == string::npos){
			declaration();
	}
	
	front = instruction.substr(0,pos);
	rear = instruction.substr(pos, instruction.length()-pos-1);
	
	if(instruction[pos] == ops[0]){
		assignment(front,rear);
	}else {
		calculate(front, rear, ops.find(instruction[pos]));
		return start();
	}
	
}

bool check_argument(string str){
	
	if(str.length() != 1) {
			return false;
	}

	char letter = str[0];
	
	switch(letter){
		case 'x':
			return true;
			break;

		case 'y':
			return true;
			break;

		case 'z':
			return true;
			break;

	}
	return false;	
}

void Calculator::declaration(void){
	
	if(check_argument(instruction)){	
		char letter = instruction[0];
	
		switch(letter){
			case 'x':
				cout<<"Answer: "<<x<<endl;
				return start();
				break;

			case 'y':
				cout<<"Answer: "<<y<<endl;
				return start();
				break;

			case 'z':
				cout<<"Answer: "<<x<<endl;
				return start();
				break;

			default:
				cout<< "Invalid Input";
		}
	}
	else cout<< "Invalid Input";
}

void Calculator::assignment(string front, string rear){
	char letter = front[0];
	switch(letter){
		case 'x':
			x = rear;
			return start();
			break;

		case 'y':
			y = rear;
			return start();
			break;

		case 'z':
			z = rear;
			return start();
			break;

		default:
			cout<< "Invalid Input";
	}
}

void Calculator::caculate(string front, front rear, int operation){
	int check = check_num(front);
	if(check)	
}

int Calculator::check_num(string str){
	char letter;
	int len = str.length(),result = 1;
	//0 for argument
	//1 for int
	//2 for double
	
	for(int i = 0; i<len; ++i){
		letter = str[i];
		if(isdigit(letter)) continue;
		else if(letter == '.') result = 2;
		else return 0;
	}
	return result;
}

