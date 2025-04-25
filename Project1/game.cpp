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

	//add takes a string of where the image file is, its size, and a custom index (used so you can refer to it later) and adds to the batch
	map.add("img/mtrainierbg.png", bsize, 0);
	map.add("img/grass.png", asize, 1);
	map.add("img/fisherman.png", asize, 2);

	//SFML is annoying
	const float tileScaleConst = 0.1;
	float scaleFactor = 1 / tileScaleConst;
	float bgScale = 4.0 / 3.0;
	//sets properties of each sprite, selected by index. The {} is because Origin requires a Vector2f, so it contains X and Y values.
	map.setOrg({ 0, 0 }, 0);
	map.setOrg({ scaleFactor*0, scaleFactor*-400 }, 2);
	//Implemented scaling!
	map.setScl({ bgScale,bgScale}, 0);
	map.setScl({ tileScaleConst, tileScaleConst }, 1);
	map.setScl({ tileScaleConst,tileScaleConst }, 2);

	//multiple positions for anyting you want to tile
	vector<Vector2f> mapPos = { {scaleFactor*0,scaleFactor * -100}, {scaleFactor * 0, scaleFactor * 0}, {scaleFactor * -800,scaleFactor * -899} };

	//not working yet
	map.setMultiPos(mapPos, 1);

	//start music. this has to be out of the draw loop
	main.play();
	//for demo movement
	float x = 0.0;
	//opens window (tried to put this inside the batch class, but it didn't work)
	RenderWindow window(VideoMode({ 1600, 900 }), "GET FISH");
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
		//Doing this in here updates the sprite's position every frame, making it move.
		map.setPos({ x, 0 }, 2);
		//update the sprite's position every frame
		x += 0.1;
	}
}