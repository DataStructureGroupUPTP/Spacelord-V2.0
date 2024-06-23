#include "Game.h"

void Game::initializeLines()
{
	
	
	this->lane = 4;
	this->rightKeyPressed = false;
	this->leftKeyPressed = false;
	this->laneRandomizer = 1;
	this->lanePos = 200;

	this->line1Pos = 200;
	this->line2Pos = 400;
	this->line3Pos = 600;
	this->line4Pos = 800;

	this->line1[0] = sf::Vertex(sf::Vector2f(200, 0), sf::Color::White);
	this->line1[1] = sf::Vertex(sf::Vector2f(200, 1000), sf::Color::White);

	this->line2[0] = sf::Vertex(sf::Vector2f(400, 0), sf::Color::White);
	this->line2[1] = sf::Vertex(sf::Vector2f(400, 1000), sf::Color::White);

	this->line3[0] = sf::Vertex(sf::Vector2f(600, 0), sf::Color::White);
	this->line3[1] = sf::Vertex(sf::Vector2f(600, 1000), sf::Color::White);

	this->line4[0] = sf::Vertex(sf::Vector2f(800, 0), sf::Color::White);
	this->line4[1] = sf::Vertex(sf::Vector2f(800, 1000), sf::Color::White);
}

void Game::initializeTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	if (!this->textures["BULLET"]->loadFromFile("Textures/Redbulletrfix.png"))
	{
		std::cout << "TEXTURE::BULLET::FAILED_TO_LOAD" << "\n";
	}

	this->textures["GREENALIEN"] = new sf::Texture();
	if (!this->textures["GREENALIEN"]->loadFromFile("Textures/Greenalienfix.png"))
	{
		std::cout << "TEXTURE::GREEN_ALIEN::FAILED_TO_LOAD" << "\n";
	}

	this->textures["BLUEALIEN"] = new sf::Texture();
	if (!this->textures["BLUEALIEN"]->loadFromFile("Textures/Bluealienfix.png"))
	{
		std::cout << "TEXTURE::BLUE_ALIEN::FAILED_TO_LOAD" << "\n";
	}

	this->textures["YELLOWALIEN"] = new sf::Texture();
	if (!this->textures["YELLOWALIEN"]->loadFromFile("Textures/Yellowalienfix.png"))
	{
		std::cout << "TEXTURE::YELLOW_ALIEN::FAILED_TO_LOAD" << "\n";
	}

	this->textures["HEALTH"] = new sf::Texture();
	if (!this->textures["HEALTH"]->loadFromFile("Textures/Heart.png"))
	{
		std::cout << "TEXTURE::HEART::FAILED_TO_LOAD" << "\n";
	}

	this->textures["REDBALL"] = new sf::Texture();
	if(!this->textures["REDBALL"]->loadFromFile("Textures/Ball1.png"))
	{
		std::cout << "TEXTURE::BALL1::FAILED_TO_LOAD" << "\n";
	}

	this->textures["BLUEBALL"] = new sf::Texture();
	if (!this->textures["BLUEBALL"]->loadFromFile("Textures/Ball2.png"))
	{
		std::cout << "TEXTURE::BALL2::FAILED_TO_LOAD" << "\n";
	}

	this->textures["YELLOWBALL"] = new sf::Texture();
	if (!this->textures["YELLOWBALL"]->loadFromFile("Textures/Ball3.png"))
	{
		std::cout << "TEXTURE::BALL3::FAILED_TO_LOAD" << "\n";
	}

	this->textures["PURPLEBALL"] = new sf::Texture();
	if (!this->textures["PURPLEBALL"]->loadFromFile("Textures/Ball4.png"))
	{
		std::cout << "TEXTURE::BALL4::FAILED_TO_LOAD" << "\n";
	}

	this->textures["METEOR"] = new sf::Texture();
	if (!this->textures["METEOR"]->loadFromFile("Textures/Meteor.png"))
	{
		std::cout << "TEXTURE::METEOR::FAILED_TO_LOAD" << "\n";
	}

	this->textures["SMALLENEMY"] = new sf::Texture();
	if (!this->textures["SMALLENEMY"]->loadFromFile("Textures/Smallenemyf1.png"))
	{
		std::cout << "TEXTURE::SMALL_ENEMY::FAILED_TO_LOAD" << "\n";
	}

	this->textures["MEDIUMENEMY"] = new sf::Texture();
	if (!this->textures["MEDIUMENEMY"]->loadFromFile("Textures/Mediumenemyf1.png"))
	{
		std::cout << "TEXTURE::MEDIUM_ENEMY::FAILED_TO_LOAD" << "\n";
	}

	this->textures["BIGENEMY"] = new sf::Texture();
	if (!this->textures["BIGENEMY"]->loadFromFile("Textures/Bigenemyf1.png"))
	{
		std::cout << "TEXTURE::BIG_ENEMY::FAILED_TO_LOAD" << "\n";
	}
}

