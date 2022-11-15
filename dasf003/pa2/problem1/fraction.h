#ifndef FRACTION_H
#define FRACTION_H

class Fraction{
  //Write class definition here
  
	public:
		Fraction():N(0),D(0),NU(0){};

		Fraction(int n, int d, int nu): N(n), D(d), NU(nu){};

		inline int getN(){return N;};
		inline int getD(){return D;};
		inline int getNU(){return NU;};

  	//Add two fractions and return result
		Fraction sum (Fraction b);

	//Add double and fraction value and return result
		Fraction sum (double b);

	//Multiply two fractions and return result
		Fraction multiply (Fraction b);

	//Multiply double and fraction value and return result
		Fraction multiply (double b);

	//Abbreviate fraction.
		void abbreviation ();

	//Convert fraction into mixed number.
	//- Updates N, D, and NU.
	//- If it is changed, return true, else return false.
		Bool toMixedNum ();

	//Print fraction value
	//* Format : N and NU/D
		void print ();

	//Convert fraction into double.
	//* Round to fourth decimal place
		double toDouble ();

	//Convert string into a Fraction class
	//* String format : N/NU/D
		Fraction str2Fraction (string str);
	
	//Convert double value into a Fraction class
		Fraction double2Fraction (double val);

	private:
		int N;
		int D;
		int NU;
};

#endif
