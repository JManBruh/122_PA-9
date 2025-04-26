#include "character.hpp"

Character::Character(const char* texturePath, IntRect frame, Vector2f startPos, tilemap *batch, int IDin)
{
	PlayerID = IDin;
	batch->add(texturePath, frame, PlayerID);

	//center origin for 512x512 sprite
	batch->setOrg({ 256.f, 256.f }, PlayerID);

	batch->setPos(startPos, PlayerID);
	position = startPos;
	velocity = { 0.f, 0.f };
}

void Character::update(tilemap *batch)
{
	if (!isJumping && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		velocity.y = jumpStrength;
		isJumping = true;
	}

	//apply gravity
	velocity.y += gravity;
	position.y += velocity.y;

	//ground collision
	if (position.y >= groundY) {
		position.y = groundY;
		velocity.y = 0;
		isJumping = false;
	}

	//update position in batch
	batch->setPos(position, PlayerID);
}

Vector2f Character::getPosition() const
{
	return position;
}