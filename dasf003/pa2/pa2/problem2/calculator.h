#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator{
  //Write class definition here

	public:
		Calculator():x(0.0),y(0.0),z(0.0){};

	void input();
		
		enum ops = {add,sub,multi,div,remain,expo};

		double x, y, z, a, b;
};

#endif
