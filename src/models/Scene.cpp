#include "Scene.hpp"

Scene::Scene(size_t width_, size_t height_) {
   m_blocks
     = std::vector<std::vector<char>>(height_, std::vector<char>(width_));
}

std::vector<char>& Scene::operator[](size_t y_) {
   return m_blocks[ y_ ];
}

char Scene::getBlock(size_t x_, size_t y_) {
   return m_blocks[ y_ ][ x_ ];
}

size_t Scene::getWidth() const {
   return m_blocks.front().size();
}

size_t Scene::getHeight() const {
   return m_blocks.size();
}