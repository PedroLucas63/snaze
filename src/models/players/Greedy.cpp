#include "Greedy.hpp"
#include <iostream>
#include <map>

bool GreedyPlayer::thinking(Snake snake_, Fruit fruit_) {
   Snake my_snake { snake_ };

   std::vector<Position> exclude;
   auto distances { fillDistances(fruit_.getPosition(), exclude) };
   std::queue<Side> moves;

   while (my_snake.getHead() != fruit_.getPosition()) {
      std::map<Side, int> move_distance;

      for (Side const& side : { Left, Right, Up, Down }) {
         Position move { movementToSide(my_snake.getHead(), side) };
         if (distances[move.y][move.x] != DISTANCE_WALL
           && cumulativeMovements(side, my_snake.getSide())) {
            move_distance[side] = distances[move.y][move.x];
         }
      }

      if (move_distance.empty()) {
         return false;
      }

      Side best_move { move_distance.begin()->first };

      for (auto const& move : move_distance) {
         if (move.second < move_distance[best_move]) {
            best_move = move.first;
         }
      }

      if (conflictHasBody(
            my_snake, movementToSide(my_snake.getHead(), best_move))) {
         exclude.push_back(movementToSide(my_snake.getHead(), best_move));
         distances = fillDistances(fruit_.getPosition(), exclude);
         my_snake = snake_;
         while (not moves.empty()) {
            moves.pop();
         }
      } else {
         my_snake.toWalk(best_move);
         moves.push(best_move);
      }
   }

   m_moves = moves;
   return true;
}

std::vector<std::vector<int>> GreedyPlayer::fillDistances(
  Position position_, std::vector<Position> non_used_) {
   std::vector<std::vector<int>> distances { m_scene.getHeight(),
      std::vector<int>(m_scene.getWidth(), DISTANCE_NON) };

   for (Position const& pos : non_used_) {
      distances[pos.y][pos.x] = DISTANCE_WALL;
   }

   std::queue<Position> queue;
   queue.push(position_);
   distances[position_.y][position_.x] = DISTANCE_DEFAULT;

   while (not queue.empty()) {
      Position current { queue.front() };
      queue.pop();

      std::vector<Position> neighbors { movementToSide(current, Left),
         movementToSide(current, Right),
         movementToSide(current, Up),
         movementToSide(current, Down) };

      for (Position const& neighbor : neighbors) {
         if (neighbor.x >= 0 && neighbor.x < m_scene.getWidth()
           && neighbor.y >= 0 && neighbor.y < m_scene.getHeight()) {
            if (distances[neighbor.y][neighbor.x] == DISTANCE_NON) {
               Element element { m_scene.getElement(neighbor) };

               if (element != Wall && element != InvisibleWall) {
                  distances[neighbor.y][neighbor.x]
                    = distances[current.y][current.x] + 1;
                  queue.push(neighbor);
               } else {
                  distances[neighbor.y][neighbor.x] = DISTANCE_WALL;
               }
            }
         }
      }
   }

   for (auto& line : distances) {
      for (auto& column : line) {
         if (column == DISTANCE_NON) {
            column = DISTANCE_WALL;
         }
      }
   }

   return distances;
}

bool GreedyPlayer::conflictHasBody(Snake snake_, Position position_) {
   for (size_t body { 1 }; body < snake_.getSize() - 1; ++body) {
      if (position_ == snake_.getTail(body)) {
         return true;
      }
   }

   return false;
}