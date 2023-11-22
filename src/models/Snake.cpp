#include "Snake.hpp"

Snake::Snake(Position const& position_) : m_side(None) {
   m_body.push_back(position_);
   m_tail_position = getHead();
}

Snake::Snake(int x_, int y_) : m_side(None) {
   m_body.push_back(Position(x_, y_));
   m_tail_position = getHead();
}

Position Snake::getHead() const {
   return m_body.front();
}

Side Snake::getSide() const {
   return m_side;
}

size_t Snake::getSize() const {
   return m_body.size();
}

void Snake::restart(Position const& position_) {
   m_body.assign({ position_ });
   m_side = None;
}

void Snake::toGrow() {
   m_body.push_back(m_tail_position);
}

void Snake::toWalk(Side side_) {
   m_tail_position = m_body.back();

   if (cumulativeMovements(side_, m_side)) {
      m_side = side_;
   }

   walk();
}

bool Snake::hasConflict() const {
   Position head { getHead() };

   for (auto index { 1 }; index != getSize(); ++index) {
      if (head == m_body[ index ]) {
         return true;
      }
   }

   return false;
}

void Snake::walk() {
   for (auto index { getSize() - 1 }; index != 0; --index) {
      m_body[index] = m_body[index - 1];
   }

   m_body.front() = movementToSide(m_body.front(), m_side);
}
