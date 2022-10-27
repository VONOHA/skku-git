#include <iostream>

using namespace std;

int main(){
	//static_cast
	int intVar1 = 1, intVar2 = 2;
	cout<<endl<<"static_cast example"<<endl;
	double doubleVar = static_cast<double>(intVar1) / intVar2;
	cout << doubleVar << endl;
	doubleVar = intVar1/ static_cast<string>(intVar2);
	cout << doubleVar << endl;
	doubleVar = static_cast<double>(intVar1 / intVar2);
	cout << doubleVar <<endl;
}
