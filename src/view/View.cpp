#include "SnazeConfig.hpp"
#include "Utils.hpp"
#include "View.hpp"
#include "fstring.hpp"
#include <iostream>
#include <sstream>

void View::renderTitle() {
   int width_base { WIDTH - 2 };

   std::ostringstream oss;
   oss << "┌";
   for (auto i { 0 }; i != width_base; ++i) {
      oss << "─";
   }
   oss << "┐";
   ext::fstring top { oss.str() };
   top.style(ext::stl::bold);
   top.color(ext::cfg::blue);

   oss.str("");
   oss << "Snaze project v" << Snaze_VERSION_MAJOR << "."
       << Snaze_VERSION_MINOR;
   ext::fstring title { oss.str() };
   title.align_center(width_base);

   oss.str("");
   oss << "│" << title << "│";
   title = oss.str();
   title.style(ext::stl::bold);
   title.color(ext::cfg::blue);

   oss.str("");
   oss << "Pedro Lucas, (C) 2023";
   ext::fstring author { oss.str() };
   author.align_center(width_base);

   oss.str("");
   oss << "│" << author << "│";
   author = oss.str();
   author.style(ext::stl::bold);
   author.color(ext::cfg::blue);

   oss.str("");
   oss << "└";
   for (auto i { 0 }; i != width_base; ++i) {
      oss << "─";
   }
   oss << "┘";
   ext::fstring bottom { oss.str() };
   bottom.style(ext::stl::bold);
   bottom.color(ext::cfg::blue);

   std::cout << top << '\n'
             << title << '\n'
             << author << '\n'
             << bottom << '\n';
}

void View::renderHelp(int default_fps, int default_lives, int default_foods,
  std::string default_player) {
   renderTitle();

   std::cout << "Usage: snaze [<options>] <input_level_file>\n";
   std::cout << "  Game simulation options:\n";
   std::cout << "    --help Print this help text.\n";
   std::cout << "    --fps <num> Number of frames (board) presented per "
                "second. Default = "
             << default_fps << ".\n";
   std::cout
     << "    --lives <num> Number of lives the snake shall have. Default = "
     << default_lives << ".\n";
   std::cout << "    --food <num> Number of food pellets for the entire "
                "simulation. Default = "
             << default_foods << ".\n";
   std::cout
     << "    --playertype <type> Type of snake intelligence: random, greedy. Default = "
     << default_player << ".\n";
}

void View::renderInformations(size_t levels_, int lives_, int foods_) {
   std::cout << std::string(WIDTH, '-') << "\n";
   std::cout << "Levels loaded: " << levels_ << " | Snake lives: " << lives_
             << " | Apples to eat: " << foods_ << "\n";
   std::cout << std::string(WIDTH, '-') << "\n";
}

void View::renderPause() { std::cout << " >>> Press <ENTER> to continue!\n"; }

void View::renderPlay(Game game_, int lives_base_, int foods_) {
   renderTitle();
   renderGamingInfo(game_, lives_base_, foods_);
   renderBoard(game_);
}

void View::renderGamingInfo(Game game_, int lives_base_, int foods_) {
   size_t lives { static_cast<size_t>(game_.getLives()) };
   ext::fstring hearts;
   for (int live { 0 }; live != lives_base_; ++live) {
      if (live < lives) {
         hearts += "♥";
      } else {
         hearts += "♡";
      }
   }

   hearts.color(ext::cfg::red);

   ext::fstring score { std::to_string(game_.getScore()) };
   score.align_right(WIDTH_SCORE);
   score.color(ext::cfg::blue);

   ext::fstring foods { std::to_string(game_.getSnake().getSize() - 1) };
   foods += " of " + std::to_string(foods_);
   foods.color(ext::cfg::yellow);

   std::cout << "Lives: " << hearts << " | Score: " << score
             << " | Foods eaten: " << foods << "\n";
   std::cout << std::string(WIDTH, '-') << "\n\n";
}

void View::renderBoard(Game game_) {
   Scene scene { game_.getScene() };

   for (int y { 0 }; y != scene.getHeight(); ++y) {
      renderBoardLine(game_, y);
      std::cout << "\n";
   }
}

void View::renderBoardLine(Game game_, int y_) {
   Scene scene { game_.getScene() };
   Fruit fruit { game_.getFruit() };
   Snake snake { game_.getSnake() };

   for (int x { 0 }; x != scene.getWidth(); ++x) {
      Position pos { x, y_ };

      switch (scene.getElement(x, y_)) {
         case Wall:
            std::cout << "█";
            break;
         case InvisibleWall:
            std::cout << " ";
            break;
         case Road:
            renderRoadIcon(snake, fruit, pos);
            break;
         case Begin:
            renderRoadIcon(snake, fruit, pos);
            break;
         default:
            break;
      }
   }
}

void View::renderRoadIcon(Snake snake_, Fruit fruit_, Position road_position_) {
   if (snake_.getHead() == road_position_) {
      std::cout << "◊";
      return;
   }

   for (size_t body { 1 }; body != snake_.getSize(); ++body) {
      if (snake_.getTail(body) == road_position_) {
         std::cout << "●";
         return;
      }
   }

   if (fruit_.getPosition() == road_position_) {
      std::cout << "";
   } else {
      std::cout << " ";
   }
}

void View::renderSituation(
  Game game_, int lives_base_, int foods_, bool winner_) {
   renderTitle();
   renderGamingInfo(game_, lives_base_, foods_);

   Scene scene { game_.getScene() };

   int height { 4 };

   int y_information { static_cast<int>((scene.getHeight() - height) / 2) };

   for (int y { 0 }; y < scene.getHeight(); ++y) {
      if (y == y_information) {
         renderBlock(winner_);
         y += height - 1;
      } else {
         renderBoardLine(game_, y);
      }

      std::cout << "\n";
   }
}

void View::renderBlock(bool winner_) {
   int width { WIDTH * 2 / 3 };

   std::ostringstream oss;
   oss << "┌";
   for (auto i { 0 }; i != width; ++i) {
      oss << "─";
   }
   oss << "┐";
   ext::fstring top { oss.str() };

   oss.str("");
   oss << (winner_ ? "CONGRATULATIONS" : "SORRY") << ", anaconda "
       << (winner_ ? "WON" : "LOST");
   ext::fstring situation { oss.str() };
   situation.align_center(width);

   oss.str("");
   oss << "│" << situation << "│";
   situation = oss.str();

   oss.str("");
   oss << "Thanks for playing!";
   ext::fstring thanks { oss.str() };
   thanks.align_center(width);

   oss.str("");
   oss << "│" << thanks << "│";
   thanks = oss.str();

   oss.str("");
   oss << "└";
   for (auto i { 0 }; i != width; ++i) {
      oss << "─";
   }
   oss << "┘";
   ext::fstring bottom { oss.str() };

   std::cout << top << '\n' << situation << '\n' << thanks << '\n' << bottom;
}