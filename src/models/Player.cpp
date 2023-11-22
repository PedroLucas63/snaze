#include "Player.hpp"

void Player::thinking(Snake snake_, Fruit fruit_) { m_moves.push(Right); }

std::stack<Side> Player::getMoves() const { return m_moves; }

void Player::clearMoves() {
   while (not m_moves.empty()) {
      m_moves.pop();
   }
}