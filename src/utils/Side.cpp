/**
 * @file Side.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation file for the Side enum and related functions in the
 * Snaze game.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "Side.hpp"

/// @brief Checks if two movements are cumulative (opposite directions).
bool cumulativeMovements(Side first_, Side second_) {
   if (first_ == Left && second_ == Right) {
      return false;
   } else if (first_ == Right && second_ == Left) {
      return false;
   } else if (first_ == Up && second_ == Down) {
      return false;
   } else if (first_ == Down && second_ == Up) {
      return false;
   }

   return true;
}
