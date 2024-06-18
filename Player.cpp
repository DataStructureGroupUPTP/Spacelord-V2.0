#include "Player.h"

void Player::initializeVariables()
{
	this->movementSpeed = 7.5f;

	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;

	this->hpMax = 5;
	this->hp = this->hpMax;
}

void Player::initializeTexture()
{
	// Load texture
	if (!this->texture.loadFromFile("Textures/Mainshipfix.png"))
	{
		std::cout << "TEXTURE::MAIN_SHIP::FAILED_TO_LOAD" << "\n";
	}
}


void Player::initializeSprite()
{
	// Set texture to sprite
	this->ship.setTexture(this->texture);

	// Resize
	this->ship.scale(2.25f, 2.25f);

	this->ship.setPosition(345.5f, 400.f);

}

// Constructors
Player::Player()
{
	this->initializeVariables();
	this->initializeTexture();
	this->initializeSprite();


}

Player::~Player()
{
}

const sf::Vector2f& Player::getPos() const
{
	return this-> ship.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->ship.getGlobalBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

void Player::move(const float dirX, const float dirY)
{
	this->ship.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->ship.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->ship.setPosition(x,y);
}

void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp = this->hp - value;
	if (this->hp < 0)
	{
		this->hp = 0;
	}
}

void Player::updateAttackCooldown()
{
	if(this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.75f;
	}


	
}

// Functions
void Player::update()
{
	this->updateAttackCooldown();


}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->ship);

}
