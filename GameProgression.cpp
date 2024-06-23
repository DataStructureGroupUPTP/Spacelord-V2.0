#include "Game.h"

void Game::updateDifficulty()
{

	if (elapsedTime >= 30.f && elapsedTime <= 31.f)
	{
		this->meteorSpawnRate = 0.25f;
		this->doubleMeteorChance = 5.f;
		this->tripleMeteorChance = 0.f;
	}

	if (elapsedTime >= 105.f && elapsedTime <= 106.f)
	{
		this->meteorSpawnRate = 0.f;
		this->dpsItemSpawnRate = 0.f;
		this->enemySpawnRate = 0.f;
		this->backgroundScrollSpeed = 1.5f;
	}

	if(elapsedTime >= 109.f && elapsedTime <= 110.f)
	{
		if (!this->stageMusic.openFromFile("Music/BossMusic.ogg"))
		{
			std::cout << "ERROR::BOSSMUSIC::FAILED_TO_LOAD" << "\n";
		}
		this->stageMusic.play();

		bossIsActive = true;
		this->boss->spawn(sf::Vector2f(550.f,-200.f));
	}

}