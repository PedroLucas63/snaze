/**
 * @file GameController.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Header file for the GameController class, managing the game's flow and
 * interactions.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */

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

constexpr int const DEFAULT_FPS { 24 }; ///< Default frames per second value.
constexpr int const MINIMUM_FPS { 1 }; ///< Minimum frames per second value.
constexpr int const MAXIMUM_FPS { 60 }; ///< Maximum frames per second value.

constexpr int const DEFAULT_LIVES { 5 }; ///< Default number of lives.
constexpr int const MINIMUM_LIVES { 1 }; ///< Minimum number of lives.
constexpr int const MAXIMUM_LIVES { 10 }; ///< Maximum number of lives.

constexpr int const DEFAULT_FOODS { 10 }; ///< Default number of foods.
constexpr int const MINIMUM_FOODS { 1 }; ///< Minimum number of foods.
constexpr int const MAXIMUM_FOODS { 24 }; ///< Maximum number of foods.

constexpr char const* DEFAULT_PLAYER { "random" }; ///< Default player type.
constexpr char const* GREEDY_PLAYER { "greedy" }; ///< Greedy player type.

/**
 * @class GameController
 * @brief Class managing the game's flow and interactions.
 */
class GameController {
   private:
   /**
    * @enum State
    * @brief Enumeration representing the possible states of the game.
    */
   enum State {
      Starting, ///< Starting state.
      Welcome, ///< Welcome state.
      Helping, ///< Helping state.
      Information, ///< Information state.
      Pause, ///< Pause state.
      Playing, ///< Playing state.
      Thinking, ///< Thinking state.
      Update, ///< Update state.
      Winner, ///< Winner state.
      Lost, ///< Lost state.
      Ending, ///< Ending state.
   };

   static GameController* m_instance; ///< Singleton instance.

   State m_state; ///< Current state of the game.
   std::vector<Scene> m_scenes; ///< Vector of scenes.
   size_t m_current_scene; ///< Index of the current scene.
   Game m_game; ///< The game object.
   std::unique_ptr<Player> m_player; ///< Pointer to the player object.
   View m_window; ///< The view object.

   ///< Config members >//
   bool m_help; ///< Flag indicating if help is requested.
   bool m_pause; ///< Flag indicating if the game is paused.
   int m_fps; ///< Frames per second setting.
   int m_lives; ///< Number of lives setting.
   int m_foods; ///< Number of foods setting.
   std::string m_type_player; ///< Type of player setting.
   std::string m_file; ///< File setting.

   /**
    * @brief Default constructor for GameController.
    */
   GameController() = default;

   /**
    * @brief Destructor for GameController.
    */
   ~GameController() = default;

   ///< Process functions >//
   /**
    * @brief Process command line arguments.
    */
   void processArguments();

   /**
    * @brief Process game data.
    */
   void processData();

   /**
    * @brief Process player movements.
    */
   void processMovements();

   /**
    * @brief Process game results.
    */
   void processResults();

   /**
    * @brief Read level data from a file.
    */
   void readLevelFile();

   /**
    * @brief Initialize the game.
    */
   void initGame();

   /**
    * @brief Create the player based on settings.
    */
   void createPlayer();

   /**
    * @brief Update the game state.
    */
   void updateGame();

   /**
    * @brief Pause the game.
    */
   void pause();

   /**
    * @brief Update the game situation.
    */
   void updateSituation();

   /**
    * @brief Check if the player won the game.
    * @return True if the player won, false otherwise.
    */
   bool winnerGame();

   public:
   /**
    * @brief Get the singleton instance of the GameController.
    * @return Reference to the GameController instance.
    */
   static GameController& getInstance();

   /**
    * @brief Destructor for GameController.
    */
   static void destruct();

   /**
    * @brief Initialize the GameController with command line arguments.
    * @param argc Number of command line arguments.
    * @param argv Array of command line arguments.
    */
   void initialize(int argc, char* argv[]);

   /**
    * @brief Check if the game is over.
    * @return True if the game is over, false otherwise.
    */
   bool isOver() const;

   /**
    * @brief Process the game (main loop).
    */
   void process();

   /**
    * @brief Update the game state.
    */
   void update();

   /**
    * @brief Render the game.
    */
   void render();
};

#endif /// GAME_CONTROLLER_HPP
