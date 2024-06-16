#include "Game.h"


// Private

void Game::initializeLines()
{
	
	this->line1[0] = sf::Vertex(sf::Vector2f(200, 0), sf::Color::White);
	this->line1[1] = sf::Vertex(sf::Vector2f(200, 800), sf::Color::White);

	this->line2[0] = sf::Vertex(sf::Vector2f(400, 0), sf::Color::White);
	this->line2[1] = sf::Vertex(sf::Vector2f(400, 800), sf::Color::White);

	this->line3[0] = sf::Vertex(sf::Vector2f(600, 0), sf::Color::White);
	this->line3[1] = sf::Vertex(sf::Vector2f(600, 800), sf::Color::White);
}

void Game::initializeTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	if (!this->textures["BULLET"]->loadFromFile("Textures/Redbulletrfix.png"))
	{
		std::cout << "TEXTURE::BULLET::FAILED_TO_LOAD" << "\n";
	}

	this->textures["ENEMY1"] = new sf::Texture();
	if(!this->textures["ENEMY1"]->loadFromFile("Textures/Greenalienfix.png"))
	{
		std::cout << "TEXTURE::GREEN_ALIEN::FAILED_TO_LOAD" << "\n";
	}

	this->textures["ENEMY2"] = new sf::Texture();
	if (!this->textures["ENEMY2"]->loadFromFile("Textures/Bluealienfix.png"))
	{
		std::cout << "TEXTURE::BLUE_ALIEN::FAILED_TO_LOAD" << "\n";
	}

	this->textures["ENEMY3"] = new sf::Texture();
	if (!this->textures["ENEMY3"]->loadFromFile("Textures/Yellowalienfix.png"))
	{
		std::cout << "TEXTURE::YELLOW_ALIEN::FAILED_TO_LOAD" << "\n";
	}
}

void Game::initializeSounds()
{
	if (!this->laserBuffer.loadFromFile("Sounds/Shiplaser.wav"))
	{
		std::cout << "SOUND::SHIPLASER::FAILED_TO_LOAD" << "\n";
	}
	this->laserSound.setBuffer(this->laserBuffer);

	this->laserSound.setVolume(12.5);

	if(!this->menuClick.loadFromFile("Sounds/Menu.wav"))
	{
		std::cout << "SOUND::MENU::FAILED_TO_LOAD" << "\n";
	}

	this->menuSound.setBuffer(this->menuClick);
}

void Game::initializeMusic()
{
	if (!this->stageMusic.openFromFile("Music/BattleInTheStars.ogg"))
	{
		std::cout << "ERROR::BATTLEINTHESTARS::FAILED_TO_LOAD" << "\n";
	}

	this->stageMusic.setVolume(30);
	// Play the music
	this->stageMusic.play();
}

void Game::initializeGUI()
{
	// Load Fonts
	if (!this->font.loadFromFile("Fonts/Pixellettersfull.ttf"))
	{
		std::cout << "FONT::PIXELLETTERSFULL::FAILED_TO_LOAD" << "\n";
	}

	if(!this->titleFont.loadFromFile("Fonts/Debrosee.ttf"))
	{
		std::cout << "FONT::DEBROSEE::FAILED_TO_LOAD" << "\n";
	}

	temporalPointSystem = 0;

	//Initialize point text
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(36);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("ERROR");

	this->gameTitle.setFont(this->titleFont);
	this->gameTitle.setCharacterSize(100);
	this->gameTitle.setFillColor(sf::Color::White);
	this->gameTitle.setString("ASTRAL ATTACK");

	
}

