#ifndef VIEW_HPP_
#define VIEW_HPP_

#include <string>

constexpr int const WIDTH { 60 };

class View {
   public:
   void renderTitle();
   void renderHelp(int default_fps, int default_lives, int default_foods,
    std::string default_player);
};

#endif /// VIEW_HPP_