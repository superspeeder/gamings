#pragma once

#include <spdlog/spdlog.h>

#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <string>

namespace kat {
    class Engine : public std::enable_shared_from_this<Engine> {
      public:
        ~Engine();

        static std::shared_ptr<Engine> init();

        static std::shared_ptr<Engine> get();

        std::shared_ptr<spdlog::logger> create_standard_logger(const std::string &name);

        [[nodiscard]] const std::shared_ptr<spdlog::logger> &get_logger() const { return m_logger; }

      private:
        inline static std::weak_ptr<Engine> s_engine;
        inline static bool                  s_init = false;

        Engine();

        std::shared_ptr<spdlog::sinks::stdout_color_sink_mt>  m_logging_stdout_sink;
        std::shared_ptr<spdlog::sinks::rotating_file_sink_mt> m_logging_file_sink;

        std::shared_ptr<spdlog::logger> m_logger;
    };


} // namespace kat
