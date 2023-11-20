#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <vector>

class Scene {
   public:
   Scene() = default;
   Scene(size_t width_, size_t height_);
   std::vector<char>& operator[](size_t y_);

   char getBlock(size_t x_, size_t y_);
   size_t getWidth() const;
   size_t getHeight() const;

   private:
   std::vector<std::vector<char>> m_blocks;
};

#endif /// SCENE_HPP_