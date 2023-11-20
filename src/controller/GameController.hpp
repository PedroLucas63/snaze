#ifndef GAME_CONTROLLER_HPP_
#define GAME_CONTROLLER_HPP_

#include "Utils.hpp"
#include "Fruit.hpp"
#include "Scene.hpp"
#include "Snake.hpp"
#include <vector>

class GameController {
private:
enum State {
   Starting,
   Welcome,
   Playing,
   Thinking,
   Checking,
   Ending,
};

static GameController* m_instance;

State m_state;
std::vector<Scene> m_scenes;
Scene m_current_scene;
Fruit m_fruit;
Snake m_snake;

public:
GameController& getInstance();
};

#endif /// GAME_CONTROLLER_HPP_