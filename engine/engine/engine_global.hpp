#ifndef ENGINE_GLOBAL_HPP
#define ENGINE_GLOBAL_HPP

#if defined(_WIN32) || defined(__CYGWIN__)
    #ifdef LITTLE_ENGINE
        #ifdef __GNUC__
            #define LITTLE_ENGINE_API __attribute__((dllexport))
        #else
            #define LITTLE_ENGINE_API __declspec(dllexport)
        #endif
    #else
        #ifdef __GNUC__
            #define LITTLE_ENGINE_API __attribute__((dllimport))
        #else
            #define LITTLE_ENGINE_API __declspec(dllimport)
        #endif
    #endif
#elif __GNUC__ >= 4
    // #ifdef LITTLE_GRAPHICS_ENGINE
        #define LITTLE_ENGINE_API __attribute__((visibility("default")))
    // #else
        // #define LITTLE_ENGINE_API
    // #endif
#endif

#endif
