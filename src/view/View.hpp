/**
 * @file View.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Header file for the View class, responsible for rendering the Snaze
 * game.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef VIEW_HPP_
#define VIEW_HPP_

#include "Game.hpp"
#include <string>

constexpr int const WIDTH { 60 }; ///< The width of the game board. >/
constexpr int const WIDTH_SCORE { 10 }; ///< The width of the score display. >/

/**
 * @class View
 * @brief Responsible for rendering the Snaze game and providing visual feedback
 * to the player.
 */
class View {
   public:
   /**
    * @brief Renders help information with default settings.
    * @param default_fps The default frames per second.
    * @param default_lives The default number of lives.
    * @param default_foods The default number of foods.
    * @param default_player The default player name.
    */
   void renderHelp(int default_fps, int default_lives, int default_foods,
     std::string default_player);

   /**
    * @brief Renders game information, including levels, lives, and foods.
    * @param levels_ The current game level.
    * @param lives_ The remaining lives.
    * @param foods_ The remaining foods.
    */
   void renderInformations(size_t levels_, int lives_, int foods_);

   /**
    * @brief Renders the pause screen.
    */
   void renderPause();

   /**
    * @brief Renders the gameplay screen.
    * @param game_ The current game state.
    * @param lives_base_ The base number of lives.
    * @param foods_ The remaining foods.
    */
   void renderPlay(Game game_, int lives_base_, int foods_);

   /**
    * @brief Renders the end-of-game screen with the final game situation.
    * @param game_ The final game state.
    * @param lives_base_ The base number of lives.
    * @param foods_ The remaining foods.
    * @param winner_ Indicates if the player won the game.
    */
   void renderSituation(Game game_, int lives_base_, int foods_, bool winner_);

   private:
   /**
    * @brief Renders the title of the game.
    */
   void renderTitle();

   /**
    * @brief Renders gaming information during gameplay.
    * @param game_ The current game state.
    * @param lives_base_ The base number of lives.
    * @param foods_ The remaining foods.
    */
   void renderGamingInfo(Game game_, int lives_base_, int foods_);

   /**
    * @brief Renders the game board.
    * @param game_ The current game state.
    */
   void renderBoard(Game game_);

   /**
    * @brief Renders a line of the game board.
    * @param game_ The current game state.
    * @param y_ The y-coordinate of the line to render.
    */
   void renderBoardLine(Game game_, int y_);

   /**
    * @brief Renders the icons for the snake, fruit, and road at a specific
    * position on the board.
    * @param snake_ The snake object.
    * @param fruit_ The fruit object.
    * @param road_position_ The position of the road icon.
    */
   void renderRoadIcon(Snake snake_, Fruit fruit_, Position road_position_);

   /**
    * @brief Renders a block indicating the game result (winner or loser).
    * @param winner_ Indicates if the player won the game.
    */
   void renderBlock(bool winner_);
};

#endif /// VIEW_HPP_
