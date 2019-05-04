#ifndef SHARED_LIBRARY_H
#define SHARED_LIBRARY_H

#define LENGINE_NAMESPACE_BEGIN namespace LEngine {
#define LENGINE_NAMESPACE_END }

LENGINE_NAMESPACE_BEGIN

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
    // #ifdef LITTLE_GRAPHICS_ENGINE
        #define ENGINE_API __attribute__((visibility("default")))
    // #else
        // #define ENGINE_API
    // #endif
#endif

#define DISABLE_COPY(ClassType) ClassType(const ClassType&); ClassType &operator=(const ClassType&);
#define FLOAT_PRECISE 0.001f

LENGINE_NAMESPACE_END
#endif // SHARED_LIBRARY_H
