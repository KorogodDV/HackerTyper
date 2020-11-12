#include "String.h"
#include <SFML/Graphics.hpp>
#include <cstdio>

const int window_length = 1920;
const int window_width = 1080;


//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	sf::RenderWindow window(sf::VideoMode(window_length, window_width), "HackerTyper", sf::Style::Fullscreen);
//	sf::View view;
//
//	#pragma warning(disable : 4996) .
//	FILE* f = fopen("D:\\Проги\\ht.txt", "r");
//	fseek(f, 0, SEEK_END);
//	int len = ftell(f);
//	rewind(f);
//	char* cbuffer = new char[len];
//	size_t p = fread(cbuffer, 1, len, f);
//	fclose(f);
//	String buffer = String(cbuffer).split(p)[0];
//	delete[] cbuffer;
//
//	String text;
//
//	sf::Text program;
//	sf::Font font;
//	if (!font.loadFromFile("D:\\Проги\\arial.ttf"))
//	{
//		std::cout << "error" << std::endl;
//	}
//
//	program.setFont(font);
//	program.setFillColor(sf::Color(255, 0, 0));
//	program.setCharacterSize(20);
//	//program.setString(buffer.str);
//
//	int start = 0;
//	int end = 0;
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		program.setString((buffer.split(end))[0].str);
//		window.draw(program);
//		window.display();
//
//
//		while (window.pollEvent(event))
//		{
//			if ((event.type == sf::Event::Closed) || (event.key.code == sf::Keyboard::Escape))
//			{
//				window.close();
//				break;
//			}
//
//			if (event.type == sf::Event::KeyPressed)
//			{
//				text += String(buffer.str[end] + buffer.str[end + 1]);
//				end += 2;
//				break;
//			}
//		}
//	}
//	return 0;
//}

int main()
{
	char s1[] = "asdsadasdsads";
	char s2[] = "122212333333333333333333321312312312312312";
	String str1 = String(s1);
	String str2 = String(s2);
	//str1 += str2;
	std::cout << str1.split(5)[0].str;
	return 0;
}