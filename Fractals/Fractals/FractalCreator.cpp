#include "FractalCreator.h"
#include "ColorDefinitor.h"
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

sf::Image FractalCreator::create_image() {

	ColorDefinitor def(settings->max_iterations);
	unsigned size = settings->num_width_points * settings->num_height_points * 4;
	int columns_size = settings->num_width_points * 4;
	sf::Uint8* pxl = new sf::Uint8[size];

	double left = settings->left.real();
	double bottom = settings->left.imag();
	double right = settings->right.real();
	double top = settings->right.imag();

	double step_real = (right - left) / settings->num_width_points;
	double step_imag = (top - bottom) / settings->num_height_points;

	complex c;
	complex z = 0;
	#pragma omp parallel for num_threads(4)
	for (int i = 0; i < settings->num_width_points; ++i) {

		for (int j = 0; j < settings->num_height_points; ++j) {

			 c = left + i * step_real + bottom * 1i + j * step_imag * 1i;
			
			 z = 0;
			 sf::Color color = sf::Color(0, 0, 0, 255);
			 for (int num_iter = 0; num_iter < settings->max_iterations; ++num_iter) {

				 z = settings->function_builder(z, c);
				 if (abs(z) > settings->infinity_border) {

					 color = def.get_color(num_iter);
					 break;

				 }

			 }
			 pxl[i * columns_size + j * 4 + 0] = color.r;
			 pxl[i * columns_size + j * 4 + 1] = color.g;
			 pxl[i * columns_size + j * 4 + 2] = color.b;
			 pxl[i * columns_size + j * 4 + 3] = color.a;

		}


	}

	sf::Image im;
	im.create(settings->num_width_points, settings->num_height_points, pxl);

	return im;
};
