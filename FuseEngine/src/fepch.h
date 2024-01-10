#pragma once

#ifdef FE_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
		#define NOMINMAX
	#endif
#endif

#define IMGUI_USER_CONFIG "fb/imgui/ImGuiConfig.h"

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "FuseEngine/Core/Core.h"

#include "FuseEngine/Core/Log.h"

#ifdef FE_PLATFORM_WINDOWS
	#include <Windows.h>
#endif