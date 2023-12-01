
#ifndef GREEDY_HPP_
#define GREEDY_HPP_

#include "Player.hpp"
#include <vector>

constexpr int const DISTANCE_DEFAULT { 1 };
constexpr int const DISTANCE_WALL { -1 };
constexpr int const DISTANCE_NON { 0 };

class GreedyPlayer : public Player {
   public:
   GreedyPlayer() : Player() { }
   GreedyPlayer(Scene scene_) : Player(scene_) { }

   bool thinking(Snake snake_, Fruit fruit_) override;

   private:
   std::vector<std::vector<int>> fillDistances(
     Position position_, std::vector<Position> non_used_);
   bool conflictHasBody(Snake snake_, Position position_);
};
#endif /// GREEDY_HPP_