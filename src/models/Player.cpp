#include "Player.hpp"

void Player::thinking(Snake snake_, Fruit fruit_) { m_moves.push(Right); }

std::queue<Side> Player::getMoves() const { return m_moves; }

Side Player::frontMovement() const { return m_moves.front(); }

void Player::popMovement() { m_moves.pop(); }

void Player::clearMoves() {
   while (not m_moves.empty()) {
      m_moves.pop();
   }
}