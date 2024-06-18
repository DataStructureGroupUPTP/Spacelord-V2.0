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


// Hello world

class Player
{
private:
	sf::Texture texture;
	sf::Sprite ship;

	float movementSpeed;

	float attackCooldown;
	float attackCooldownMax;

	int hp;
	int hpMax;

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
	const int& getHp() const;
	const int& getHpMax() const;

	// Functions
	void move(const float dirX, const float dirY);
	const bool canAttack();

	// Modifiers
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setHp(const int hp);
	void loseHp(const int value);
	
	
	void updateAttackCooldown();
	void update();
	void render(sf::RenderTarget& target);
};
