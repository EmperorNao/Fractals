#pragma once
#include <SFML/Graphics.hpp>

#include "Complex.h"
#include "Settings.h"
#include "ColorDefinitor.h"

#include <functional>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <iostream>

class FractalCreator {

private:

	Settings* settings;

public:

	FractalCreator(Settings* _settings) : settings(_settings) {};

	sf::Image create_image();




};

