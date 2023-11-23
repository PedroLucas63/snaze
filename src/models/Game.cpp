#include "Game.hpp"

Game::Game(Scene scene_, int lives_, int max_size_, int score_)
    : m_scene(scene_), m_lives(lives_), m_max_size(max_size_), m_score(score_) {
   m_snake = Snake { m_scene.getBegin() };
   m_fruit = Fruit { m_scene.getWidth(), m_scene.getHeight() };
   randomFruitPosition();
}

Scene Game::getScene() const { return m_scene; }

Snake Game::getSnake() const { return m_snake; }

Fruit Game::getFruit() const { return m_fruit; }

int Game::getLives() const { return m_lives; }

int Game::getScore() const { return m_score; }

bool Game::winner() const { return m_snake.getSize() == m_max_size; }

bool Game::defeat() const { return not m_lives; }

bool Game::toWalk(Side side_) {
   m_snake.toWalk(side_);

   if (catchFruit()) {
      randomFruitPosition();
      m_score += m_snake.getSize() * SCORE_BASE;
      m_snake.toGrow();
   } else if (hasConflict()) {
      m_snake.restart(m_scene.getBegin());
      --m_lives;

      return false;
   }

   return true;
}

bool Game::hasConflict() const {
   auto head { m_snake.getHead() };

   if (m_snake.hasConflict()) {
      return true;
   } else if (m_scene.getElement(head.x, head.y) == Wall) {
      return true;
   }

   return false;
}

bool Game::catchFruit() const {
   return m_snake.getHead() == m_fruit.getPosition();
}

void Game::randomFruitPosition() {
   m_fruit.randomPosition();

   while (m_scene.getElement(m_fruit.getPosition()) != Road) {
      m_fruit.randomPosition();
   }
}
