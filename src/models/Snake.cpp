/**
 * @file Snake.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation file for the Snake class and its methods in the Snaze
 * game.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "Snake.hpp"

/// @brief Parameterized constructor for Snake.
/// @param position_ The initial position of the snake.
Snake::Snake(Position const& position_) : m_side(None) {
   m_body.push_back(position_);
   m_tail_position = getHead();
}

/// @brief Parameterized constructor for Snake.
/// @param x_ The initial x-coordinate of the snake.
/// @param y_ The initial y-coordinate of the snake.
Snake::Snake(int x_, int y_) : m_side(None) {
   m_body.push_back(Position(x_, y_));
   m_tail_position = getHead();
}

/// @brief Get the head position of the snake.
/// @return The position of the snake's head.
Position Snake::getHead() const { return m_body.front(); }

/// @brief Get the position of a specific segment of the snake's body.
/// @param index_ The index of the body segment.
/// @return The position of the specified body segment.
Position Snake::getTail(size_t index_) const { return m_body[index_]; }

/// @brief Get the current direction or side of the snake.
/// @return The current side or direction of the snake.
Side Snake::getSide() const { return m_side; }

/// @brief Get the current size of the snake.
/// @return The current size of the snake.
size_t Snake::getSize() const { return m_body.size(); }

/// @brief Restart the snake at a new position.
/// @param position_ The new position for the snake.
void Snake::restart(Position const& position_) {
   m_body.assign({ position_ });
   m_side = None;
}

/// @brief Increase the size of the snake.
void Snake::toGrow() { m_body.push_back(m_tail_position); }

/// @brief Move the snake in the specified direction.
/// @param side_ The direction in which to move the snake.
void Snake::toWalk(Side side_) {
   m_tail_position = m_body.back();

   if (cumulativeMovements(side_, m_side)) {
      m_side = side_;
   }

   walk();
}

/// @brief Check if the snake has conflicts, such as colliding with walls or
/// itself.
/// @return True if there are conflicts, false otherwise.
bool Snake::hasConflict() const {
   Position head { getHead() };

   for (auto index { 1 }; index != getSize(); ++index) {
      if (head == m_body[index]) {
         return true;
      }
   }

   return false;
}

/// @brief Move the snake one step forward in its current direction.
void Snake::walk() {
   for (auto index { getSize() - 1 }; index != 0; --index) {
      m_body[index] = m_body[index - 1];
   }

   m_body.front() = movementToSide(m_body.front(), m_side);
}
