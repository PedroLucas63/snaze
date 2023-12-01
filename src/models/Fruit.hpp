/**
 * @file Fruit.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Header file for the Fruit class, representing the fruit in the Snaze
 * game.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include "Utils.hpp"
#include <cstddef>

/**
 * @class Fruit
 * @brief Class representing the fruit in the Snaze game.
 */
class Fruit {
   public:
   /**
    * @brief Default constructor for Fruit.
    */
   Fruit() = default;

   /**
    * @brief Parameterized constructor for Fruit.
    * @param width_ The width of the game board.
    * @param height_ The height of the game board.
    */
   Fruit(size_t width_, size_t height_);

   /**
    * @brief Get the current position of the fruit.
    * @return The position of the fruit.
    */
   Position getPosition() const;

   /**
    * @brief Set a random position for the fruit on the game board.
    */
   void randomPosition();

   /**
    * @brief Set the size of the game board for proper positioning of the fruit.
    * @param width_ The width of the game board.
    * @param height_ The height of the game board.
    */
   void setSceneSize(size_t width_, size_t height_);

   private:
   /**
    * @brief The current position of the fruit.
    */
   Position m_position;

   /**
    * @brief The width of the game board.
    */
   size_t m_width;

   /**
    * @brief The height of the game board.
    */
   size_t m_height;
};

#endif /// FRUIT_HPP_
