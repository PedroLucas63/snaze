#ifndef GAME_HPP_
#define GAME_HPP_

#include "Scene.hpp"
#include "Snake.hpp"
#include "Fruit.hpp"
#include "Utils.hpp"
#include <cstddef>

constexpr uint const SCORE_BASE { 10 };

class Game {
   public:
   Game() = default;
   Game(Scene scene_, uint lives_, uint max_size_, uint score_ = uint()) : m_scene(scene_), m_snake(m_scene.getBegin()), m_fruit(m_scene.getWidth(), m_scene.getHeight()), m_lives(lives_), m_max_size(max_size_), m_score(score_) {}

   Scene getScene() const;
   Snake getSnake() const;
   Fruit getFruit() const;
   uint getLives() const;
   uint getScore() const;
   bool defeat() const;
   bool winner() const;

   void toWalk(Side side_);
   bool hasConflict() const;
   bool catchFruit() const;

   private:
   Scene m_scene;
   Snake m_snake;
   Fruit m_fruit;
   uint m_lives;
   uint m_max_size;
   uint m_score;

   void randomFruitPosition();
};

#endif /// GAME_HPP_