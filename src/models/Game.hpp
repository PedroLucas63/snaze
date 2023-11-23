#ifndef GAME_HPP_
#define GAME_HPP_

#include "Fruit.hpp"
#include "Scene.hpp"
#include "Snake.hpp"
#include "Utils.hpp"
#include <cstddef>

constexpr int const SCORE_BASE { 10 };

class Game {
   public:
   Game() = default;
   Game(Scene scene_, int lives_, int max_size_, int score_ = int());

   Scene getScene() const;
   Snake getSnake() const;
   Fruit getFruit() const;
   int getLives() const;
   int getScore() const;
   bool defeat() const;
   bool winner() const;

   bool toWalk(Side side_);
   bool hasConflict() const;
   bool catchFruit() const;

   private:
   Scene m_scene;
   Snake m_snake;
   Fruit m_fruit;
   int m_lives;
   int m_max_size;
   int m_score;

   void randomFruitPosition();
};

#endif /// GAME_HPP_