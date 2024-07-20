#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>

// Bullet class declaration
class Bullet
{
private:
	// Bullet parameters
	sf::Sprite bullet;
	sf::Vector2f direction;

	float bulletSpeed;
	bool enemyBullet; // Variable to tell whether a bullet is from a player or enemy


public:
	// Constructors
	Bullet();
	Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float moveSpeed, bool enemyBullet, int type);
	virtual ~Bullet();


	// Accessor
	const sf::FloatRect getBounds() const;
	const bool bulletChecker() const;

	void update();
	void render(sf::RenderTarget* target);

};

