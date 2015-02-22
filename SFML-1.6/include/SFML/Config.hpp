ifndef SFML_CONFIG_HPP
#define SFML_CONFIG_HPP

////////////////////////////////////////////////////////////
// Identify the operating system
////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(__WIN32__)

    // Windows
    #define SFML_SYSTEM_WINDOWS
    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif
    #ifndef NOMINMAX
        #define NOMINMAX
    #endif

#elif defined(linux) || defined(__linux)

    // Linux
    #define SFML_SYSTEM_LINUX

#elif defined(__APPLE__) || defined(MACOSX) || defined(macintosh) || defined(Macintosh)

    // MacOS
    #define SFML_SYSTEM_MACOS

#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)

    // FreeBSD
    #define SFML_SYSTEM_FREEBSD

#else

    // Unsupported system
    #error This operating system is not supported by SFML library

#endif


////////////////////////////////////////////////////////////
// Define a portable debug macro
////////////////////////////////////////////////////////////
#if !defined(NDEBUG)

    #define SFML_DEBUG

#endif


////////////////////////////////////////////////////////////
// Define portable import / export macros
////////////////////////////////////////////////////////////
#if defined(SFML_SYSTEM_WINDOWS)

    #ifdef SFML_DYNAMIC

        // Windows platforms
        #ifdef SFML_EXPORTS

            // From DLL side, we must export
            #define SFML_API __declspec(dllexport)

        #else

            // From client application side, we must import
            #define SFML_API __declspec(dllimport)

        #endif

        // For Visual C++ compilers, we also need to turn off this annoying C4251 warning.
        // You can read lots ot different things about it, but the point is the code will
        // just work fine, and so the simplest way to get rid of this warning is to disable it
        #ifdef _MSC_VER

            #pragma warning(disable : 4251)

        #endif

    #else

        // No specific directive needed for static build
        #define SFML_API

    #endif

#else

    // Other platforms don't need to define anything
    #define SFML_API

#endif


////////////////////////////////////////////////////////////
// Define portable fixed-size types
////////////////////////////////////////////////////////////
#include <climits>

namespace sf
{
    // 8 bits integer types
    #if UCHAR_MAX == 0xFF
        typedef signed   char Int8;
        typedef unsigned char Uint8;
    #else
        #error No 8 bits integer type for this platform
    #endif

    // 16 bits integer types
    #if USHRT_MAX == 0xFFFF
        typedef signed   short Int16;
        typedef unsigned short Uint16;
    #elif UINT_MAX == 0xFFFF
        typedef signed   int Int16;
        typedef unsigned int Uint16;
    #elif ULONG_MAX == 0xFFFF
        typedef signed   long Int16;
        typedef unsigned long Uint16;
    #else
        #error No 16 bits integer type for this platform
    #endif

    // 32 bits integer types
    #if USHRT_MAX == 0xFFFFFFFF
        typedef signed   short Int32;
        typedef unsigned short Uint32;
    #elif UINT_MAX == 0xFFFFFFFF
        typedef signed   int Int32;
        typedef unsigned int Uint32;
    #elif ULONG_MAX == 0xFFFFFFFF
        typedef signed   long Int32;
        typedef unsigned long Uint32;
    #else
        #error No 32 bits integer type for this platform
    #endif

} // namespace sf


#endif // SFML_CONFIG_HPP
