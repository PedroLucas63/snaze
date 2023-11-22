#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Scene.hpp"
#include "Snake.hpp"
#include "Fruit.hpp"
#include "Utils.hpp"
#include <stack>

class Player {
   public:
   Player() = default;
   Player(Scene scene_) : m_scene(scene_), m_side(None) {}

   virtual void thinking(Snake snake_, Fruit fruit_);
   std::stack<Side> getMoves() const;
   void clearMoves();

   protected:
   Scene m_scene;
   Side m_side;
   std::stack<Side> m_moves;
};

#endif /// PLAYER_HPP_