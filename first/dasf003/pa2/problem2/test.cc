#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
	string str;
	getline(cin,str);
	int i = 0;
	while(i < str.length()){
		if(str[i] == ' ') str.erase(i,1);
		else ++i;
	}
	cout<<str;
	return 0;
}
