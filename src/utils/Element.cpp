/**
 * @file Element.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation file for the Element enum and character-to-element conversion function in the Snaze game.
 * @version 1.0
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "Element.hpp"

/// @brief Converts a character to an Element enum.
/// @param character_ The input character to be converted.
/// @return The corresponding Element enum.
Element charToElement(char character_) {
   switch (character_) {
   case '#':
      return Wall; ///< Represents a wall element.
   case '.':
      return InvisibleWall; ///< Represents an invisible wall element.
   case ' ':
      return Road; ///< Represents a road element.
   case '&':
      return Begin; ///< Represents the beginning point element.
   default:
      break;
   }

   return Unknown; ///< Represents an unknown element.
}
