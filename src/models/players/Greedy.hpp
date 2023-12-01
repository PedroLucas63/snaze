/**
 * @file Greedy.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Header file for the GreedyPlayer class, a player in the Snaze game
 * that makes greedy moves based on the shortest path to the fruit.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef GREEDY_HPP_
#define GREEDY_HPP_

#include "Player.hpp"
#include <vector>

constexpr int const DISTANCE_DEFAULT { 1 }; ///< Default distance value. >/
///< Distance value representing a wall. >/
constexpr int const DISTANCE_WALL { -1 };
///< Distance value representing a non-used position. >/
constexpr int const DISTANCE_NON { 0 };

/**
 * @class GreedyPlayer
 * @brief A player class that makes greedy moves based on the shortest path to
 * the fruit.
 */
class GreedyPlayer : public Player {
   public:
   /**
    * @brief Default constructor for GreedyPlayer.
    */
   GreedyPlayer() : Player() { }

   /**
    * @brief Parameterized constructor for GreedyPlayer.
    * @param scene_ The scene or board on which the player operates.
    */
   GreedyPlayer(Scene scene_) : Player(scene_) { }

   /**
    * @brief Determine the next move of the player based on the shortest path
    * to the fruit.
    * @param snake_ The current state of the snake.
    * @param fruit_ The current state of the fruit.
    * @return True if the player has made a valid move, false otherwise.
    */
   bool thinking(Snake snake_, Fruit fruit_) override;

   private:
   /**
    * @brief Fill distances from the given position to other positions on the
    * board.
    * @param position_ The starting position.
    * @param non_used_ A vector of positions that are not used.
    * @return A 2D vector representing distances from the starting position.
    */
   std::vector<std::vector<int>> fillDistances(
     Position position_, std::vector<Position> non_used_);

   /**
    * @brief Check if the given position conflicts with the snake's body.
    * @param snake_ The current state of the snake.
    * @param position_ The position to check for conflicts.
    * @return True if the position conflicts with the snake's body, false
    * otherwise.
    */
   bool conflictHasBody(Snake snake_, Position position_);
};

#endif /// GREEDY_HPP_
