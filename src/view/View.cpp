/**
 * @file View.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation file for the View class, responsible for rendering the
 * Snaze game and providing visual feedback to the player.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "SnazeConfig.hpp"
#include "Utils.hpp"
#include "View.hpp"
#include "fstring.hpp"
#include <iostream>
#include <sstream>

/// @brief Renders the title screen of the Snaze game.
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

   /// Generate and format the version information.
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

   /// Generate and format the author information.
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

   /// Print the formatted title screen.
   std::cout << top << '\n'
             << title << '\n'
             << author << '\n'
             << bottom << '\n';
}
/// @brief Render the help information.
void View::renderHelp(int default_fps, int default_lives, int default_foods,
  std::string default_player) {
   renderTitle(); /// Render title.

   /// Render command-line usage and options.
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
   std::cout << "    --playertype <type> Type of snake intelligence: random, "
                "greedy. Default = "
             << default_player << ".\n";
}

/// @brief Render game information during gameplay.
void View::renderInformations(size_t levels_, int lives_, int foods_) {
   std::cout << std::string(WIDTH, '-') << "\n";
   std::cout << "Levels loaded: " << levels_ << " | Snake lives: " << lives_
             << " | Apples to eat: " << foods_ << "\n";
   std::cout << std::string(WIDTH, '-') << "\n";
}

/// @brief Render the pause screen.
void View::renderPause() { std::cout << " >>> Press <ENTER> to continue!\n"; }

/// @brief Render the gameplay screen.
void View::renderPlay(Game game_, int lives_base_, int foods_) {
   renderTitle(); /// Render title.
   renderGamingInfo(game_, lives_base_, foods_); /// Render gaming information.
   renderBoard(game_); /// Render the game board.
}
/// @brief Render gaming information during gameplay.
void View::renderGamingInfo(Game game_, int lives_base_, int foods_) {
   size_t lives { static_cast<size_t>(game_.getLives()) };
   ext::fstring hearts;

   /// Generate and format heart icons based on the number of lives.
   for (int live { 0 }; live != lives_base_; ++live) {
      if (live < lives) {
         hearts += "♥";
      } else {
         hearts += "♡";
      }
   }

   hearts.color(ext::cfg::red);

   /// Format and color the score information.
   ext::fstring score { std::to_string(game_.getScore()) };
   score.align_right(WIDTH_SCORE);
   score.color(ext::cfg::blue);

   /// Format and color the foods eaten information.
   ext::fstring foods { std::to_string(game_.getSnake().getSize() - 1) };
   foods += " of " + std::to_string(foods_);
   foods.color(ext::cfg::yellow);

   /// Print the formatted gaming information.
   std::cout << "Lives: " << hearts << " | Score: " << score
             << " | Foods eaten: " << foods << "\n";
   std::cout << std::string(WIDTH, '-') << "\n\n";
}

/// @brief Render the game board.
void View::renderBoard(Game game_) {
   Scene scene { game_.getScene() };

   /// Iterate over each row and render the board lines.
   for (int y { 0 }; y != scene.getHeight(); ++y) {
      renderBoardLine(game_, y);
      std::cout << "\n";
   }
}
/// @brief Render a line of the game board.
void View::renderBoardLine(Game game_, int y_) {
   Scene scene { game_.getScene() };
   Fruit fruit { game_.getFruit() };
   Snake snake { game_.getSnake() };

   /// Iterate over each column and render the corresponding board elements.
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
            renderRoadIcon(snake, fruit, pos); /// Render road icon.
            break;
         case Begin:
            renderRoadIcon(
              snake, fruit, pos); /// Render road icon at the beginning.
            break;
         default:
            break;
      }
   }
}

/// @brief Render the icon for a position on the road.
void View::renderRoadIcon(Snake snake_, Fruit fruit_, Position road_position_) {
   if (snake_.getHead() == road_position_) {
      std::cout << "◊"; /// Render snake head icon.
      return;
   }

   /// Check if the position corresponds to any part of the snake's body.
   for (size_t body { 1 }; body != snake_.getSize(); ++body) {
      if (snake_.getTail(body) == road_position_) {
         std::cout << "●"; /// Render snake body icon.
         return;
      }
   }

   /// Check if the position corresponds to the fruit.
   if (fruit_.getPosition() == road_position_) {
      std::cout << ""; /// Render fruit icon.
   } else {
      std::cout << " "; /// Render empty road space.
   }
}

/// @brief Render the end-of-game screen with the final game situation.
void View::renderSituation(
  Game game_, int lives_base_, int foods_, bool winner_) {
   renderTitle(); /// Render title.
   renderGamingInfo(game_, lives_base_, foods_); /// Render gaming information.

   Scene scene { game_.getScene() };

   int height { 4 };

   int y_information { static_cast<int>((scene.getHeight() - height) / 2) };

   /// Iterate over each row and render the board lines or the result block.
   for (int y { 0 }; y < scene.getHeight(); ++y) {
      if (y == y_information) {
         renderBlock(winner_); /// Render the block indicating the game result.
         y += height - 1;
      } else {
         renderBoardLine(game_, y); /// Render the game board lines.
      }

      std::cout << "\n";
   }
}

/// @brief Render a block indicating the game result.
/// @param winner_ Indicates if the player won the game.
void View::renderBlock(bool winner_) {
   int width { WIDTH * 2 / 3 };

   std::ostringstream oss;
   oss << "┌";
   for (auto i { 0 }; i != width; ++i) {
      oss << "─";
   }
   oss << "┐";
   ext::fstring top { oss.str() };

   /// Generate and format the situation message based on the game result.
   oss.str("");
   oss << (winner_ ? "CONGRATULATIONS" : "SORRY") << ", anaconda "
       << (winner_ ? "WON" : "LOST") << "!";
   ext::fstring situation { oss.str() };
   situation.align_center(width);

   oss.str("");
   oss << "│" << situation << "│";
   situation = oss.str();

   /// Generate and format the thanks message.
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

   /// Print the formatted result block.
   std::cout << top << '\n' << situation << '\n' << thanks << '\n' << bottom;
}
