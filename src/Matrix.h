#ifndef __MATRIX_H__
#define __MATRIX_H__

class Matrix{
	
	public:
		Matrix(int line, int column);
		int getColumn();
		int getLine()
		double getValue(int i, int j);
		setValue(int i, int j, double value);
		sum(Matrix m);
		dot(Matrix m);
		dot(int n);
		power(int n);
		invert();
		~Matrix()
	
	private:
		double **tab;
		int line, column;
	
};






#endif