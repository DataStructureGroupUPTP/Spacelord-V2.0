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

	this->textures["STAGE2ENEMY1"] = new sf::Texture();
	if(!this->textures["STAGE2ENEMY1"]->loadFromFile("Textures/Stage2e1.png"))
	{
		std::cout << "TEXTURE::STAGE2ENEMY1::FAILED_TO_LOAD" << "\n";
	}

	this->textures["STAGE2ENEMY2"] = new sf::Texture();
	if (!this->textures["STAGE2ENEMY2"]->loadFromFile("Textures/Stage2e2.png"))
	{
		std::cout << "TEXTURE::STAGE2ENEMY2::FAILED_TO_LOAD" << "\n";
	}

	this->textures["STAGE2ENEMY3"] = new sf::Texture();
	if (!this->textures["STAGE2ENEMY3"]->loadFromFile("Textures/Stage2e3.png"))
	{
		std::cout << "TEXTURE::STAGE2ENEMY3::FAILED_TO_LOAD" << "\n";
	}

	this->textures["STAGE2ENEMY4"] = new sf::Texture();
	if (!this->textures["STAGE2ENEMY4"]->loadFromFile("Textures/Stage2e4.png"))
	{
		std::cout << "TEXTURE::STAGE2ENEMY4::FAILED_TO_LOAD" << "\n";
	}

	this->textures["STAGE2ENEMY5"] = new sf::Texture();
	if (!this->textures["STAGE2ENEMY5"]->loadFromFile("Textures/Stage2e5.png"))
	{
		std::cout << "TEXTURE::STAGE2ENEMY5::FAILED_TO_LOAD" << "\n";
	}

	this->textures["STAGE2ENEMY6"] = new sf::Texture();
	if (!this->textures["STAGE2ENEMY6"]->loadFromFile("Textures/Stage2e6.png"))
	{
		std::cout << "TEXTURE::STAGE2ENEMY6::FAILED_TO_LOAD" << "\n";
	}

	if (!this->bomberFireTexture.loadFromFile("Animations/Bomberfire.png"))
	{
		std::cout << "TEXTURE::BOMBER_FIRE::FAILED_TO_LOAD" << "\n";
	}

	if (!this->frigateFireTexture.loadFromFile("Animations/Frigatefire.png"))
	{
		std::cout << "TEXTURE::FRIGATE_FIRE::FAILED_TO_LOAD" << "\n";
	}

	if (!this->scoutFireTexture.loadFromFile("Animations/Scoutfire.png"))
	{
		std::cout << "TEXTURE::SCOUT_FIRE::FAILED_TO_LOAD" << "\n";
	}

	if (!this->fighterFireTexture.loadFromFile("Animations/Fighterfire.png"))
	{
		std::cout << "TEXTURE::FIGHTER_FIRE::FAILED_TO_LOAD" << "\n";
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
		this->enemyOne.setTexture(*this->textures["MEDIUMENEMY"]);
		this->enemyOne.scale(2.75f, 2.75f);

		this->enemyOne.setPosition(pos_x, pos_y);

		this->type = type;
		this->hp = 1.5f;
		this->damage = 1;
		this->points = 250;
		this->speed = 5.5f;
		break;

	case 3:
		this->enemyOne.setTexture(*this->textures["BIGENEMY"]);
		this->enemyOne.scale(2.75f, 2.75f);

		this->enemyOne.setPosition(pos_x, pos_y);

		this->type = type;
		this->hp = 3.f;
		this->damage = 1;
		this->points = 500;
		this->speed = 5.0f;
		break;

	case 4:
		this->enemyOne.setTexture(*this->textures["METEOR"]);

		this->enemyOne.setPosition(pos_x, pos_y);
		this->enemyOne.setScale(2.25f, 2.25f);

		this->type = type;
		this->hp = 999;
		this->damage = 1;
		this->points = 0;
		this->speed = 7.5f + meteorSpeedIncrease;

		break;

	case 5:
		this->enemyOne.setTexture(*this->textures["STAGE2ENEMY1"]);
		this->enemyOne.scale(2.75f, 2.75f);

		this->enemyOne.setPosition(pos_x, pos_y);

		this->type = type;
		this->hp = 9.f;
		this->damage = 1;
		this->points = 500; 
		this->speed = 6.5f;

		this->bomberFire.setTexture(this->bomberFireTexture);
		this->bomberfireFrame = sf::IntRect(0, 0, 64, 64); // Set the initial frame (width = 64, height = 64)
		this->bomberFire.setTextureRect(this->bomberfireFrame);
		this->bomberFire.setScale(2.75f, 2.75f);
		this->bomberFire.setPosition(this->enemyOne.getPosition().x - (this->textures["STAGE2ENEMY1"]->getSize().x / 2) * 2.75, this->enemyOne.getPosition().y - (this->textures["STAGE2ENEMY1"]->getSize().y) * 2.75 + 45.f);
		this->bomberCurrentFrame = 0;
		this->bomberAnimationTimer = 0.f;
		this->bomberAnimationSpeed = 0.1f;
		break;

	case 6:
		this->enemyOne.setTexture(*this->textures["STAGE2ENEMY2"]);
		this->enemyOne.scale(2.75f, 2.75f);

		this->enemyOne.setPosition(pos_x, pos_y);

		this->type = type;
		this->hp = 4.5f;
		this->damage = 1;
		this->points = 200;
		this->speed = 7.5f;

		this->scoutFire.setTexture(this->scoutFireTexture);
		this->scoutFireFrame = sf::IntRect(0, 0, 64, 64); // Set the initial frame (width = 64, height = 64)
		this->scoutFire.setTextureRect(this->scoutFireFrame);
		this->scoutFire.setScale(2.75f, 2.75f);
		this->scoutFire.setPosition(this->enemyOne.getPosition().x - (this->textures["STAGE2ENEMY2"]->getSize().x / 2) * 2.75, this->enemyOne.getPosition().y - (this->textures["STAGE2ENEMY2"]->getSize().y) * 2.75 - 50.f);
		this->scoutCurrentFrame = 0;
		this->scoutAnimationTimer = 0.f;
		this->scoutAnimationSpeed = 0.1f;
		break;

	case 7:
		this->enemyOne.setTexture(*this->textures["STAGE2ENEMY3"]);
		this->enemyOne.scale(2.75f, 2.75f);

		this->enemyOne.setPosition(pos_x, pos_y);

		this->type = type;
		this->hp = 15.f;
		this->damage = 2;
		this->points = 1000;
		this->speed = 4.0f;

		this->frigateFire.setTexture(this->frigateFireTexture);
		this->frigateFireFrame = sf::IntRect(0, 0, 64, 64); // Set the initial frame (width = 64, height = 64)
		this->frigateFire.setTextureRect(this->frigateFireFrame);
		this->frigateFire.setScale(2.75f, 2.75f);
		this->frigateFire.setPosition(this->enemyOne.getPosition().x - (this->textures["STAGE2ENEMY3"]->getSize().x / 2) * 2.75, this->enemyOne.getPosition().y - (this->textures["STAGE2ENEMY3"]->getSize().y) * 2.75 - 50.f);
		this->frigateCurrentFrame = 0;
		this->frigateAnimationTimer = 0.f;
		this->frigateAnimationSpeed = 0.1f;
		break;

	case 8:
		this->enemyOne.setTexture(*this->textures["STAGE2ENEMY4"]);
		this->enemyOne.scale(2.75f, 2.75f);

		this->enemyOne.setPosition(pos_x, pos_y);

		this->type = type;
		this->hp = 1.f;
		this->damage = 1;
		this->points = 100;
		this->speed = 13.5f;

		this->fighterFire.setTexture(this->fighterFireTexture);
		this->fighterFrame = sf::IntRect(0, 0, 64, 64); // Set the initial frame (width = 64, height = 64)
		this->fighterFire.setTextureRect(this->fighterFrame);
		this->fighterFire.setScale(2.75f, 2.75f);
		this->fighterFire.setPosition(this->enemyOne.getPosition().x - (this->textures["STAGE2ENEMY4"]->getSize().x / 2) * 2.75, this->enemyOne.getPosition().y - (this->textures["STAGE2ENEMY4"]->getSize().y) * 2.75 - 50.f);
		this->fighterCurrentFrame = 0;
		this->fighterAnimationTimer = 0.f;
		this->fighterAnimationSpeed = 0.1f;
		break;

	case 9:
		this->enemyOne.setTexture(*this->textures["STAGE2ENEMY5"]);
		this->enemyOne.scale(2.75f, 2.75f);

		this->enemyOne.setPosition(pos_x, pos_y);

		this->type = type;
		this->hp = 6.f;
		this->damage = 1;
		this->points = 500;
		this->speed = 5.0f;
		break;

	case 10:
		this->enemyOne.setTexture(*this->textures["STAGE2ENEMY6"]);
		this->enemyOne.scale(2.75f, 2.75f);

		this->enemyOne.setPosition(pos_x, pos_y);

		this->type = type;
		this->hp = 6.f;
		this->damage = 1;
		this->points = 500;
		this->speed = 5.0f;
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

const sf::Vector2f& Enemy::getPos() const
{
	return this->enemyOne.getPosition();
}

void Enemy::update()
{
	updateAnimation();
	updateBomberAnimation();
	updateFrigateAnimation();
	updateScoutAnimation();
	updateFighterAnimation();

	if(this->type == 9)
	{
		this->enemyOne.move(this->speed, 0.f);
	}
	else if(this->type == 10)
	{
		this->enemyOne.move(-this->speed, 0.f);
	}
	else 
	{
		this->enemyOne.move(0.f, this->speed);
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
				this->enemyOne.setTexture(*this->textures["MEDIUMENEMY2"]);
				this->currentFrame = 1;
			}
			else
			{
				this->enemyOne.setTexture(*this->textures["MEDIUMENEMY"]);
				this->currentFrame = 0;
			}
			break;

		case 3:
			if (this->currentFrame == 0)
			{
				this->enemyOne.setTexture(*this->textures["BIGENEMY2"]);
				this->currentFrame = 1;
			}
			else
			{
				this->enemyOne.setTexture(*this->textures["BIGENEMY"]);
				this->currentFrame = 0;
			}
			break;

		default:
			break;
		}
	}
}

