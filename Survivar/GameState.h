#pragma once
#include "State.h"
class GameState :
    public State
{
private:
    void initKeybinds();
    Player* player;
    void initTe();
    void initPl();
public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedkeys, std::stack<State*>* state_s);
    virtual ~GameState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target);
};

