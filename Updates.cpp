#include "Game.h"

void Game::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !leftKeyPressed)
	{
		leftKeyPressed = true;

		if (lane > 1) 
		{
			this->player->move(-26.65f, 0.f);
			lane--;
		}
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		leftKeyPressed = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !rightKeyPressed)
	{
		rightKeyPressed = true;

		if (lane < 4) 
		{
			this->player->move(26.65f, 0.f);
			lane++;
		}
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rightKeyPressed = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{

		this->player->move(0.f, -1.f);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{

		this->player->move(0.f, 1.f);

	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && this->player->canAttack())
	{
		this->laserSound.play();
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2 - 5.5f,
			this->player->getPos().y, 0.f, -1.5f, 5.f));
	}

	// FUTURE PAUSE
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		this->pauseSound.play();
		this->gameState = PAUSED;
		this->stageMusic.pause();
	}

	// COLOR TESTS

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{

		if (!this->textures["BULLET"]->loadFromFile("Textures/Redbulletrfix.png"))
		{
			std::cout << "TEXTURE::BULLET_RED::FAILED_TO_LOAD" << "\n";
		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{

		if (!this->textures["BULLET"]->loadFromFile("Textures/Bluebulletfix.png"))
		{
			std::cout << "TEXTURE::BULLET_BLUE::FAILED_TO_LOAD" << "\n";
		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		if (!this->textures["BULLET"]->loadFromFile("Textures/Greenbulletfix.png"))
		{
			std::cout << "TEXTURE::BULLET_GREEN::FAILED_TO_LOAD" << "\n";
		}
	}
}

void Game::updateBackground()
{

	// Move the backgrounds downwards
	this->stageBackground.move(0, this->backgroundScrollSpeed);
	this->stageBackground2.move(0, this->backgroundScrollSpeed);

	// Check if the first background has moved out of view
	if (this->stageBackground.getPosition().y > this->window->getSize().y)
	{
		this->stageBackground.setPosition(0, this->stageBackground2.getPosition().y - this->stageBackground2.getGlobalBounds().height);
	}

	// Check if the second background has moved out of view
	if (this->stageBackground2.getPosition().y > this->window->getSize().y)
	{
		this->stageBackground2.setPosition(0, this->stageBackground.getPosition().y - this->stageBackground.getGlobalBounds().height);
	}
}

void Game::updateGUI()
{
	// Update Score

	std::stringstream ss;

	ss << "Score: " << this->points;

	this->pointText.setString(ss.str());

	// Update Player GUI
	float hpPercent = static_cast<float>(this->player->getHp()) / static_cast<float>(this->player->getHpMax());
	this->playerHpBar.setSize(sf::Vector2f(150.f * hpPercent, this->playerHpBar.getSize().y));

	if (this->player->getHp() == 0)
	{
		this->stageMusic.stop();
		this->gameOverMusic.play();
		this->gameState = GAME_OVER;
	}
}

void Game::updateTimer()
{
	sf::Time dt = clock.restart();
	elapsedTime += dt.asSeconds();

	// Update timer text
	minutes = static_cast<int>(elapsedTime) / 60;
	seconds = static_cast<int>(elapsedTime) % 60;

	std::ostringstream oss;
	oss << std::setfill('0') << std::setw(2) << minutes << ":" << std::setw(2) << seconds;
	timerText.setString(oss.str());
}


void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();

		// Bullet culling (top)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			// Delete bullets
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;


		}

		++counter;
	}
}

void Game::updateCollision()
{
	// Collision with left side of the screen
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}

	// Collision with right side of the screen
	else if (this->player->getBounds().left + this->player->getBounds().width > this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}

	// Collision with top of the screen
	if (this->player->getBounds().top < 0.f)
	{
		this->player->setPosition(this->player->getBounds().left, 0.f);
	}

	// Collision with bottom of the screen
	else if (this->player->getBounds().top + this->player->getBounds().height > this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
	}
}


void Game::updateEnemies()
{
	// Spawning
	this->spawnTimer += 1.5f;
	this->horizontalSpawnTimer += 1.f;

	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->laneRandomizer = rand() % 4 + 1;

		switch (laneRandomizer)
		{
		case 1:
			this->lanePos = 200.f;
			break;
		case 2:
			this->lanePos = 400.f;
			break;
		case 3:
			this->lanePos = 600.f;
			break;
		case 4:
			this->lanePos = 800.f;
			break;
		}


		int enemyRandomizer = rand() % 3;

		switch (enemyRandomizer)
		{
		case 0:
			this->enemies.push_back(new Enemy(this->textures["GREENALIEN"], lanePos - 44.f, -200.f, 3));
			this->spawnTimer = 0;
			break;
		case 1:
			this->enemies.push_back(new Enemy(this->textures["BLUEALIEN"], lanePos - 44.f, -200.f, 2));
			this->spawnTimer = 0;
			break;
		case 2:
			this->enemies.push_back(new Enemy(this->textures["YELLOWALIEN"], lanePos - 44.f, -200.f, 1));
			this->spawnTimer = 0;
			break;
		default:
			this->enemies.push_back(new Enemy(this->textures["GREENALIEN"], lanePos - 44.f, -200.f, 3));
			this->spawnTimer = 0;
			break;

		}


		if (this->horizontalSpawnTimer >= horizontalSpawnTimerMax)
		{
			int enemyRandomizer = rand() % 3;
			int sideRandomizer = 0;

			if (sideRandomizer == 1)
			{
				this->horizontalPos = 200.f;
			}
			else
			{
				this->horizontalPos = -200.f;
			}

			switch (enemyRandomizer)
			{
			case 0:
				this->enemies.push_back(new Enemy(this->textures["GREENALIEN"], horizontalPos, rand() % 750, 4));
				this->horizontalSpawnTimer = 0;
				break;
			case 1:
				this->enemies.push_back(new Enemy(this->textures["BLUEALIEN"], horizontalPos, rand() % 750, 5));
				this->horizontalSpawnTimer = 0;
				break;
			case 2:
				this->enemies.push_back(new Enemy(this->textures["YELLOWALIEN"], horizontalPos, rand() % 750, 6));
				this->horizontalSpawnTimer = 0;
				break;

			}
		}

	}

	unsigned counter = 0;
	for (auto it = this->enemies.begin(); it != this->enemies.end();)
	{
		auto* enemy = *it;
		enemy->update();

		if (enemy->getBounds().top > this->window->getSize().y ||
			enemy->getBounds().left > this->window->getSize().x)
		{
			// Delete enemies at bottom or right screen
			delete enemy;
			it = this->enemies.erase(it);
		}
		else if (enemy->getBounds().intersects(this->player->getBounds()))
		{
			this->player->loseHp(enemy->getDamage());
			delete enemy;
			it = this->enemies.erase(it);
			this->playerHit.play();
		}
		else
		{
			++it;
		}
	}

}

void Game::updateCombat()
{

	for (size_t i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				enemies[i]->reduceHp(1);
				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + (int)k);
				this->alienHit.play();


				if (enemies[i]->getHp() == 0)
				{
					this->points = this->points + this->enemies[i]->getPoints();


					delete this->enemies[i];
					this->enemies.erase(this->enemies.begin() + (int)i);

					enemy_deleted = true;
				}

			}

		}
	}
}