void Enemy::updateBomberAnimation()
{
	if (this->type == 5) // Only update for bomber type
	{
		this->bomberAnimationTimer += 0.025f; // Assuming this function is called frequently (e.g., every frame)

		if (this->bomberAnimationTimer >= this->bomberAnimationSpeed)
		{
			// Reset timer
			this->bomberAnimationTimer = 0.f;

			// Update frame
			this->bomberCurrentFrame++;
			if (this->bomberCurrentFrame >= 10)
				this->bomberCurrentFrame = 0;

			// Set texture rect
			this->bomberfireFrame.left = this->bomberCurrentFrame * 64;
			this->bomberFire.setTextureRect(this->bomberfireFrame);
			this->bomberFire.setPosition(this->enemyOne.getPosition().x - (this->textures["STAGE2ENEMY1"]->getSize().x / 2)*2.75, this->enemyOne.getPosition().y - (this->textures["STAGE2ENEMY1"]->getSize().y)*2.75 + 55.f); 
		}
	}
}



void Enemy::updateScoutAnimation()
{
	if (this->type == 6) // Only update for scout type
	{
		this->scoutAnimationTimer += 0.04f; // Assuming this function is called frequently (e.g., every frame)

		if (this->scoutAnimationTimer >= this->scoutAnimationSpeed)
		{
			// Reset timer
			this->scoutAnimationTimer = 0.f;

			// Update frame
			this->scoutCurrentFrame++;
			if (this->scoutCurrentFrame >= 10)
				this->scoutCurrentFrame = 0;

			// Set texture rect
			this->scoutFireFrame.left = this->scoutCurrentFrame * 64; // Assuming each frame is 64x64
			this->scoutFire.setTextureRect(this->scoutFireFrame);
			this->scoutFire.setPosition(this->enemyOne.getPosition().x - (this->textures["STAGE2ENEMY2"]->getSize().x / 2) * 2.75 - 17.f, this->enemyOne.getPosition().y - (this->textures["STAGE2ENEMY2"]->getSize().y) * 2.75 + 18.f);
		}
	}
}

