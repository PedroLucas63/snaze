/**
 * @file Scene.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation file for the Scene class and its methods in the Snaze game.
 * @version 1.0
 * @date 2023-12-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Scene.hpp"

/// @brief Get the current board configuration.
std::vector<std::vector<char>> Scene::getBoard() const { return m_board; }

/// @brief Get the element at the specified coordinates on the board.
Element Scene::getElement(int x_, int y_) const {
   return charToElement(m_board[y_][x_]);
}

/// @brief Get the element at the specified position on the board.
Element Scene::getElement(Position position_) const {
   return charToElement(m_board[position_.y][position_.x]);
}

/// @brief Get the width of the board.
size_t Scene::getWidth() const { return m_board.front().size(); }

/// @brief Get the height of the board.
size_t Scene::getHeight() const { return m_board.size(); }

/// @brief Get the position of the snake's starting point on the board.
Position Scene::getBegin() const { return m_begin; }

/// @brief Validate the board configuration.
/// @return True if the board is valid, false otherwise.
bool Scene::validate() const {
   int begins { 0 };
   int y { 0 }, x { 0 };

   for (auto line : m_board) {
      for (auto column : line) {
         Element element { charToElement(column) };

         if (element == Unknown) {
            return false;
         } else if (element == Begin) {
            ++begins;
         }

         if (y == 0 || y == getHeight() - 1) {
            if (element != Wall && element != InvisibleWall) {
               return false;
            }
         } else if (x == 0 || x == getWidth() - 1) {
            if (element != Wall && element != InvisibleWall) {
               return false;
            }
         }

         ++x;
      }

      x = 0;
      ++y;
   }

   return begins == 1;
}

/// @brief Search for the starting point of the snake on the board.
/// @return The position of the snake's starting point.
Position Scene::searchBegin() const {
   for (auto y { 0 }; y != getHeight(); ++y) {
      for (auto x { 0 }; x != getWidth(); ++x) {
         if (charToElement(m_board[y][x]) == Begin) {
            return Position(x, y);
         }
      }
   }

   return { -1, -1 };
}
