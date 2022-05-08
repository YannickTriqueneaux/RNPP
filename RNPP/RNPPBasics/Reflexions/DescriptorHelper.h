#include "Descriptor.h"
#include "NativeDescriptor.h"
#include "GenericDescriptor.h"
#include "StringDescriptor.h"


RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflexions{


template<typename Type>
Descriptor const * getDescriptorOf(Type const & instance){
	return DescriptorHelper<Type>::DescriptorType::_getDescriptorInstance();
}
//template<typename Type>
//Descriptor const * getDescriptorOf(Type const &&){
//	return DescriptorHelper<Type>::DescriptorType::getDescriptorInstance();
//}
template<typename Type>
Descriptor const * getDescriptorOf(){
	return DescriptorHelper<Type>::DescriptorType::_getDescriptorInstance();
}

template<typename Type>
struct DescriptorHelper{
	typedef GenericDescriptor<Type> DescriptorType;
};

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
struct DescriptorHelper<StringId>{
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
struct DescriptorHelper < StringId const > {
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


};
RNPPBASICS_NAMESPACE_END()


