#include "Boss.h"
#include <iostream>

Boss::Boss(float initialHealth, float initialMoveSpeed)
    : health(initialHealth), moveSpeed(initialMoveSpeed), isMovingInLoop(false), angle(0.f), isDefeated(false), defeatTimer(0.f)
{
    // Load textures
    if (!bossTexture.loadFromFile("Textures/Boss1.png"))
    {
        std::cerr << "TEXTURE::BOSS::FAILED_TO_LOAD" << std::endl;
    }

    if (!this->bossFire.loadFromFile("Animations/Bossfireidle.png"))
    {
        std::cout << "TEXTURE::BOSS_ENGINE_FIRE::FAILED_TO_LOAD" << "\n";
    }

    bossSprite.setTexture(bossTexture);
    bossSprite.setScale(3.0f, 3.0f);
    bossSprite.rotate(180.f);

    startPosition = sf::Vector2f(400.f, -250.f); // Start just above the screen
    bossSprite.setPosition(startPosition);
    loopCenter = sf::Vector2f(600.f, 300.f); // Center of the loop
    loopRadius = 200.f; // Radius of the loop

    this->fire.setTexture(this->bossFire);
    this->fireFrame = sf::IntRect(0, 0, 128, 128);
    this->fire.setTextureRect(this->fireFrame);
    this->fire.setScale(3.0f, 3.0f);
    this->fire.rotate(180.f);

    this->fire.setPosition(
        this->bossSprite.getPosition().x + this->bossSprite.getGlobalBounds().width / 2 - this->fire.getGlobalBounds().width / 2,
        this->bossSprite.getPosition().y + this->bossSprite.getGlobalBounds().height - 100.f
    );

    // Animation
    this->currentFrame = 0;
    this->animationTimer = 0.f;
    this->animationSpeed = 0.1f; // Speed of the animation

    this->movingDown = true;
}

Boss::~Boss()
{
    // Destructor
}

const sf::FloatRect Boss::getBounds() const
{
    sf::FloatRect originalBounds = this->bossSprite.getGlobalBounds();
    float shrinkFactor = 0.8f; // Shrink the hitbox by 20%
    float widthReduction = originalBounds.width * (1 - shrinkFactor);
    float heightReduction = originalBounds.height * (1 - shrinkFactor);

    sf::FloatRect smallerBounds(
        originalBounds.left + widthReduction / 2, // Center the hitbox
        originalBounds.top + heightReduction / 2, // Center the hitbox
        originalBounds.width * shrinkFactor,      // Shrink the width
        originalBounds.height * shrinkFactor      // Shrink the height
    );

    return smallerBounds;
}

const sf::Vector2f& Boss::getPos() const
{
    return this->bossSprite.getPosition();
}

void Boss::spawn(sf::Vector2f position)
{
    bossSprite.setPosition(position);
    isMovingInLoop = false; // Start with coming down from the top
    isDefeated = false;
    defeatTimer = 0.f;
}

void Boss::updateAnimation()
{
    this->animationTimer += this->animationSpeed;
    if (this->animationTimer >= 1.f)
    {
        this->animationTimer = 0.f;
        this->currentFrame++;
        if (this->currentFrame >= 8) // 8 frames
        {
            this->currentFrame = 0;
        }
        this->fireFrame.left = this->currentFrame * 128; // Frame width is 128
        this->fire.setTextureRect(this->fireFrame);
    }
}

void Boss::update(float deltaTime)
{
    if (isDefeated)
    {
        updateDefeatedState(deltaTime);
        return;
    }

    this->updateAnimation();
    if (!isMovingInLoop)
    {
        // Move slowly down to the loop center
        sf::Vector2f currentPosition = bossSprite.getPosition();
        sf::Vector2f direction = loopCenter - currentPosition;
        float distance = moveSpeed * deltaTime;
        if (distance >= std::sqrt(direction.x * direction.x + direction.y * direction.y))
        {
            isMovingInLoop = true;
        }
        else
        {
            direction = distance * direction / std::sqrt(direction.x * direction.x + direction.y * direction.y);
            bossSprite.move(direction);
        }
    }
    else
    {
        moveInLoop(deltaTime);
    }
}

void Boss::updateDefeatedState(float deltaTime)
{
    defeatTimer += deltaTime;

    if (defeatTimer >= 2.5f)
    {
        // After 3 seconds, make the boss fall off the screen slowly
        bossSprite.move(0, moveSpeed * deltaTime + 5.f);
    }

}

void Boss::render(sf::RenderTarget& target)
{
    target.draw(bossSprite);

    if (!isDefeated)
    {
        target.draw(this->fire);
    }
}

void Boss::takeDamage(float damage)
{
    health -= damage;
    if (health <= 0 && !isDefeated)
    {
        isDefeated = true;
        defeatTimer = 0.f;
    }
}

bool Boss::isAlive() const
{
    return health > 0;
}

void Boss::moveInLoop(float deltaTime)
{
    // Move in a circular loop
    angle += 0.5f * deltaTime; // Adjust loop speed as needed

    float x = loopCenter.x + (loopRadius + 50) * std::cos(angle);
    float y = loopCenter.y + loopRadius * std::sin(angle);

    bossSprite.setPosition(x, y);

    if (bossSprite.getPosition().y >= 850)
    {
        this->movingDown = false;
    }

    if (bossSprite.getPosition().y <= 200)
    {
        this->movingDown = true;
    }

    if (movingDown)
    {
        loopCenter.y++;
    }
    else
    {
        loopCenter.y--;
    }

    this->fire.setPosition(
        this->bossSprite.getPosition().x + this->bossSprite.getGlobalBounds().width / 2 - 17.f,
        this->bossSprite.getPosition().y + this->bossSprite.getGlobalBounds().height - 277.f
    );
}
