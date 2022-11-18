#include "fraction.h"

int main(){
  //write your code here
	string input;
	int i;
	cin>>input;
	for(i = input.length()-1; input[i]!=' '; --i);
	string frac0_input = input.substr(0,i);
	string frac1_input = input.substr(i+1, input.length()-i-1);
	cout<<"1";
	Fraction f0,f1;
	Fraction frac0 = f0.str2Fraction(frac0_input);
	Fraction frac1 = f1.double2Fraction(stod(frac1_input));
	frac0.print();
	frac1.print();
	return 0;
}
