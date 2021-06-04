#include "MainWindow.h"
#include "Settings.h"
#include "FractalCreator.h"
#include <iostream>

complex z_sq(complex z, complex c) {

	return z*z*z*z*z*z + c;

}


class Button : public sf::Drawable, sf::Transformable {
private:
	sf::RectangleShape shape;
	sf::Text text;

public:
	Button() {};
	Button(std::string t, sf::Vector2f pos, sf::Vector2f size) {//, int charSize, sf::Color bgColor, sf::Color textColor) {
		text.setString(t);
		text.setFillColor({255, 255, 0, 255});
		text.setCharacterSize(10);
		text.setPosition({30, 30});
		shape.setPosition(pos);
		shape.setSize(size);
		shape.setFillColor({ 120, 120, 120, 255 });
	}

	void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		states.transform *= getTransform();
		target.draw(shape);
		target.draw(text);
	}

	bool isMouseOver(sf::RenderWindow& window) {
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float buttonX = shape.getPosition().x;
		float buttonY = shape.getPosition().y;

		float buttonWidth = shape.getPosition().x + shape.getLocalBounds().width;
		float buttonHeight = shape.getPosition().y + shape.getLocalBounds().height;

		if (mouseX < buttonWidth && mouseX > buttonX && mouseY < buttonHeight && mouseY > buttonY)
			return true;

		else
			return false;
	}
};


void MainWindow::run() {

	Button b("Name", sf::Vector2f{ 0, 0 }, sf::Vector2f{ 0, 0 });
	// —оздаем окно размером 600 на 600 и частотой обновлени€ 60 кадров в секунду
	Settings settings;
	sf::RenderWindow window(sf::VideoMode(settings.window_width, settings.window_height), \
		settings.window_name, \
		sf::Style::Titlebar | sf::Style::Close);

	window.setFramerateLimit(settings.framelimit);

	FractalCreator plt(&settings);
	settings.function_builder = z_sq;
	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				// ѕолучаем нажатую клавишу - выполн€ем соответствующее действие
				if (event.key.code == sf::Keyboard::Escape) window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{

					int x_pos = sf::Mouse::getPosition(window).x;
					int y_pos = sf::Mouse::getPosition(window).y;
					complex _left = settings.left;
					complex _right = settings.right;
					double left = _left.real();
					double bottom = _left.imag();
					double right = _right.real();
					double top = _right.imag();
					double x_dist = right - left;
					double y_dist = top - bottom;
					double new_x = left + double(x_pos)/settings.window_width * x_dist;
					double new_y = bottom + double(settings.window_height - y_pos) / settings.window_height * y_dist;

					left = new_x -  x_dist* settings.zoom_low_scale;
					bottom = new_y - y_dist * settings.zoom_low_scale;
					right = new_x + x_dist * settings.zoom_low_scale;
					top = new_y + y_dist * settings.zoom_low_scale;
					settings.left = left + bottom * 1i;
					settings.right = right + top * 1i;

				}
				if (event.mouseButton.button == sf::Mouse::Right)
				{

					int x_pos = sf::Mouse::getPosition(window).x;
					int y_pos = sf::Mouse::getPosition(window).y;
					complex _left = settings.left;
					complex _right = settings.right;
					double left = _left.real();
					double bottom = _left.imag();
					double right = _right.real();
					double top = _right.imag();
					double x_dist = right - left;
					double y_dist = top - bottom;
					double new_x = left + double(x_pos) / settings.window_width * x_dist;
					double new_y = bottom + double(settings.window_height - y_pos) / settings.window_height * y_dist;

					left = new_x - x_dist / settings.zoom_high_scale;
					bottom = new_y - y_dist / settings.zoom_high_scale;
					right = new_x + x_dist / settings.zoom_high_scale;
					top = new_y + y_dist / settings.zoom_high_scale;
					settings.left = left + bottom * 1i;
					settings.right = right + top * 1i;

				}
				if (b.isMouseOver(window)) {

					std::cout << "test" << std::endl;

				}
			}

			// zoom
			// zoom mouse pressed
		}

		// ¬ыполн€ем необходимые действи€ по отрисовке
		sf::Image im = plt.create_image();
		sf::Texture texture;
		texture.loadFromImage(im);
		sf::Sprite sprite;
		sprite.setTexture(texture, true);
		sprite.rotate(270);
		sprite.setPosition(0, settings.window_height);	
		double x_scale = double(settings.window_width) / settings.num_width_points;
		double y_scale = double(settings.window_height) / settings.num_height_points;
		sprite.setScale(x_scale, y_scale);

		// очистка окна
		window.clear();

		// отрисовка
		window.draw(sprite);
		window.draw(b);

		// отображение на экран
		window.display();
	}


}
