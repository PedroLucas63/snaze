#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include "Utils.hpp"

class Fruit {
   public:
   Fruit() = default;
   Fruit(int width_, int height_);

   Position getPosition() const;
   void randomPosition();

   void setSceneSize(int width_, int height_);

   private:
   Position m_position;
   int m_width, m_height;
};

#endif /// FRUIT_HPP_