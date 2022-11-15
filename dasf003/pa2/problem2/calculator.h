#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

using namespace std;

class Calculator{
  //Write class definition here

		Calculator():x("0"),y("0"),z("0"){};

		void start(void);
		int count(void);
		int check_num(string str);
		bool check_argument(string str);
		void declaration(void);
		void assignment(string front, string rear);
		void calculate(string front, string rear, int operation);		
		string x, y, z, instruction;
		const string ops = "=+-*/%^";
		const string numb_dot = "01.23456789";
};


#endif
