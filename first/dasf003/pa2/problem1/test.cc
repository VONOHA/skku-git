#include <iostream>
#include <string>

using namespace std;

int main(void){
	
	string str;

	cin>>str;	

	int index0 = -1, index1 = -1, length = str.length();
	for(char c: str) if(++index0, c == '/') break;
	string str_N = str.substr(0,index0);
	str.erase(0,index0+1);
	cout<<"str: "<<str<<endl;
	for(char c:str) if(++index1, c =='/') break;
	string str_NU = str.substr(0,index1);
	str.erase(0,index1+1);
	cout<<str_N<<str_NU;
	int n = stoi(str_N), nu = stoi(str_NU), d = stoi(str);
	int b = nu, s = d, tmp;
	if(b < s) tmp = b, b = s, s = tmp;
	while(s) tmp = b%s, b = s, s = tmp;
	cout<<endl<<b<<s<<endl;
	nu /= b, d /= b;
	cout<<n<<" "<<nu<<" "<<d;
	return 0;
}
