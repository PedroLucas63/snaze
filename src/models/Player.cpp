/**
 * @file Player.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation file for the Player class and its methods in the Snaze
 * game.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "Player.hpp"

/// @brief Determine the next move of the player.
/// @param snake_ The current state of the snake.
/// @param fruit_ The current state of the fruit.
/// @return True if the player has made a valid move, false otherwise.
bool Player::thinking(Snake snake_, Fruit fruit_) {
   m_moves.push(Right);
   return true;
}

/// @brief Get the queue of pending moves for the player.
/// @return The queue of pending moves.
std::queue<Side> Player::getMoves() const { return m_moves; }

/// @brief Get the front movement in the queue without removing it.
/// @return The front movement in the queue.
Side Player::frontMovement() const { return m_moves.front(); }

/// @brief Remove the front movement from the queue.
void Player::popMovement() { m_moves.pop(); }

/// @brief Clear all moves in the queue.
void Player::clearMoves() {
   while (not m_moves.empty()) {
      m_moves.pop();
   }
}
