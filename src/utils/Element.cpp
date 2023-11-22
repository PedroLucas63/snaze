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
      return Begin;
      break;
   default:
      break;
   }

   return Unknown;
}
