/*#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <vector> */
#include "draw.hpp"

using namespace sf;
using std::vector;



int main()
{
	Music destroy("mp3/Destroy.mp3");
	batch load;

	load.add("img/mtrainierbg.png", 0);
	load.add("img/grass.png", 1);
	load.add("img/fisherman.png", 2);
	load.setOrg({ 0, 0 }, 0);
	load.setOrg({ 0,-800 }, 1);
	load.setOrg({ 0, -400 }, 2);
	destroy.play();
	float x = 0.0;
	//main game loop
	RenderWindow window(VideoMode({ 1600, 900 }), "GET FISH");
	while(window.isOpen()) 
	{
		load.draw(window);
		load.setPos({ x, 0 }, 2);
		x += 0.1;
	}

}