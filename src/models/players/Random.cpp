/**
 * @file Random.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation file for the RandomPlayer class and its methods in the
 * Snaze game.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "Random.hpp"
#include <map>
#include <random>

/// @brief Determine the next random move of the player.
/// @param snake_ The current state of the snake.
/// @param fruit_ The current state of the fruit.
/// @return True if the player has made a valid move, false otherwise.
bool RandomPlayer::thinking(Snake snake_, Fruit fruit_) {
   clearMoves();

   std::map<Side, int> moves {
      { Left, 1},
      {Right, 1},
      {   Up, 1},
      { Down, 1}
   };

   Side last_move { snake_.getSide() };
   for (auto& move : moves) {
      if (not cumulativeMovements(move.first, last_move)) {
         move.second = 0;
      }
   }

   Position head { snake_.getHead() };
   Position left { movementToSide(head, Left) };
   Position right { movementToSide(head, Right) };
   Position up { movementToSide(head, Up) };
   Position down { movementToSide(head, Down) };

   for (auto body { 1 }; body < snake_.getSize() - 1; ++body) {
      if (left == snake_.getTail(body)) {
         moves[Left] = 0;
      } else if (right == snake_.getTail(body)) {
         moves[Right] = 0;
      } else if (up == snake_.getTail(body)) {
         moves[Up] = 0;
      } else if (down == snake_.getTail(body)) {
         moves[Down] = 0;
      }
   }

   if (m_scene.getElement(left) == Wall
     || m_scene.getElement(left) == InvisibleWall) {
      moves[Left] = 0;
   }
   if (m_scene.getElement(right) == Wall
     || m_scene.getElement(right) == InvisibleWall) {
      moves[Right] = 0;
   }
   if (m_scene.getElement(up) == Wall
     || m_scene.getElement(up) == InvisibleWall) {
      moves[Up] = 0;
   }
   if (m_scene.getElement(down) == Wall
     || m_scene.getElement(down) == InvisibleWall) {
      moves[Down] = 0;
   }

   Position fruit_pos { fruit_.getPosition() };
   if (moves[Left] && head.x > fruit_pos.x) {
      moves[Left] += 2;
   }
   if (moves[Right] && head.x < fruit_pos.x) {
      moves[Right] += 2;
   }
   if (moves[Up] && head.y > fruit_pos.y) {
      moves[Up] += 2;
   }
   if (moves[Down] && head.y < fruit_pos.y) {
      moves[Down] += 2;
   }

   std::random_device rd;
   std::mt19937 gen(rd());

   std::vector<Side> sides;
   std::vector<int> weights;

   for (auto move : moves) {
      sides.push_back(move.first);
      weights.push_back(move.second);
   }

   std::discrete_distribution<> dist { weights.begin(), weights.end() };

   m_moves.push(sides[dist(gen)]);

   return true;
}
