#pragma once
#include <string>
#include <complex>
#include <functional>

using namespace std::complex_literals;
typedef std::complex<double> complex;
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
	complex left = -2.5 - 2i;
	complex right = 1.5 + 2i;
	double zoom_low_scale = 0.3;
	double zoom_high_scale = 1 + zoom_low_scale;
	std::function<complex(complex, complex)> function_builder;

};

