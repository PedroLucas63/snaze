#ifndef GAME_CONTROLLER_HPP_
#define GAME_CONTROLLER_HPP_

#include "Fruit.hpp"
#include "Scene.hpp"
#include "Snake.hpp"
#include "Utils.hpp"
#include <fstream>
#include <string>
#include <vector>
#include "View.hpp"

constexpr int const DEFAULT_FPS { 24 };
constexpr int const MINIMUM_FPS { 1 };
constexpr int const MAXIMUM_FPS { 60 };

constexpr int const DEFAULT_LIVES { 5 };
constexpr int const MINIMUM_LIVES { 1 };
constexpr int const MAXIMUM_LIVES { 10 };

constexpr int const DEFAULT_FOODS { 10 };
constexpr int const MINIMUM_FOODS { 1 };
constexpr int const MAXIMUM_FOODS { 24 };

constexpr char* const DEFAULT_PLAYER { "random" };

class GameController {
   private:
   enum State {
      Starting,
      Welcome,
      Helping,
      Playing,
      Thinking,
      Checking,
      Ending,
   };

   static GameController* m_instance;

   State m_state;
   std::vector<Scene> m_scenes;
   View window;
   Scene m_current_scene;
   Fruit m_fruit;
   Snake m_snake;

   ///< Config members >//
   bool m_help;
   int m_fps;
   int m_lives;
   int m_foods;
   std::string m_type_player;
   std::string m_file;

   GameController(GameController const& other_) = delete;
   GameController& operator=(GameController const& other_) = delete;

   ///< Process functions >//
   void processArguments();

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