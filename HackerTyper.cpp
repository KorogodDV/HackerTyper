#include "String.h"
#include <SFML/Graphics.hpp>
#include <cstdio>

const int window_length = 1920;
const int window_width = 1080;

String uploadBufferFromFile(const char* path)
{
#pragma warning(disable : 4996) .
	FILE* f = fopen(path, "r");
	fseek(f, 0, SEEK_END);
	int len = ftell(f);
	rewind(f);
	char* cbuffer = new char[len];
	size_t p = fread(cbuffer, 1, len, f);
	fclose(f);
	String buffer = String(cbuffer).split(p)[0];
	delete[] cbuffer;
	return buffer;
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(window_length, window_width), "HackerTyper", sf::Style::Fullscreen);
	window.setFramerateLimit(60);
	sf::View view = window.getView();

	String buffer = uploadBufferFromFile("D:\\Проги\\ht.txt");

	String text;

	sf::Text program;
	sf::Font font;
	if (!font.loadFromFile("D:\\Проги\\arial.ttf"))
	{
		std::cout << "error" << std::endl;
	}

	program.setFont(font);
	program.setFillColor(sf::Color(255, 0, 0));
	program.setCharacterSize(20);

	int end = 0;
	int strings = 1;

	while (window.isOpen())
	{
		sf::Event event;

		program.setString(text.str);

		window.clear();
		window.setView(view);
		window.draw(program);
		window.display();


		while (window.pollEvent(event))
		{
			if ((event.type == sf::Event::Closed) || (event.key.code == sf::Keyboard::Escape))
			{
				window.close();
				break;
			}

			if (event.type == sf::Event::MouseWheelScrolled)
			{
				view.move(0, -20 * event.mouseWheelScroll.delta);
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (end <= buffer.length() - 1)
				{
					if (buffer[end] == '\n')
					{
						strings++;
						if (strings >= 46)
							view.move(0, 25);
					}
					if (buffer[end + 1] == '\n')
					{
						strings++;
						if (strings >= 46)
							view.move(0, 25);
					}
					text += String(buffer[end]);
					text += String(buffer[end + 1]);
					std::cout << text.str;
					end += 2;
				}
				break;
			}
		}
	}
	return 0;
}
