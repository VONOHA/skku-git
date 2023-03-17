#include <iostream>

using namespace std;

double& func(double& variable){
	return variable;
}

double& mal_func(double variable){
	double v = 5;
	double& k = v;
	return k;
}

int main(){

	double dvar = 3.14;

	cout<<dvar <<endl;
	cout<<func(dvar)<<endl;
	cout<<dvar<<endl;

	//double dvar2 = func(dvar);
	//ee the difference
	double& dvar2 = mal_func(dvar);
	cout<<"&dvar:"<<&dvar<<endl;
	cout<<"&dvar2:"<<dvar2<<endl;
}
