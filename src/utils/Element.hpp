#ifndef ELEMENT_HPP_
#define ELEMENT_HPP_

enum Element {
   Wall,
   InvisibleWall,
   Road,
   SnakeHead,
   SnakeTail,
   Food,
   None,
};

Element charToElement(char character_);

#endif /// ELEMENT_HPP_