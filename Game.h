#pragma once
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <map>
#include <string>
#include <sstream>

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

    sf::Font titleFont;
    sf::Text gameTitle;

    //World
    sf::Texture startMenuTexture;
    sf::Sprite startMenuBackground;

    sf::Texture stageBackgroundTexture;
    sf::Sprite stageBackground;
    sf::Sprite stageBackground2;
    float backgroundScrollSpeed;

    // Systems
    unsigned points;

    // Player
    Player* player;

    // Enemies
    float spawnTimer;
    float spawnTimerMax;
    std::vector<Enemy*> enemies;

    // Sound effects
    sf::SoundBuffer laserBuffer;
    sf::Sound laserSound;
    sf::SoundBuffer menuClick;
    sf::Sound menuSound;


    // Music
    sf::Music stageMusic;
    sf::Music menuMusic;

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
    void initializeMusic();
    void initializeGUI();
    void initializeBackground();
    void initializeSystems();

    void initializeStartMenu(); // New function for initializing the start menu

    void initializeEnemy();
    void initializePlayer();

    // Menu
    sf::Text playText;
    sf::Text shopText;
    sf::Text settingsText;
    sf::Text creditsText;
    sf::Text quitText;

    int selectedMenuItem;


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
    void updateCollision();

    void updateEnemies();
    void updateCombat();
    void update();

    void renderGUI();
    void renderWorld();
    void render();
    void renderStartMenu(); // New function for rendering the start menu
};
