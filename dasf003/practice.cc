#include <string>
#include <iostream>

using namespace std;

int main(void){

	string hi = "Hi, my name is Ye";
	int a;
	while((a = hi.find(' ')) != string::npos) hi.erase(a,1);
	cout<<hi;
	return 0;
}
