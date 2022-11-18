#include "fraction.h"

//Implement Member Functions

//elementary functions
//getN() => return N;
//getD() => return D;
//getNU() => return NU;

bool Fraction::toMixedNum (){
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
	Fraction right = double2Fraction(b);
	Fraction r_improper = right.Mixed2Improper();
	Fraction result = Mixed2Improper();
	result.setN(0);
	result.setD(r_improper.getD() * result.getD());
	result.setNU(r_improper.getNU() * result.getNU());
	return result;
}


void Fraction::abbreviation (){
	
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


	result_N += b_N;
	result_N += N;

	result_NU = b_NU * NU;
	result_D = b_NU * D + NU * b_D;

	Fraction result = Fraction(result_N, result_D, result_NU);

	result.abbreviation();

	result.toMixedNum();

	return result;

}

Fraction Fraction::str2Fraction(string str){

	string val_N, dummy;
	int n, d, nu, b, s, tmp, index;

	for(index = 0; str[index]!= '.'; ++index);
	
	val_N = str.substr(0,index);
	dummy = str.substr(index+1, str.length()-1-index);

	n = stoi(val_N);
	d = stoi(dummy);

	for(index = dummy.length(), nu = 1; index > 0; --index, nu *= 10); 

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

Fraction Fraction::Mixed2Improper (){
	int n, nu, d;
	n = 0, nu = D*N+NU, d = D;
	return Fraction(n, nu, d);
}
