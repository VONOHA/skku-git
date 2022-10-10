#include "wordProcess.h"
#include <string>

std::string cpe::getMostPairsWord(std::string words[300])
{
  //write your code here!
  	int length = 0,s_len, value;
	char p,n;
	std::string result = "",now;
	for(int i = 0;i<300;++i){
		now = words[i];
		s_len =now.length();
		p = now[0],value = 0;
		for(int l = 1; l<s_len; ++l){
			n = now[l];
			if(p==n){
				p = '\0';
				++value;
			}else{
				p = n;
			}
		}
		if(value>length){
			length = value;
			result = now;
		}
	}
	return result;
}
