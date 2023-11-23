#include "Greedy.hpp"
#include <map>
#include <algorithm>
#include <iostream>

/// TODO: CHECK LAST_SIDE, COMPACT CODE

void GreedyPlayer::thinking(Snake snake_, Fruit fruit_) {
   std::vector<std::vector<int>> distances {m_scene.getHeight(), std::vector<int>(m_scene.getWidth(), DISTANCE_NON)};
   fillDistances(distances, fruit_.getPosition());

   for (auto i : distances) {
      for (auto c : i) {
         std::cout << c << " ";
      }
      std::cout << "\n";
   }

   Snake my_snake {snake_}; 

   while (my_snake.getHead() != fruit_.getPosition()) {
      Position head {my_snake.getHead()};

      std::map<Side, int> side_distance;


      Position left {movementToSide(head, Left)};
      if (distances[left.y][left.x] != DISTANCE_WALL) {
         bool collision {false};
         for (size_t body {1}; body != my_snake.getSize(); ++body) {
            if (left == my_snake.getTail(body)) {
               collision = true;
               break;
            }
         }

         if (not collision) {
            side_distance[Left] = distances[left.y][left.x];
         }
      }

      Position right {movementToSide(head, Right)};
      if (distances[right.y][right.x] != DISTANCE_WALL) {
         bool collision {false};
         for (size_t body {1}; body != my_snake.getSize(); ++body) {
            if (right == my_snake.getTail(body)) {
               collision = true;
               break;
            }
         }

         if (not collision) {
            side_distance[Right] = distances[right.y][right.x];
         }
      }

      Position up {movementToSide(head, Up)};
      if (distances[up.y][up.x] != DISTANCE_WALL) {
         bool collision {false};
         for (size_t body {1}; body != my_snake.getSize(); ++body) {
            if (up == my_snake.getTail(body)) {
               collision = true;
               break;
            }
         }

         if (not collision) {
            side_distance[Up] = distances[up.y][up.x];
         }
      }

      Position down {movementToSide(head, Down)};
      if (distances[down.y][down.x] != DISTANCE_WALL) {
         bool collision {false};
         for (size_t body {1}; body != my_snake.getSize(); ++body) {
            if (down == my_snake.getTail(body)) {
               collision = true;
               break;
            }
         }

         if (not collision) {
            side_distance[Down] = distances[down.y][down.x];
         }
      }

      if (side_distance.empty()) {
         m_moves.push(Left);
         break;
      } else {
         auto minimum_distance { std::min_element(side_distance.begin(), side_distance.end(), [](auto const& left, auto const& right) {
            return left.second < right.second;
         })};

         m_moves.push(minimum_distance->first);
         my_snake.toWalk(minimum_distance->first);
      }
   }
}

void GreedyPlayer::fillDistances(std::vector<std::vector<int>>& distances_, Position position_, int distance_base_) {
   Element element {m_scene.getElement(position_)};

   if (element == Wall || element == InvisibleWall) {
      distances_[position_.y][position_.x] = DISTANCE_WALL;
      return;
   }

   distances_[position_.y][position_.x] = distance_base_;

   Position left {movementToSide(position_, Left)};
   if (distances_[left.y][left.x] == DISTANCE_NON) {
      fillDistances(distances_, left, distance_base_ + 1);
   }

   Position right {movementToSide(position_, Right)};
   if (distances_[right.y][right.x] == DISTANCE_NON) {
      fillDistances(distances_, right, distance_base_ + 1);
   }

   Position up {movementToSide(position_, Up)};
   if (distances_[up.y][up.x] == DISTANCE_NON) {
      fillDistances(distances_, up, distance_base_ + 1);
   }

   Position down {movementToSide(position_, Down)};
   if (distances_[down.y][down.x] == DISTANCE_NON) {
      fillDistances(distances_, down, distance_base_ + 1);
   }
}
