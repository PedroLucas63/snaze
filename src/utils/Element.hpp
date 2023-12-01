/**
 * @file Element.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Header file defining the Element enum and a function for character to
 * Element conversion in the Snaze game.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef ELEMENT_HPP_
#define ELEMENT_HPP_

/**
 * @enum Element
 * @brief Represents different elements in the Snaze game.
 */
enum Element {
   Wall, ///< Represents a wall element.
   InvisibleWall, ///< Represents an invisible wall element.
   Road, ///< Represents a road element.
   Begin, ///< Represents the beginning point element.
   Unknown, ///< Represents an unknown element.
};

/**
 * @brief Converts a character to an Element enum.
 * @param character_ The input character to be converted.
 * @return The corresponding Element enum.
 */
Element charToElement(char character_);

#endif /// ELEMENT_HPP_
