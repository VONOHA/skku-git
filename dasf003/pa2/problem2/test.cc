#include <iostream>
#include <string>

using namespace std;

int main(void){
	string hi = "1+2-3/", ops = "+=-/%^";
	for(auto i = ops.cbegin(); i!= ops.cend(); ++i){
		cout<<hi.find(*i)<<endl;
	}
	return 0;
}
