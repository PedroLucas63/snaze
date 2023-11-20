#ifndef GAME_CONTROLLER_HPP_
#define GAME_CONTROLLER_HPP_

#include "Fruit.hpp"
#include "Scene.hpp"
#include "Snake.hpp"
#include "Utils.hpp"
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

   GameController(GameController const& other_) = delete;
   GameController& operator=(GameController const& other_) = delete;

   public:
   GameController() = default;
   ~GameController() = default;

   static GameController& getInstance();
   static void destruct();

   void initialize(int argc, char* argv[]);
   bool isOver() const;

   void process();
   void update();
   void render();
};

#endif /// GAME_CONTROLLER_HPP_