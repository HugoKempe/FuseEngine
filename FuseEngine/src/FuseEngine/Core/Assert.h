#pragma once

#include "FuseEngine/Core/Core.h"
#include "FuseEngine/Core/Log.h"
#include <filesystem>

#ifdef FUSE_ENGINE_ENABLE_ASSERTS

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define FE_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { FE##type##ERROR(msg, __VA_ARGS__); FE_DEBUGBREAK(); } }
	#define FE_INTERNAL_ASSERT_WITH_MSG(type, check, ...) FE_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define FE_INTERNAL_ASSERT_NO_MSG(type, check) FE_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", FE_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)
	
	#define FE_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define FE_INTERNAL_ASSERT_GET_MACRO(...) FE_EXPAND_MACRO( FE_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, FE_INTERNAL_ASSERT_WITH_MSG, FE_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define FE_ASSERT(...) FE_EXPAND_MACRO( FE_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define FE_CORE_ASSERT(...) FE_EXPAND_MACRO( FE_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define FE_ASSERT(...)
#define FE_CORE_ASSERT(...)
#endif