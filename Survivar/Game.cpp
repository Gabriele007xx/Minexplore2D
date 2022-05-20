#include "Game.h"
Game::Game()
{

}

Game::~Game()
{
	delete this->window;
}
void Game::update()
{

}
void Game::render()
{
	this->window->clear();
	this->window->draw(world.getSprite());
	this->window->draw(player.getSprite());
	this->window->display();
}
void Game::init()
{
	world.init("Assets/graphics/bg.png");
	player.init("Assets/graphics/Player_0.png");
	this->window = new sf::RenderWindow(sf::VideoMode(1000, 696), "Survivar", sf::Style::Default);
}
const bool Game::running() const
{
	return this->window->isOpen();
}
void Game::pollEvents()
{
	while (this->window->pollEvent(this->evento))
	{
		switch (this->evento.type)
		{
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				if (this->evento.key.code == sf::Keyboard::Escape)
				{
					this->window->close();
				}
				break;
		}
	}
}

Player Game::getPlayer()
{
	return this->player;
}

