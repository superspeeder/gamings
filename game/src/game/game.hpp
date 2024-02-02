#pragma once

#include <kat/engine.hpp>

#include <spdlog/spdlog.h>

namespace game {
    class Game {
      public:
        Game();

        ~Game();

        Game(const Game &other)     = delete;
        Game(Game &&other) noexcept = default;

        Game &operator=(const Game &other)     = delete;
        Game &operator=(Game &&other) noexcept = default;

        int run();

        [[nodiscard]] const std::shared_ptr<spdlog::logger> &get_logger() const { return m_logger; }

      private:
        std::shared_ptr<spdlog::logger> m_logger;

        std::shared_ptr<kat::Engine> m_engine;
    };
} // namespace game
