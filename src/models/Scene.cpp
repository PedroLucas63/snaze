#include "Scene.hpp"

std::vector<std::vector<char>> Scene::getBoard() const { return m_board; }

Element Scene::getElement(int x_, int y_) const {
   return charToElement(m_board[y_][x_]);
}

Element Scene::getElement(Position position_) const {
   return charToElement(m_board[position_.y][position_.x]);
}

size_t Scene::getWidth() const { return m_board.front().size(); }

size_t Scene::getHeight() const { return m_board.size(); }

Position Scene::getBegin() const { return m_begin; }

bool Scene::validate() const {
   int begins { 0 };
   int y { 0 }, x { 0 };

   for (auto line : m_board) {
      for (auto column : line) {
         Element element { charToElement(column) };

         if (element == Unknown) {
            return false;
         } else if (element == Begin) {
            ++begins;
         }

         if (y == 0 || y == getHeight() - 1) {
            if (element != Wall && element != InvisibleWall) {
               return false;
            }
         } else if (x == 0 || x == getWidth() - 1) {
            if (element != Wall && element != InvisibleWall) {
               return false;
            }
         }

         ++x;
      }

      x = 0;
      ++y;
   }

   return begins == 1;
}

Position Scene::searchBegin() const {
   for (auto y { 0 }; y != getHeight(); ++y) {
      for (auto x { 0 }; x != getWidth(); ++x) {
         if (charToElement(m_board[y][x]) == Begin) {
            return Position(x, y);
         }
      }
   }

   return { -1, -1 };
}