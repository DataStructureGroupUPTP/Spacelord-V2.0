#include "Player.h"

void Player::initializeVariables()
{
    this->movementSpeed = 10.f;
    this->damage = 1.f;

    this->invincible = false;
    this->invincibilityDuration = 1.f;
    this->invincibilityTimer = 0.0f;

    this->attackCooldownMax = 25.f;
    this->attackCooldown = this->attackCooldownMax;

    this->hpMax = 5;
    this->hp = this->hpMax;

    this->shieldActive = false;
    this->shieldDuration = 5.0f; // Shield lasts for 5 seconds
    this->shieldTimer = 0.0f;
}

void Player::initializeTexture()
{
    // Load texture
    if (!this->shipFull.loadFromFile("Textures/Mainshipfix.png"))
    {
        std::cout << "TEXTURE::MAIN_SHIP::FAILED_TO_LOAD" << "\n";
    }

    if (!this->shipDamaged.loadFromFile("Textures/Mainshipdamage1.png"))
    {
        std::cout << "TEXTURE::MAIN_SHIP_DAMAGED_1::FAILED_TO_LOAD" << "\n";
    }

    if (!this->shipVeryDamaged.loadFromFile("Textures/Mainshipdamage2.png"))
    {
        std::cout << "TEXTURE::MAIN_SHIP_DAMAGED_2::FAILED_TO_LOAD" << "\n";
    }

    if (!this->shipEngine1.loadFromFile("Textures/Mainshipengine.png"))
    {
        std::cout << "TEXTURE::MAIN_SHIP_ENGINE::FAILED_TO_LOAD" << "\n";
    }

    if (!this->shipEngine1Fire.loadFromFile("Animations/Fireidle.png"))
    {
        std::cout << "TEXTURE::MAIN_SHIP_ENGINE_FIRE::FAILED_TO_LOAD" << "\n";
    }

    if (!this->shieldTexture.loadFromFile("Animations/Shield.png"))
    {
        std::cout << "TEXTURE::MAIN_SHIP_ENGINE_FIRE::FAILED_TO_LOAD" << "\n";
    }
}

void Player::initializeSprite()
{
    // Set texture to sprite
    this->ship.setTexture(this->shipFull);
    this->ship.setColor(sf::Color::Yellow);

    this->engine.setTexture(this->shipEngine1);

    // Resize
    this->ship.scale(2.25f, 2.25f);
    this->ship.setPosition(765.5f, 660.f);

    this->engine.setScale(2.25f, 2.25f);

    this->fire.setTexture(this->shipEngine1Fire);
    this->fireFrame = sf::IntRect(0, 0, 48, 48);
    this->fire.setTextureRect(this->fireFrame);
    this->fire.setScale(2.25f, 2.25f);

    this->shield.setTexture(this->shieldTexture);
    this->shieldFrame = sf::IntRect(0, 0, 64, 64);
    this->shield.setTextureRect(this->shieldFrame);
    this->shield.setScale(2.25f, 2.25f);
}

void Player::initializeAnimation()
{
    this->currentFrame = 0;
    this->animationTimer = 0.f;
    this->animationSpeed = 0.1f; // Speed of the animation

    this->currentFrameShield = 0;
    this->animationTimerShield = 0.f;
    this->animationSpeedShield = 0.075f;
}

// Constructors
Player::Player()
{
    this->initializeVariables();
    this->initializeTexture();
    this->initializeSprite();
    this->initializeAnimation();

    this->engine.setPosition(
        this->ship.getPosition().x + this->ship.getGlobalBounds().width / 2 - this->engine.getGlobalBounds().width / 2,
        this->ship.getPosition().y + this->ship.getGlobalBounds().height - 80.f
    );

    this->fire.setPosition(
        this->engine.getPosition().x + this->engine.getGlobalBounds().width / 2 - this->fire.getGlobalBounds().width / 2,
        this->engine.getPosition().y + this->engine.getGlobalBounds().height - 100.f
    );

    this->shield.setPosition(
        this->ship.getPosition().x + this->ship.getGlobalBounds().width / 2 - this->shield.getGlobalBounds().width / 2,
        this->ship.getPosition().y + this->ship.getGlobalBounds().height - 90.f
    );
}

Player::~Player()
{
}

const sf::Vector2f& Player::getPos() const
{
    return this->ship.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
    return this->ship.getGlobalBounds();
}

const int& Player::getHp() const
{
    return this->hp;
}

const int& Player::getHpMax() const
{
    return this->hpMax;
}

const float& Player::getMoveSpeed() const
{
    return this->movementSpeed;
}

const float& Player::getDamage() const
{
    return this->damage;
}

void Player::move(const float dirX, const float dirY)
{
    this->ship.move(dirX, dirY);

    this->engine.setPosition(
        this->ship.getPosition().x + this->ship.getGlobalBounds().width / 2 - this->engine.getGlobalBounds().width / 2,
        this->ship.getPosition().y + this->ship.getGlobalBounds().height - 80.f
    );

    this->fire.setPosition(
        this->engine.getPosition().x + this->engine.getGlobalBounds().width / 2 - this->fire.getGlobalBounds().width / 2,
        this->engine.getPosition().y + this->engine.getGlobalBounds().height - 100.f
    );

    this->shield.setPosition(
        this->ship.getPosition().x + this->ship.getGlobalBounds().width / 2 - this->shield.getGlobalBounds().width / 2,
        this->ship.getPosition().y + this->ship.getGlobalBounds().height - 90.f
    );
}

