#include "Game.h"

void Game::handleMainMenuInput(const sf::Event& ev)
{
	if (ev.key.code == sf::Keyboard::Up)
	{
		if (this->selectedMenuItem > 0)
		{
			this->menuSound.play();
			this->selectedMenuItem--;
		}
	}
	if (ev.key.code == sf::Keyboard::Down)
	{
		if (this->selectedMenuItem < 5)
		{
			this->menuSound.play();
			this->selectedMenuItem++;
		}
	}
	if (ev.key.code == sf::Keyboard::Return)
	{
		switch (this->selectedMenuItem)
		{
		case 0:
			this->initializeMusic();
			this->gameState = GAMEPLAY;
			this->menuMusic.stop();
			this->clock.restart();
			this->elapsedTime = 0;
			this->minutes = 0;
			this->seconds = 0;
			break;
		case 1:
			this->gameState = SHOP;
			this->selectedMenuItem = 0;
			break;
		case 2:
			this->prevgameState = this->gameState;
			this->gameState = SETTINGS;
			this->selectedMenuItem = 0;
			break;
		case 3:
			// Handle credits selection
			this->selectedMenuItem = 0;
			break;
		case 4:
			resetGameData();
			initializeGameData();
			this->selectedMenuItem = 0;
			break;
		case 5:
			this->window->close();
			break;
		default:
			break;
		}
	}
}

void Game::handleShopMenuInput(const sf::Event& ev)
{
	if (ev.key.code == sf::Keyboard::Up)
	{
		if (this->selectedMenuItem > 0)
		{
			this->menuSound.play();
			this->selectedMenuItem--;
		}
	}
	if (ev.key.code == sf::Keyboard::Down)
	{
		if (this->selectedMenuItem < 3)
		{
			this->menuSound.play();
			this->selectedMenuItem++;
		}
	}
	if (this->selectedMenuItem != 3)
	{
		if (ev.key.code == sf::Keyboard::Left)
		{
			if (this->shopselectedMenuItem > 0)
			{
				this->menuSound.play();
				this->shopselectedMenuItem--;
			}
		}
		if (ev.key.code == sf::Keyboard::Right)
		{
			if (this->shopselectedMenuItem < 5)
			{
				this->menuSound.play();
				this->shopselectedMenuItem++;
			}
		}
	}
	if (ev.key.code == sf::Keyboard::Return)
	{
		switch (this->selectedMenuItem)
		{
		case 0:
			switch (this->shopselectedMenuItem)
			{
			case 0:
				gameData.equipedbullet = "red";
				updateGameData(gameData);
				if (!this->textures["BULLET"]->loadFromFile("Textures/Redbulletrfix.png"))
				{
					std::cout << "TEXTURE::BULLET_RED::FAILED_TO_LOAD" << "\n";
				}
				break;
			case 1:
				gameData.equipedbullet = "blue";
				updateGameData(gameData);
				if (!this->textures["BULLET"]->loadFromFile("Textures/Bluebulletfix.png"))
				{
					std::cout << "TEXTURE::BULLET_BLUE::FAILED_TO_LOAD" << "\n";
				}
				break;
			case 2:
				gameData.equipedbullet = "green";
				updateGameData(gameData);
				if (!this->textures["BULLET"]->loadFromFile("Textures/Greenbulletfix.png"))
				{
					std::cout << "TEXTURE::BULLET_GREEN::FAILED_TO_LOAD" << "\n";
				}
				break;
			case 3:
				gameData.equipedbullet = "yellow";
				if (!this->textures["BULLET"]->loadFromFile("Textures/Yellowbullet.png"))
				{
					std::cout << "TEXTURE::BULLET_GREEN::FAILED_TO_LOAD" << "\n";
				}
				break;
			case 4:
				gameData.equipedbullet = "purple";
				if (!this->textures["BULLET"]->loadFromFile("Textures/Purplebullet.png"))
				{
					std::cout << "TEXTURE::BULLET_GREEN::FAILED_TO_LOAD" << "\n";
				}
				break;
			case 5:
				gameData.equipedbullet = "white";
				if (!this->textures["BULLET"]->loadFromFile("Textures/Whitebullet.png"))
				{
					std::cout << "TEXTURE::BULLET_GREEN::FAILED_TO_LOAD" << "\n";
				}
				break;
			}
			break;
		case 1:
			switch (this->shopselectedMenuItem)
			{
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			}
			break;
		case 2:
			switch (this->shopselectedMenuItem)
			{
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			}
			break;
		case 3:
			this->gameState = MAIN_MENU;
			this->selectedMenuItem = 0;
			break;
		default:
			break;
		}
	}
}

void Game::handlePauseMenuInput(const sf::Event& ev)
{
	if (ev.key.code == sf::Keyboard::Up)
	{
		if (this->selectedMenuItem > 0)
		{
			this->menuSound.play();
			this->selectedMenuItem--;
		}
	}
	if (ev.key.code == sf::Keyboard::Down)
	{
		if (this->selectedMenuItem < 2)
		{
			this->menuSound.play();
			this->selectedMenuItem++;
		}
	}
	if (ev.key.code == sf::Keyboard::Return)
	{
		switch (this->selectedMenuItem)
		{
		case 0:
			this->gameState = GAMEPLAY;
			this->menuMusic.stop();
			this->stageMusic.play();
			this->selectedMenuItem = 0;
			break;
		case 1:
			this->prevgameState = this->gameState;
			this->gameState = SETTINGS;
			this->selectedMenuItem = 0;
			break;
		case 2:
			this->updateGameData();
			this->reset();
			this->gameState = MAIN_MENU;
			this->stageMusic.stop();
			this->menuMusic.play();
			this->selectedMenuItem = 0;
			break;
		default:
			break;
		}
	}
}

void Game::handleGameOverMenuInput(const sf::Event& ev)
{
	if (ev.key.code == sf::Keyboard::Return)
	{
		updateGameData(gameData);
		this->reset();
		this->gameState = MAIN_MENU;
		this->menuMusic.play();
		this->gameOverMusic.stop();
	}
}

void Game::handleSettingsMenuInput(const sf::Event& ev)
{
	if (ev.key.code == sf::Keyboard::Up)
	{
		if (this->selectedMenuItem > 0)
		{
			this->menuSound.play();
			this->selectedMenuItem--;
		}
	}
	if (ev.key.code == sf::Keyboard::Down)
	{
		if (this->selectedMenuItem < 2)
		{
			this->menuSound.play();
			this->selectedMenuItem++;
		}
	}
	switch (this->selectedMenuItem)
	{
	case 0:
		if (ev.key.code == sf::Keyboard::Left)
		{
			musicVolume = std::max(musicVolume - 0.5f, 0.0f);
			updateMusicVolume();
		}
		if (ev.key.code == sf::Keyboard::Right)
		{
			musicVolume = std::min(musicVolume + 0.5f, 10.0f);
			updateMusicVolume();
		}
		break;
	case 1:
		if (ev.key.code == sf::Keyboard::Left)
		{
			soundfxVolume = std::max(soundfxVolume - 0.5f, 0.0f);
			updateSoundFXVolume();
		}
		if (ev.key.code == sf::Keyboard::Right)
		{
			soundfxVolume = std::min(soundfxVolume + 0.5f, 10.0f);
			updateSoundFXVolume();
		}
		break;
	case 2:
		if (ev.key.code == sf::Keyboard::Return)
		{
			this->gameState = this->prevgameState;
			if (this->prevgameState == GAMEPLAY)
			{
				this->stageMusic.play();
			}
			this->selectedMenuItem = 0;
		}
		break;
	default:
		break;
	}
}