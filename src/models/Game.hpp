/**
 * @file Game.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Header file for the Game class, representing the game state and logic
 * in the Snaze game.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include "Fruit.hpp"
#include "Scene.hpp"
#include "Snake.hpp"
#include "Utils.hpp"
#include <cstddef>

///< Base score multiplier for the game. >/
constexpr int const SCORE_BASE { 10 };

/**
 * @class Game
 * @brief Class representing the game state and logic in the Snaze game.
 */
class Game {
   public:
   /**
    * @brief Default constructor for Game.
    */
   Game() = default;

   /**
    * @brief Parameterized constructor for Game.
    * @param scene_ The initial scene or board for the game.
    * @param lives_ The initial number of lives for the snake.
    * @param max_size_ The maximum size of the snake.
    * @param score_ The initial score for the game (default is 0).
    */
   Game(Scene scene_, int lives_, int max_size_, int score_ = int());

   /**
    * @brief Get the current scene or board of the game.
    * @return The current scene.
    */
   Scene getScene() const;

   /**
    * @brief Get the current state of the snake in the game.
    * @return The current snake.
    */
   Snake getSnake() const;

   /**
    * @brief Get the current state of the fruit in the game.
    * @return The current fruit.
    */
   Fruit getFruit() const;

   /**
    * @brief Get the current number of lives for the snake.
    * @return The current number of lives.
    */
   int getLives() const;

   /**
    * @brief Get the current score of the game.
    * @return The current score.
    */
   int getScore() const;

   /**
    * @brief Check if the game is in a defeated state.
    * @return True if the game is defeated, false otherwise.
    */
   bool defeat() const;

   /**
    * @brief Check if the game is in a winning state.
    * @return True if the game is won, false otherwise.
    */
   bool winner() const;

   /**
    * @brief Move the snake in the specified direction.
    * @param side_ The direction to move the snake.
    * @return True if the move is valid, false otherwise.
    */
   bool toWalk(Side side_);

   /**
    * @brief Check if there is a conflict in the game (e.g., snake collision).
    * @return True if there is a conflict, false otherwise.
    */
   bool hasConflict() const;

   /**
    * @brief Check if the snake catches the fruit in the game.
    * @return True if the snake catches the fruit, false otherwise.
    */
   bool catchFruit() const;

   private:
   Scene m_scene; ///< The current scene or board of the game.
   Snake m_snake; ///< The current state of the snake in the game.
   Fruit m_fruit; ///< The current state of the fruit in the game.
   int m_lives; ///< The current number of lives for the snake.
   int m_max_size; ///< The maximum size of the snake.
   int m_score; ///< The current score of the game.

   /**
    * @brief Randomly set the position of the fruit on the board.
    */
   void randomFruitPosition();
};

#endif /// GAME_HPP_
