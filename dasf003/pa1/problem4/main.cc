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
  	std::string result="", now;
	int i,k=1;
	std::ifstream text("words.txt");
	while(k){
		//std::cout<<++k<<std::endl;
		for(i = 0; i<300; ++i){
			std::cout<<k++<<std::endl;
			if(!std::getline(text,a[i])) {
				--i;
				k = 0;
				goto exit;
			}
			//std::cout<<a[i]<<std::endl;
		}
		exit:
		for(int l = i+1; l<2500;++l) a[l]="";
		now = cpe::getMostPairsWord(a);
		if(now.length()>result.length())result = now;
		std::cout<<result<<std::endl;
	}
	std::cout<<result;
	return 0;
}
