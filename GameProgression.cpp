#include "Game.h"

void Game::updateDifficulty()
{

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

	if(elapsedTime >= 108.f && elapsedTime <= 109.f)
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

	if(elapsedTime >= 111.f && elapsedTime <= 112.f)
	{
		this->player->setAttackCooldownMax(10000);
	}

	if(elapsedTime >= 125.f && elapsedTime <= 126.f)
	{
		startShooting = true;
		this->player->setAttackCooldownMax(25);
	}

	if(elapsedTime >= 185.f && elapsedTime <= 186.f)
	{
		this->meteorSpawnRate = 0.25f;
	}

	if(elapsedTime >= 230.f && elapsedTime <= 231.f)
	{
		this->meteorSpawnRate = 0.75f;
	}

	if(bossDefeated)
	{
		this->stageMusic.stop();
		this->explosionSound.play();
		this->startShooting = false;
		bossDefeated = false;
		this->meteorSpawnRate = 0.f;
	}
}