#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>

// Item class declaration
class Item
{
private:

	//Item parameters
	sf::Texture itemTexture;
	sf::Sprite itemSprite;

	int type;
	float speed;
	int points;

	void initializeVariables();

public:
	// Constructors
	Item();
	Item(sf::Texture* texture, float pos_x, float pos_y, int type );
	
	virtual ~Item();

	// Getters
	const int& getPoints() const;
	const sf::FloatRect getBounds() const;
	const int& getType() const;

	// Update & render
	void update();
	void render(sf::RenderTarget& target);
};

