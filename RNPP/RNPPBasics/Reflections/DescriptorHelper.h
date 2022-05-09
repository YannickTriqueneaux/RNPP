#pragma once
#include "Descriptor.h"

#include <utility>
#include <vector>
#include <unordered_map>

RNPPBASICS_NAMESPACE_BEGIN()


template<typename T>
class NativeDescriptor;
template<typename T>
class GenericDescriptor;
class StringDescriptor;
template<typename T>
class VectorDescriptor;
template<typename T, typename U>
class PairDescriptor;
template<typename T, typename U>
class MapDescriptor;

namespace Reflections{


template<typename Type>
struct DescriptorHelper;

template<>
struct DescriptorHelper < double > {
    typedef NativeDescriptor<double> DescriptorType;
};
template<>
struct DescriptorHelper < bool > {
	typedef NativeDescriptor<bool> DescriptorType;
};
template<>
struct DescriptorHelper<int>{
	typedef NativeDescriptor<int> DescriptorType;
};

template<>
struct DescriptorHelper<unsigned int>{
	typedef NativeDescriptor<unsigned int> DescriptorType;
};

template<>
struct DescriptorHelper<short>{
	typedef NativeDescriptor<short> DescriptorType;
};

template<>
struct DescriptorHelper<unsigned short>{
	typedef NativeDescriptor<unsigned short> DescriptorType;
};

template<>
struct DescriptorHelper<float>{
	typedef NativeDescriptor<float> DescriptorType;
};

template<>
struct DescriptorHelper<std::string>{
	typedef StringDescriptor DescriptorType;
};

template<typename T>
struct DescriptorHelper<std::vector<T>>{
	typedef VectorDescriptor<T> DescriptorType;
};

template<typename T, typename U>
struct DescriptorHelper<std::unordered_map<T, U>> {
	typedef MapDescriptor<T, U> DescriptorType;
};

template<typename T, typename U>
struct DescriptorHelper<std::pair<T, U>> {
	typedef PairDescriptor<T, U> DescriptorType;
};

//constant types support
template<>
struct DescriptorHelper < std::string const > {
    typedef StringDescriptor DescriptorType;
};

template<typename T>
struct DescriptorHelper < std::vector<T> const > {
    typedef VectorDescriptor<T> DescriptorType;
};

template<typename T, typename U>
struct DescriptorHelper < std::unordered_map<T, U> const > {
    typedef MapDescriptor<T, U> DescriptorType;
};
template<typename T, typename U>
struct DescriptorHelper < std::pair<T, U> const > {
    typedef PairDescriptor<T, U> DescriptorType;
};

template<typename Type>
struct DescriptorHelper {
    typedef GenericDescriptor<Type> DescriptorType;
};



};
RNPPBASICS_NAMESPACE_END()


