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
