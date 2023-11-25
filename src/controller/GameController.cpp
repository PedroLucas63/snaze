#include "Cli.hpp"
#include "GameController.hpp"
#include "fstring.hpp"
#include <chrono>
#include <iostream>
#include <string>
#include <thread>

GameController* GameController::m_instance = nullptr;

GameController& GameController::getInstance() {
   if (m_instance == nullptr) {
      m_instance = new GameController;
   }

   return *m_instance;
}

void GameController::destruct() {
   if (m_instance != nullptr) {
      delete m_instance;
   }

   m_instance == nullptr;
}

void GameController::initialize(int argc, char* argv[]) {
   ext::CLI cli;

   cli.addArgument('h', "help");
   cli.addArgumentInteger('f', "fps", DEFAULT_FPS);
   cli.addArgumentInteger('l', "lives", DEFAULT_LIVES);
   cli.addArgumentInteger('F', "food", DEFAULT_LIVES);
   cli.addArgumentText('p', "playertype", DEFAULT_PLAYER);

   cli.parse(argc, argv);

   m_help = cli.receiveSimple("-h");
   m_fps = cli.receiveInteger("-f");
   m_lives = cli.receiveInteger("-l");
   m_foods = cli.receiveInteger("-F");
   m_type_player = cli.receiveText("-p");

   auto buffer { cli.receiveBuffer() };

   if (not buffer.empty()) {
      m_file = buffer.front();
   } else {
      m_help = true;
   }

   m_state = Starting;
}

bool GameController::isOver() const { return m_state == Ending; }

void GameController::process() {
   switch (m_state) {
      case Starting:
         processArguments();
         break;
      case Welcome:
         processData();
         break;
      case Pause:
         pause();
         break;
      case Thinking:
         processMovements();
         break;
      case Update:
         processResults();
         break;
      default:
         break;
   }
}

void GameController::update() {
   switch (m_state) {
      case Starting:
         m_state = Welcome;
         break;
      case Welcome:
         m_state = m_help ? Helping : Information;
         break;
      case Information:
         m_state = Pause;
         break;
      case Pause:
         m_state = Playing;
         break;
      case Playing:
         m_state = Thinking;
         break;
      case Thinking:
         m_state = Update;
         break;
      case Update:
         updateSituation();
         break;
      default:
         m_state = Ending;
         break;
   }
}

void GameController::render() {
   switch (m_state) {
      case Helping:
         m_window.renderHelp(
           DEFAULT_FPS, DEFAULT_LIVES, DEFAULT_FOODS, DEFAULT_PLAYER);
         break;
      case Information:
         m_window.renderInformations(m_scenes.size(), m_lives, m_foods);
         break;
      case Pause:
         m_window.renderPause();
         break;
      case Playing:
         m_window.renderPlay(m_game, m_lives, m_foods);
         std::this_thread::sleep_for(std::chrono::milliseconds(1000 / m_fps));
         break;
      case Winner:
         m_window.renderSituation(m_game, m_lives, m_foods, true);
         break;
      case Lost:
         m_window.renderSituation(m_game, m_lives, m_foods, false);
         break;
      default:
         break;
   }
}

///< Process functions >//
void GameController::processArguments() {
   if (m_fps < MINIMUM_FPS || m_fps > MAXIMUM_FPS) {
      m_fps = DEFAULT_FPS;
   }

   if (m_lives < MINIMUM_LIVES || m_lives > MAXIMUM_LIVES) {
      m_lives = DEFAULT_LIVES;
   }

   if (m_foods < MINIMUM_FOODS || m_foods > MAXIMUM_FOODS) {
      m_foods = DEFAULT_FOODS;
   }

   std::vector<std::string> accepted_players { DEFAULT_PLAYER, GREEDY_PLAYER };
   bool found { false };

   for (auto player : accepted_players) {
      if (m_type_player == player) {
         found = true;
         break;
      }
   }

   if (not found) {
      m_type_player = DEFAULT_PLAYER;
   }

   std::ifstream input_file { m_file };

   if (not input_file.is_open()) {
      m_help = true;
   }
}

void GameController::processData() {
   readLevelFile();

   if (not m_help) {
      initGame();
      createPlayer();
   }
}

void GameController::processMovements() {
   if (m_player->getMoves().empty()) {
      m_player->thinking(m_game.getSnake(), m_game.getFruit());
   }
}

void GameController::processResults() {
   m_pause = false;
   auto moves { m_player->getMoves() };

   if (m_game.winner()) {
      updateGame();
   } else {
      if (not m_game.toWalk(m_player->frontMovement())) {
         m_player->clearMoves();
      } else {
         m_player->popMovement();
      }
   }
}

void GameController::readLevelFile() {
   std::ifstream input_file { m_file };
   ext::fstring level_size;

   while (std::getline(input_file >> std::ws, level_size)) {
      int width, height;

      try {
         size_t position;
         height = std::stoi(level_size, &position);
         level_size.erase(level_size.cbegin(), level_size.cbegin() + position);
         width = std::stoi(level_size, &position);
      } catch (...) { break; }

      std::vector<std::vector<char>> board;
      ext::fstring line;

      while (board.size() != height && std::getline(input_file, line)) {
         std::vector<char> columns;

         for (auto column : line) {
            columns.push_back(column);
         }

         if (columns.size() != width) {
            break;
         } else {
            board.push_back(columns);
         }
      }

      if (board.size() != height) {
         break;
      } else {
         Scene scene { board };

         if (scene.validate()) {
            m_scenes.push_back(scene);
         } else {
            break;
         }
      }
   }

   if (m_scenes.empty()) {
      m_help = true;
   }
}

void GameController::initGame() {
   m_game = Game(m_scenes.front(), m_lives, m_foods + 1);
   m_current_scene = 0;
}

void GameController::createPlayer() {
   if (m_type_player == DEFAULT_PLAYER) {
      m_player = std::make_unique<RandomPlayer>(m_game.getScene());
   } else if (m_type_player == GREEDY_PLAYER) {
      m_player = std::make_unique<GreedyPlayer>(m_game.getScene());
   }
}

void GameController::updateGame() {
   ++m_current_scene;

   if (m_current_scene != m_scenes.size()) {
      m_pause = true;
      m_game = Game(
        m_scenes[m_current_scene], m_lives, m_foods + 1, m_game.getScore());
      createPlayer();
   }
}

void GameController::pause() {
   std::string buffer;
   std::getline(std::cin, buffer);
}

void GameController::updateSituation() {
   if (m_game.defeat()) {
      m_state = Lost;
   } else if (winnerGame()) {
      m_state = Winner;
   } else if (m_pause) {
      m_state = Pause;
   } else {
      m_state = Playing;
   }
}

bool GameController::winnerGame() { return m_current_scene == m_scenes.size(); }