#include "Enemy.h"

void Enemy::initializeVariables()
{
	this->hpMax = 10;
	this->hp = 0;
	this->damage = 1;
	this->points = 5;
	this->speed = 10.f;
}

Enemy::Enemy(sf::Texture* texture, float pos_x, float pos_y, int type)
{
	this->initializeVariables();

	switch(type)
	{
	case 1:
		this->enemyOne.setTexture(*texture);
		this->enemyOne.scale(1.f, 1.f);

		this->enemyOne.setPosition(pos_x, pos_y);

		this->hpMax = 10;
		this->hp = 0;
		this->damage = 1;
		this->points = 100;
		this->speed = 12.5f;
		break;

	case 2:
		this->enemyOne.setTexture(*texture);
		this->enemyOne.scale(1.f, 1.f);

		this->enemyOne.setPosition(pos_x, pos_y);

		this->hpMax = 10;
		this->hp = 0;
		this->damage = 1;
		this->points = 50;
		this->speed = 8.f;
		break;

	case 3:
		this->enemyOne.setTexture(*texture);
		this->enemyOne.scale(1.f, 1.f);

		this->enemyOne.setPosition(pos_x, pos_y);

		this->hpMax = 10;
		this->hp = 0;
		this->damage = 1;
		this->points = 25;
		this->speed = 5.f;
		break;
	}


}


Enemy::Enemy()
{
	initializeVariables();
}

Enemy::~Enemy()
{
}


const sf::FloatRect Enemy::getBounds() const
{
	return this->enemyOne.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return this->points;
}

void Enemy::update()
{
	this->enemyOne.move(0.f, this->speed);
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->enemyOne);
}