void Enemy::updateFrigateAnimation()
{
	if (this->type == 7) // Only update for frigate type
	{
		this->frigateAnimationTimer += 0.02f; // Assuming this function is called frequently (e.g., every frame)

		if (this->frigateAnimationTimer >= this->frigateAnimationSpeed)
		{
			// Reset timer
			this->frigateAnimationTimer = 0.f;

			// Update frame
			this->frigateCurrentFrame++;
			if (this->frigateCurrentFrame >= 12)
				this->frigateCurrentFrame = 0;

			// Set texture rect
			this->frigateFireFrame.left = this->frigateCurrentFrame * 64; // Assuming each frame is 64x64
			this->frigateFire.setTextureRect(this->frigateFireFrame);
			this->frigateFire.setPosition(this->enemyOne.getPosition().x - (this->textures["STAGE2ENEMY3"]->getSize().x / 2) * 2.75 + 16.f, this->enemyOne.getPosition().y - (this->textures["STAGE2ENEMY3"]->getSize().y) * 2.75 - 25.f);
		}
	}
}

void Enemy::updateFighterAnimation()
{
	if (this->type == 8) // Only update for fighter type
	{
		this->fighterAnimationTimer += 0.04f; // Assuming this function is called frequently (e.g., every frame)

		if (this->fighterAnimationTimer >= this->fighterAnimationSpeed)
		{
			// Reset timer
			this->fighterAnimationTimer = 0.f;

			// Update frame
			this->fighterCurrentFrame++;
			if (this->fighterCurrentFrame >= 10)
				this->fighterCurrentFrame = 0;

			// Set texture rect
			this->fighterFrame.left = this->fighterCurrentFrame * 64; // Assuming each frame is 64x64
			this->fighterFire.setTextureRect(this->fighterFrame);
			this->fighterFire.setPosition(this->enemyOne.getPosition().x - (this->textures["STAGE2ENEMY4"]->getSize().x / 2) * 2.75 - 28.f, this->enemyOne.getPosition().y - (this->textures["STAGE2ENEMY4"]->getSize().y) * 2.75 - 35.f);
		}
	}
}

void Enemy::render(sf::RenderTarget& target)
{

	if (this->type == 5) // Only render for bomber type
	{
		target.draw(this->bomberFire);
	}

	if (this->type == 6) // Only render for scout type
	{
		target.draw(this->scoutFire);
	}

	if (this->type == 7) // Only render for frigate type
	{
		target.draw(this->frigateFire);
	}

	if (this->type == 8) // Only render for fighter type
	{
		target.draw(this->fighterFire);
	}

	target.draw(this->enemyOne);
}

