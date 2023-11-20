#include "Player.hpp"

void Player::thinking(Scene scene_, Fruit fruit_, Snake snake_) {
   m_movements.push(Right);
}

std::stack<Side> Player::getMovements() {
   std::stack<Side> moves { m_movements };

   while (!m_movements.empty()) {
      m_movements.pop();
   }

   return moves;
}

bool Player::hasCollisionWithWall(Scene scene_, Fruit fruit_, Snake snake_) {
   Position head { snake_.getHead() };
   Element block { charToElement(scene_[ head.y ][ head.x ]) };

   if (block == Wall || block == InvisibleWall) {
      return true;
   }

   return false;
}