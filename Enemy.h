	#pragma once

	#include <iostream>
	#include <vector>
	#include <ctime>

	#include <SFML/Graphics.hpp>

// Enemy class declaration
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

		// Animations
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

		sf::Texture stage3e1FireTexture;
		sf::Sprite stage3e1Fire;

		sf::IntRect stage3e1Frame;
		int stage3e1CurrentFrame;
		float stage3e1AnimationTimer;
		float stage3e1AnimationSpeed;

		sf::Texture stage3e2FireTexture;
		sf::Sprite stage3e2Fire;

		sf::IntRect stage3e2Frame;
		int stage3e2CurrentFrame;
		float stage3e2AnimationTimer;
		float stage3e2AnimationSpeed;

		sf::Texture stage3e3FireTexture;
		sf::Sprite stage3e3Fire;

		sf::IntRect stage3e3Frame;
		int stage3e3CurrentFrame;
		float stage3e3AnimationTimer;
		float stage3e3AnimationSpeed;

		sf::Texture stage3e4FireTexture;
		sf::Sprite stage3e4Fire;

		sf::IntRect stage3e4Frame;
		int stage3e4CurrentFrame;
		float stage3e4AnimationTimer;
		float stage3e4AnimationSpeed;

		sf::Texture stage3e5FireTexture;
		sf::Sprite stage3e5Fire;

		sf::IntRect stage3e5Frame;
		int stage3e5CurrentFrame;
		float stage3e5AnimationTimer;
		float stage3e5AnimationSpeed;

		sf::Texture stage3e6FireTexture;
		sf::Sprite stage3e6Fire;

		sf::IntRect stage3e6Frame;
		int stage3e6CurrentFrame;
		float stage3e6AnimationTimer;
		float stage3e6AnimationSpeed;

		sf::Texture deathBeam2Texture;

		sf::IntRect deathBeam2Frame;
		int deathBeam2CurrentFrame;
		float deathBeam2AnimationTimer;
		float deathBeam2AnimationSpeed;

	public:
		// Constructors
		Enemy();
		Enemy(float pos_x, float pos_y, int type);

		virtual ~Enemy();

		// Accessors
		const sf::FloatRect getBounds() const;
		const int& getPoints() const;
		const int& getDamage() const;
		const float& getHp() const;
		const int& getType() const;
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
		void updateStage3Enemy1();
		void updateStage3Enemy2();
		void updateStage3Enemy3();
		void updateStage3Enemy4();
		void updateStage3Enemy5();
		void updateStage3Enemy6();

		void render(sf::RenderTarget& target);
	};

