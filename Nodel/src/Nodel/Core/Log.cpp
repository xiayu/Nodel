#include "ndpch.h"
#include "Log.h"

namespace Nodel {
	std::shared_ptr<spdlog::logger> Log::m_ClientLogger;
	std::shared_ptr<spdlog::logger> Log::m_CoreLogger;

	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");

		m_CoreLogger = spdlog::stdout_color_mt("Nodel");
		m_CoreLogger->set_level(spdlog::level::trace);

		m_ClientLogger = spdlog::stdout_color_mt("Client");
		m_ClientLogger->set_level(spdlog::level::trace);
	}
}
