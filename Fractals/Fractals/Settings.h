#pragma once
#include <string>
#include "Complex.h"
#include <functional>

const double INF = -1;

class Settings {

public:

	std::string window_name = "FractalPlotter";
	unsigned framelimit = 60;
	unsigned window_width = 900;
	unsigned window_height = 900;
	double infinity_border = 2;
	unsigned max_iterations = 50;
	unsigned num_width_points = 900;
	unsigned num_height_points = 900;
	Complex left = Complex(-2.5,-2);
	Complex right = Complex(1.5, 2);
	double zoom_low_scale = 0.2;
	double zoom_high_scale = 1 / zoom_low_scale;
	std::function<Complex(Complex, Complex)> function_builder;

};

