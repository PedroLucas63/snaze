/**
 * @file Side.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Header file defining the Side enum and related functions for
 * representing directions or sides in the Snaze game.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef SIDE_HPP_
#define SIDE_HPP_

/**
 * @enum Side
 * @brief Represents different directions or sides in the Snaze game.
 */
enum Side {
   Left, ///< Represents the left direction.
   Right, ///< Represents the right direction.
   Up, ///< Represents the up direction.
   Down, ///< Represents the down direction.
   None, ///< Represents no specific direction.
};

/**
 * @brief Checks if two movements are cumulative (opposite directions).
 * @param first_ The first movement direction.
 * @param second_ The second movement direction.
 * @return True if the movements are cumulative, false otherwise.
 */
bool cumulativeMovements(Side first_, Side second_);

#endif /// SIDE_HPP_
