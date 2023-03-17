#include "calculator.h"
#include <iostream>
#include <string>

using namespace std;

//Implement Member Functions
void Calculator::setvalue(string str){

	value = str;
	is_int = 1;
	for(char c:value) if(c == '.') is_int = 0;

}

const Calculator Calculator::operator +(const Calculator& c){
	
	int c_is_int = c.is_int;
	string c_value = c.value;
	
	int iresult;
	double dresult;
	string result;

	if(is_int && c_is_int){
		iresult = stoi(value) + stoi(c_value);
		result = to_string(iresult);
	}else	{
		dresult = stod(value) + stod(c_value);
		result = to_string(dresult);
	}
	return Calculator(result);
}

const Calculator Calculator::operator -(const Calculator& c){

	int c_is_int = c.is_int;
	string c_value = c.value;
	
	int iresult;
	double dresult;
	string result;

	if(is_int && c_is_int){
		iresult = stoi(value) - stoi(c_value);
		result = to_string(iresult);
	}else	{
		dresult = stod(value) - stod(c_value);
		result = to_string(dresult);
	}
	return Calculator(result);
}

const Calculator Calculator::operator *(const Calculator& c){

	int c_is_int = c.is_int;
	string c_value = c.value;
	
	int iresult;
	double dresult;
	string result;

	if(is_int && c_is_int){
		iresult = stoi(value) * stoi(c_value);
		result = to_string(iresult);
	}else	{
		dresult = stod(value) * stod(c_value);
		result = to_string(dresult);
	}
	return Calculator(result);
}

const Calculator Calculator::operator /(const Calculator& c){
	int c_is_int = c.is_int;
	string c_value = c.value;
	
	int a, b,iresult;
	double dresult,d0,d1;
	string result;
	if(is_int && c_is_int){
		a = stoi(value), b = stoi(c_value);
		if(b == 0) return Calculator("Operation Disallowed",-1);
		if(a%b){
			dresult = stod(value) / stod(c_value);
			result = to_string(dresult);
		}
		else{
			iresult = stoi(value) / stoi(c_value);
			result = to_string(iresult);
		}
	}else	{
		d0 = stod(value), d1 = stod(c_value);
		if(d1 == 0.0) return Calculator("Operation Diasllowed", -1);
		dresult = stod(value) / stod(c_value);
		result = to_string(dresult);
	}
	
	return Calculator(result);

}

const Calculator Calculator::operator %(const Calculator& c){
	
	int c_is_int = c.is_int,index;
	string c_value = c.value,v = value;

	if(!is_int){
		index = -1;
		for(char c: v) if(++index, c == '.') v = value.substr(0,index);
	}

	if(!c_is_int){
		index = -1;
		for(char c: c_value) if(++index, c == '.') c_value = c_value.substr(0,index);
	}
	
	int iresult;
	string result;
	if(stoi(c_value) == 0)  return Calculator("Operation Disallowed", -1);
	iresult = stoi(v) % stoi(c_value);
	result = to_string(iresult);
	return Calculator(result);
}

const Calculator Calculator::operator ^(const Calculator& c){

	int c_is_int = c.is_int, index=-1;
	string c_value = c.value;

	if(!c_is_int) {
		for(char c:c_value) if(++index,c=='.')  c_value = c_value.substr(0,index);
	}
	
	int iresult = 1, a, e = stoi(c_value);
	double dresult = 1.0, b;
	string result;

	if(is_int){
		a = stoi(value);
		for(int i = e; i > 0; --i) iresult *= a;
		result = to_string(iresult);
	}else {
		b = stod(value);
		for(int i = e; i > 0; --i) dresult *= b;
		result = to_string(dresult);
	}

	return Calculator(result);
}

void Calculator::int2double(void){
	int n = stoi(value);
	double d = (double)n;
	value = to_string(d);
}

void Calculator::print(void){
	if(is_int==1) cout<<stoi(value);
	else if(is_int == -1) cout<<value;
	else cout<<stod(value);

}
