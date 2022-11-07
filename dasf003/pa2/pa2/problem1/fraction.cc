#include "fraction.h"
#include <iostream>
#include <string>

using namespace std;

//Implement Member Functions

//elementary functions
//getN() => return N;
//getD() => return D;
//getNU() => return NU;

Bool Fraction::toMixedNum (){
	if(D<NU) return false;
	else{
		int tmp;
		tmp = D/NU;
		N += tmp;
		D -= D%NU;
		if(!D) NU = 0;
		return true;
	}
}

Fraction Fraction::multiply (double b){
	
	Fractioin a = double2Fracction(b);
	
	int n,d,nu;
	
	n = N*a.N;
}


void Fractioin::abbreviation (){
	
	int b, s, tmp;

	if(D>NU) b = D, s = NU;
	else b = NU, s = D;

	while(s!=0){
		tmp = s;
		s = b % s;
		b = tmp;
	}
	
	D /= b, NU /= b;

}

Fraction Fraction::sum(Fraction b){
	
	int b_N = b.getN();
	int b_D = b.getD();
	int b_NU = b.getNU();

	int result_N = 0;
	int result_D = 0;
	int result_NU = 0;

	int b, s, tmp;

	result_N += b_N;
	result_N += N;

	result_NU = b_NU * NU;
	result_D = b_NU * D + Nu * b_D;

	Fraction result = Fraction(result_N, result_D, result_NU);

	result.abbreviation();

	result.toMixedNum();

	return result;

}

Fraction Fraction::str2Fraction(string str){

	string val_N, dummy;
	int N, D, NU;
	int b, s, tmp;

	getline(str, val_N, '.');
	getline(str, dummy);

	N = stoi(val_N);
	D = stoi(dummy);

	for(int i = 0, NU = 1; i < dummy.length; ++i, _NU *= 10); 

	Fraction result = Fraction(N, D, NU);
	
	result.abbreviation();

	return result;
}

void Fraction::print(){
	cout<<N<<" and "<<D<<"/"<<NU<<endl;
}


Fraction Fraction::sum (double b){
	return sum(double2Fraction(b));
}


Fraction Fraction::double2Fraction(double val){

	string val_str = to_string(val);
	return str2Fraction(val_str);
}
