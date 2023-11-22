#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <vector>
#include "Utils.hpp"

class Scene {
   public:
   Scene() = default;
   Scene(std::vector<std::vector<char>> board_) : m_board(board_), m_begin(searchBegin()) {}
   
   std::vector<std::vector<char>> getBoard() const;
   Element getElement(int x_, int y_) const;
   Element getElement(Position position_) const;
   size_t getWidth() const;
   size_t getHeight() const;
   Position getBegin() const;

   private:
   std::vector<std::vector<char>> m_board;
   Position m_begin;

   Position searchBegin() const;
};

#endif /// SCENE_HPP_