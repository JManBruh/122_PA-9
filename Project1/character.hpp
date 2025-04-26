#include "tilemap.hpp"

class Character {
public:
	//initialize sprite and physics values
	Character(const char* texturePath, IntRect frame, Vector2f startPos, tilemap *batch, int IDin);

	//handle input and physics
	void update(tilemap *batch);

	//get current position (for collisions or camera use)
	Vector2f getPosition() const;

private:
	int PlayerID;
	Vector2f velocity;
	Vector2f position;
	bool isJumping = false;

	const float gravity = 0.5f;
	const float jumpStrength = -12.0f;
	const float groundY = 500.0f; //hardcoded floor ypos (temp)
};