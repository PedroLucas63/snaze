#include "Fruit.hpp"
#include <ctime>
#include <cstdlib>

Fruit::Fruit(size_t width_, size_t height_) : m_width(width_), m_height(height_) {
   std::srand(std::time(nullptr));
   randomPosition();
}

Position Fruit::getPosition() const {
   return m_position;
}
void Fruit::randomPosition() {
   int x { std::rand() % m_width };
   int y { std::rand() % m_height };

   m_position = Position(x, y);
}