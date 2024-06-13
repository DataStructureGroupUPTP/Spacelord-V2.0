#pragma once
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <map>


class Game
{
private:

	// Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	// Resources
	std::map <std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	// GUI
	sf::Font font;
	sf::Text pointText;

	// Player
	Player* player;

	// Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;
	float temporalPointSystem;

	// Sound effects
	sf::SoundBuffer laserBuffer;
	sf::Sound laserSound;
	
	// Line Mechanic
	sf::Vertex line1[2];
	sf::Vertex line2[2];
	sf::Vertex line3[2];

	// Private functions
	void initializeWindow();
	void initializeLines();
	void initializeTextures();
	void initializeSounds();
	void initializeGUI();
	
	void initializeEnemy();
	void initializePlayer();

public:
	Game();
	virtual	~Game();


	// Functions
	void run();

	void updatePollEvents();
	void updateInput();
	
	void updateGUI();
	void updateBullets();
	void updateEnemies();

	void update();

	void renderGUI();
	void render();

};
