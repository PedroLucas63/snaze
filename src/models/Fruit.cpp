#include "Fruit.hpp"
#include <random>

Fruit::Fruit(size_t width_, size_t height_)
    : m_width(width_), m_height(height_) {
   randomPosition();
}

Position Fruit::getPosition() const { return m_position; }

void Fruit::randomPosition() {
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<int> dist_x(0, m_width - 1);
   std::uniform_int_distribution<int> dist_y(0, m_height - 1);

   m_position = Position(dist_x(gen), dist_y(gen));
}

void Fruit::setSceneSize(size_t width_, size_t height_) {
   m_width = width_;
   m_height = height_;
}
