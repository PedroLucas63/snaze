#ifndef SIDE_HPP_
#define SIDE_HPP_

#include "Position.hpp"

enum Side {
   Left,
   Right,
   Up,
   Down,
   None,
};

bool cumulativeMovements(Side first_, Side second_);

#endif /// SIDE_HPP_