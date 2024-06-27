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
	sf::Sprite meteor;

	// Stats
	int type;
	float hp;
	int damage;
	int points;
	float speed;

	float meteorSpeedIncrease;

	// Texture vector
	std::map<std::string, sf::Texture*> textures;

	// Private functions
	void initializeVariables();
	void initializeTextures();

	// Animation
	int currentFrame;
	float animationTimer;
	float animationInterval;


public:

	Enemy();
	Enemy(float pos_x, float pos_y, int type);

	virtual ~Enemy();

	// Accessors
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;
	const float& getHp() const;
	void reduceHp(const float value);
	void increaseMeteorSpeed(const float value);
	const sf::Vector2f& getPos() const;

	void update();
	void updateAnimation();
	void render(sf::RenderTarget& target);
};

