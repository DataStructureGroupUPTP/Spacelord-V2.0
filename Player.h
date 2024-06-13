#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>


class Player
{
private:
	sf::Texture texture;
	sf::Sprite ship;

	float movementSpeed;

	float attackCooldown;
	float attackCooldownMax;

	// Private functions
	void initializeVariables();
	void initializeTexture();
	void initializeSprite();

public:
	Player();
	virtual ~Player();

	// Accessors
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;

	// Functions
	void move(const float dirX, const float dirY);
	const bool canAttack();
	
	
	void updateAttackCooldown();
	void update();
	void render(sf::RenderTarget& target);
};
