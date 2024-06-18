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

class Enemy
{
private:
	sf::Texture texture;
	sf::Sprite enemyOne;

	// Stats
	int type;
	int hp;
	int hpMax;
	int damage;
	int points;
	float speed;

	// Private functions
	void initializeVariables();


public:

	Enemy();
	Enemy(sf::Texture* texture, float pos_x, float pos_y, int type);

	virtual ~Enemy();

	// Accessors
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;


	void update();
	void render(sf::RenderTarget& target);
};

