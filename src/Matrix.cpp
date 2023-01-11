#include "Matrix.hpp"

Matrix::Matrix(int n_line, int n_column){
	
	this->line = n_line;
	this->column = n_column;
	this->tab = (double **)malloc(sizeof(double *)*n_line + 1);
	for(int i = 0; i != n_line; i++){
		this->tab[i] = (double *)malloc(sizeof(double)*n_column + 1);
		for(int j = 0;j != n_column; j++ ){
			this->tab[i][j] = 0;
		};
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
std::string Matrix::toString(){
	
	int i, j;
	std::string str;
	for(i=0; i!=this->getLine(); i++){
		str += "[";
		for(j=0; j != this->getColumn(); j++){
			str += (j==0) ? std::to_string(this->tab[i][j]) : "," +  std::to_string(this->tab[i][j]); 
		}
		str += "] \n";
	}
	return str; 
}
int Matrix::sum(Matrix m){
	
	int i, j;
	if(this->line == m.getLine() && this->column == m.getColumn()){
		for(i=0;i!=this->line;i++){
			for(j=0;j!=this->column;j++){
				this->setValue(i, j, this->getValue(i, j) + m.getValue(i, j));
			}	
		}
	}
	
}
Matrix::dot(int n){
	
	int i, j;
	Matrix buff(this->line, this->column);
	for(i=0;i!=this->line;i++){
		for(j=0;j!=this->column;j++){
			buff.setValue(i, j, this->getValue(i, j)*n);
		}	
	}
	//return buff;
}
Matrix::dot(Matrix m){
	
	Matrix buff(this->line, m.column);
	double product= 0;
	int i, j, k;
	if(this->column == m.getLine()){
		for(i=0;i!=buff.getLine();i++){
			for(j=0;j!=buff.getColumn();j++){
				for(k=0;k != this->column;k++){
					product += this->getValue(i, k) * this->getValue (k, j);
				}
			buff.setValue(i, j, product);
			product = 0;
			}
		}	
	}
}
Matrix::invert(){
	
}
Matrix::~Matrix(){
	
	for(int i = 0; i != this->line; i++){
		free(this->tab[i]);
	}
	free(this->tab);
	
}

Matrix *sum(Matrix *m1, Matrix *m2){
	
	int i, j;
	Matrix *buff = new Matrix(m1->getLine(), m1->getColumn());
	if(m1->getLine() == m2->getLine() && m1->getColumn() == m2->getColumn()){
		for(i=0;i!=m1->getLine();i++){
			for(j=0;j!=m1->getColumn();j++){
				buff->setValue(i, j, m1->getValue(i, j) + m2->getValue(i, j));
			}	
		}
	}
	return buff;
}
Matrix *dot(Matrix *m1, Matrix *m2){
	
	Matrix *buff = new Matrix(m1->getLine(), m2->getColumn());
	double product= 0;
	int i, j, k;
	//Line * column
	if(m1->getColumn() == m2->getLine()){
		for(i=0;i!=m1->getLine();i++){
			for(j=0;j!=m2->getColumn();j++){
				for(k=0;k != m1->getColumn();k++){
					product += m1->getValue(i, k) * m2->getValue (k, j);	
				}
				buff->setValue(i, j, product);
				product = 0;
			}
		}
	}
	return buff;
	
}
Matrix *power(Matrix *m1, int n){
	
	Matrix *buff = new Matrix(m1->getLine(), m1->getColumn());
	for(int i = 1; i != n;i++){
		m1 = dot(m1, m1);
	}
	return m1;
}