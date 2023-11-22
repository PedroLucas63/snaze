#ifndef POSITION_HPP_
#define POSITION_HPP_

#include "Side.hpp"

struct Position {
   int x;
   int y;

   Position(int x_ = int(), int y_ = int()) : x(x_), y(y_) { }
   bool operator==(Position const& other_);
   bool operator!=(Position const& other_);
};

Position movementToSide(Position position_, Side side_);

#endif /// POSITION_HPP_