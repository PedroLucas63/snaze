#ifndef POSITION_HPP_
#define POSITION_HPP_

struct Position {
   int x;
   int y;

   Position(int x_ = int(), int y_ = int()) : x(x_), y(y_) { }

   bool operator==(Position const& other_) {
      return x == other_.x && y == other_.y;
   }

   bool operator!=(Position const& other_) {
      return x != other_.x || y != other_.y;
   }

   void operator+=(Position const& other_) {
      x += other_.x;
      y += other_.y;
   }
};

#endif /// POSITION_HPP_