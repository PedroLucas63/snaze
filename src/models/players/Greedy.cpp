#include "Greedy.hpp"
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <stack>

void GreedyPlayer::thinking(Snake snake_, Fruit fruit_) {
   clearMoves();
   std::vector<std::vector<int>> distances { m_scene.getHeight(),
      std::vector<int>(m_scene.getWidth(), DISTANCE_NON) };
   fillDistances(distances, fruit_.getPosition());

   Snake my_snake { snake_ };
   std::stack<std::pair<std::map<Side, bool>, size_t>> decisions;
   std::deque<Side> moves;

   while (my_snake.getHead() != fruit_.getPosition()) {
      Position head { my_snake.getHead() };
      std::map<Side, int> side_distance;

      for (auto side : { Left, Right, Up, Down }) {
         if (nonHasConflict(my_snake, side)) {
            Position side_move { movementToSide(my_snake.getHead(), side) };
            side_distance[side] = distances[side_move.y][side_move.x];
         }
      }

      if (not side_distance.empty()) {
         auto minimum_distance { std::min_element(side_distance.begin(),
           side_distance.end(),
           [](auto const& left, auto const& right) {
              return left.second < right.second;
           }) };

         moves.push_back(minimum_distance->first);
         my_snake.toWalk(minimum_distance->first);

         if (side_distance.size() > 1) {
            std::map<Side, bool> decision;

            for (const auto& pair : side_distance) {
               decision[pair.first] = pair.first == minimum_distance->first;
            }

            decisions.push({ decision, moves.size() - 1 });
         }
      } else {
         if (decisions.empty()) {
            moves.push_back(Left);
            break;
         } else {
            Side possible_side { None };
            bool clear;

            do {
               clear = false;
               auto last_decision { decisions.top() };

               for (auto const& side : last_decision.first) {
                  if (not side.second) {
                     clear = true;
                     possible_side = side.first;
                     break;
                  }
               }

               if (not clear) {
                  decisions.pop();
               }
            } while (not clear && not decisions.empty());

            if (decisions.empty()) {
               moves.push_back(Left);
               break;
            } else {
               moves.erase(
                 moves.cbegin() + decisions.top().second, moves.end());
               my_snake = snake_;

               for (auto const& move : moves) {
                  my_snake.toWalk(move);
               }

               possible_side
                 = possible_side == None ? Left : possible_side; /// Undefined
               decisions.top().first[possible_side] = true;

               moves.push_back(possible_side);
               my_snake.toWalk(possible_side);
            }
         }
      }
   }

   /// Movement
   for (auto const& move : moves) {
      m_moves.push(move);
   }
}

void GreedyPlayer::fillDistances(
  std::vector<std::vector<int>>& distances_, Position position_) {
   std::queue<Position> queue;
   queue.push(position_);
   distances_[position_.y][position_.x] = DISTANCE_DEFAULT;

   while (not queue.empty()) {
      Position current { queue.front() };
      queue.pop();

      std::vector<Position> neighbors { movementToSide(current, Left),
         movementToSide(current, Right),
         movementToSide(current, Up),
         movementToSide(current, Down) };

      for (auto const& neighbor : neighbors) {
         if (neighbor.x >= 0 && neighbor.x < m_scene.getWidth()
           && neighbor.y >= 0 && neighbor.y < m_scene.getHeight()) {
            if (distances_[neighbor.y][neighbor.x] == DISTANCE_NON) {
               Element element { m_scene.getElement(neighbor) };

               if (element != Wall && element != InvisibleWall) {
                  distances_[neighbor.y][neighbor.x]
                    = distances_[current.y][current.x] + 1;
                  queue.push(neighbor);
               }
            }
         }
      }
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
