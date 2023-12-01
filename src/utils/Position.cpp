/**
 * @file Position.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation file for the Position struct and related functions in
 * the Snaze game.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "Position.hpp"

/// @brief Equality operator for comparing two Position instances.
bool Position::operator==(Position const& other_) {
   return x == other_.x && y == other_.y;
}

/// @brief Inequality operator for comparing two Position instances.
bool Position::operator!=(Position const& other_) {
   return x != other_.x || y != other_.y;
}

/// @brief Moves a position in a specified direction.
Position movementToSide(Position position_, Side side_) {
   switch (side_) {
      case Left:
         position_.x--;
         break;
      case Right:
         position_.x++;
         break;
      case Up:
         position_.y--;
         break;
      case Down:
         position_.y++;
         break;
      default:
         break;
   }

   return position_;
}
