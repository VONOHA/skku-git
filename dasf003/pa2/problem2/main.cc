#include "calculator.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
  	//write your code here
  	string input;
	string quit_sign = "quit";

	enum ops {zero, sum = '+', sub = '-', multi = '*', div = '/', mod = '%', expo = '^', assign = '='};
	
	ops operation = zero;
	int index, ops_index,i, b;

	Calculator x, y, z, left, right, result;
	string l_str,r_str;

	while(1){
		cout<<"Enter your equation to calculate: ";		
		getline(cin,input);	
		
		i = 0;
		while(i < input.length()){
		if(input[i] == ' ') input.erase(i,1);
		else ++i;
		}
		

		if(input == quit_sign){
			break;
		}
		
		operation = zero;
		index = -1, ops_index = 0;

		for(char c: input){
			
			++index;

			switch(c){
			
				case '+':
					operation = sum;
					ops_index = index;
					break;

				case '-':
					operation = sub;
					ops_index = index;
					break;

				case '*':
					operation = multi;
					ops_index = index;
					break;

				case '/':
					operation = div;
					ops_index = index;
					break;

				case '%':
					operation = mod;
					ops_index = index;
					break;

				case '^':
					operation = expo;
					ops_index = index;
					break;

				case '=':
					operation = assign;
					ops_index = index;
					break;

				default:
					
					b = 0;

					for(char digit = '0'; digit <= '9'; ++digit){
						
						if(c == digit) b = 1;
					
					}
					
					if(!b && c!= 'x' && c!= 'y' && c!='z' && c!='.'){
						cout<<"Invalid input";
						return 0;
					}

					break;
			
			}
		}

		if(!ops_index){
			
			cout<<"Answer: ";
			if(input == "x") x.print();
			else if(input == "y") y.print();
			else if(input == "z") z.print();
			else {
				cout<<"Invalid Input";
				return 0;
			}
			cout<<endl;
		
		}else{

			l_str = input.substr(0,ops_index);
			input.erase(0,ops_index+1);
			r_str = input;

			if(l_str == "x") left.setvalue(x.value);
			else if(l_str == "y") left.setvalue(y.value);
			else if(l_str == "z") left.setvalue(z.value);
			else left.setvalue(l_str);
			
			if(r_str == "x") right.setvalue(x.value);
			else if(r_str == "y") right.setvalue(y.value);
			else if(r_str == "z") right.setvalue(z.value);
			else right.setvalue(r_str);
			
			if(operation == assign){
			
				if( l_str == "x") x.setvalue(right.value);
				else if( l_str == "y") y.setvalue(right.value);
				else if( l_str == "z" ) z.setvalue(right.value);
				else {
					cout<<"Invalid input";
					return 0;
				}
				continue;	
			}else if(operation == sum){
				
				cout<<"Answer: ";
				result = left + right;
				result.print();

			}else if(operation == sub){

				cout<<"Answer: ";
				result = left - right;
				result.print();

			}else if(operation == multi){

				cout<<"Answer: ";
				result = left * right;
				result.print();

			}else if(operation == div){

				cout<<"Answer: ";
				result = left / right;
				result.print();

			}else if(operation == mod){

				cout<<"Answer: ";
				result = left % right;
				result.print();

			}else if(operation == expo){

				cout<<"Answer: ";
				result = left ^ right;
				result.print();

			}else{

				cout<<"Answer: ";
				cout<<"Invalid input";
				return 0;

			}
			cout<< endl;
		
		}

	}
	return 0;
}
