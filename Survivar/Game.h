#pragma once
#include "World.h"
#include "Player.h"
class Game
{
private:
	World world;
	sf::RenderWindow* window = nullptr;
	sf::Event evento;
	Player player;
	
public:
	Game();
	virtual ~Game();
	const bool running() const;
	void update();
	void render();
	void init();
	void pollEvents();
	Player getPlayer();
};

