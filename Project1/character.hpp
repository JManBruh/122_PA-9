#include "draw.hpp"

class Character {
public:
	//initialize sprite and physics values
	void init(const char* texturePath, IntRect frame, Vector2f startPos);

	//handle input and physics
	void update();

	//render using internal batch
	void draw(RenderWindow& window);

	//get current position (for collisions or camera use)
	Vector2f getPosition() const;

private:
	batch charBatch;
	Vector2f velocity;
	Vector2f position;
	bool isJumping = false;

	const float gravity = 0.5f;
	const float jumpStrength = -12.0f;
	const float groundY = 500.0f; //hardcoded floor ypos (temp)
};