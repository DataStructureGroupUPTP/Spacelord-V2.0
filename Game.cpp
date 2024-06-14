#include "Game.h"


// Private

void Game::initializeLines()
{
	
	this->line1[0] = sf::Vertex(sf::Vector2f(200, 40), sf::Color::White);
	this->line1[1] = sf::Vertex(sf::Vector2f(200, 800), sf::Color::White);

	this->line2[0] = sf::Vertex(sf::Vector2f(400, 40), sf::Color::White);
	this->line2[1] = sf::Vertex(sf::Vector2f(400, 800), sf::Color::White);

	this->line3[0] = sf::Vertex(sf::Vector2f(600, 40), sf::Color::White);
	this->line3[1] = sf::Vertex(sf::Vector2f(600, 800), sf::Color::White);
}

void Game::initializeTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	if (!this->textures["BULLET"]->loadFromFile("Textures/Redbulletr.png"))
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

	this->laserSound.setVolume(7.5);
}

void Game::initializeGUI()
{
	// Load Fonts
	if (!this->font.loadFromFile("Fonts/Pixellettersfull.ttf"))
	{
		std::cout << "FONT::PIXELLETTERSFULL::FAILED_TO_LOAD" << "\n";
	}

	temporalPointSystem = 0;

	//Initialize point text
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(36);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("ERROR");

	
}

void Game::initializeStartMenu()
{
	// Load Fonts
	if (!this->font.loadFromFile("Fonts/Pixellettersfull.ttf"))
	{
		std::cout << "FONT::PIXELLETTERSFULL::FAILED_TO_LOAD" << "\n";
	}

	// Initialize start menu text
	this->startText.setFont(this->font);
	this->startText.setCharacterSize(48);
	this->startText.setFillColor(sf::Color::White);
	this->startText.setString("Press Enter to Start");
	this->startText.setPosition(
		this->window->getSize().x / 2.f - this->startText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->startText.getGlobalBounds().height / 2.f
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

	this->gameState = MAIN_MENU; // Set initial game state to MAIN_MENU
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
		if (ev.Event::type == sf::Event::Closed)
		{
			this->window->close();
		}
		if (ev.Event::type == sf::Event::KeyPressed)
		{
			if (ev.Event::key.code == sf::Keyboard::Escape)
			{
				this->window->close();
			}
			else if (this->gameState == MAIN_MENU && ev.Event::key.code == sf::Keyboard::Enter)
			{
				this->gameState = GAMEPLAY; // Start the game when Enter is pressed
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
			if (this->player->getPos().y > 0) // Check upper boundary
			{
				this->player->move(0.f, -0.5f);
			}

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if(this->player->getPos().y + this->player->getBounds().height < this->window->getSize().y)
			{
				this->player->move(0.f, 0.5f);
			}
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
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 32.5f,
		this->player->getPos().y - 40.f, 0.f, -1.5f, 5.f));
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

void Game::updateEnemies()
{

	this->spawnTimer += 3.f;

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


	for ( size_t i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_removed = false;
		this->enemies[i]->update();

		for ( size_t k = 0; k < this->bullets.size() && !enemy_removed; k++)
		{
			if (this->bullets[k]->getBounds().intersects(this->enemies[i]->getBounds()))
			{
				this->bullets.erase(this->bullets.begin() + static_cast<int>(k));
				this->enemies.erase(this->enemies.begin() + static_cast<int>(i));
				enemy_removed = true;
				temporalPointSystem = temporalPointSystem + 1;
			}
		}


		// Enemy removal
		if (!enemy_removed) 
		{
			if (this->enemies[i]->getBounds().top > this->window->getSize().y)
			{
				this->enemies.erase(this->enemies.begin() + (int)i);
				enemy_removed = true;
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
		this->updateBullets();
		this->updateEnemies();
		this->updateGUI();
	}
}


void Game::renderGUI()
{
	this->window->draw(this->pointText);
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
	this->window->draw(this->startText);
}