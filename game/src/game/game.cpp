#include "game/game.hpp"


namespace game {
    Game::Game() {
        m_engine = kat::Engine::init(); // engine must be stored in all things that depend on it to keep it alive long enough
        m_logger = m_engine->create_standard_logger("game");

        m_logger->info("Hello!");
    }

    Game::~Game() {
        m_logger->info("Goodbye!");
    }

    int Game::run() {
        return 0;
    }
} // namespace game

int main() {
    game::Game game;
    return game.run();
}
