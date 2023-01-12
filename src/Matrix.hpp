#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <iostream>
#include <string>
class Matrix{
	
	public:
		Matrix(int line, int column);
		Matrix(int size);
		int getColumn();
		int getLine();
		double getValue(int i, int j);
		setValue(int i, int j, double value);
		std::string toString();
		Matrix operator=(Matrix &n);
		Matrix operator+(Matrix &m2);
		Matrix operator*(Matrix &m2);
		Matrix operator*(int &n);
		Matrix operator^(int &n);
		dot(Matrix m);
		dot(int n);
		invert();
		~Matrix();
		
	
	private:
		double **tab;
		int line, column;
		setColumn(int n_column);
		setLine(int n_line);
		
	
};
Matrix sum(Matrix &m1, Matrix &m2);
Matrix dot(Matrix &m1, Matrix &m2);
Matrix power(Matrix &m1, int n);




#endif
