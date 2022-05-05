// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// add headers that you want to pre-compile here

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <type_traits>
#include <chrono>
#include <functional>


#include <memory>
#include <assert.h>

#if !defined(RNPP_NAMESPACE)//can be overridden by compiler arguments in case of conflict
    #define RNPP_NAMESPACE RNPP
#endif

#define RNPP_INTERNAL

#define RNPP_NAMESPACE_BEGIN() namespace RNPP_NAMESPACE {
#define RNPP_NAMESPACE_END() }

#if !defined(RNPP_ALLOW_PARALLEL)//can be overridden by compiler arguments
    #define RNPP_ALLOW_PARALLEL() true
    
    #if RNPP_ALLOW_PARALLEL()
    
        #if !defined(NO_PPL)
            #include <concurrent_vector.h>
            #include <concurrent_unordered_set.h>
            
            #define concurrent_vector Concurrency::concurrent_vector
            #define concurrent_unordered_set Concurrency::concurrent_unordered_set
            
        #else
            #include "concurrent_custom.h"//customize compiler arguments include paths to make it find your own
        #endif
    
    #endif

#else
    #define RNPP_ALLOW_PARALLEL() false
#endif