void Game::initializeBackground()
{
	if(!this->stageBackgroundTexture.loadFromFile("Textures/Space1.png"))
	{
		std::cout << "TEXTURE::SPACE1::FAILED_TO_LOAD" << "\n";
	}

	this->stageBackground.setTexture(this->stageBackgroundTexture);
	this->stageBackground2.setTexture(this->stageBackgroundTexture);

	this->stageBackground2.setPosition(0, this->stageBackground.getGlobalBounds().height);

	this->backgroundScrollSpeed = 1.f;

	int randomBackground = rand() % 4 + 1;

	switch(randomBackground)
	{
	case 1:
		if (!this->startMenuTexture.loadFromFile("Textures/StartMenu1.png"))
		{
			std::cout << "TEXTURE::STARTMENU::FAILED_TO_LOAD" << "\n";
		}

		this->startMenuBackground.setTexture(this->startMenuTexture);
		break;

	case 2:
		if (!this->startMenuTexture.loadFromFile("Textures/StartMenu2.png"))
		{
			std::cout << "TEXTURE::STARTMENU::FAILED_TO_LOAD" << "\n";
		}

		this->startMenuBackground.setTexture(this->startMenuTexture);
		break;

	case 3:
		if (!this->startMenuTexture.loadFromFile("Textures/StartMenu3.png"))
		{
			std::cout << "TEXTURE::STARTMENU::FAILED_TO_LOAD" << "\n";
		}

		this->startMenuBackground.setTexture(this->startMenuTexture);
		break;

	case 4:
		if (!this->startMenuTexture.loadFromFile("Textures/StartMenu4.png"))
		{
			std::cout << "TEXTURE::STARTMENU::FAILED_TO_LOAD" << "\n";
		}

		this->startMenuBackground.setTexture(this->startMenuTexture);
		break;
	
	}
}

void Game::initializeStartMenu()
{
	// Initialize music
	if (!this->menuMusic.openFromFile("Music/SkyFire.ogg"))
	{
		std::cout << "ERROR::SKYFIRE::FAILED_TO_LOAD" << "\n";
	}

	this->menuMusic.setVolume(30);
	// Play the music
	this->menuMusic.play();


	// Initialize title
	this->gameTitle.setPosition
	(
		this->window->getSize().x / 2.f - this->gameTitle.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->gameTitle.getGlobalBounds().height / 2.f - 250.f
	);


	// Initialize Play menu item
	this->playText.setFont(this->font);
	this->playText.setCharacterSize(48);
	this->playText.setFillColor(sf::Color::White);
	this->playText.setString("Play");
	this->playText.setPosition(
		this->window->getSize().x / 2.f - this->playText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->playText.getGlobalBounds().height / 2.f - 100.f
	);

	// Initialize Shop menu item
	this->shopText.setFont(this->font);
	this->shopText.setCharacterSize(48);
	this->shopText.setFillColor(sf::Color::White);
	this->shopText.setString("Shop");
	this->shopText.setPosition(
		this->window->getSize().x / 2.f - this->shopText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->shopText.getGlobalBounds().height / 2.f - 50.f
	);

	// Initialize Settings menu item
	this->settingsText.setFont(this->font);
	this->settingsText.setCharacterSize(48);
	this->settingsText.setFillColor(sf::Color::White);
	this->settingsText.setString("Settings");
	this->settingsText.setPosition(
		this->window->getSize().x / 2.f - this->settingsText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->settingsText.getGlobalBounds().height / 2.f
	);

	// Initialize Quit menu item
	this->quitText.setFont(this->font);
	this->quitText.setCharacterSize(48);
	this->quitText.setFillColor(sf::Color::White);
	this->quitText.setString("Quit");
	this->quitText.setPosition(
		this->window->getSize().x / 2.f - this->quitText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->quitText.getGlobalBounds().height / 2.f + 50.f
	);
}

void Game::initializeWindow()
{
	// Size of the window
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Astral Attack", sf::Style::Close | sf::Style::Titlebar);

	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);

}

void Game::initializeEnemy()
{
	this->spawnTimerMax = 60.f;
	this->spawnTimer = this->spawnTimerMax;
}

void Game::initializePlayer()
{
	this->player = new Player;
	

}

// Constructor

Game::Game()
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

	this->gameState = MAIN_MENU; // Set initial game state to MAIN_MENU
	this->selectedMenuItem = 0;  // Initialize the selected menu item to the first item
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
			else if (this->gameState == MAIN_MENU)
			{
				if (ev.key.code == sf::Keyboard::Up)
				{
					if (this->selectedMenuItem > 0)
					{
						this->menuSound.play();
						this->selectedMenuItem--;
					}
				}
				else if (ev.key.code == sf::Keyboard::Down)
				{
					if (this->selectedMenuItem < 3)
					{
						this->menuSound.play();
						this->selectedMenuItem++;
					}
				}
				else if (ev.key.code == sf::Keyboard::Return)
				{
					if (this->selectedMenuItem == 0)
					{
						this->initializeMusic();
						this->gameState = GAMEPLAY;
						this->menuMusic.stop();
					}
					else if (this->selectedMenuItem == 1)
					{
						// Handle shop selection
					}
					else if (this->selectedMenuItem == 2)
					{
						// Handle settings selection
					}
					else if (this->selectedMenuItem == 3)
					{
						this->window->close();
					}
				}
			}
		}
	}
}

