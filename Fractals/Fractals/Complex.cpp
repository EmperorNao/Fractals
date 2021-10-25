#include "Complex.h"

double Complex::real() {

	return Re;

}

double Complex::imag() {

	return Im;

}


Complex operator*(Complex a, Complex b) {

	Complex t(a.real()*b.real() - a.imag()* b. imag(), a.real()*b.imag() + b.real()*a.imag());
	return t;

}

Complex operator+(Complex a, Complex b) {

	Complex t(a.real() + b.real(), a.imag() + b.imag());
	return t;

}

Complex operator-(Complex a, Complex b) {

	Complex t(a.real() - b.real(), a.imag() - b.imag());
	return t;

}
double abs(Complex a) {

	return sqrt(a.real() * a.real() + a.imag() * a.imag());

}