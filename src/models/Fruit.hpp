#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include "Utils.hpp"

class Fruit {
public:
Fruit(size_t width_, size_t height_);

Position getPosition() const;
void randomPosition();

private:
Position m_position;
size_t m_width, m_height;
};

#endif /// FRUIT_HPP_