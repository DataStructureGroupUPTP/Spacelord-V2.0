#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>

class Item
{
private:
	sf::Texture itemTexture;
	sf::Sprite itemSprite;

	int type;
	float speed;
	int points;

	void initializeVariables();

public:
	Item();
	Item(sf::Texture* texture, float pos_x, float pos_y, int type );
	
	virtual ~Item();

	const int& getPoints() const;
	const sf::FloatRect getBounds() const;
	const int& getType() const;

	void update();
	void render(sf::RenderTarget& target);
};

