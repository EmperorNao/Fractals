#pragma once
#include <iostream>

class Complex{

private:

	double Re;
	double Im;

public:

	Complex(double _Re = 0, double _Im = 0) : Re(_Re), Im(_Im) {};

	double real();
	double imag();

	

	friend Complex operator*(Complex a, Complex b);
	friend Complex operator+(Complex a, Complex b);
	friend Complex operator-(Complex a, Complex b);




};

double abs(Complex a);

