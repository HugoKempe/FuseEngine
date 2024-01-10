#include "fepch.h"
#include "Log.h"

#include <iostream>

namespace Fuse
{
    void Log::Init()
    {
        std::cout << "Logger Initialized\n";
    }

    void Log::Debug(const char* msg)
    {
        std::cout << "[DEBUG] -> " << msg << '\n';
    }
}