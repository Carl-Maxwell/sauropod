#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

#include "Core.h"

namespace Sauropod {

	class SAUROPOD_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger()   { return s_EngineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define HZ_CORE_TRACE(...) ::Sauropod::Log::GetEngineLogger()->trace(__VA_ARGS__);
#define HZ_CORE_INFO(...)  ::Sauropod::Log::GetEngineLogger()->info(__VA_ARGS__);
#define HZ_CORE_WARN(...)  ::Sauropod::Log::GetEngineLogger()->warn(__VA_ARGS__);
#define HZ_CORE_ERROR(...) ::Sauropod::Log::GetEngineLogger()->error(__VA_ARGS__);
#define HZ_CORE_FATAL(...) ::Sauropod::Log::GetEngineLogger()->fatal(__VA_ARGS__);

// Client log macros
#define HZ_TRACE(...)      ::Sauropod::Log::GetClientLogger()->trace(__VA_ARGS__);
#define HZ_INFO(...)       ::Sauropod::Log::GetClientLogger()->info(__VA_ARGS__);
#define HZ_WARN(...)       ::Sauropod::Log::GetClientLogger()->warn(__VA_ARGS__);
#define HZ_ERROR(...)      ::Sauropod::Log::GetClientLogger()->error(__VA_ARGS__);
#define HZ_FATAL(...)      ::Sauropod::Log::GetClientLogger()->fatal(__VA_ARGS__);

