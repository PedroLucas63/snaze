#include "Cli.hpp"
#include "GameController.hpp"
#include "fstring.hpp"

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
         m_state = m_help ? Helping : Playing;
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

   std::vector<std::string> accepted_players { DEFAULT_PLAYER };
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

      while (std::getline(input_file, line) && board.size() != height) {
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
   m_game = Game(m_scenes.front(), m_lives, m_foods);
   m_current_scene = 0;
}

void GameController::createPlayer() {
   if (m_type_player == DEFAULT_PLAYER) {
      m_player = std::make_unique<RandomPlayer>();
   }
}

void GameController::updateGame() {
   ++m_current_scene;

   if (m_current_scene != m_scenes.size()) {
      m_game
        = Game(m_scenes[m_current_scene], m_lives, m_foods, m_game.getScore());
   }
}