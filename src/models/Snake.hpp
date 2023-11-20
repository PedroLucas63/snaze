#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "Utils.hpp"
#include <vector>

class Snake {
public:
Snake(Position const& position_);
Snake(int x_, int y_);

Position getHead() const;
Side getSide() const;

size_t size() const;
void addTail();

void toWalk(Side side_);
bool hasConflict();

private:
std::vector<Position> m_body;
Side m_side;
size_t m_moves;
};

#endif /// SNAKE_HPP_