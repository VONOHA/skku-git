#include "wordProcess.h"
#include <string>
#include <iostream>
std::string cpe::getMostPairsWord(std::string words[300])
{
  //write your code here!
	using namespace std;
	string result="";
	string now;
	int max_num = -1, n, length;
	char f = 0, b = 0;
	for(int i = 0; i<300; ++i){
		n = 0, f = 0, b = 0;
		now = words[i];
		length = now.length();
		for(int l = 0; l < length; ++l){
			f = now[l];
			if(f == b){ n += 1, b = 0;
				//cout<<b<<f<<" ";
			}
			else b = f;
		}
		//if(n) cout<< now<< " "<<n<<endl;
		if(n < max_num) words[i] = "";
		else if(n > max_num) {
			//cout<<endl<<now<<"chage"<<endl;
			max_num = n, result = now;
			for(int l = 0; l<i; ++l) words[l] = "";		
		}
	}/*
	for(int i = 0; i<300; ++i) std::cout<<words[i]<<" ";
	std::cout<<std::endl;*/
	return result;
}
