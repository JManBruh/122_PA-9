#include "game.hpp"

void game()
{
	/* Since my team's actually looking at the code below, I guess I have to explain how it works...
	
	Sprite            ID
	--------------------
	Background        0
	Grass             1
	Player            2

	
	Sprites with a lower ID will be drawn first. Remember that when adding them to the batch list.
	*/

	//(obviously) loads the music from the folder. SFML's Music class is used for long files, while the Sound class is used for effects
	Music main("mp3/Fish Game.wav");
	//instantiate batch drawing class
	// Removed!
	//instantiate tile drawing class
	tilemap map; //Thanks to the magic of inheritance, this is now the class for everyting on the screen!

	//Optimization for the batch-drawer. For any sprite you want to add, look at its x/y dimensions, then add them here.
	IntRect asize({ 0, 0 }, { 512, 512 }), bsize({ 0, 0 }, { 1200, 675 });

	//SFML is annoying
	const float tileScaleConst = 0.1;
	float scaleFactor = 1 / tileScaleConst;
	//more variables
	float bgScale = 4.0 / 3.0;
	int framerate = 60;
	//w/h of each tile, makes math convenient
	int tileSize = 51;

	//add takes a string of where the image file is, its size, and a custom index (used so you can refer to it later) and adds to the batch
	map.add("img/mtrainierbg.png", bsize, 0);
	map.add("img/grass.png", asize, 1);
	//utilizing the player class!
	Character guy("img/fisherman.png", asize, { scaleFactor * 0, scaleFactor * -650 }, &map, 2);

	//sets properties of each sprite, selected by index. The {} is because Origin requires a Vector2f, so it contains X and Y values.
	map.setOrg({ 0, 0 }, 0);
	map.setOrg({ scaleFactor*0, scaleFactor*-650 }, 2);
	//Implemented scaling!
	map.setScl({ bgScale,bgScale}, 0);
	map.setScl({ tileScaleConst, tileScaleConst }, 1);
	map.setScl({ tileScaleConst,tileScaleConst }, 2);

	//multiple positions for anyting you want to tile
	vector<Vector2f> mapPos = {};
	//heheheha
	map.setMultiPos(mapGen(mapPos, scaleFactor, tileSize), 1);

	//start music. this has to be out of the draw loop
	main.play();
	//for demo movement
	float x = 0.0;
	//opens window (tried to put this inside the batch class, but it didn't work)
	RenderWindow window(VideoMode({ 1600, 900 }), "GET FISH");
	window.setFramerateLimit(framerate);
	while (window.isOpen())
	{
		//controlling the window
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<Event::Closed>())
				window.close();
		}
		/*Code inside this loop gets called every frame.*/

		//One command for drawing everything in the batch!
		map.drawTilemap(window);
		//Physics! Hopefully!
		guy.update(&map);
		//update the sprite's position every frame
		x += 0.1;
	}
}

vector<Vector2f> mapGen(vector<Vector2f> array, float scaleFactor, int tileSize) 
{
	//each int is how many blocks it generates of that level
	int floor = 500;
	int platform1 = 10;
	int hillwidth = 10;
	int hillheight = 5;
	//makes the code nicer to read
	int aggregate = 0;
	float spacing = -scaleFactor * (float)tileSize;

	array.resize(floor);
	for(int i = 0; i < floor; i++) 
	{
		array[i] = { spacing * i, spacing * 14 };
	}
	aggregate += floor;
	array.resize(aggregate + platform1);
	for(int i = 0; i < platform1; i++) 
	{
		array[aggregate + i] = {spacing * i, spacing * 8 };
	}
	aggregate += platform1;
	array.resize(aggregate + hillwidth);

	for (int i = 0; i < hillwidth; i++)
	{
		if (i < hillheight) 
		{
			array[aggregate + i] = { spacing * i + (spacing * 10), -spacing * i + (spacing * 14)};
		} else 
		{
			array[aggregate + i] = { spacing * i + (spacing * 12), spacing * i + (spacing * 5) };
		}
	}
	return array;
}