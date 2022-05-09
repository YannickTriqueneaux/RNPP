#pragma once
//#include "DescriptorHelper.h"
//#include "Descriptor.h"
//#include "GenericDescriptor.h"
//#include "MapDescriptor.h"
//#include "NativeDescriptor.h"
//#include "PairDescriptor.h"
//#include "StringDescriptor.h"
//#include "VectorDescriptor.h"
//#include "DescriptorHelper.h"


RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflections {

    template<typename Type>
    Descriptor const* getDescriptorOf(Type const& instance) {
        return DescriptorHelper<Type>::DescriptorType::_getDescriptorInstance();
    }
    //template<typename Type>
    //Descriptor const * getDescriptorOf(Type const &&){
    //	return DescriptorHelper<Type>::DescriptorType::getDescriptorInstance();
    //}
    template<typename Type>
    Descriptor const* getDescriptorOf() {
        return DescriptorHelper<Type>::DescriptorType::_getDescriptorInstance();
    }
};
RNPPBASICS_NAMESPACE_END()