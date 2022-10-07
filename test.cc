#include <iostream>
#include <string>

using namespace std;

int main(void){
	string target, stack = "", result = "";
	getline(cin,target);
	int length = target.length();
	char value;
	for(int i = 0; i<length; ++i){
		//cout << result<<" "<<stack<<" "<<endl;
		value = target.at(i);
		if(value > 48 && value < 58) stack = stack +  value;
		else{
			result = stack + result;
			result = target.at(i) + result;
			stack = "";
		}
	}
	result = stack + result;
	cout<<result;

	return 0;
}
