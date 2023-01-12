#include "Matrix.hpp"
#include <iostream>
int main(int argc, char *argv[]){
	
	Matrix m(3, 3);
	Matrix m2(3, 3);
	m.setValue(0, 0, 1);
	m.setValue(1, 1, 1);
	m.setValue(2, 2, 1);
	m2.setValue(0, 2, 5);
	int d = 5;
	std::cout << "Matrice 1:\n" + m.toString() << std::endl;
	std::cout << "Matrice 2:\n" + (m + m2).toString() << std::endl;
	std::cout << "Matrice 3:\n" + (m * m2).toString() << std::endl;
	Matrix m4 = m + m2;
	std::cout << "Matrice 4:\n" + (m4).toString() << std::endl;
	delete &m;
	delete &m2;
	
	return 0;
}