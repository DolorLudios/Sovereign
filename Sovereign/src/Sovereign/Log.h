#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Sovereign {
	class SVG_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define SVG_CORE_CRITICAL(...)		::Sovereign::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define SVG_CORE_ERROR(...)			::Sovereign::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SVG_CORE_WARN(...)			::Sovereign::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SVG_CORE_INFO(...)			::Sovereign::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SVG_CORE_TRACE(...)			::Sovereign::Log::GetCoreLogger()->trace(__VA_ARGS__)

//Client log macros
#define SVG_CRITICAL(...)			::Sovereign::Log::GetClientLogger()->critical(__VA_ARGS__)
#define SVG_ERROR(...)				::Sovereign::Log::GetClientLogger()->error(__VA_ARGS__)
#define SVG_WARN(...)				::Sovereign::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SVG_INFO(...)				::Sovereign::Log::GetClientLogger()->info(__VA_ARGS__)
#define SVG_TRACE(...)				::Sovereign::Log::GetClientLogger()->trace(__VA_ARGS__)

