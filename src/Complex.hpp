#ifndef __COMPLEX_H__
#define __COMPLEX_H__
#include <iostream>
class Complex{
	
	public:
	Complex(double real, double img);
	~Complex();
	double imaginaire_part;
	double real_part;
	Complex Conjugate();
	std::string toString();
	
	Complex operator+(double real);
	Complex operator+(Complex &cmp);
	Complex operator*(Complex &cmp);
	Complex operator*(int n);
	
	private:
	
	
};



#endif