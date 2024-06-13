#include "Enemy.h"

void Enemy::initializeVariables()
{
	this->type = 0;
	this->hpMax = 10;
	this->hp = 0;
	this->damage = 1;
	this->points = 5;
	this->speed = 10.f;
}

Enemy::Enemy(sf::Texture* texture, float pos_x, float pos_y)
{
	this->initializeVariables();

	this->enemyOne.setTexture(*texture);
	this->enemyOne.scale(1.f,1.f);

	this->enemyOne.setPosition(pos_x, pos_y);


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

void Enemy::update()
{
	this->enemyOne.move(0.f, this->speed);
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->enemyOne);
}

