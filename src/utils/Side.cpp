#include "Side.hpp"

Position getMovement(Side side_) {
   switch (side_) {
   case Left:
      return Position(-1, 0);
      break;
   case Right:
      return Position(1, 0);
      break;
   case Up:
      return Position(0, 1);
      break;
   case Down:
      return Position(0, -1);
      break;
   default:
      break;
   }
}
