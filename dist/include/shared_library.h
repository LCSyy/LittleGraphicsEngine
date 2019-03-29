#ifndef SHARED_LIBRARY_H
#define SHARED_LIBRARY_H

#if defined(_WIN32) || defined(__CYGWIN__)
    #ifdef LITTLE_GRAPHICS_ENGINE
        #ifdef __GNUC__
            #define ENGINE_API __attribute__((dllexport))
        #else
            #define ENGINE_API __declspec(dllexport)
        #endif
    #else
        #ifdef __GNUC__
            #define ENGINE_API __attribute__((dllimport))
        #else
            #define ENGINE_API __declspec(dllimport)
        #endif
    #endif
#elif __GNUC__ >= 4
    // linux...
#endif

#endif // SHARED_LIBRARY_H
