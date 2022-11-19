#include <iostream>
#include <string>
#include "fraction.h"

using namespace std;

int main(){
  	//write your code here
	//receving the input  	
	string input;
	getline(cin,input);
	int index = -1;
	for(char c: input) if(++index,c == ' ') break;
	string f0 = input.substr(0,index);
	input.erase(0,index);
	double d1 = stod(input);
	
	//makeing two fractions
	Fraction frac0(f0);
	Fraction frac1(d1);

	//printfing
	frac0.print();
	frac1.print();

	//sum
	Fraction sum0 = frac0.sum(frac0);
	sum0.print();

	Fraction sum1 = frac0.sum(d1);
	sum1.print();

	//multiply
	Fraction multi0 = frac1.multiply(frac0);
	multi0.print();

	Fraction multi1 = frac1.multiply(d1);
	multi1.print();

	//to double
	cout.precision(6);
	cout<<to_string(frac0.toDouble())<<endl;
	cout<<to_string(frac1.toDouble());

	return 0;
}
