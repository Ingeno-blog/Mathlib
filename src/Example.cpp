#include "Matrix.hpp"
#include "Complex.hpp"
#include "function.hpp"
#include <iostream>
int main(int argc, char *argv[]){
	
	/***********************************************MATRIX EXAMPLE************************************************************************/
	Matrix m(3, 3);
	Matrix m2(3, 3);
	//m1
	m.setValue(0, 0, 5);m.setValue(0, 1, 4);m.setValue(0, 2, 77);
	m.setValue(1, 0, 5);m.setValue(1, 1, 2);m.setValue(1, 2, 51);
	m.setValue(2, 0, 5);m.setValue(2, 1, 5);m.setValue(2, 2, 123);
	//m2
	m2.setValue(0, 0, 77);m2.setValue(0, 1, 96);m2.setValue(0, 2, 56);
	m2.setValue(1, 0, 88);m2.setValue(1, 1, 21);m2.setValue(1, 2, 56);
	m2.setValue(2, 0, 41);m2.setValue(2, 1, 11);m2.setValue(2, 2, 54);
	int d = 5;
	std::cout << "Matrice 1:\n" + m.toString() << std::endl;
	std::cout << "Matrice 2:\n" + (m + m2).toString() << std::endl;
	std::cout << "Matrice 3:\n" + (m * m2).toString() << std::endl;
	Matrix m4 = m + m2;
	std::cout << "Matrice 4:\n" + (m4).toString() << std::endl;
	std::cout << "Matrice 5:\n" + (m4*500).toString() << std::endl; 
	m4.setRandomValue();
	std::cout << "Matrice 6:\n" + (m4).toString() << std::endl; 
	delete &m;
	delete &m2;
	
	/***********************************************COMPLEX EXAMPLE************************************************************************/
	
	Complex c1(5, 4);
	std::cout << "Complex 1 \n" + c1.toString() << std::endl;
	std::cout << "Complex 2 \n" + (c1 + c1).toString() << std::endl;
	std::cout << "Complex 3 \n" + (c1 + 4).toString() << std::endl;
	std::cout << "Complex 4 \n" + (c1 * c1).toString() << std::endl;
	std::cout << "Complex 5 \n" + (c1 * 4).toString() << std::endl;
	std::cout << "Complex 6 \n" + c1.Conjugate().toString() << std::endl;
	
	//function test
	double x;
	std::cout << solve(x, 5, 6) << std::endl;
	
	return 0;
}