const bool Player::canAttack()
{
    if (this->attackCooldown >= this->attackCooldownMax)
    {
        this->attackCooldown = 0.f;
        return true;
    }

    return false;
}

void Player::setPosition(const sf::Vector2f pos)
{
    this->ship.setPosition(pos);

    this->engine.setPosition(
        this->ship.getPosition().x + this->ship.getGlobalBounds().width / 2 - this->engine.getGlobalBounds().width / 2,
        this->ship.getPosition().y + this->ship.getGlobalBounds().height - 80.f
    );

    this->fire.setPosition(
        this->engine.getPosition().x + this->engine.getGlobalBounds().width / 2 - this->fire.getGlobalBounds().width / 2,
        this->engine.getPosition().y + this->engine.getGlobalBounds().height - 100.f
    );

    this->shield.setPosition(
        this->ship.getPosition().x + this->ship.getGlobalBounds().width / 2 - this->shield.getGlobalBounds().width / 2,
        this->ship.getPosition().y + this->ship.getGlobalBounds().height - 90.f
    );
}

void Player::setPosition(const float x, const float y)
{
    this->ship.setPosition(x, y);

    this->engine.setPosition(
        this->ship.getPosition().x + this->ship.getGlobalBounds().width / 2 - this->engine.getGlobalBounds().width / 2,
        this->ship.getPosition().y + this->ship.getGlobalBounds().height - 80.f
    );

    this->fire.setPosition(
        this->engine.getPosition().x + this->engine.getGlobalBounds().width / 2 - this->fire.getGlobalBounds().width / 2,
        this->engine.getPosition().y + this->engine.getGlobalBounds().height - 100.f
    );

    this->shield.setPosition(
        this->ship.getPosition().x + this->ship.getGlobalBounds().width / 2 - this->shield.getGlobalBounds().width / 2,
        this->ship.getPosition().y + this->ship.getGlobalBounds().height - 90.f
    );
}

void Player::setHp(const int newhp)
{
    this->hp = newhp;

    if (this->hp >= 6)
    {
        this->hp = 5;
    }
    updateSprite();
}

void Player::loseHp(const int value)
{
    if (!invincible)
    {
        this->hp = this->hp - value;
        if (this->hp < 0)
        {
            this->hp = 0;
        }
        startInvincibility();
    }

    this->updateSprite();
}

bool Player::isInvincible() const
{
    return invincible;
}

void Player::startInvincibility()
{
    invincible = true;
    invincibilityTimer = 0.0f;
}

void Player::upgradeDamage()
{
    this->damage = this->damage + 0.25f;
    std::cout << this->damage << "\n";
}

void Player::upgradeAttackSpeed()
{
    this->attackCooldownMax = this->attackCooldownMax - 1.f;
}

void Player::updateAttackCooldown()
{
    if (this->attackCooldown < this->attackCooldownMax)
    {
        this->attackCooldown += 1.f;
    }
}

void Player::setAttackCooldown(float val)
{
    this->attackCooldown = val;
}

void Player::updateSprite()
{
    if (this->hp == 3 or this->hp == 2)
    {
        this->ship.setTexture(this->shipDamaged);
    }
    else if (this->hp == 1)
    {
        this->ship.setTexture(this->shipVeryDamaged);
    }
    else
    {
        this->ship.setTexture(this->shipFull);
    }
}

void Player::updateAnimation()
{
    this->animationTimer += this->animationSpeed;
    if (this->animationTimer >= 1.f)
    {
        this->animationTimer = 0.f;
        this->currentFrame++;
        if (this->currentFrame >= 3) // 3 frames
        {
            this->currentFrame = 0;
        }
        this->fireFrame.left = this->currentFrame * 48; // Frame width is 48
        this->fire.setTextureRect(this->fireFrame);
    }

}

void Player::updateAnimationShield()
{
    if (this->shieldActive)
    {
        this->animationTimerShield += this->animationSpeedShield;
        if (this->animationTimerShield >= 1.f)
        {
            this->animationTimerShield = 0.f;
            this->currentFrameShield++;
            if (this->currentFrameShield >= 8) // 8 frames
            {
                this->currentFrameShield = 0;
            }
            this->shieldFrame.left = this->currentFrameShield * 64; // Frame width is 64
            this->shield.setTextureRect(this->shieldFrame);
        }
    }
}

void Player::update()
{
    this->updateAttackCooldown();
    this->updateAnimation();
    this->updateAnimationShield();

    if (this->isInvincible() && !this->shieldActive)
    {
        invincibilityTimer += 0.01667f;
        if (invincibilityTimer >= invincibilityDuration)
        {
            invincible = false;
        }
    }

    if (this->shieldActive)
    {
        this->shieldTimer += 0.01667f; // Assuming update is called at approximately 60 FPS
        if (this->shieldTimer >= this->shieldDuration)
        {
            this->shieldActive = false;
            this->invincible = false;

        }
    }
}

void Player::render(sf::RenderTarget& target)
{
    target.draw(this->fire);
    target.draw(this->engine);
    target.draw(this->ship);
    if (this->shieldActive) // Render shield only if active
    {
        target.draw(this->shield);
    }
}

void Player::activateShield()
{
    if (!this->shieldActive) // Ensure shield can only be activated if not already active
    {
        this->shieldActive = true;
        this->shieldTimer = 0.0f;
        this->invincible = true;
    }
}
