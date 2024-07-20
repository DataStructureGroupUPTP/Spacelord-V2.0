#include "Bullet.h"

Bullet::Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float moveSpeed, bool enemyBullet, int type)
{
	// Bullet type initializer
	switch (type)
	{
	case 1:
		this->bullet.setTexture(*texture);
		this->bullet.scale(0.3f, 0.3f);
		this->enemyBullet = enemyBullet;

		this->bullet.setPosition(pos_x, pos_y);
		this->direction.x = dir_x;
		this->direction.y = dir_y;
		this->bulletSpeed = moveSpeed;
		break;
	case 2:
		this->bullet.setTexture(*texture);
		this->bullet.scale(0.7f, 0.7f);
		this->enemyBullet = enemyBullet;

		this->bullet.setPosition(pos_x, pos_y);
		this->direction.x = dir_x;
		this->direction.y = dir_y;
		this->bulletSpeed = moveSpeed;
		break;
	case 3:
		this->bullet.setTexture(*texture);
		this->bullet.scale(0.425f, 0.425f);
		this->enemyBullet = enemyBullet;

		this->bullet.setPosition(pos_x, pos_y);
		this->direction.x = dir_x;
		this->direction.y = dir_y;
		this->bulletSpeed = moveSpeed;
		break;

	}
}

Bullet::~Bullet()
{

}

// Bounds getter
const sf::FloatRect Bullet::getBounds() const
{
	return this->bullet.getGlobalBounds();
}

// Bullet type checker
const bool Bullet::bulletChecker() const
{
	return enemyBullet;
}

// Update
void Bullet::update()
{
	this->bullet.move(this->bulletSpeed * this->direction);
}

// Render
void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->bullet);
}
