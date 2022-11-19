#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <iostream>

using namespace std;

class Calculator{
  //Write class definition here
	//constructor
	public:	
	Calculator():value("0"),is_int(1){};
	Calculator(string str){
		value = str;
		is_int = 1;
		for(char c: value) if(c == '.') is_int = 0;
	};
	Calculator(string str,int n):value(str), is_int(n){};

	//member function
	void setvalue(string str);
	const Calculator operator +(const Calculator& c);
	const Calculator operator -(const Calculator& c);
	const Calculator operator *(const Calculator& c);
	const Calculator operator /(const Calculator& c);
	const Calculator operator %(const Calculator& c);
	const Calculator operator ^(const Calculator& c);
	void int2double(void);
	void print(void);

	//values
	int is_int;
	string value;
};

#endif
