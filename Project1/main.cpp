#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>

using namespace sf;
using std::vector;

int main()
{
	Texture guy("img/fisherman.png", false, IntRect({ 10, 10 }, { 16, 16 }));
	Sprite sprguy(guy);
	sprguy.setPosition({10.f, 50.f});
	sprguy.setRotation(sf::degrees(90));
	sprguy.setScale({ 0.5f, 2.f });

	RenderWindow window(sf::VideoMode({ 1600, 900 }), "PA 9: FISHING");
	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<Event::Closed>())
				window.close();
		}
		window.clear();
		window.draw(sprguy);
		window.display();
	}

}