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

	class Enemy
	{
	private:
		sf::Texture texture;
		sf::Sprite enemyOne;
		sf::Sprite meteor;

		// Stats
		int type;
		float hp;
		int damage;
		int points;
		float speed;

		float meteorSpeedIncrease;

		// Texture vector
		std::map<std::string, sf::Texture*> textures;

		// Private functions
		void initializeVariables();
		void initializeTextures();

		// Animation
		int currentFrame;
		float animationTimer;
		float animationInterval;

		// Animations stage 2
		sf::Texture bomberFireTexture;
		sf::Sprite bomberFire;

		sf::IntRect bomberfireFrame;
		int bomberCurrentFrame;
		float bomberAnimationTimer;
		float bomberAnimationSpeed;

		sf::Texture frigateFireTexture;
		sf::Sprite frigateFire;

		sf::IntRect frigateFireFrame;
		int frigateCurrentFrame;
		float frigateAnimationTimer;
		float frigateAnimationSpeed;

		sf::Texture scoutFireTexture;
		sf::Sprite scoutFire;

		sf::IntRect scoutFireFrame;
		int scoutCurrentFrame;
		float scoutAnimationTimer;
		float scoutAnimationSpeed;

		sf::Texture fighterFireTexture;
		sf::Sprite fighterFire;

		sf::IntRect fighterFrame;
		int fighterCurrentFrame;
		float fighterAnimationTimer;
		float fighterAnimationSpeed;

		sf::Texture supportFireTexture;
		sf::Sprite supportFire;

		sf::IntRect supportFrame;
		int supportCurrentFrame;
		float supportAnimationTimer;
		float supportAnimationSpeed;

		sf::Texture torpedoFireTexture;
		sf::Sprite torpedoFire;

		sf::IntRect torpedoFrame;
		int torpedoCurrentFrame;
		float torpedoAnimationTimer;
		float torpedoAnimationSpeed;

		sf::Texture deathBeamTexture;

		sf::IntRect deathBeamFrame;
		int deathBeamCurrentFrame;
		float deathBeamAnimationTimer;
		float deathBeamAnimationSpeed;


	public:

		Enemy();
		Enemy(float pos_x, float pos_y, int type);

		virtual ~Enemy();

		// Accessors
		const sf::FloatRect getBounds() const;
		const int& getPoints() const;
		const int& getDamage() const;
		const float& getHp() const;
		const float& getType() const;
		void reduceHp(const float value);
		void increaseMeteorSpeed(const float value);
		const sf::Vector2f& getPos() const;

		void update();
		void updateAnimation();
		void updateBomberAnimation();
		void updateFrigateAnimation();
		void updateScoutAnimation();
		void updateFighterAnimation();
		void updateSupportAnimation();
		void updateTorpedoAnimation();
		void updateDeathBeamAnimation();

		void render(sf::RenderTarget& target);
	};

