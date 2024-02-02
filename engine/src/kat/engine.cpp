#include "kat/engine.hpp"

namespace kat {
    Engine::~Engine() {
        s_engine.reset();
        s_init = false;

        m_logger->info("Goodbye!");
    }

    std::shared_ptr<Engine> Engine::init() {
        if (!s_init) {
            auto engine = std::shared_ptr<Engine>(new Engine());
            s_engine    = engine;
            s_init      = true;
            return std::move(engine);
        }
        return get();
    }

    std::shared_ptr<Engine> Engine::get() {
        return s_engine.lock();
    }

    std::shared_ptr<spdlog::logger> Engine::create_standard_logger(const std::string &name) {
        return std::make_shared<spdlog::logger>(name,
                                                spdlog::sinks_init_list{ m_logging_stdout_sink, m_logging_file_sink });
    }

    Engine::Engine() {
        m_logging_stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        m_logging_file_sink =
            std::make_shared<spdlog::sinks::rotating_file_sink_mt>("logs/output.log", SIZE_MAX, 30, true);

        m_logger = create_standard_logger("katengine");

        m_logger->info("Hello!");
    }

} // namespace kat
