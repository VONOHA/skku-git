#include "fraction.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//get & set variable
void Fraction::setN(int n){
	N = n;
}
void Fraction::setNU(int nu){
	NU = nu;
}
void Fraction::setD(int d){
	D = d;
}
int Fraction::getN(void){
	return N;
}
int Fraction::getNU(void){
	return NU;
}
int Fraction::getD(void){
	return D;
}

//member function
Fraction Fraction::sum(Fraction b){
	toImproperNum();
	if(!NU) D =1;
	b.toImproperNum();
	int r_NU = b.getNU(), r_D = b.getD();
	if(!r_NU) r_D = 1;
	Fraction result(0,NU*r_D+D*r_NU,D*r_D);
	result.abbreviation();
	result.toMixedNum();
	abbreviation();
	toMixedNum();
	return result;
}

Fraction Fraction::sum(double b){
	toImproperNum();
	if(!NU) D = 1;
	Fraction right(b);
	right.toImproperNum();
	int r_NU = right.getNU(), r_D = right.getD();
	if(!r_NU) r_D = 1;
	Fraction result(0,NU*r_D+D*r_NU,D*r_D);
	result.abbreviation();
	result.toMixedNum();
	abbreviation();
	toMixedNum();
	return result;
}

Fraction Fraction::multiply(Fraction b){
	toImproperNum();
	if(!NU) D = 1;
	b.toImproperNum();
	int r_NU = b.getNU(), r_D = b.getD();
	if(!r_NU) r_D =1;
	Fraction result(0,NU*r_NU,D*r_D);
	result.abbreviation();
	result.toMixedNum();
	abbreviation();
	toMixedNum();
	return result;
}

Fraction Fraction::multiply(double b){
	toImproperNum();
	if(!NU) D = 1;
	Fraction right(b);
	right.toImproperNum();
	int r_NU = right.getNU(), r_D = right.getD();
	if(!r_NU) r_D = 1;
	Fraction result(0,NU*r_NU,D*r_D);
	result.abbreviation();
	result.toMixedNum();
	abbreviation();
	toMixedNum();
	return result;
}

void Fraction::abbreviation(void){
	if(!NU) D = 1;
	int b = NU, s = D, tmp;
	if(b<s) tmp = b, b = s, s = tmp;
	while(s) tmp = b % s, b = s, s = tmp;
	NU /= b;
	D /= b;
	if(!NU) D = 0;
}

bool Fraction::toImproperNum(void){
	if(!N) return false;
	else{
		if(!NU) D = 1;
		NU += N*D;
		N = 0;
		if(!NU) D = 0;
		return true;
	}
}

bool Fraction::toMixedNum(void){
	if(!NU) D = 1;
	if(NU<D){ 
		if(!NU) D = 0;
		return false;
	}
	else{
		N += NU/D;
		NU %= D;
		if(!NU) D = 0;
		return true;
	}
}

void Fraction::print(void){
	cout<<N<<" and ";
	cout<<NU<<"/"<<D<<endl;
}

double Fraction::toDouble(void){
	double n = (double)N, d = (double) D, nu = (double)NU;
	if(!nu) d =1;
	double result = n + nu/d;
	result *= 1000000;
	result = round(result);
	result /= 1000000;
	return result;
}

Fraction Fraction::str2Fraction(string str){
	int index0 = -1, index1 = -1, length = str.length();
	for(char c: str) if(++index0, c == '/') break;
	string str_N = str.substr(0,index0);
	str.erase(0,index0+1);
	for(char c:str) if(++index1, c =='/') break;
	string str_NU = str.substr(0,index1);
	str.erase(0,index1+1);
	string str_D = str;

	int n = stoi(str_N), nu = stoi(str_NU), d = stoi(str_D);
	
	if(!nu) d = 1;
	Fraction result(n,nu,d);
	result.abbreviation();

	return result;
}

Fraction Fraction::double2Fraction(double val){
	string str = to_string(val);
	int index = -1, length = str.length();
	for(char c: str) if(++index, c == '.') break;
	string str_N = str.substr(0,index);
	string str_NU = str.substr(index+1,length-index-1);
	int n = stoi(str_N), nu = stoi(str_NU), d =(double) pow(10,str_NU.length());
	//cout<<n<<" "<<nu<<" "<<d;
	if(!nu) d = 1;
	Fraction result(n,nu,d);
	result.abbreviation();
	return result;
}
