#include "GameState.h"


void GameState::initKeybinds()
{
	std::ifstream ifs("Config/games_keybind.ini");
	if (ifs.is_open())
	{
		std::string key = "";
		int key_val = 0;
		while (ifs >> key >> key_val)
		{
			this->keybinds[key] = key_val;
		}
	}


}

void GameState::initTe()
{
	if(this->textures["PLAYER_IDLE"].loadFromFile("Assets/graphics/Player_0.png"));
}

void GameState::initPl()
{
	this->player = new Player(0, 0, this->textures["PLAYER_IDLE"]);
}


GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedkeys, std::stack<State*>* state_s) : State(window, supportedkeys, state_s)
{
	this->initKeybinds();
	this->initTe();
	this->initPl();
}

GameState::~GameState()
{
	delete this->player;
}

void GameState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		this->endState();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->player->move(dt, -1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->player->move(dt, 1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->player->move(dt, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->player->move(dt, 0.f, 1.f);
	}
	
}

void GameState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->player->tick(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
this->player->render(target);
	
}
