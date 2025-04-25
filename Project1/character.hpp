#pragma once
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
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
