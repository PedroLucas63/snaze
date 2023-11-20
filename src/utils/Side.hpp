#ifndef SIDE_HPP_
#define SIDE_HPP_

#include "Position.hpp"

enum Side {
   Left,
   Right,
   Up,
   Down,
};

Position getMovement(Side side_);

#endif /// SIDE_HPP_