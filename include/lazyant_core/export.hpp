#pragma once

#ifdef LAZYANT_EXPORT
    #if _WIN32
        #define LAZYANT_API __declspec(dllexport)
    #else
        #define LAZYANT_API __attribute__ ((visibility ("default")))
    #endif
#else
    #if _WIN32
        #define LAZYANT_API __declspec(dllimport)
    #else
        #define LAZYANT_API
    #endif
#endif