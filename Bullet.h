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

class Bullet
{
private:
	sf::Sprite bullet;

	sf::Vector2f direction;

	float bulletSpeed;


public:
	Bullet();
	Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float moveSpeed);
	virtual ~Bullet();

	// Accessor
	const sf::FloatRect getBounds() const;

	void update();
	void render(sf::RenderTarget* target);

};
