#ifndef GAME_CONTROLLER_HPP_
#define GAME_CONTROLLER_HPP_

#include "Game.hpp"
#include "Greedy.hpp"
#include "Random.hpp"
#include "Scene.hpp"
#include "Utils.hpp"
#include "View.hpp"
#include <fstream>
#include <memory>
#include <string>
#include <vector>

constexpr int const DEFAULT_FPS { 24 };
constexpr int const MINIMUM_FPS { 1 };
constexpr int const MAXIMUM_FPS { 60 };

constexpr int const DEFAULT_LIVES { 5 };
constexpr int const MINIMUM_LIVES { 1 };
constexpr int const MAXIMUM_LIVES { 10 };

constexpr int const DEFAULT_FOODS { 10 };
constexpr int const MINIMUM_FOODS { 1 };
constexpr int const MAXIMUM_FOODS { 24 };

constexpr char const* DEFAULT_PLAYER { "random" };
constexpr char const* GREEDY_PLAYER { "greedy" };

class GameController {
   private:
   enum State {
      Starting,
      Welcome,
      Helping,
      Information,
      Playing,
      Thinking,
      Update,
      Winner,
      Lost,
      Ending,
   };

   static GameController* m_instance;

   State m_state;
   std::vector<Scene> m_scenes;
   size_t m_current_scene;
   Game m_game;
   std::unique_ptr<Player> m_player;
   View m_window;

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
   void processData();
   void processMovements();
   void processResults();

   void readLevelFile();
   void initGame();
   void createPlayer();
   void updateGame();

   void pause();

   void updateSituation();

   bool winnerGame();

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