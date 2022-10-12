#include <iostream>
#include <fstream>
#include <string>
#include "wordProcess.h"

int main()
{
  std::string a[2500];
  
  //Write your code here!
  //You should read file words.txt
  //call getMostParisWord function to find the most pairs of consecutive double letters
	//std::string k;
  	using namespace std;
  	string result[2500]={""}, input[300];
	int k = -1, start = 0, end = 0, n, index = 0;
	std::ifstream text("words.txt");
	while(getline(text,a[++k]));
	while(end <= k){
		start = end + 1;
		end = start + 298;
		for(int l = 1; l<300; ++l) {
			n = start + l - 1;
			if(n<=k)input[l] = a[n];
			else input[l] = "";
		};
		input[0] = result[0];
		if(result[0] != cpe::getMostPairsWord(input)) index = -1;
		for(int i = 1; i<300; ++i) if(input[i]!="") result[++index] = input[i];
	}

	for(int i = 0; i<= index; ++i) cout<<result[i]<<endl;

	return 0;
}
