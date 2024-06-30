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
		if (enemyKillCounter < 500)
		{
			this->laserSound.play();
			this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2 - 5.5f,
				this->player->getPos().y, 0.f, -1.5f, this->bulletSpeed, false, 1));


		}

		else
		{
			this->laserSound.play();
			this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2 - 8.0f,
				this->player->getPos().y, 0.f, -1.5f, this->bulletSpeed, false, 3));
		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && this->bombs > 0 && !this->player->isInvincible())
	{
		this->shield.play();
		this->player->activateShield();
		bombs--;
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
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		this->player->setHp(5);
		this->player->upgradeDamage();
		this->player->upgradeAttackSpeed();


	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{

		elapsedTime = elapsedTime + 1.f;
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

	// Update Coins
	std::stringstream ss2;
	ss2 << "Money: " << this->gameData.coins << "$";
	this->coinText.setString(ss2.str());

	// Update Player GUI
	float hpPercent = static_cast<float>(this->player->getHp()) / static_cast<float>(this->player->getHpMax());
	this->playerHpBar.setSize(sf::Vector2f(150.f * hpPercent, this->playerHpBar.getSize().y));

	if (this->player->getHp() <= 0)
	{
		this->stageMusic.stop();
		this->gameOverMusic.play();
		this->gameState = GAME_OVER;
		if (gameData.highScore < points)
		{
			gameData.highScore = points;
			updateGameData(gameData);
		}
	}

	// Update bombs
	std::stringstream ssBombs;
	ssBombs << "Bombs: " << this->bombs;
	this->bombsText.setString(ssBombs.str());

	// Update Kill Counter
	std::stringstream ss3;
	if (enemyKillCounter < 50)
	{
		ss3 << "Kills: " << this->enemyKillCounter << "/50";
		this->killCounterText.setString(ss3.str());

	}
	else if (enemyKillCounter < 150)
	{
		ss3 << "Kills: " << this->enemyKillCounter << "/150";
		this->killCounterText.setString(ss3.str());
		if (lastKillThreshold < 50 && enemyKillCounter >= 50)
		{
			levelup.play();
			this->bombs++;
			lastKillThreshold = 50;
		}
	}
	else if (enemyKillCounter < 300)
	{
		ss3 << "Kills: " << this->enemyKillCounter << "/300";
		this->killCounterText.setString(ss3.str());
		if (lastKillThreshold < 150 && enemyKillCounter >= 150)
		{
			levelup.play();
			this->bombs++;
			lastKillThreshold = 150;
		}
	}
	else if (enemyKillCounter < 500)
	{
		ss3 << "Kills: " << this->enemyKillCounter << "/500";
		this->killCounterText.setString(ss3.str());
		if (lastKillThreshold < 300 && enemyKillCounter >= 300)
		{
			levelup.play();
			this->bombs++;
			lastKillThreshold = 300;
		}
	}
	else
	{
		ss3 << "Kills: " << this->enemyKillCounter << "/MAX";
		this->killCounterText.setString(ss3.str());
		if (lastKillThreshold < 500 && enemyKillCounter >= 500)
		{
			levelup.play();
			this->bombs++;
			lastKillThreshold = 500;
		}
	}
}



void Game::updateTimer()
{
	sf::Time dt = clock.restart();
	elapsedTime += dt.asSeconds();

	if(gameState == PAUSED or gameState == SETTINGS)
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
		int enemyRandomizerStage2 = rand() % 4;

		if (Stage == 1) {
			switch (enemyRandomizer)
			{
			case 0:
				this->enemies.push_back(new Enemy(static_cast<float> (lanePos - (this->textures["SMALLENEMY"]->getSize().x / 2) * 2.75), -200.f, 1));
				this->spawnTimer = 0;
				break;
			case 1:
				this->enemies.push_back(new Enemy(static_cast<float> (lanePos - (this->textures["MEDIUMENEMY"]->getSize().x / 2) * 2.75), -200.f, 2));
				this->spawnTimer = 0;
				break;
			case 2:
				this->enemies.push_back(new Enemy(static_cast<float> (lanePos - (this->textures["BIGENEMY"]->getSize().x / 2) * 2.75), -200.f, 3));
				this->spawnTimer = 0;
				break;
			default:
				this->enemies.push_back(new Enemy(static_cast<float> (lanePos), -200.f, 3));
				this->spawnTimer = 0;
				break;

			}
		}
		if (Stage == 2)
		{
			switch(enemyRandomizerStage2)
			{
			case 0:
				this->enemies.push_back(new Enemy(static_cast<float> (lanePos - (this->textures["STAGE2ENEMY1"]->getSize().x / 2) * 2.75), -200.f, 5));
				this->spawnTimer = 0;
				break;
			case 1:
				this->enemies.push_back(new Enemy(static_cast<float> (lanePos - (this->textures["STAGE2ENEMY2"]->getSize().x / 2) * 2.75), -200.f, 6));
				this->spawnTimer = 0;
				break;
			case 2:
				this->enemies.push_back(new Enemy(static_cast<float> (lanePos - (this->textures["STAGE2ENEMY3"]->getSize().x / 2) * 2.75), -200.f, 7));
				this->spawnTimer = 0;
				break;
			case 3:
				this->enemies.push_back(new Enemy(static_cast<float> (lanePos - (this->textures["STAGE2ENEMY4"]->getSize().x / 2) * 2.75), -200.f, 8));
				this->spawnTimer = 0;
				break;
			case 4:
				this->enemies.push_back(new Enemy(static_cast<float> (lanePos - (this->textures["STAGE2ENEMY5"]->getSize().x / 2) * 2.75), -200.f, 9));
				this->spawnTimer = 0;
				break;
			case 5:
				this->enemies.push_back(new Enemy(static_cast<float> (lanePos - (this->textures["STAGE2ENEMY6"]->getSize().x / 2) * 2.75), -200.f, 10));
				this->spawnTimer = 0;
				break;
			}


		}
	}


	if (this->horizontalSpawnTimer >= horizontalSpawnTimerMax)
	{
		int enemyRandomizer = rand() % 2;

		switch (enemyRandomizer)
		{
		case 0:
			this->enemies.push_back(new Enemy(-200.f, static_cast<float> (rand() % 400 + 300), 9));
			this->horizontalSpawnTimer = 0;
			break;
		case 1:
			this->enemies.push_back(new Enemy(1200.f, static_cast <float> (rand() % 400 + 300), 10));
			this->horizontalSpawnTimer = 0;
			break;


		}

	}

	if (this->meteorSpawnTimer >= meteorSpawnTimerMax)
	{
		std::random_device rd; // Obtain a random number from hardware
		std::default_random_engine rng(rd()); // Seed the generator

		std::cout << meteorSpawnRate << "\n";
		// Reset the meteor spawn timer
		this->meteorSpawnTimer = 0;

		// Randomize the lane

		int meteorChance = rand() % 100 + 1;

		if (meteorChance <= tripleMeteorChance)
		{
			// Triple meteor spawn (on three separate lanes)
			std::vector<int> lanes = { 1, 2, 3, 4 };
			std::shuffle(lanes.begin(), lanes.end(), rng);

			for (unsigned int i = 0; i < 3; ++i)
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
			std::shuffle(lanes.begin(), lanes.end(), rng);

			for (unsigned int i = 0; i < 2; ++i)
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


	for (auto it = this->enemies.begin(); it != this->enemies.end();)
	{
		auto* enemy = *it;
		enemy->update();

		if (enemy->getBounds().top > this->window->getSize().y ||
			enemy->getBounds().left > this->window->getSize().x + 350.f || enemy->getBounds().left < -350.f)
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
				this->gameData.coins = this->gameData.coins + 50;
				this->bulletSpeed = this->bulletSpeed + 0.15f;
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
				this->bullets.erase(this->bullets.begin() + unsigned(k));
				this->alienHit.play();

				if (enemies[i]->getHp() <= 0) 
				{
					this->points += this->enemies[i]->getPoints();
					this->gameData.coins += 5;

					// Create explosion at the enemy's position
					this->explosions.push_back(new Explosion(this->enemies[i]->getPos().x, this->enemies[i]->getPos().y, this->enemies[i]->getBounds().getSize()));

					delete this->enemies[i];
					this->enemies.erase(this->enemies.begin() + unsigned(i));

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
				this->bullets.erase(this->bullets.begin() + unsigned(j));
				this->clangHit.play();

				if (!boss->isAlive())
				{
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
				this->bullets.erase(this->bullets.begin() + unsigned(j));
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
			this->bossLaser.play();
			this->bullets.push_back(new Bullet(this->textures["BOSSBULLET"], (this->boss->getPos().x - (this->boss->getBounds().width / 2))-15.f,
				this->boss->getPos().y - 17.5f, 0.f, 1.5f, 4.5f, true, 2));
		}
	}


}

void Game::updateSoundFXVolume() 
{
	this->laserSound.setVolume(this->soundfxVolume * 3.0f); // 12.5
	this->levelup.setVolume(this->soundfxVolume * 25);
	this->shield.setVolume(this->soundfxVolume * 50);
	this->bossLaser.setVolume(this->soundfxVolume * 3);
	this->explosionSound.setVolume(this->soundfxVolume * 15);
	this->criticalHit.setVolume(this->soundfxVolume * 15);
	this->clangHit.setVolume(this->soundfxVolume * 15);
	this->healSound.setVolume(this->soundfxVolume * 5);
	this->powerUpSound.setVolume(this->soundfxVolume * 5);
	this->swooshSound.setVolume(this->soundfxVolume * 50);
	this->pauseSound.setVolume(this->soundfxVolume * 10); // 50
	this->alienHit.setVolume(this->soundfxVolume * 6); // 30
	this->playerHit.setVolume(this->soundfxVolume * 7); // 35
	this->menuSound.setVolume(this->soundfxVolume * 10); // 50
	float soundfxvolumePercent = static_cast<float>(this->soundfxVolume / static_cast<float>(10));
	this->soundfxvolumeIndicator.setSize(sf::Vector2f(300.f * soundfxvolumePercent, this->soundfxvolumeIndicator.getSize().y));
}

void Game::updateMusicVolume()
{
	this->stageMusic.setVolume(this->musicVolume * 6); // 30
	this->gameOverMusic.setVolume(this->musicVolume * 6); // 30
	this->victoryTune.setVolume(this->musicVolume * 6); // 30
	this->menuMusic.setVolume(this->musicVolume * 6); // 30
	float musicvolumePercent = static_cast<float>(this->musicVolume / static_cast<float>(10));
	this->musicvolumeIndicator.setSize(sf::Vector2f(300.f * musicvolumePercent, this->musicvolumeIndicator.getSize().y));
}

void Game::updateFadeEffect()
{
	const float fadeSpeed = 100.f; // Alpha units per second

	switch (fadeState) {
	case FADING_OUT:
		fadeAlpha += fadeSpeed * fadeClock.restart().asSeconds();
		if (fadeAlpha >= 255.f) {
			fadeAlpha = 255.f;
			fadeState = BLACK_SCREEN;
			fadeClock.restart();
		}
		break;
	case BLACK_SCREEN:
		if (fadeClock.getElapsedTime().asSeconds() >= 1.f) {
			fadeState = FADING_IN;
		}
		break;
	case FADING_IN:
		fadeAlpha -= fadeSpeed * fadeClock.restart().asSeconds();
		if (fadeAlpha <= 0.f) {
			fadeAlpha = 0.f;
			fadeState = NONE;
		}
		break;
	default:
		break;
	}

	fadeOverlay.setFillColor(sf::Color(0, 0, 0, static_cast<sf::Uint8>(fadeAlpha)));
}

void Game::updateExplosionEffect()
{
	for (size_t i = 0; i < this->explosions.size(); ++i) {
		this->explosions[i]->update();
		if (this->explosions[i]->isFinished()) {
			delete this->explosions[i];
			this->explosions.erase(this->explosions.begin() + unsigned(i));
			--i;
		}
	}
}
