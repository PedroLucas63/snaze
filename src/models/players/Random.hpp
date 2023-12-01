/**
 * @file Random.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Header file for the RandomPlayer class, a derived class from Player,
 * representing a player with random moves in the Snaze game.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef RANDOM_PLAYER_HPP_
#define RANDOM_PLAYER_HPP_

#include "Player.hpp"

/**
 * @class RandomPlayer
 * @brief Derived class from Player representing a player with random moves in
 * the Snaze game.
 */
class RandomPlayer : public Player {
   public:
   /**
    * @brief Default constructor for RandomPlayer.
    */
   RandomPlayer() : Player() { }

   /**
    * @brief Parameterized constructor for RandomPlayer.
    * @param scene_ The scene or board on which the player operates.
    */
   RandomPlayer(Scene scene_) : Player(scene_) { }

   /**
    * @brief Determine the next random move of the player.
    * @param snake_ The current state of the snake.
    * @param fruit_ The current state of the fruit.
    * @return True if the player has made a valid move, false otherwise.
    */
   bool thinking(Snake snake_, Fruit fruit_) override;
};

#endif /// RANDOM_PLAYER_HPP_
