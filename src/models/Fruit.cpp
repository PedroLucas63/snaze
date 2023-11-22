#include "Fruit.hpp"
#include <random>

Fruit::Fruit(int width_, int height_) : m_width(width_), m_height(height_) {
   randomPosition();
}

Position Fruit::getPosition() const { return m_position; }

void Fruit::randomPosition() {
   std::random_device rand;
   std::mt19937 mt(rand);
   std::uniform_int_distribution gen_x(0, m_width - 1);
   std::uniform_int_distribution gen_y(0, m_height - 1);

   m_position = Position(gen_x(mt), gen_y(mt));
}

void Fruit::setSceneSize(int width_, int height_) {
   m_width = width_;
   m_height = height_;
}
