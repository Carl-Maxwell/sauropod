#pragma once

#include <memory>

#include <spdlog/spdlog.h>

#include "core.h"

namespace sauropod {

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
#define HZ_CORE_TRACE(...) ::sauropod::Log::GetEngineLogger()->trace(__VA_ARGS__);
#define HZ_CORE_INFO(...)  ::sauropod::Log::GetEngineLogger()->info(__VA_ARGS__);
#define HZ_CORE_WARN(...)  ::sauropod::Log::GetEngineLogger()->warn(__VA_ARGS__);
#define HZ_CORE_ERROR(...) ::sauropod::Log::GetEngineLogger()->error(__VA_ARGS__);
#define HZ_CORE_FATAL(...) ::sauropod::Log::GetEngineLogger()->fatal(__VA_ARGS__);

// Client log macros
#define HZ_TRACE(...)      ::sauropod::Log::GetClientLogger()->trace(__VA_ARGS__);
#define HZ_INFO(...)       ::sauropod::Log::GetClientLogger()->info(__VA_ARGS__);
#define HZ_WARN(...)       ::sauropod::Log::GetClientLogger()->warn(__VA_ARGS__);
#define HZ_ERROR(...)      ::sauropod::Log::GetClientLogger()->error(__VA_ARGS__);
#define HZ_FATAL(...)      ::sauropod::Log::GetClientLogger()->fatal(__VA_ARGS__);

