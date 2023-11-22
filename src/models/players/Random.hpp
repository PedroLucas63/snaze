#ifndef RANDOM_PLAYER_HPP_
#define RANDOM_PLAYER_HPP_

#include "Player.hpp"

class RandomPlayer : public Player {
   public:
   RandomPlayer() : Player() { }
   RandomPlayer(Scene scene_) : Player(scene_) { }

   void thinking(Snake snake_, Fruit fruit_) override;
};

#endif /// RANDOM_PLAYER_HPP_