void Game::initializeSounds()
{
	this->soundfxVolume = 5.f;
	this->musicVolume = 5.f;

	if (!this->laserBuffer.loadFromFile("Sounds/Shiplaser.wav"))
	{
		std::cout << "SOUND::SHIPLASER::FAILED_TO_LOAD" << "\n";
	}
	this->laserSound.setBuffer(this->laserBuffer);

	this->laserSound.setVolume(this->soundfxVolume * 3.0f); // 12.5

	if (!this->menuClick.loadFromFile("Sounds/Menu.wav"))
	{
		std::cout << "SOUND::MENU::FAILED_TO_LOAD" << "\n";
	}

	this->menuSound.setBuffer(this->menuClick);

	this->menuSound.setVolume(this->soundfxVolume * 10); // 50

	if (!this->playerHitBuffer.loadFromFile("Sounds/Playerhit.flac"))
	{
		std::cout << "SOUND::PLAYER_HIT::FAILED_TO_LOAD" << "\n";
	}

	this->playerHit.setBuffer(this->playerHitBuffer);

	this->playerHit.setVolume(this->soundfxVolume * 7); // 35

	if (!this->alienHitBuffer.loadFromFile("Sounds/Enemyhit.wav"))
	{
		std::cout << "SOUND::ALIEN_HIT::FAILED_TO_LOAD" << "\n";
	}

	this->alienHit.setBuffer(this->alienHitBuffer);
	
	this->alienHit.setVolume(this->soundfxVolume * 6); // 30

	if (!this->pauseBuffer.loadFromFile("Sounds/PauseSound.wav"))
	{
		std::cout << "SOUND::MENU::PAUSE::FAILED_TO_LOAD" << "\n";
	}

	this->pauseSound.setBuffer(this->pauseBuffer);

	this->pauseSound.setVolume(this->soundfxVolume * 10); // 50

	if(!this->healBuffer.loadFromFile("Sounds/heal.wav"))
	{
		std::cout << "SOUND::HEAL::FAILED_TO_LOAD";
	}

	this->healSound.setBuffer(this->healBuffer);

	this->healSound.setVolume(this->soundfxVolume * 5);

	if(!this->powerUpBuffer.loadFromFile("Sounds/Powerup1.wav"))
	{
		std::cout << "SOUND::POWERUP1::FAILED_TO_LOAD";
	}

	this->powerUpSound.setBuffer(this->powerUpBuffer);

	this->powerUpSound.setVolume(this->soundfxVolume * 5);

	if (!this->swooshBuffer.loadFromFile("Sounds/Swoosh.mp3"))
	{
		std::cout << "SOUND::SWOOSH::FAILED_TO_LOAD";
	}

	this->swooshSound.setBuffer(this->swooshBuffer);

	this->swooshSound.setVolume(this->soundfxVolume * 50);

	if (!this->clangBuffer.loadFromFile("Sounds/Bosshit.wav"))
	{
		std::cout << "SOUND::BOSS_HIT::FAILED_TO_LOAD";
	}

	this->clangHit.setBuffer(this->clangBuffer);

	this->clangHit.setVolume(this->soundfxVolume * 15);

	if (!this->criticalBuffer.loadFromFile("Sounds/CriticalHit.wav"))
	{
		std::cout << "SOUND::CRITICAL_HIT::FAILED_TO_LOAD";
	}

	this->criticalHit.setBuffer(this->criticalBuffer);

	this->criticalHit.setVolume(75);
}

void Game::initializeMusic()
{
	if (!this->stageMusic.openFromFile("Music/BattleInTheStars.ogg"))
	{
		std::cout << "ERROR::BATTLEINTHESTARS::FAILED_TO_LOAD" << "\n";
	}

	this->stageMusic.setVolume(this->musicVolume * 6); // 30
	// Play the music
	this->stageMusic.play();

	if (!this->gameOverMusic.openFromFile("Music/Yellow.mp3"))
	{
		std::cout << "ERROR::YELLOW_GAME_OVER_THEME::FAILED_TO_LOAD" << "\n";
	}

	this->gameOverMusic.setVolume(this->musicVolume * 6); // 30

}

