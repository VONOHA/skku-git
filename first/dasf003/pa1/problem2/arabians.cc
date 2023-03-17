#include "arabians.h"

//implement this function
std::string cpe::reverseString(const std::string& target) {
  //write your code here!
	std::string result = "", stack = "";
	int length = target.length();
	char value;
	for(int i = 0; i<length; ++i){
		value = target.at(i);
		if(value > 47 && value < 58) stack += value;
		else	{
			result = stack + result;
			result = target.at(i) + result;
			stack = "";
		}
	}
	result = stack + result;
  return result;
}

