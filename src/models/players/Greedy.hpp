#ifndef GREEDY_PLAYER_HPP_
#define GREEDY_PLAYER_HPP_

#include "Player.hpp"

constexpr int const DISTANCE_DEFAULT { 1 };
constexpr int const DISTANCE_WALL { -1 };
constexpr int const DISTANCE_NON { 0 };

class GreedyPlayer : public Player {
   public:
   GreedyPlayer() : Player() { }
   GreedyPlayer(Scene scene_) : Player(scene_) { }

   void thinking(Snake snake_, Fruit fruit_) override;

   private:
   void fillDistances(std::vector<std::vector<int>>& distances_,
     Position position_, int distance_base_ = DISTANCE_DEFAULT);
   bool nonHasConflict(Snake snake_, Side side_);
};

#endif /// GREEDY_PLAYER_HPP_