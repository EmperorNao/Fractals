#pragma once
#include <SFML/Graphics.hpp>
#include <complex>
#include <functional>
#include "Settings.h"

using namespace std::complex_literals;
typedef std::complex<double> complex;

class FractalCreator {

private:
	Settings* settings;

public:

	FractalCreator(Settings* _settings) : settings(_settings) {};

	sf::Image create_image();




};

