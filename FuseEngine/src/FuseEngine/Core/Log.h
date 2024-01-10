#pragma once

#include "Core.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Fuse
{
    class Log
    {
    public:
        static void Init();

        static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    private:
        static Ref<spdlog::logger> s_CoreLogger;
        static Ref<spdlog::logger> s_ClientLogger;
    };
}

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
    return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream operator<<(OStream& os, const glm::mat<C, R, T>& matrix)
{
    return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream operator<<(OStream& os, const glm::qua<T, Q> quaternion)
{
    return os << glm::to_string(quaternion);
}

// Core log macros
#define FE_CORE_TRACE(...)		::Fuse::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FE_CORE_DEBUG(...)		::Fuse::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define FE_CORE_INFO(...)		::Fuse::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FE_CORE_WARN(...)		::Fuse::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FE_CORE_ERROR(...)		::Fuse::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FE_CORE_CRITICAL(...)	::Fuse::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define FE_TRACE(...)		    ::Fuse::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FE_DEBUG(...)		    ::Fuse::Log::GetClientLogger()->debug(__VA_ARGS__)
#define FE_INFO(...)		    ::Fuse::Log::GetClientLogger()->info(__VA_ARGS__)
#define FE_WARN(...)		    ::Fuse::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FE_ERROR(...)		    ::Fuse::Log::GetClientLogger()->error(__VA_ARGS__)
#define FE_CRITICAL(...)	    ::Fuse::Log::GetClientLogger()->critical(__VA_ARGS__)