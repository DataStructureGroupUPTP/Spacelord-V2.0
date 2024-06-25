#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>


// Hello world

class Player
{
private:
	sf::Texture shipFull;
	sf::Texture shipDamaged;
	sf::Texture shipVeryDamaged;
	
	sf::Texture shipEngine1;
	sf::Texture shipEngine1Fire;

	sf::Texture shieldTexture;

	sf::Sprite ship;
	sf::Sprite engine;
	sf::Sprite fire;
	sf::Sprite shield;

	float movementSpeed;

	float attackCooldown;
	float attackCooldownMax;

	float damage;

	int hp;
	int hpMax;

	// Animation
	sf::IntRect fireFrame;
	int currentFrame;
	float animationTimer;
	float animationSpeed;

	sf::IntRect shieldFrame;
	int currentFrameShield;
	float animationTimerShield;
	float animationSpeedShield;

	// Invincibility
	bool invincible;
	float invincibilityDuration; // Total duration of invincibility
	float invincibilityTimer;    // Timer to track the elapsed time

	// Shield mechanic
	bool shieldActive;
	float shieldDuration;
	float shieldTimer;

	// Private functions
	void initializeVariables();
	void initializeTexture();
	void initializeSprite();
	void initializeAnimation();

public:
	Player();
	virtual ~Player();

	// Accessors
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getHpMax() const;
	const float& getMoveSpeed() const;
	const float& getDamage() const;

	// Functions
	void move(const float dirX, const float dirY);
	const bool canAttack();

	// Modifiers
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setHp(const int hp);
	void loseHp(const int value);

	// Invincibility frames
	bool isInvincible() const;
	void startInvincibility();
	void activateShield();

	void upgradeDamage();
	void upgradeAttackSpeed();
	
	
	void updateAttackCooldown();
	void setAttackCooldownMax(float max);
	void updateSprite();
	void updateAnimation();
	void updateAnimationShield();
	void update();


	void render(sf::RenderTarget& target);
};
