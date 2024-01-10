#pragma message("Checking Platform!")
#ifdef FE_PLATFORM_WINDOWS
	#error "FUSE_ENGINE_PLATFORM_WINDOWS defined"
#endif



// Platform detection using predefined macros
#ifdef _WIN32
	/* Windows x64/x86 */
	#ifdef _WIN64
		/* Windows x64  */
	#define FE_PLATFORM_WINDOWS
	#define FE_CURRENT_PLATFORM "WINDOWS"
	#else
		/* Windows x86 */
	#error "x86 Builds are not supported!"
	#endif
#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>
	/* TARGET_OS_MAC exists on all the platforms
	 * so we must check all of them (in this order)
	 * to ensure that we're running on MAC
	 * and not some other Apple platform */
	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS simulator is not supported!"
	#elif TARGET_OS_IPHONE == 1
		#define FE_PLATFORM_IOS
		#define FE_CURRENT_PLATFORM "IOS"
		#error "IOS is not supported!"
	#elif TARGET_OS_MAC == 1
		#define FE_PLATFORM_MACOS
		#define FE_CURRENT_PLATFORM "MACOS"
		#error "MacOS is not supported!"
	#else
		#error "Unknown Apple platform!"
	#endif
 /* We also have to check __ANDROID__ before __linux__
  * since android is based on the linux kernel
  * it has __linux__ defined */
#elif defined(__ANDROID__)
	#define FE_PLATFORM_ANDROID
	#define FE_CURRENT_PLATFORM "ANDROID"
	#error "Android is not supported!"
#elif defined(__linux__)
	#define FE_PLATFORM_LINUX
	#define FE_CURRENT_PLATFORM "LINUX"
	#error "Linux is not supported!"
#else
	/* Unknown compiler/platform */
	#define FE_CURRENT_PLATFORM "UNKNOWN"
	#error "Unknown platform!"
#endif // End of platform detection

#ifdef FE_PLATFORM_WINDOWS
#pragma message("Platform = Windows")
#elif defined FE_PLATFORM_IOS
#pragma message("Platform = IOS")
#elif defined FE_PLATFORM_MACOS
#pragma message("Platform = MacOS")
#elif defined FE_PLATFORM_ANDROID
#pragma message("Platform = Android")
#elif defined FE_PLATFORM_LINUX
#pragma message("Platform = Linux")
#else
#pragma message("Platform = Unknown")
#endif