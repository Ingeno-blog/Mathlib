#include "Complex.hpp"

Complex::Complex(double real, double img){
	
	this->real_part = real;
	this->imaginaire_part = img;
	
}
std::string Complex::toString(){
	
	return (this->imaginaire_part > 0) ? std::to_string(this->real_part) + "+" + std::to_string(this->imaginaire_part) + "i" : std::to_string(this->real_part) + std::to_string(this->imaginaire_part) + "i" ;
	
}
Complex Complex::Conjugate(){
	Complex c(this->real_part, this->imaginaire_part*-1);
	return c;
}
Complex::~Complex(){
	
	
	
	
}
Complex Complex::operator+(double real){
	
	Complex c(this->real_part + real, this->imaginaire_part);
	return c;
	
}
Complex Complex::operator+(Complex &cmp){
	
	Complex c((this->real_part + cmp.real_part), (this->imaginaire_part + cmp.real_part));
	return c;
}
Complex Complex::operator*(Complex &cmp){
	
	Complex c((this->real_part + cmp.real_part) - (this->imaginaire_part*cmp.imaginaire_part), (this->real_part * cmp.imaginaire_part) + (this->imaginaire_part * cmp.real_part));
	return c;
}
Complex Complex::operator*(int n){
	
	Complex c(this->real_part*n, this->imaginaire_part*n);
	return c;
}
