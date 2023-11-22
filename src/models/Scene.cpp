#include "Scene.hpp"

std::vector<std::vector<char>> Scene::getBoard() const {
   return m_board;
}

Element Scene::getElement(int x_, int y_) const {
   return charToElement(m_board[y_][x_]);
}

Element Scene::getElement(Position position_) const {
   return charToElement(m_board[position_.y][position_.x]);
}

size_t Scene::getWidth() const {
   return m_board.front().size();
}

size_t Scene::getHeight() const {
   return m_board.size();
}

Position Scene::getBegin() const {
   return m_begin;
}

Position Scene::searchBegin() const {
   for (auto y { 0 }; y != getHeight(); ++y) {
      for (auto x { 0 }; x != getWidth(); ++x) {
         if (charToElement(m_board[y][x]) == Begin) {
            return Position(x, y);
         }
      }
   }

   return {-1, -1};
}