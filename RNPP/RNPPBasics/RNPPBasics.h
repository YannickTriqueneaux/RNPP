#pragma once


#if !defined(RNPPBasics_NAMESPACE)//can be overridden by compiler arguments in case of conflict
#define RNPPBASICS_NAMESPACE RNPPBasics
#endif

#define RNPPBASICS_INTERNAL

#define RNPPBASICS_NAMESPACE_BEGIN() namespace RNPPBASICS_NAMESPACE {
#define RNPPBASICS_NAMESPACE_END() }

#if !defined(RNPPBASICS_ALLOW_PARALLEL)//can be overridden by compiler arguments
#define RNPPBASICS_ALLOW_PARALLEL() true

#if RNPPBASICS_ALLOW_PARALLEL()

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