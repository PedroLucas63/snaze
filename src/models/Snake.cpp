#include "Snake.hpp"

Snake::Snake(Position const& position_) : m_side(Right), m_moves(0) {
   m_body.push_back(position_);
}

Snake::Snake(int x_, int y_) : m_side(Right), m_moves(0) {
   m_body.push_back(Position(x_, y_));
}

Position Snake::getHead() const {
   return m_body.front();
}

Side Snake::getSide() const {
   return m_side;
}


size_t Snake::size() const {
   return m_body.size();
}

void Snake::addTail() {
   m_body.push_back(m_body.back());
}

void Snake::toWalk(Side side_) {
   if (m_moves != 0) {
      if (side_ == Left && m_side == Right) {
         return;
      } else if (side_ == Right && m_side == Left) {
         return;
      } else if (side_ == Up && m_side == Down) {
         return;
      } else if (side_ == Down && m_side == Up) {
         return;
      }
   }

   Position move {getMovement(side_)};

   for (auto index {m_body.size() - 1}; index != 0; --index) {
      m_body[index] = m_body[index - 1];
   }

   m_body.front() += move;
   m_side = side_;
   ++m_moves;
}

bool Snake::hasConflict() {
   Position head {getHead()};

   for (auto index {1}; index != m_body.size(); ++index) {
      if (head == m_body[index]) {
         return true;
      }
   }

   return false;
}
