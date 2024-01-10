#pragma once

#include <memory>

// Common defines
#define FE_EXPAND_MACRO(x) x
#define FE_STRINGIFY_MACRO(x) #x

#ifdef FUSE_ENGINE_DEBUG
	#if defined(FE_PLATFORM_WINDOWS)
		#define FE_DEBUGBREAK() __debugbreak()
	#elif defined(FE_PLATFORM_LINUX)
		#include <signal.h>
		#define HZ_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define FUSE_ENGINE_ENABLE_ASSERTS
#else
	#define FE_DEBUGBREAK()
#endif

#define BIT(x) (1 << x)

#define FE_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

#ifdef FUSE_ENGINE_DEBUG
#define FE_WRAP_DEBUG(x) x
#else
#define FE_WRAP_DEBUG(x)
#endif

namespace Fuse
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}

#include "FuseEngine/Core/Log.h"
#include "FuseEngine/Core/Assert.h"