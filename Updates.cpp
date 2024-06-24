#include "Game.h"

void Game::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !leftKeyPressed)
	{
		leftKeyPressed = true;
		
		if (lane > 1) 
		{
			swooshSound.play();
			this->player->move(static_cast<float>(-26.65f * 7.5), 0.f);
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
			swooshSound.play();
			this->player->move(static_cast<float>(26.65f*7.5), 0.f);
			lane++;
		}
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rightKeyPressed = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{

		this->player->move(0.f, -this->player->getMoveSpeed());

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{

		this->player->move(0.f, this->player->getMoveSpeed());

	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && this->player->canAttack())
	{
		this->laserSound.play();
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2 - 5.5f,
			this->player->getPos().y, 0.f, -1.5f, this->bulletSpeed, false, 1));
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
		elapsedTime = elapsedTime + 5.f;
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

	// Update Currency

	std::stringstream ss2;

	ss2 << "Money: " << this->currency << "$";

	this->currencyText.setString(ss2.str());

	// Update Player GUI
	float hpPercent = static_cast<float>(this->player->getHp()) / static_cast<float>(this->player->getHpMax());
	this->playerHpBar.setSize(sf::Vector2f(150.f * hpPercent, this->playerHpBar.getSize().y));

	if (this->player->getHp() == 0)
	{
		this->stageMusic.stop();
		this->gameOverMusic.play();
		this->gameState = GAME_OVER;
	}
	
	// Update Kill Counter
	std::stringstream ss3;

	if (enemyKillCounter < 50) 
	{
		ss3 << "Kills: " << this->enemyKillCounter << "/50";

		this->killCounterText.setString(ss3.str());
	}

	if(enemyKillCounter >= 50 && enemyKillCounter <= 149)
	{
		ss3 << "Kills: " << this->enemyKillCounter << "/150";

		this->killCounterText.setString(ss3.str());
	}

	if (enemyKillCounter == 150)
	{
		ss3 << "Kills: " << this->enemyKillCounter << "/MAXED";

		this->killCounterText.setString(ss3.str());
	}
}

