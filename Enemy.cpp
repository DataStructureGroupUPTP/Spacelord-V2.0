#include "Enemy.h"

void Enemy::initializeVariables()
{
	this->type = 1;
	this->hp = 0;
	this->damage = 1;
	this->points = 5;
	this->speed = 10.f;

	this->meteorSpeedIncrease = 0.f;

	// Initialize animation variables
	this->animationTimer = 0.f;
	this->animationInterval = 0.5f; // Change frame every 0.2 seconds
	this->currentFrame = 0;
}

void Enemy::initializeTextures()
{
	this->textures["SMALLENEMY"] = new sf::Texture();
	if (!this->textures["SMALLENEMY"]->loadFromFile("Textures/Smallenemyf1.png"))
	{
		std::cout << "TEXTURE::SMALL_ENEMY::FAILED_TO_LOAD" << "\n";
	}

	this->textures["SMALLENEMY2"] = new sf::Texture();
	if (!this->textures["SMALLENEMY2"]->loadFromFile("Textures/Smallenemyf2.png"))
	{
		std::cout << "TEXTURE::SMALL_ENEMY::FAILED_TO_LOAD" << "\n";
	}

	this->textures["MEDIUMENEMY"] = new sf::Texture();
	if (!this->textures["MEDIUMENEMY"]->loadFromFile("Textures/Mediumenemyf1.png"))
	{
		std::cout << "TEXTURE::MEDIUM_ENEMY::FAILED_TO_LOAD" << "\n";
	}

	this->textures["MEDIUMENEMY2"] = new sf::Texture();
	if (!this->textures["MEDIUMENEMY2"]->loadFromFile("Textures/Mediumenemyf2.png"))
	{
		std::cout << "TEXTURE::MEDIUM_ENEMY::FAILED_TO_LOAD" << "\n";
	}

	this->textures["BIGENEMY"] = new sf::Texture();
	if (!this->textures["BIGENEMY"]->loadFromFile("Textures/Bigenemyf1.png"))
	{
		std::cout << "TEXTURE::BIG_ENEMY::FAILED_TO_LOAD" << "\n";
	}

	this->textures["BIGENEMY2"] = new sf::Texture();
	if (!this->textures["BIGENEMY2"]->loadFromFile("Textures/Bigenemyf2.png"))
	{
		std::cout << "TEXTURE::BIG_ENEMY::FAILED_TO_LOAD" << "\n";
	}

	this->textures["METEOR"] = new sf::Texture();
	if (!this->textures["METEOR"]->loadFromFile("Textures/Meteor.png"))
	{
		std::cout << "TEXTURE::METEOR::FAILED_TO_LOAD" << "\n";
	}
}


Enemy::Enemy(float pos_x, float pos_y, int type)
{
	this->initializeVariables();
	this->initializeTextures();

	switch(type)
	{
	case 1:
		this->enemyOne.setTexture(*this->textures["SMALLENEMY"]);
		this->enemyOne.setScale(2.75f, 2.75f);

		this->enemyOne.setPosition(pos_x, pos_y);

		this->type = type;
		this->hp = 1.f;
		this->damage = 1;
		this->points = 100;
		this->speed = 6.0f;
		break;

	case 2:
		this->enemyTwo.setTexture(*this->textures["MEDIUMENEMY"]);
		this->enemyTwo.scale(2.75f, 2.75f);

		this->enemyTwo.setPosition(pos_x, pos_y);

		this->type = type;
		this->hp = 1.5f;
		this->damage = 1;
		this->points = 250;
		this->speed = 5.5f;
		break;

	case 3:
		this->enemyThree.setTexture(*this->textures["BIGENEMY"]);
		this->enemyThree.scale(2.75f, 2.75f);

		this->enemyThree.setPosition(pos_x, pos_y);

		this->type = type;
		this->hp = 3.f;
		this->damage = 1;
		this->points = 500;
		this->speed = 5.0f;
		break;

	case 4:
		this->meteor.setTexture(*this->textures["METEOR"]);

		this->meteor.setPosition(pos_x, pos_y);
		this->meteor.setScale(2.25f, 2.25f);

		this->type = type;
		this->hp = 999;
		this->damage = 1;
		this->points = 0.f;
		this->speed = 7.5f + meteorSpeedIncrease;
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
	if(type == 1)
	{
		return this->enemyOne.getGlobalBounds();
	}
	if(type == 2)
	{
		return this->enemyTwo.getGlobalBounds();
	}
	if(type == 3)
	{
		return this->enemyThree.getGlobalBounds();
	}
	if(type == 4)
	{
		return this->meteor.getGlobalBounds();
	}
	
}

const int& Enemy::getPoints() const
{
	return this->points;
}

const int& Enemy::getDamage() const
{
	return this->damage;
}

const float& Enemy::getHp() const
{
	return this->hp;
}

void Enemy::reduceHp(const float value)
{
	this->hp = this->hp - value;

	if(this->hp < 0)
	{
		this->hp = 0;
	}
}

void Enemy::increaseMeteorSpeed(const float value)
{
	this->meteorSpeedIncrease = meteorSpeedIncrease + value;
}

void Enemy::update()
{
	updateAnimation();

	if (type == 5 or type == 6) 
	{
		this->enemyOne.move(this->speed, 0.f);

	}
	else
	{

		if (type == 1)
		{
			this->enemyOne.move(0.f, this->speed);
		}
		
		if(type == 2)
		{
			this->enemyTwo.move(0.f, this->speed);
		}
		
		if(type == 3)
		{
			this->enemyThree.move(0.f, this->speed);
		}
		
		if(type == 4)
		{
			this->meteor.move(0.f, this->speed);
		}


	}
}

void Enemy::updateAnimation()
{
	// Update animation timer
	this->animationTimer += 0.1f; // Assuming this function is called frequently (e.g., every frame)

	if (this->animationTimer >= this->animationInterval)
	{
		// Reset timer
		this->animationTimer = 0.f;

		// Swap frames based on enemy type
		switch (this->type)
		{
		case 1:
			if (this->currentFrame == 0)
			{
				this->enemyOne.setTexture(*this->textures["SMALLENEMY2"]);
				this->currentFrame = 1;
			}
			else
			{
				this->enemyOne.setTexture(*this->textures["SMALLENEMY"]);
				this->currentFrame = 0;
			}
			break;

		case 2:
			if (this->currentFrame == 0)
			{
				this->enemyTwo.setTexture(*this->textures["MEDIUMENEMY2"]);
				this->currentFrame = 1;
			}
			else
			{
				this->enemyTwo.setTexture(*this->textures["MEDIUMENEMY"]);
				this->currentFrame = 0;
			}
			break;

		case 3:
			if (this->currentFrame == 0)
			{
				this->enemyThree.setTexture(*this->textures["BIGENEMY2"]);
				this->currentFrame = 1;
			}
			else
			{
				this->enemyThree.setTexture(*this->textures["BIGENEMY"]);
				this->currentFrame = 0;
			}
			break;

		default:
			break;
		}
	}
}

void Enemy::render(sf::RenderTarget& target)
{
	switch (this->type)
	{
	case 1:
		target.draw(this->enemyOne);
		break;
	case 2:
		target.draw(this->enemyTwo);
		break;
	case 3:
		target.draw(this->enemyThree);
		break;
	case 4:
		target.draw(this->meteor);
		break;
	default:
		break;
	}
}

