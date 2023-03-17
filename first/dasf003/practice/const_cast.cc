#include <iostream>

using namespace std;

int main(void){

	//exl

	double a = 1.1;
	double b = const_cast<double&>(a);
	b = 2.2;
	cout<<a<<" "<<b;
	//ex2
	//const double a = 1.1;
	//const double& b = a;
	//b = 2.2;
	//double& c = const_cast<double&>(b);
	//c = 2.2;
	//cout << "a: "<<a<<", b: "<< b <<", c: " <<c <<endl;
}
