/**
 * @file main.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Main entry point for the Snaze game.
 * @version 1.0
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "GameController.hpp"

/**
 * @brief The main function of the Snaze game.
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return An integer representing the exit status of the program.
 */
int main(int argc, char* argv[]) {
   // Create an instance of the GameController using the Singleton pattern
   GameController& game { GameController::getInstance() };

   // Initialize the game with command-line arguments
   game.initialize(argc, argv);

   // Main game loop
   while (not game.isOver()) {
      // Process user input and update game state
      game.process();
      // Update the game logic
      game.update();
      // Render the current game state
      game.render();
   }

   // Clean up and release resources
   game.destruct();

   // Return exit successful program execution
   return EXIT_SUCCESS;
}
