/**
 * @file Scene.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Header file for the Scene class, representing the game scene or board
 * in the Snaze game.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef SCENE_HPP_
#define SCENE_HPP_

#include "Utils.hpp"
#include <vector>

/**
 * @class Scene
 * @brief Represents the game scene or board in the Snaze game.
 */
class Scene {
   public:
   /**
    * @brief Default constructor for Scene.
    */
   Scene() = default;

   /**
    * @brief Parameterized constructor for Scene.
    * @param board_ The initial board configuration.
    */
   Scene(std::vector<std::vector<char>> board_)
       : m_board(board_), m_begin(searchBegin()) { }

   /**
    * @brief Get the current board configuration.
    * @return The current board configuration.
    */
   std::vector<std::vector<char>> getBoard() const;

   /**
    * @brief Get the element at the specified coordinates on the board.
    * @param x_ The x-coordinate of the element.
    * @param y_ The y-coordinate of the element.
    * @return The element at the specified coordinates.
    */
   Element getElement(int x_, int y_) const;

   /**
    * @brief Get the element at the specified position on the board.
    * @param position_ The position of the element.
    * @return The element at the specified position.
    */
   Element getElement(Position position_) const;

   /**
    * @brief Get the width of the board.
    * @return The width of the board.
    */
   size_t getWidth() const;

   /**
    * @brief Get the height of the board.
    * @return The height of the board.
    */
   size_t getHeight() const;

   /**
    * @brief Get the position of the snake's starting point on the board.
    * @return The position of the snake's starting point.
    */
   Position getBegin() const;

   /**
    * @brief Validate the board configuration.
    * @return True if the board is valid, false otherwise.
    */
   bool validate() const;

   private:
   std::vector<std::vector<char>> m_board; ///< The current board configuration.
   Position m_begin; ///< The position of the snake's starting point.

   /**
    * @brief Search for the starting point of the snake on the board.
    * @return The position of the snake's starting point.
    */
   Position searchBegin() const;
};

#endif /// SCENE_HPP_