void Game::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			this->player->move(-0.5f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			this->player->move(0.5f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			this->player->move(0.f, -0.5f);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			this->player->move(0.f, 0.5f);

		}
	}

	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			this->player->move(-1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			this->player->move(1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (this->player->getPos().y > 0) // Check upper boundary
			{
				this->player->move(0.f, -1.f);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (this->player->getPos().y + this->player->getBounds().height < this->window->getSize().y)
			{
				this->player->move(0.f, 1.f);
			}
		}
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && this->player->canAttack()) 
	{
		this->laserSound.play();
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 28.f,
		this->player->getPos().y, 0.f, -1.5f, 5.f));
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
	std::stringstream ss;

	ss << "Points: " << this->temporalPointSystem;

	this->pointText.setString(ss.str());
}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();

		// Bullet culling (top)
		if(bullet->getBounds().top + bullet->getBounds().height < 0.f)
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
	if (this->player->getBounds().left + this->player->getBounds().width > this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}

	// Collision with top of the screen
	if (this->player->getPos().y < 0.f)
	{
		this->player->setPosition(this->player->getPos().x, 0.f);
	}

	// Collision with bottom of the screen
	if (this->player->getPos().y + this->player->getBounds().height > this->window->getSize().y)
	{
		this->player->setPosition(this->player->getPos().x, this->window->getSize().y - this->player->getBounds().height);
	}
}


void Game::updateEnemies()
{

	// Spawning
	this->spawnTimer += 2.f;

	if(this->spawnTimer >= this->spawnTimerMax)
	{
		int enemyRandomizer = rand() % 3;

		switch(enemyRandomizer)
		{
		case 0:
			this->enemies.push_back(new Enemy(this->textures["ENEMY1"], float(rand() % 500), -200.f));
			this->spawnTimer = 0;
			break;
		case 1:
			this->enemies.push_back(new Enemy(this->textures["ENEMY2"], float(rand() % 500), -200.f));
			this->spawnTimer = 0;
			break;
		case 2:
			this->enemies.push_back(new Enemy(this->textures["ENEMY3"], float(rand() % 500), -200.f));
			this->spawnTimer = 0;
			break;
		default:
			this->enemies.push_back(new Enemy(this->textures["ENEMY1"], float(rand() % 500), -200.f));
			this->spawnTimer = 0;
			break;

		}


	}

	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		enemy->update();

		if (enemy->getBounds().top  > this->window->getSize().y)
		{
			// Delete enemies at bottom screen
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;


		}

		++counter;
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
				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				enemy_deleted = true;
			}
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
	}
}



void Game::renderGUI()
{
	this->window->draw(this->pointText);
}

void Game::renderWorld()
{

	this->window->draw(this->stageBackground);
	this->window->draw(this->stageBackground2);
}

void Game::render()
{
	this->window->clear();

	if (this->gameState == MAIN_MENU)
	{
		this->renderStartMenu(); // Render start menu if in MAIN_MENU state
	}

	else if (this->gameState == GAMEPLAY)
	{
		// Draw world
		this->renderWorld();


		// Draw game elements
		this->window->draw(this->line1, 2, sf::Lines);
		this->window->draw(this->line2, 2, sf::Lines);
		this->window->draw(this->line3, 2, sf::Lines);

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

	this->window->display();
}


void Game::renderStartMenu()
{
	this->window->draw(this->startMenuBackground);

	// Reset the color of all menu items
	this->playText.setFillColor(sf::Color::White);
	this->shopText.setFillColor(sf::Color::White);
	this->settingsText.setFillColor(sf::Color::White);
	this->quitText.setFillColor(sf::Color::White);

	// Highlight the selected menu item
	switch (this->selectedMenuItem)
	{
	case 0:
		this->playText.setFillColor(sf::Color::Yellow);
		break;
	case 1:

		this->shopText.setFillColor(sf::Color::Yellow);
		break;
	case 2:

		this->settingsText.setFillColor(sf::Color::Yellow);
		break;
	case 3:

		this->quitText.setFillColor(sf::Color::Yellow);
		break;
	}

	// Draw menu items
	this->window->draw(this->gameTitle);
	this->window->draw(this->playText);
	this->window->draw(this->shopText);
	this->window->draw(this->settingsText);
	this->window->draw(this->quitText);
}