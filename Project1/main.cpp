#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>

using namespace sf;
using std::vector;

int main()
{
	Texture guy(Image("img/fisherman.png"), false);
	Sprite sprguy(guy);
	sprguy.setOrigin({ -300.f, -300.f });
	sprguy.setRotation(degrees(0));
	sprguy.setScale({ 1.f, 1.f });
	Vector2f debug = sprguy.getPosition();

	RenderWindow window(VideoMode({ 1600, 900 }), "GET FISH");
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