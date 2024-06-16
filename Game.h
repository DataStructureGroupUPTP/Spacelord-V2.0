#pragma once
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <map>

enum GameState
{
    MAIN_MENU,
    GAMEPLAY,
    PAUSED,
    GAME_OVER
};


class Game
{
private:
    // Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;

    // Resources
    std::map<std::string, sf::Texture*> textures;
    std::vector<Bullet*> bullets;

    // GUI
    sf::Font font;
    sf::Text pointText;
    sf::Text startText; // New text for the start menu

    //World
    sf::Texture stageBackgroundTexture;
    sf::Sprite stageBackground;
    sf::Sprite stageBackground2;
    float scrollSpeed;

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

    // Game state
    GameState gameState; // New game state variable

    // Private functions
    void initializeWindow();
    void initializeLines();
    void initializeTextures();
    void initializeSounds();
    void initializeGUI();
    void initializeBackground();

    void initializeStartMenu(); // New function for initializing the start menu

    void initializeEnemy();
    void initializePlayer();

public:
    Game();
    virtual ~Game();

    // Functions
    void run();

    void updatePollEvents();
    void updateInput();

    void updateBackground();
    void updateGUI();
    void updateBullets();
    void updateEnemies();
    void updateCombat();
    void update();

    void renderGUI();
    void renderWorld();
    void render();
    void renderStartMenu(); // New function for rendering the start menu
};
