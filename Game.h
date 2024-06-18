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
    SETTINGS,
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
    sf::Text pauseTitle;
    sf::Text settingsTitle;

    //World
    sf::Texture startMenuTexture;
    sf::Sprite startMenuBackground;

    sf::Texture stageBackgroundTexture;
    sf::Sprite stageBackground;
    sf::Sprite stageBackground2;
    float backgroundScrollSpeed;

    // Menu Backgrounds
    sf::Texture gameOverBackgroundTexture;
    sf::Sprite gameOverBackground;

    // Systems
    unsigned points;

    // Player
    Player* player;

    // Player GUI
    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerHpBarBack;
    sf::Texture heartTexture;
    sf::Sprite heartSprite;


    // Enemies
    float spawnTimer;
    float spawnTimerMax;
    std::vector<Enemy*> enemies;

    // Sound effects
    sf::SoundBuffer laserBuffer;
    sf::Sound laserSound;

    sf::SoundBuffer menuClick;
    sf::Sound menuSound;

    sf::SoundBuffer playerHitBuffer;
    sf::Sound playerHit;

    sf::SoundBuffer alienHitBuffer;
    sf::Sound alienHit;

    sf::SoundBuffer pauseBuffer;
    sf::Sound pauseSound;

    // Music
    sf::Music stageMusic;
    sf::Music menuMusic;
    sf::Music gameOverMusic;

    // Line Mechanic
    sf::Vertex line1[2];
    sf::Vertex line2[2];
    sf::Vertex line3[2];
    sf::Vertex line4[2];

    // Game state
    GameState gameState; // New game state variable
    GameState prevgameState;

    // Private functions
    void initializeWindow();
    void initializeLines();
    void initializeTextures();
    void initializeSounds();
    void initializeMusic();
    void initializeGUI();
    void initializeBackground();
    void initializeSystems();
    void initializeMenuBackgrounds();

    void initializeStartMenu(); // New function for initializing the start menu
    void initializePauseMenu();
    void initializeGameOverMenu();
    void initializeSettingsMenu();

    void initializeEnemy();
    void initializePlayer();
    void handleMainMenuInput(const sf::Event& ev);
    void handlePauseMenuInput(const sf::Event& ev);
    void handleGameOverMenuInput(const sf::Event& ev);
    void handleSettingsMenuInput(const sf::Event& ev);

    // Main Menu options
    sf::Text playText;
    sf::Text shopText;
    sf::Text settingsText;
    sf::Text creditsText;
    sf::Text quitText;

    // Pause Menu options
    sf::Text resumeText;
    sf::Text pausesettingsText;
    sf::Text mainmenuText;

    // Game Over menu options
    sf::Text gameOverText;

    // Settings Menu options
    sf::Text musicvolumeText;
    sf::Text soundfxText;
    sf::Text backText;


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
    void renderPauseMenu();
    void renderSettingsMenu();
    void renderGameOverMenu();
};
