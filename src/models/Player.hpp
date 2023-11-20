#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Fruit.hpp"
#include "Scene.hpp"
#include "Snake.hpp"
#include "Utils.hpp"
#include <stack>

class Player {
   public:
   Player() = default;

   void thinking(Scene scene_, Fruit fruit_, Snake snake_);
   std::stack<Side> getMovements();

   private:
   std::stack<Side> m_movements;
   bool hasCollisionWithWall(Scene scene_, Fruit fruit_, Snake snake_);
};
#endif /// PLAYER_HPP_