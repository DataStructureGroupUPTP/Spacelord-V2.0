#include "Item.h"

void Item::initializeVariables()
{
	this->type = 1;
	this->points = 1000;
	this->speed = 5.f;
}


Item::Item(sf::Texture* texture, float pos_x, float pos_y, int type)
{
	this->initializeVariables();

	switch (type)
	{
	case 1:
		this->itemSprite.setTexture(*texture);
		this->itemSprite.scale(1.5f, 1.5f);

		this->itemSprite.setPosition(pos_x, pos_y);

		this->type = type;
		this->points = 5000;
		this->speed = 2.5f;
		break;
	case 2:
		this->itemSprite.setTexture(*texture);
		this->itemSprite.scale(1.5f, 1.5f);

		this->itemSprite.setPosition(pos_x, pos_y);

		this->type = type;
		this->points = 2000;
		this->speed = 3.5f;
		break;

	case 3:
		this->itemSprite.setTexture(*texture);
		this->itemSprite.scale(1.5f, 1.5f);

		this->itemSprite.setPosition(pos_x, pos_y);

		this->type = type;
		this->points = 2000;
		this->speed = 3.5f;
		break;

	}
}

Item::Item()
{
	initializeVariables();
}

Item::~Item()
{
}

const int& Item::getPoints() const
{
	return this->points;
}

const sf::FloatRect Item::getBounds() const
{
	return this->itemSprite.getGlobalBounds();
}

const int& Item::getType() const
{
	return this->type;
}

void Item::update()
{
	this->itemSprite.move(0.f, this->speed);
}

void Item::render(sf::RenderTarget& target)
{
	target.draw(this->itemSprite);
}
