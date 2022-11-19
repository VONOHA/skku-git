#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Fraction{
  //Write class definition here
	public:
		//constructor
		Fraction():N(0),NU(0),D(1){};
		Fraction(int n, int nu, int d): N(n), NU(nu), D(d){};
		Fraction(double input){
			Fraction dummy0;
			Fraction dummy1 = dummy0.double2Fraction(input);
			N = dummy1.getN();
			NU = dummy1.getNU();
			D = dummy1.getD();
		};
		Fraction(string str){
			Fraction dummy0;
			Fraction dummy1 = dummy0.str2Fraction(str);
			N = dummy1.getN();
			NU = dummy1.getNU();
			D = dummy1.getD();
		};

		//get & set variable
		void setN(int n);
		void setNU(int nu);
		void setD(int d);
		int getN(void);
		int getNU(void);
		int getD(void);

		//member function
		Fraction sum(Fraction b);
		Fraction sum(double b);
		Fraction multiply(Fraction b);
		Fraction multiply(double b);
		void abbreviation(void);
		bool toMixedNum(void);
		bool toImproperNum(void);
		void print(void);
		double toDouble(void);
		Fraction str2Fraction(string str);
		Fraction double2Fraction(double val);
	
	private:
		int N,NU,D;
};

#endif
