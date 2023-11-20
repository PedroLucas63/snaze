#include "Element.hpp"

Element charToElement(char character_) {
   switch (character_) {
   case '#':
      return Wall;
      break;
   case '.':
      return InvisibleWall;
      break;
   case ' ':
      return Road;
      break;
   case '&':
      return SnakeHead;
      break;
   case '*':
      return SnakeTail;
      break;
   case 'o':
      return Food;
      break;
   default:
      break;
   }

   return None;
}
