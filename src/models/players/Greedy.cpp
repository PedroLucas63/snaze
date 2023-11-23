#include "Greedy.hpp"
#include <algorithm>
#include <iostream>
#include <map>

void GreedyPlayer::thinking(Snake snake_, Fruit fruit_) {
   clearMoves();
   std::vector<std::vector<int>> distances { m_scene.getHeight(),
      std::vector<int>(m_scene.getWidth(), DISTANCE_NON) };
   fillDistances(distances, fruit_.getPosition());

   Snake my_snake { snake_ };

   while (my_snake.getHead() != fruit_.getPosition()) {
      Position head { my_snake.getHead() };

      std::map<Side, int> side_distance;

      if (nonHasConflict(my_snake, Left)) {
         Position left { movementToSide(my_snake.getHead(), Left) };
         side_distance[Left] = distances[left.y][left.x];
      }

      if (nonHasConflict(my_snake, Right)) {
         Position right { movementToSide(my_snake.getHead(), Right) };
         side_distance[Right] = distances[right.y][right.x];
      }

      if (nonHasConflict(my_snake, Up)) {
         Position up { movementToSide(my_snake.getHead(), Up) };
         side_distance[Up] = distances[up.y][up.x];
      }

      if (nonHasConflict(my_snake, Down)) {
         Position down { movementToSide(my_snake.getHead(), Down) };
         side_distance[Down] = distances[down.y][down.x];
      }

      if (side_distance.empty()) {
         m_moves.push(Left); /// Undefined movement
         break;
      } else {
         auto minimum_distance { std::min_element(side_distance.begin(),
           side_distance.end(),
           [](auto const& left, auto const& right) {
              return left.second < right.second;
           }) };

         m_moves.push(minimum_distance->first);
         my_snake.toWalk(minimum_distance->first);
      }
   }
}

void GreedyPlayer::fillDistances(std::vector<std::vector<int>>& distances_,
  Position position_, int distance_base_) {
   Element element { m_scene.getElement(position_) };

   if (element == Wall || element == InvisibleWall) {
      distances_[position_.y][position_.x] = DISTANCE_WALL;
      return;
   }

   distances_[position_.y][position_.x] = distance_base_;

   Position left { movementToSide(position_, Left) };
   if (distances_[left.y][left.x] == DISTANCE_NON) {
      fillDistances(distances_, left, distance_base_ + 1);
   }

   Position right { movementToSide(position_, Right) };
   if (distances_[right.y][right.x] == DISTANCE_NON) {
      fillDistances(distances_, right, distance_base_ + 1);
   }

   Position up { movementToSide(position_, Up) };
   if (distances_[up.y][up.x] == DISTANCE_NON) {
      fillDistances(distances_, up, distance_base_ + 1);
   }

   Position down { movementToSide(position_, Down) };
   if (distances_[down.y][down.x] == DISTANCE_NON) {
      fillDistances(distances_, down, distance_base_ + 1);
   }
}

bool GreedyPlayer::nonHasConflict(Snake snake_, Side side_) {
   Position move { movementToSide(snake_.getHead(), side_) };

   if (m_scene.getElement(move.x, move.y) == Wall) {
      return false;
   } else if (not cumulativeMovements(side_, snake_.getSide())) {
      return false;
   }

   for (size_t body { 1 }; body != snake_.getSize(); ++body) {
      if (move == snake_.getTail(body)) {
         return false;
         break;
      }
   }

   return true;
}
