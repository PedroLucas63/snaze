#include "Cli.hpp"
#include "GameController.hpp"

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
         window.renderHelp(DEFAULT_FPS, DEFAULT_LIVES, DEFAULT_FOODS, DEFAULT_PLAYER);
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

   std::vector<std::string> accepted_players {DEFAULT_PLAYER};
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

   std::ifstream input_file {m_file};

   if (not input_file.is_open()) {
      m_help  = true;
   }
}
