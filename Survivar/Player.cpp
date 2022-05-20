#include "Player.h"

float Player::getSpeed()
{
    return this->Speed;
}

int Player::getCurrentHealth()
{
    return this->CURRENT_H;
}

int Player::getMaxHealth()
{
    return this->MAX_HEALTH;
}

void Player::init(std::string texture_location)
{
    this->player_t.loadFromFile(texture_location);
    spr_p.setTexture(player_t);
}

sf::Sprite Player::getSprite()
{
    return this->spr_p;
}
