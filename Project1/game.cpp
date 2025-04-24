#include "game.hpp"

void game()
{
	/* Since my team's actually looking at the code below, I guess I have to explain how it works...*/

	//(obviously) loads the music from the folder. SFML's Music class is used for long files, while the Sound class is used for effects
	Music main("mp3/Fish Game.wav");
	//instantiate batch drawing class
	batch load;
	//instantiate tile drawing class
	tilemap map;

	//Optimization for the batch-drawer. For any sprite you want to add, look at its x/y dimensions, then add them here.
	IntRect asize({ 0, 0 }, { 512, 512 }), bsize({ 0, 0 }, { 1200, 675 });
	//not working yet
	vector<Vector2f> mapPos = { {0,-600}, {-100, -600}, {-200, -600}, {-300, -600} };

	//.add takes a string of where the image file is, its size, and a custom index (used so you can refer to it later) and adds to the batch
	load.add("img/mtrainierbg.png", bsize, 0);
	load.add("img/fisherman.png", asize, 2);
	//sets properties of each sprite, selected by index. The {} is because Origin requires a Vector2f, so it contains X and Y values.
	load.setOrg({ 0, 0 }, 0);
	load.setOrg({ 0,-800 }, 1);
	load.setOrg({ 0, -400 }, 2);
	//Implemented scaling!
	load.setScl({ 2,2 }, 0);
	load.setScl({ 1,1 }, 1);
	load.setScl({ 1,1 }, 2);

	//not working yet
	map.addTilemap("img/grass.png", 0);
	map.setMultiPos(mapPos, 0);

	//start music. this has to be out of the draw loop
	main.play();
	//for demo movement
	float x = 0.0;
	//opens window (tried to put this inside the batch class, but it didn't work)
	RenderWindow window(VideoMode({ 1600, 900 }), "GET FISH");
	while (window.isOpen())
	{
		/*Code inside this loop gets called every frame.*/

		//One command for drawing everything in the batch!
		load.draw(window);
		//Doing this in here updates the sprite's position every frame, making it move.
		load.setPos({ x, 0 }, 2);
		//update the sprite's position every frame
		x += 0.1;
	}
}