void Game::updateTimer()
{
	sf::Time dt = clock.restart();
	elapsedTime += dt.asSeconds();

	if(gameState == PAUSED)
	{
		elapsedTime -= dt.asSeconds();
	}

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

		// Bullet culling (top and bottom)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f ||
			bullet->getBounds().top > this->window->getSize().y)
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
	this->spawnTimer += enemySpawnRate;
	this->meteorSpawnTimer += meteorSpawnRate;
	this->horizontalSpawnTimer += horizontalEnemySpawnRate;

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
			this->enemies.push_back(new Enemy(static_cast<float> (lanePos - (this->textures["SMALLENEMY"]->getSize().x / 2) * 2.75), -200.f, 1));
			this->spawnTimer = 0;
			break;
		case 1:
			this->enemies.push_back(new Enemy(static_cast<float> (lanePos - (this->textures["MEDIUMENEMY"]->getSize().x / 2) * 2.75) , -200.f, 2));
			this->spawnTimer = 0;
			break;
		case 2:
			this->enemies.push_back(new Enemy(static_cast<float> (lanePos - (this->textures["BIGENEMY"]->getSize().x / 2) * 2.75) , -200.f, 3));
			this->spawnTimer = 0;
			break;
		default:
			this->enemies.push_back(new Enemy(static_cast<float> (lanePos) , -200.f, 3));
			this->spawnTimer = 0;
			break;

		}
	}

	if (this->horizontalSpawnTimer >= horizontalSpawnTimerMax)
	{
		int enemyRandomizer = rand() % 2;
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
			this->enemies.push_back(new Enemy(horizontalPos, static_cast<float> (rand() % 400 + 300), NULL));
			this->horizontalSpawnTimer = 0;
			break;
		case 1:
			this->enemies.push_back(new Enemy(horizontalPos, static_cast <float> (rand() % 400 + 300), NULL));
			this->horizontalSpawnTimer = 0;
			break;


		}

	}

	if (this->meteorSpawnTimer >= meteorSpawnTimerMax)
	{
		// Reset the meteor spawn timer
		this->meteorSpawnTimer = 0;

		// Randomize the lane

		int meteorChance = rand() % 100 + 1;

		if (meteorChance <= tripleMeteorChance)
		{
			// Triple meteor spawn (on three separate lanes)
			std::vector<int> lanes = { 1, 2, 3, 4 };
			std::random_shuffle(lanes.begin(), lanes.end());

			for (int i = 0; i < 3; ++i)
			{
				switch (lanes[i])
				{
				case 1:
					lanePos = static_cast<float> (line1Pos);
					break;
				case 2:
					lanePos = static_cast<float> (line2Pos);
					break;
				case 3:
					lanePos = static_cast<float> (line3Pos);
					break;
				case 4:
					lanePos = static_cast<float> (line4Pos);
					break;
				}
				this->enemies.push_back(new Enemy(lanePos - (this->textures["METEOR"]->getSize().x * 1.125f), -200.f, 4));
			}
		}
		else if (meteorChance > tripleMeteorChance && meteorChance <= doubleMeteorChance)
		{
			// Double Meteor Spawn (on two separate lanes)
			std::vector<int> lanes = { 1, 2, 3, 4 };
			std::random_shuffle(lanes.begin(), lanes.end());

			for (int i = 0; i < 2; ++i)
			{

				switch (lanes[i])
				{
				case 1:
					lanePos = static_cast<float> (line1Pos);
					break;
				case 2:
					lanePos = static_cast<float> (line2Pos);
					break;
				case 3:
					lanePos = static_cast<float> (line3Pos);
					break;
				case 4:
					lanePos = static_cast<float> (line4Pos);
					break;
				}
				this->enemies.push_back(new Enemy(lanePos - (this->textures["METEOR"]->getSize().x * 1.125f), -200.f, 4));
			}
		}
		else // Singular meteor
		{
			this->laneRandomizer = rand() % 4 + 1;

			switch (laneRandomizer)
			{
			case 1:
				lanePos = static_cast<float> (line1Pos);
				break;
			case 2:
				lanePos = static_cast<float> (line2Pos);
				break;
			case 3:
				lanePos = static_cast<float> (line3Pos);
				break;
			case 4:
				lanePos = static_cast<float> (line4Pos);
				break;
			}

			this->enemies.push_back(new Enemy(lanePos - (this->textures["METEOR"]->getSize().x * 1.125f), -200.f, 4));
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

void Game::updateItems()
{
	this->healthItemSpawnTimer += healthItemSpawnRate;
	this->dpsItemSpawnTimer +=dpsItemSpawnRate;

	if (this->healthItemSpawnTimer >= this->healthItemSpawnTimerMax)
	{
		healthItemSpawnTimer = 0.f;
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

		this->items.push_back(new Item(this->textures["REDBALL"], static_cast<float> (lanePos - (this->textures["REDBALL"]->getSize().x / 2) * 1.5), -200.f, 1));
	}

	if (this->dpsItemSpawnTimer >= this->dpsItemSpawnTimerMax)
	{
		dpsItemSpawnTimer = 0.f;
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

		int randomizer = rand() % 3;

		switch (randomizer)
		{
		case 0:
			this->items.push_back(new Item(this->textures["PURPLEBALL"], static_cast<float> (lanePos - (this->textures["PURPLEBALL"]->getSize().x / 2) * 1.5), -200.f, 2));
			break;
		case 1:
			this->items.push_back(new Item(this->textures["BLUEBALL"], static_cast<float> (lanePos - (this->textures["BLUEBALL"]->getSize().x / 2) * 1.5), -200.f, 3));
			break;
		case 2:
			this->items.push_back(new Item(this->textures["YELLOWBALL"], static_cast<float> (lanePos - (this->textures["YELLOWBALL"]->getSize().x / 2) * 1.5), -200.f, 4));
			dpsItemSpawnTimer = dpsItemSpawnTimer + 30.f;
			break;
		}
	}

	unsigned counter = 0;
	for (auto it = this->items.begin(); it != this->items.end();)
	{
		auto* item = *it;
		item->update();

		if (item->getBounds().top > this->window->getSize().y ||
			item->getBounds().left > this->window->getSize().x)
		{
			// Delete enemies at bottom or right screen
			delete item;
			it = this->items.erase(it);
		}
		else if (item->getBounds().intersects(this->player->getBounds()))
		{
			if (item->getType() == 1)
			{
				this->points = this->points + item->getPoints();
				this->player->setHp(this->player->getHp() + 1);
				this->healSound.play();
			}
			else if (item->getType() == 2)
			{
				this->points = this->points + item->getPoints();
				this->player->upgradeDamage();
				this->powerUpSound.play();
			}
			else if (item->getType() == 3)
			{
				this->points = this->points + item->getPoints();
				this->player->upgradeAttackSpeed();
				this->powerUpSound.play();
			}
			else if (item->getType() == 4)
			{
				this->points = this->points + item->getPoints();
				this->currency = this->currency + 50;
				this->bulletSpeed = this->bulletSpeed + 0.2f;
				this->powerUpSound.play();
			}
			delete item;
			it = this->items.erase(it);
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
				enemies[i]->reduceHp(this->player->getDamage());
				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + (int)k);
				this->alienHit.play();


				if (enemies[i]->getHp() <= 0)
				{
					this->points = this->points + this->enemies[i]->getPoints();
					this->currency = this->currency + 5;

					delete this->enemies[i];
					this->enemies.erase(this->enemies.begin() + (int)i);

					enemy_deleted = true;
					this->enemyKillCounter++;
				}

			}

		}
	}

	if (this->bossIsActive)
	{
		for (size_t j = 0; j < this->bullets.size() && bossDefeated == false; j++)
		{
			if (this->boss->getBounds().intersects(this->bullets[j]->getBounds()) && !this->bullets[j]->bulletChecker())
			{
				// Player's bullet hits the boss
				boss->takeDamage(this->player->getDamage());
				delete this->bullets[j];
				this->bullets.erase(this->bullets.begin() + j);
				this->clangHit.play();

				if (!boss->isAlive())
				{
					std::cout << "DEAD";
					bossDefeated = true;
				}

				--j; // Adjust index after erasing
			}
			else if (this->bullets[j]->bulletChecker() && this->bullets[j]->getBounds().intersects(this->player->getBounds()))
			{
				// Enemy's bullet hits the player
				if (!this->player->isInvincible()) {
					this->player->loseHp(2);
					this->criticalHit.play();
				}
				delete this->bullets[j];
				this->bullets.erase(this->bullets.begin() + j);
				--j; // Adjust index after erasing
			}
		}

		if (this->boss->getBounds().intersects(this->player->getBounds()))
		{
			// Boss hits the player
			if (!this->player->isInvincible()) {
				this->player->loseHp(2);
				this->criticalHit.play();
			}
		}
	}
}


