#ifndef VIEW_HPP_
#define VIEW_HPP_

#include "Game.hpp"
#include <string>

constexpr int const WIDTH { 60 };
constexpr int const WIDTH_SCORE { 10 };

class View {
   public:
   void renderHelp(int default_fps, int default_lives, int default_foods,
     std::string default_player);
   void renderInformations(size_t levels_, int lives_, int foods_);
   void renderPlay(Game game_, int lives_base_, int foods_);
   void renderWin();
   void renderLost();

   private:
   void renderTitle();
   void renderGamingInfo(Game game_, int lives_base_, int foods_);
   void renderBoard(Game game_);
   void renderRoadIcon(Snake snake_, Fruit fruit_, Position road_position_);
};

#endif /// VIEW_HPP_