#include "Fruit.hpp"
#include <cstdlib>
#include <ctime>

Fruit::Fruit(int width_, int height_) : m_width(width_), m_height(height_) {
   std::srand(std::time(nullptr));
   randomPosition();
}

Position Fruit::getPosition() const { return m_position; }
void Fruit::randomPosition() {
   int x { std::rand() % m_width };
   int y { std::rand() % m_height };

   m_position = Position(x, y);
}

void Fruit::setSceneSize(int width_, int height_) {
   m_width = width_;
   m_height = height_;
}
