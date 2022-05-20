#pragma once
#include "SFML-2.5.1/include/SFML/Graphics.hpp"
class Player
{
public:
	
	float getSpeed();
	int getCurrentHealth();
	int getMaxHealth();
	void init(std::string texture_location);
	sf::Sprite getSprite();
private:
	sf::Texture player_t;
	sf::Sprite spr_p;
	int MAX_HEALTH = 100;
	float CURRENT_H = 100;
	float Speed = 50.0f;
};

