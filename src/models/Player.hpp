/**
 * @file Player.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Header file for the Player class, representing a player in the Snaze
 * game.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Fruit.hpp"
#include "Scene.hpp"
#include "Snake.hpp"
#include "Utils.hpp"
#include <queue>

/**
 * @class Player
 * @brief Base class representing a player (human or AI) in the Snaze game.
 */
class Player {
   public:
   /**
    * @brief Default constructor for Player.
    */
   Player() = default;

   /**
    * @brief Parameterized constructor for Player.
    * @param scene_ The scene or board on which the player operates.
    */
   Player(Scene scene_) : m_scene(scene_), m_side(None) { }

   /**
    * @brief Virtual method for determining the next move of the player.
    * @param snake_ The current state of the snake.
    * @param fruit_ The current state of the fruit.
    * @return True if the player has made a valid move, false otherwise.
    */
   virtual bool thinking(Snake snake_, Fruit fruit_);

   /**
    * @brief Get the queue of pending moves for the player.
    * @return The queue of pending moves.
    */
   std::queue<Side> getMoves() const;

   /**
    * @brief Get the front movement in the queue without removing it.
    * @return The front movement in the queue.
    */
   Side frontMovement() const;

   /**
    * @brief Remove the front movement from the queue.
    */
   void popMovement();

   /**
    * @brief Clear all moves in the queue.
    */
   void clearMoves();

   protected:
   Scene m_scene; ///< The scene or board on which the player operates.
   Side m_side; ///< The current direction or side of the player.
   std::queue<Side> m_moves; ///< The queue of pending moves for the player.
};

#endif /// PLAYER_HPP_
