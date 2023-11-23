#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Fruit.hpp"
#include "Scene.hpp"
#include "Snake.hpp"
#include "Utils.hpp"
#include <queue>

class Player {
   public:
   Player() = default;
   Player(Scene scene_) : m_scene(scene_), m_side(None) { }

   virtual void thinking(Snake snake_, Fruit fruit_);
   std::queue<Side> getMoves() const;
   Side frontMovement() const;
   void popMovement();
   void clearMoves();

   protected:
   Scene m_scene;
   Side m_side;
   std::queue<Side> m_moves;
};

#endif /// PLAYER_HPP_