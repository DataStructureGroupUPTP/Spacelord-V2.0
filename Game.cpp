#include "Game.h"

// Private

void Game::initialize()
{
	this->initializeWindow();
	this->initializeLines();
	this->initializeTextures();
	this->initializeSounds();
	this->initializePlayer();
	this->initializeEnemy();
	this->initializeGUI();
	this->initializeStartMenu(); // Initialize start menu
	this->initializeBackground();
	this->initializeSystems();
	this->initializePauseMenu();
	this->initializeGameOverMenu();
	this->initializeMenuBackgrounds();
	this->initializeSettingsMenu();

	this->gameState = MAIN_MENU; // Set initial game state to MAIN_MENU
	this->prevgameState = MAIN_MENU;
	this->selectedMenuItem = 0;  // Initialize the selected menu item to the first item
}

// Constructor

Game::Game()
{
	this->initialize();

}

// Destructor
Game::~Game()
{
	delete this->window;
	delete this->player;

	// Delete textures
	for(auto &i : this->textures)
	{
		delete i.second; // Deletes second part of textures array, which is the actual texture (not the string portion)
	}

	// Delete bullets
	for(auto *i : this->bullets)
	{
		delete i;
	}

	for (auto *i : this->enemies)
	{
		delete i;
	}
}

// Public

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::reset()
{  
	// Reset player stats
	delete player;
	this->initializePlayer();
	points = 0;
	lane = 4;

	// Clear bullets
	for (auto* bullet : this->bullets)
	{
		delete bullet;
	}
	this->bullets.clear();

	// Clear enemies
	for (auto* enemy : this->enemies)
	{
		delete enemy;
	}
	this->enemies.clear();

	// Reset other game stats if necessary
	// Example: this->currentLevel = 1;
}

void Game::updatePollEvents()
{
	sf::Event ev;
	while (this->window->pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
		{
			this->window->close();
		}
		if (ev.type == sf::Event::KeyPressed)
		{
			if (ev.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
			}
			switch (this->gameState)
			{
			case MAIN_MENU:
				handleMainMenuInput(ev);
				break;
			case PAUSED:
				handlePauseMenuInput(ev);
				break;
			case GAME_OVER:
				handleGameOverMenuInput(ev);
				break;
			case SETTINGS:
				handleSettingsMenuInput(ev);
				break;
			default:
				break;
			}
		}
	}
}

void Game::handleMainMenuInput(const sf::Event & ev)
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
		if (this->selectedMenuItem < 4)
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
			break;
		case 1:
			// Handle shop selection
			break;
		case 2:
			this->prevgameState = this->gameState;
			this->gameState = SETTINGS;
			break;
		case 3:
			// Handle credits selection
			break;
		case 4:
			this->window->close();
			break;
		default:
			break;
		}
	}
}

void Game::handlePauseMenuInput(const sf::Event & ev)
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
			break;
		case 1:
			this->prevgameState = this->gameState;
			this->gameState = SETTINGS;
			break;
		case 2:
			this->reset();
			this->gameState = MAIN_MENU;
			this->stageMusic.stop();
			this->menuMusic.play();
			break;
		default:
			break;
		}
	}
}

void Game::handleGameOverMenuInput(const sf::Event & ev)
{
	if (ev.key.code == sf::Keyboard::Return)
	{
		this->reset();
		this->gameState = MAIN_MENU;
		this->menuMusic.play();
		this->gameOverMusic.stop();
	}
}

void Game::handleSettingsMenuInput(const sf::Event & ev)
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
			// Implement changing music volume
			break;

		case 1:
			// Implement changing sound fx volume
			break;
		case 2:
			this->gameState = this->prevgameState;
			if (this->prevgameState == GAMEPLAY)
			{
				this->stageMusic.play();
			}
			break;
		default:
			break;
		}
	}
}



void Game::update()
{
	this->updatePollEvents();

	if (this->gameState == GAMEPLAY)
	{
		this->updateInput();
		this->player->update();
		this->updateCollision();
		this->updateBackground();
		this->updateBullets();
		this->updateEnemies();
		this->updateCombat();
		this->updateGUI();
		this->updateTimer();
	}
}

void Game::render()
{
	this->window->clear();

	if (this->gameState == MAIN_MENU)
	{
		this->renderStartMenu(); // Render start menu if in MAIN_MENU state
	}

	if (this->gameState == GAMEPLAY)
	{
		// Draw world
		this->renderWorld();


		// Draw game elements
		this->window->draw(this->line1, 2, sf::Lines);
		this->window->draw(this->line2, 2, sf::Lines);
		this->window->draw(this->line3, 2, sf::Lines);
		this->window->draw(this->line4, 2, sf::Lines);

		for (auto* bullet : this->bullets)
		{
			bullet->render(this->window);
		}

		for (auto* enemy : this->enemies)
		{
			enemy->render(*this->window);
		}

		this->player->render(*this->window);
		this->renderGUI();
	}

	if (this->gameState == PAUSED)
	{
		this->renderPauseMenu();
	}

	if(this->gameState == GAME_OVER)
	{
		this->renderGameOverMenu();
	}

	if (this->gameState == SETTINGS)
	{
		std::cout << "Rendering settings menu\n";
		this->renderSettingsMenu();
	}

	this->window->display();
}

