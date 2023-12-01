/**
 * @file Fruit.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation file for the Fruit class methods in the Snaze game.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "Fruit.hpp"
#include <random>

/// @brief Parameterized constructor for Fruit.
/// @param width_ The width of the game board.
/// @param height_ The height of the game board.
Fruit::Fruit(size_t width_, size_t height_)
    : m_width(width_), m_height(height_) {
   randomPosition();
}

/// @brief Get the current position of the fruit.
/// @return The position of the fruit.
Position Fruit::getPosition() const { return m_position; }

/// @brief Set a random position for the fruit on the game board.
void Fruit::randomPosition() {
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<int> dist_x(0, m_width - 1);
   std::uniform_int_distribution<int> dist_y(0, m_height - 1);

   m_position = Position(dist_x(gen), dist_y(gen));
}

/// @brief Set the size of the game board for proper positioning of the fruit.
/// @param width_ The width of the game board.
/// @param height_ The height of the game board.
void Fruit::setSceneSize(size_t width_, size_t height_) {
   m_width = width_;
   m_height = height_;
}
