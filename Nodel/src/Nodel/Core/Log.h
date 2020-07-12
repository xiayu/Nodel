#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Nodel {
	class Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return m_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return m_ClientLogger; }
	private:
		// create color multi threaded logger
		static std::shared_ptr<spdlog::logger> m_CoreLogger;
		static std::shared_ptr<spdlog::logger> m_ClientLogger;
	};

#define ND_TRACE(...) ::Nodel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ND_INFO(...) ::Nodel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ND_WARN(...) ::Nodel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ND_ERROR(...) ::Nodel::Log::GetCoreLogger()->error(__VA_ARGS__)

#define ND_TRACE_CLIENT(...) ::Nodel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ND_INFO_CLIENT(...) ::Nodel::Log::GetClientLogger()->info(__VA_ARGS__)
#define ND_WARN_CLIENT(...) ::Nodel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ND_ERROR_CLIENT(...) ::Nodel::Log::GetClientLogger()->error(__VA_ARGS__)

}