void Game::updateBoss()
{
	this->boss->update(0.05f);

	if (startShooting) {
		bossAttackCooldown += 1.2f;
		if (this->bossAttackCooldown >= this->bossAttackCooldownMax && !bossDefeated)
		{
			this->bossAttackCooldown = 0.f;
			this->laserSound.play();
			this->bullets.push_back(new Bullet(this->textures["BOSSBULLET"], (this->boss->getPos().x - (this->boss->getBounds().width / 2))-15.f,
				this->boss->getPos().y - 17.5f, 0.f, 1.5f, 4.5f, true, 2));
		}
	}


}

void Game::updateSoundFXVolume() 
{
	this->laserSound.setVolume(this->soundfxVolume * 2.5f);
	this->menuSound.setVolume(this->soundfxVolume * 10);
	this->playerHit.setVolume(this->soundfxVolume * 7);
	this->alienHit.setVolume(this->soundfxVolume * 6); 
	this->pauseSound.setVolume(this->soundfxVolume * 10);
	float soundfxvolumePercent = static_cast<float>(this->soundfxVolume / static_cast<float>(10));
	this->soundfxvolumeIndicator.setSize(sf::Vector2f(300.f * soundfxvolumePercent, this->soundfxvolumeIndicator.getSize().y));
}

void Game::updateMusicVolume()
{
	this->stageMusic.setVolume(this->musicVolume * 6);
	this->gameOverMusic.setVolume(this->musicVolume * 6);
	this->menuMusic.setVolume(this->musicVolume * 6);
	float musicvolumePercent = static_cast<float>(this->musicVolume / static_cast<float>(10));
	this->musicvolumeIndicator.setSize(sf::Vector2f(300.f * musicvolumePercent, this->musicvolumeIndicator.getSize().y));
}