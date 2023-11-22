#include "Position.hpp"

bool Position::operator==(Position const& other_) {
   return x == other_.x && y == other_.y;
}

bool Position::operator!=(Position const& other_) {
   return x != other_.x || y != other_.y;
}

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