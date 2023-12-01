/**
 * @file Snake.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Header file for the Snake class, representing the snake entity in the
 * Snaze game.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "Utils.hpp"
#include <vector>

/**
 * @class Snake
 * @brief Represents the snake entity in the Snaze game.
 */
class Snake {
   public:
   /**
    * @brief Default constructor for Snake.
    */
   Snake() = default;

   /**
    * @brief Parameterized constructor for Snake.
    * @param position_ The initial position of the snake.
    */
   Snake(Position const& position_);

   /**
    * @brief Parameterized constructor for Snake.
    * @param x_ The initial x-coordinate of the snake.
    * @param y_ The initial y-coordinate of the snake.
    */
   Snake(int x_, int y_);

   /**
    * @brief Get the head position of the snake.
    * @return The position of the snake's head.
    */
   Position getHead() const;

   /**
    * @brief Get the position of a specific segment of the snake's body.
    * @param index_ The index of the body segment.
    * @return The position of the specified body segment.
    */
   Position getTail(size_t index_) const;

   /**
    * @brief Get the current direction or side of the snake.
    * @return The current side or direction of the snake.
    */
   Side getSide() const;

   /**
    * @brief Get the current size of the snake.
    * @return The current size of the snake.
    */
   size_t getSize() const;

   /**
    * @brief Restart the snake at a new position.
    * @param position_ The new position for the snake.
    */
   void restart(Position const& position_);

   /**
    * @brief Increase the size of the snake.
    */
   void toGrow();

   /**
    * @brief Move the snake in the specified direction.
    * @param side_ The direction in which to move the snake.
    */
   void toWalk(Side side_);

   /**
    * @brief Check if the snake has conflicts, such as colliding with walls or
    * itself.
    * @return True if there are conflicts, false otherwise.
    */
   bool hasConflict() const;

   private:
   std::vector<Position> m_body; ///< The segments of the snake's body.
   Position m_tail_position; ///< The position of the snake's tail.
   Side m_side; ///< The current direction or side of the snake.

   /**
    * @brief Move the snake one step forward in its current direction.
    */
   void walk();
};

#endif /// SNAKE_HPP_
