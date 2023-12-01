/**
 * @file Position.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Header file defining the Position struct and related functions for
 * representing coordinates in the Snaze game.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef POSITION_HPP_
#define POSITION_HPP_

#include "Side.hpp"

/**
 * @struct Position
 * @brief Represents a position with x and y coordinates in the Snaze game.
 */
struct Position {
   int x; ///< The x-coordinate of the position.
   int y; ///< The y-coordinate of the position.

   /**
    * @brief Default constructor for Position.
    * @param x_ The x-coordinate of the position.
    * @param y_ The y-coordinate of the position.
    */
   Position(int x_ = int(), int y_ = int()) : x(x_), y(y_) { }

   /**
    * @brief Equality operator for comparing two Position instances.
    * @param other_ The Position to compare with.
    * @return True if the positions are equal, false otherwise.
    */
   bool operator==(Position const& other_);

   /**
    * @brief Inequality operator for comparing two Position instances.
    * @param other_ The Position to compare with.
    * @return True if the positions are not equal, false otherwise.
    */
   bool operator!=(Position const& other_);
};

/**
 * @brief Converts a position to a new position based on a given direction.
 * @param position_ The original position.
 * @param side_ The direction in which to move from the original position.
 * @return The new position after moving in the specified direction.
 */
Position movementToSide(Position position_, Side side_);

#endif /// POSITION_HPP_
