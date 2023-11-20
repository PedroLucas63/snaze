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

void GameController::initialize(int argc, char* argv[]) { }
bool GameController::isOver() const { return m_state == Ending; }

void GameController::process() { }
void GameController::update() { }
void GameController::render() { }