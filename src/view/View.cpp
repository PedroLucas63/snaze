#include "SnazeConfig.hpp"
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
     << "    --playertype <type> Type of snake intelligence: random. Default = "
     << default_player << ".\n";
}