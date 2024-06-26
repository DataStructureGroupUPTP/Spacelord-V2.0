#include "Game.h"

void Game::updateDifficulty()
{
	if (Stage == 1) {


		if (elapsedTime >= 30.f && elapsedTime <= 31.f)
		{
			this->meteorSpawnRate = 0.3f;
			this->doubleMeteorChance = 10.f;
			this->tripleMeteorChance = 0.f;
		}

		if (elapsedTime >= 60.f && elapsedTime <= 61.f)
		{
			this->meteorSpawnRate = 0.75f;
			this->doubleMeteorChance = 15.f;
		}

		if (elapsedTime >= 105.f && elapsedTime <= 106.f)
		{
			this->meteorSpawnRate = 0.f;
			this->dpsItemSpawnRate = 0.f;
			this->enemySpawnRate = 0.f;
			this->backgroundScrollSpeed = 3.0f;
			this->doubleMeteorChance = 5.f;
		}

		if (elapsedTime >= 110.f && elapsedTime <= 111.f)
		{
			if (!bossIsActive) {
				if (!this->stageMusic.openFromFile("Music/BossMusic.ogg"))
				{
					std::cout << "ERROR::BOSSMUSIC::FAILED_TO_LOAD" << "\n";
				}
				this->stageMusic.play();

				bossIsActive = true;
				this->boss->spawn(sf::Vector2f(560.f, -200.f));
			}
		}

		if (elapsedTime >= 113.f && elapsedTime <= 124.f)
		{
			this->player->setAttackCooldown(0);
		}

		if (elapsedTime >= 125.f && elapsedTime <= 126.f)
		{
			startShooting = true;
		}

		if (elapsedTime >= 185.f && elapsedTime <= 186.f && startShooting)
		{
			this->meteorSpawnRate = 0.25f;
		}

		if (elapsedTime >= 230.f && elapsedTime <= 231.f && startShooting)
		{
			this->meteorSpawnRate = 0.75f;
		}

		if (bossDefeated && checkerOne)
		{
			this->stageMusic.stop();
			this->explosionSound.play();
			this->startShooting = false;
			this->meteorSpawnRate = 0.f;
			this->timeStamp = elapsedTime;
			this->stageTransition = true;
			bossDefeated = false;
			this->points = points + 50000;
			this->currency = currency + 500;
			this->enemyKillCounter = enemyKillCounter + 40;
			checkerOne = false;
			this->backgroundScrollSpeed = 2.0f;

		}

		if (elapsedTime >= timeStamp + 5.f && stageTransition)
		{
			this->healthItemSpawnTimer = 0.f;
			this->dpsItemSpawnRate = 0.f;
			this->healthItemSpawnRate = 0.5f;
			this->dpsItemSpawnRate = 1.5f;
			bossIsActive = false;
			stageTransition = false;
			victoryTune.play();
			stage1End = true;
			this->backgroundScrollSpeed = 1.5f;
		}

		if (elapsedTime >= timeStamp + 10.f && stage1End)
		{
			this->healthItemSpawnRate = 0.f;
			this->dpsItemSpawnRate = 0.f;
			
		}

		if (elapsedTime >= timeStamp + 11.f && stage1End)
		{
			this->triggerFadeEffect();
		}

		if (elapsedTime >= timeStamp + 15.f && stage1End)
		{

			timeStamp2 = elapsedTime;
			stage1End = false;
			Stage = 2;
			this->stageBackground.setTexture(this->stage2BackgroundTexture);
			this->stageBackground2.setTexture(this->stage2BackgroundTexture);

			this->stageBackground2.setPosition(0, this->stageBackground.getGlobalBounds().height);

		}
	}

	if(Stage == 2)
	{
		this->meteorSpawnRate = 1.5f;
		this->backgroundScrollSpeed = 4.0f;
	}
}