void Game::initializeGUI()
{
	// Load Fonts
	if (!this->font.loadFromFile("Fonts/Pixellettersfull.ttf"))
	{
		std::cout << "FONT::PIXELLETTERSFULL::FAILED_TO_LOAD" << "\n";
	}

	if (!this->titleFont.loadFromFile("Fonts/Debrosee.ttf"))
	{
		std::cout << "FONT::DEBROSEE::FAILED_TO_LOAD" << "\n";
	}

	//Initialize point text
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(36);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("ERROR");

	//Initialize point text
	this->currencyText.setFont(this->font);
	this->currencyText.setCharacterSize(36);
	this->currencyText.setFillColor(sf::Color::White);
	this->currencyText.setString("ERROR");
	this->currencyText.setPosition(0.f, 750.f);

	// Initialize game title
	this->gameTitle.setFont(this->titleFont);
	this->gameTitle.setCharacterSize(100);
	this->gameTitle.setFillColor(sf::Color::White);
	this->gameTitle.setStyle(sf::Text::Italic);
	this->gameTitle.setOutlineThickness(1);
	this->gameTitle.setString("ASTRAL ATTACK");

	// Initialize Pause title
	this->pauseTitle.setFont(this->titleFont);
	this->pauseTitle.setCharacterSize(100);
	this->pauseTitle.setFillColor(sf::Color::White);
	this->pauseTitle.setStyle(sf::Text::Italic);
	this->pauseTitle.setOutlineThickness(1);
	this->pauseTitle.setString("PAUSED");

	// Initialize Settings title
	this->settingsTitle.setFont(this->titleFont);
	this->settingsTitle.setCharacterSize(100);
	this->settingsTitle.setFillColor(sf::Color::White);
	this->settingsTitle.setStyle(sf::Text::Italic);
	this->settingsTitle.setOutlineThickness(1);
	this->settingsTitle.setString("SETTINGS");

	// Initialize game over title
	this->gameOverText.setFont(this->titleFont);
	this->gameOverText.setCharacterSize(100);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setStyle(sf::Text::Italic);
	this->gameOverText.setOutlineThickness(1);
	this->gameOverText.setString("GAME OVER");

	// Initialize health bar
	this->playerHpBar.setSize(sf::Vector2f(150.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(20.f, 60.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

	// Initialize timer
	this->timerText.setFont(this->font);
	this->timerText.setCharacterSize(36);
	this->timerText.setFillColor(sf::Color::White);
	timerText.setPosition(this->window->getSize().x - 75.f, 0.f);
	this->elapsedTime = 0.f;
	this->clock.restart();
	this->minutes = 0;
	this->seconds = 0;

	// Initialize Music volume border bar
	this->musicvolumeBorder.setSize(sf::Vector2f(300.f, 35.f));
	this->musicvolumeBorder.setOutlineThickness(-5.f);
	this->musicvolumeBorder.setFillColor(sf::Color::Black);
	this->musicvolumeBorder.setPosition(
		this->window->getSize().x / 2.f - this->musicvolumeBorder.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->musicvolumeBorder.getGlobalBounds().height / 2.f - 25.f
	);

	// Initialize Music volume indicator bar
	this->musicvolumeIndicator.setSize(sf::Vector2f(300.f, 35.f));
	this->musicvolumeIndicator.setFillColor(sf::Color(255, 255, 255, 75));
	this->musicvolumeIndicator.setPosition(
		this->window->getSize().x / 2.f - this->musicvolumeIndicator.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->musicvolumeIndicator.getGlobalBounds().height / 2.f - 25.f
	);

	// Initialize Sound FX volume border bar
	this->soundfxvolumeBorder.setSize(sf::Vector2f(300.f, 35.f));
	this->soundfxvolumeBorder.setOutlineThickness(-5.f);
	this->soundfxvolumeBorder.setFillColor(sf::Color::Black);
	this->soundfxvolumeBorder.setPosition(
		this->window->getSize().x / 2.f - this->soundfxvolumeBorder.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->soundfxvolumeBorder.getGlobalBounds().height / 2.f + 75.f
	);
	// Initialize Sound FX volume indicator bar
	this->soundfxvolumeIndicator.setSize(sf::Vector2f(300.f, 35.f));
	this->soundfxvolumeIndicator.setFillColor(sf::Color(255, 255, 255, 75));
	this->soundfxvolumeIndicator.setPosition(
		this->window->getSize().x / 2.f - this->soundfxvolumeIndicator.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->soundfxvolumeIndicator.getGlobalBounds().height / 2.f + 75.f
	);
}

void Game::initializeBackground()
{
	if (!this->stageBackgroundTexture.loadFromFile("Textures/Space1.png"))
	{
		std::cout << "TEXTURE::SPACE1::FAILED_TO_LOAD" << "\n";
	}

	this->stageBackground.setTexture(this->stageBackgroundTexture);
	this->stageBackground2.setTexture(this->stageBackgroundTexture);

	this->stageBackground2.setPosition(0, this->stageBackground.getGlobalBounds().height);

	this->backgroundScrollSpeed = 1.f;

	int randomBackground = rand() % 5 + 1;

	switch (randomBackground)
	{
	case 1:
		if (!this->startMenuTexture.loadFromFile("Textures/StartMenu3.png"))
		{
			std::cout << "TEXTURE::STARTMENU::FAILED_TO_LOAD" << "\n";
		}

		this->startMenuBackground.setTexture(this->startMenuTexture);
		this->gameTitle.setOutlineColor(sf::Color(255, 165, 0));
		break;

	case 2:
		if (!this->startMenuTexture.loadFromFile("Textures/StartMenu1.png"))
		{
			std::cout << "TEXTURE::STARTMENU::FAILED_TO_LOAD" << "\n";
		}

		this->gameTitle.setOutlineColor(sf::Color::Cyan);
		this->startMenuBackground.setTexture(this->startMenuTexture);
		break;

	case 3:
		if (!this->startMenuTexture.loadFromFile("Textures/StartMenu4.png"))
		{
			std::cout << "TEXTURE::STARTMENU::FAILED_TO_LOAD" << "\n";
		}

		this->gameTitle.setOutlineColor(sf::Color::Magenta);
		this->startMenuBackground.setTexture(this->startMenuTexture);
		break;

	case 4:
		if (!this->startMenuTexture.loadFromFile("Textures/StartMenu2.png"))
		{
			std::cout << "TEXTURE::STARTMENU::FAILED_TO_LOAD" << "\n";
		}

		this->gameTitle.setOutlineColor(sf::Color::Green);
		this->startMenuBackground.setTexture(this->startMenuTexture);
		break;

	case 5:
		if (!this->startMenuTexture.loadFromFile("Textures/StartMenu5.png"))
		{
			std::cout << "TEXTURE::STARTMENU::FAILED_TO_LOAD" << "\n";
		}

		this->gameTitle.setOutlineColor(sf::Color::Yellow);
		this->startMenuBackground.setTexture(this->startMenuTexture);
		break;

	}
}

void Game::initializeSystems()
{
	this->bulletSpeed = 5.f;
	this->points = 0;
	this->currency = 0;

}

void Game::initializeMenuBackgrounds()
{
	if (!this->gameOverBackgroundTexture.loadFromFile("Textures/GameOver.png"))
	{
		std::cout << "TEXTURE::GAME_OVER_BACKGROUND::FAILED_TO_LOAD" << "\n";
	}

	this->gameOverBackground.setTexture(this->gameOverBackgroundTexture);

}

void Game::initializeStartMenu()
{
	// Initialize music
	if (!this->menuMusic.openFromFile("Music/SkyFire.ogg"))
	{
		std::cout << "ERROR::SKYFIRE::FAILED_TO_LOAD" << "\n";
	}
	this->menuMusic.setVolume(this->musicVolume * 6); // 30
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

	this->creditsText.setFont(this->font);
	this->creditsText.setCharacterSize(48);
	this->creditsText.setFillColor(sf::Color::White);
	this->creditsText.setString("Credits");
	this->creditsText.setPosition(
		this->window->getSize().x / 2.f - this->creditsText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->creditsText.getGlobalBounds().height / 2.f + 50.f
	);

	// Initialize Quit menu item
	this->quitText.setFont(this->font);
	this->quitText.setCharacterSize(48);
	this->quitText.setFillColor(sf::Color::White);
	this->quitText.setString("Quit");
	this->quitText.setPosition(
		this->window->getSize().x / 2.f - this->quitText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->quitText.getGlobalBounds().height / 2.f + 100.f
	);
}

void Game::initializePauseMenu()
{
	this->pausesettingsBackground.setSize(sf::Vector2f(1000.f, 800.f));
	this->pausesettingsBackground.setFillColor(sf::Color(0, 0, 0, 150));

	this->pauseTitle.setPosition
	(
		this->window->getSize().x / 2.f - this->pauseTitle.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->pauseTitle.getGlobalBounds().height / 2.f - 250.f
	);
	// Initialize Resume menu item
	this->resumeText.setFont(this->font);
	this->resumeText.setCharacterSize(48);
	this->resumeText.setFillColor(sf::Color::White);
	this->resumeText.setString("Resume");
	this->resumeText.setPosition(
		this->window->getSize().x / 2.f - this->resumeText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->resumeText.getGlobalBounds().height / 2.f - 100.f
	);
	// Initialize Pause Settings menu item
	this->pausesettingsText.setFont(this->font);
	this->pausesettingsText.setCharacterSize(48);
	this->pausesettingsText.setFillColor(sf::Color::White);
	this->pausesettingsText.setString("Settings");
	this->pausesettingsText.setPosition(
		this->window->getSize().x / 2.f - this->pausesettingsText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->pausesettingsText.getGlobalBounds().height / 2.f - 50.f
	);
	// Initialize Back to Main Menu menu item
	this->mainmenuText.setFont(this->font);
	this->mainmenuText.setCharacterSize(48);
	this->mainmenuText.setFillColor(sf::Color::White);
	this->mainmenuText.setString("Back to Main Menu");
	this->mainmenuText.setPosition(
		this->window->getSize().x / 2.f - this->mainmenuText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->mainmenuText.getGlobalBounds().height / 2.f
	);
}

void Game::initializeGameOverMenu()
{
	this->gameOverText.setPosition
	(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f - 250.f
	);

	// Initialize Back to Main Menu menu item
	this->mainmenuText.setFont(this->font);
	this->mainmenuText.setCharacterSize(48);
	this->mainmenuText.setFillColor(sf::Color::White);
	this->mainmenuText.setString("Back to Main Menu");
	this->mainmenuText.setPosition(
		this->window->getSize().x / 2.f - this->mainmenuText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->mainmenuText.getGlobalBounds().height / 2.f
	);
}

void Game::initializeSettingsMenu()
{
	updateMusicVolume();
	updateSoundFXVolume();

	this->settingsTitle.setPosition
	(
		this->window->getSize().x / 2.f - this->settingsTitle.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->settingsTitle.getGlobalBounds().height / 2.f - 250.f
	);
	// Initialize Music Volume menu item
	this->musicvolumeText.setFont(this->font);
	this->musicvolumeText.setCharacterSize(48);
	this->musicvolumeText.setFillColor(sf::Color::White);
	this->musicvolumeText.setString("Music Volume");
	this->musicvolumeText.setPosition(
		this->window->getSize().x / 2.f - this->musicvolumeText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->musicvolumeText.getGlobalBounds().height / 2.f - 100.f
	);
	// Initialize Sound FX menu item
	this->soundfxText.setFont(this->font);
	this->soundfxText.setCharacterSize(48);
	this->soundfxText.setFillColor(sf::Color::White);
	this->soundfxText.setString("Sound FX");
	this->soundfxText.setPosition(
		this->window->getSize().x / 2.f - this->soundfxText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->soundfxText.getGlobalBounds().height / 2.f
	);
	// Initialize Back to Main Menu menu item
	this->backText.setFont(this->font);
	this->backText.setCharacterSize(48);
	this->backText.setFillColor(sf::Color::White);
	this->backText.setString("Back");
	this->backText.setPosition(
		this->window->getSize().x / 2.f - this->backText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->backText.getGlobalBounds().height / 2.f + 100.f
	);
}

void Game::initializeWindow()
{
	// Size of the window
	this->videoMode.height = 800;
	this->videoMode.width = 1000;

	this->window = new sf::RenderWindow(this->videoMode, "Astral Attack", sf::Style::Default | sf::Style::Titlebar);

	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);

}

void Game::initializeEnemy()
{
	this->boss = new Boss(200.f, 10.f);
	this->bossIsActive = false;

	this->spawnTimerMax = 60.f;
	this->spawnTimer = this->spawnTimerMax;

	this->horizontalSpawnTimerMax = 60.f;
	this->horizontalSpawnTimer = 0.f;

	this->meteorSpawnTimerMax = 60.f;
	this->meteorSpawnTimer = 0.f;
	this->tripleMeteorChance = 10.f;
	this->doubleMeteorChance = 40.f;

}

void Game::initializeSpawnRates()
{
	this->enemySpawnRate = 2.0f;
	this->meteorSpawnRate = 0.f;
	this->horizontalEnemySpawnRate = 0.f;
	this->healthItemSpawnRate = 0.0167f;
	this->dpsItemSpawnRate = 0.1f;
}

void Game::initializeItems()
{
	this->healthItemSpawnTimerMax = 60.f;
	this->healthItemSpawnTimer = 0.f;
	this->dpsItemSpawnTimerMax = 60.f;
	this->dpsItemSpawnTimer = 0.f;
}

void Game::initializePlayer()
{
	this->player = new Player;

}
