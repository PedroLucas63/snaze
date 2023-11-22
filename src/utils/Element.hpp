#ifndef ELEMENT_HPP_
#define ELEMENT_HPP_

enum Element {
   Wall,
   InvisibleWall,
   Road,
   Begin,
   Unknown,
};

Element charToElement(char character_);

#endif /// ELEMENT_HPP_