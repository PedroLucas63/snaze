/**
 * @file Game.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation file for the Game class, representing the game state
 * and logic in the Snaze game.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "Game.hpp"

/// @brief Parameterized constructor for Game.
Game::Game(Scene scene_, int lives_, int max_size_, int score_)
    : m_scene(scene_), m_lives(lives_), m_max_size(max_size_), m_score(score_) {
   m_snake = Snake { m_scene.getBegin() };
   m_fruit = Fruit { m_scene.getWidth(), m_scene.getHeight() };
   randomFruitPosition();
}

/// @brief Get the current scene or board of the game.
Scene Game::getScene() const { return m_scene; }

/// @brief Get the current state of the snake in the game.
Snake Game::getSnake() const { return m_snake; }

/// @brief Get the current state of the fruit in the game.
Fruit Game::getFruit() const { return m_fruit; }

/// @brief Get the current number of lives for the snake.
int Game::getLives() const { return m_lives; }

/// @brief Get the current score of the game.
int Game::getScore() const { return m_score; }

/// @brief Check if the game is in a winning state.
bool Game::winner() const { return m_snake.getSize() == m_max_size; }

/// @brief Check if the game is in a defeated state.
bool Game::defeat() const { return not m_lives; }

/// @brief Move the snake in the specified direction.
/// @param side_ The direction to move the snake.
/// @return True if the move is valid, false otherwise.
bool Game::toWalk(Side side_) {
   m_snake.toWalk(side_);

   if (catchFruit()) {
      randomFruitPosition();
      m_score += m_snake.getSize() * SCORE_BASE;
      m_snake.toGrow();
   } else if (hasConflict()) {
      m_snake.restart(m_scene.getBegin());
      --m_lives;

      return false;
   }

   return true;
}

/// @brief Check if there is a conflict in the game (e.g., snake collision).
/// @return True if there is a conflict, false otherwise.
bool Game::hasConflict() const {
   auto head { m_snake.getHead() };

   if (m_snake.hasConflict()) {
      return true;
   } else if (m_scene.getElement(head.x, head.y) == Wall) {
      return true;
   }

   return false;
}

/// @brief Check if the snake catches the fruit in the game.
/// @return True if the snake catches the fruit, false otherwise.
bool Game::catchFruit() const {
   return m_snake.getHead() == m_fruit.getPosition();
}

/// @brief Randomly set the position of the fruit on the board.
void Game::randomFruitPosition() {
   bool valide { false };

   while (not valide) {
      m_fruit.randomPosition();

      Element element { m_scene.getElement(m_fruit.getPosition()) };

      if (element != Wall && element != InvisibleWall) {
         bool collision { false };

         for (size_t fill { 0 }; fill != m_snake.getSize(); ++fill) {
            if (m_fruit.getPosition() == m_snake.getTail(fill)) {
               collision = true;
            }
         }

         valide = not collision;
      }
   }
}
