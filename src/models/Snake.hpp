#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "Utils.hpp"
#include <vector>

class Snake {
   public:
   Snake() = default;
   Snake(Position const& position_);
   Snake(int x_, int y_);

   Position getHead() const;
   Position getTail(size_t index_) const;
   Side getSide() const;
   size_t getSize() const;

   void restart(Position const& position_);
   void toGrow();

   void toWalk(Side side_);
   bool hasConflict() const;

   private:
   std::vector<Position> m_body;
   Position m_tail_position;
   Side m_side;

   void walk();
};

#endif /// SNAKE_HPP_