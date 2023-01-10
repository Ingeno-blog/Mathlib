#include "Matrix.h"

Matrix::Matrix(int n_line, int n_column){
	this->line = n_line;
	this->column = n_column;
	this->tab = malloc(sizeof(double *)*n_line + 1);
	for(int i = 0; i != n_line; i++){
		this->tab[i] = malloc(sizeof(double)*n_column + 1)
	}
	
	
}
int Matrix::getColumn(){
	return this->column;
}
int Matrix::getLine(){
	return this->line;
}
double Matrix::getValue(int i, int j){
	return this->tab[i][j];
}
Matrix::setValue(int i, int j, double value){
	this->tab[i][j] = value;
}
int Matrix::sum(Matrix m){
	
	int i, j;
	Matrix buff(this->line, this->column);
	if(this->line == m.getLine() && this->column == m.column()){
		for(i=0;i!=this->line;i++){
			for(j=0;j!=this->columb;j++){
				buff.setValue(i, j, this->getValue(i, j) + m.getValue(i, j))
			}	
		}
	}
	return buff;
	
}
Matrix::dot(int n){
	
	int i, j;
	Matrix buff(this->line, this->column);
	for(i=0;i!=this->line;i++){
		for(j=0;j!=this->columb;j++){
			buff.setValue(i, j, this->getValue(i, j)*n)
		}	
	}
	return buff;
}
Matrix::matrix_product(Matrix m){
	
	Matrix buff(this->line, m.column);
	double product= 0;
	int i, j, k;
	//Line * column
	for(i=0;i!=buff->line;i++){
		for(j=0;j!=buff->columb;j++){
			for(k=0;k != this->column;k++){
				product += this->getValue(i, k) * this->getValue (k, j)
			}
			buff.setValue(i, j, product);
			product = 0;
		}
	}
	return buff;
}
Matrix::dot(Matrix m){
	
	if(this->column == m.getLine()){
		return this->matrix_product(m);
	}
}
Matrix::invert(){
	
}
Matrix::~Matrix(){
	
	for(int i = 0; i != this->line; i++){
		free(this->tab[i])
	}
	free(this->tab);
	
	
}