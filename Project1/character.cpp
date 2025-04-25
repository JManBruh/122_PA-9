#include "character.hpp"

inline void Character::init(const char* texturePath, sf::IntRect frame, sf::Vector2f startPos)
{
	charBatch.add(texturePath, frame, 0);

	//center origin for 512x512 sprite
	charBatch.setOrg({ 256.f, 256.f }, 0);

	charBatch.setPos(startPos, 0);
	position = startPos;
	velocity = { 0.f, 0.f };
}

void Character::update()
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
	charBatch.setPos(position, 0);
}

void Character::draw(RenderWindow& window)
{
	charBatch.draw(window);
}

Vector2f Character::getPosition() const
{
	return position;
}