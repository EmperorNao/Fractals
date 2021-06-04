#pragma once
#include <SFML/Graphics.hpp>
#include <random>

class ColorDefinitor {

	
	unsigned num_max_iteration;

public:

	ColorDefinitor(unsigned _max_iteration) : num_max_iteration(_max_iteration) {};
	sf::Color get_color(int num_iter) {

		sf::Color c;
		unsigned color = unsigned(255 * double(num_iter) / num_max_iteration);
		//unsigned color = 255;
		int r = rand() % 3;
		c.r = 0;
		c.g = 0;
		c.b = 0;
		switch (r) {
		case 0:
			c.r = color;
			break;
		case 1:
			c.g = color;
			break;
		case 2:
			c.b = color;
			break;

		}
		c.a = 255;
		return c;

	};

};

