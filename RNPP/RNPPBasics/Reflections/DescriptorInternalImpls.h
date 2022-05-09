#pragma once
#include "../RNPPBasics.h"
#include "DescriptorHelper.h"
#include "VectorDescriptor.h"
#include "PairDescriptor.h"
#include "MapDescriptor.h"


RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflections {

    template<typename Type>
    template<typename InferType>
    void GenericDescriptor<Type>::addInferType() {

        Descriptor const* inferDescriptor = DescriptorHelper<InferType>::DescriptorType::_getDescriptorInstance();
        if (inferDescriptor) {
            inferDescriptors.push_back(inferDescriptor);
        }
    }

    template<typename T>
    std::string const& VectorDescriptor<T>::_getInstanceTypeName() {
        static std::string const _instanceTypeName(std::string("std::vector<").append(DescriptorHelper<T>::DescriptorType::_getInstanceTypeName()).append(">"));
        return _instanceTypeName;
    }

    template<typename T>
    Descriptor const* VectorDescriptor<T>::_valueDescriptor = DescriptorHelper<T>::DescriptorType::_getDescriptorInstance();

    template<typename T>
    std::string const VectorDescriptor<T>::_descriptorName = std::string("VectorDescriptor<" + DescriptorHelper<T>::DescriptorType::_getInstanceTypeName()).append(">");


    template<typename FirstValueType, typename SecondValueType>
    Descriptor const* PairDescriptor<FirstValueType, SecondValueType>::_firstDescriptor = DescriptorHelper<FirstValueType>::DescriptorType::_getDescriptorInstance();
    template<typename FirstValueType, typename SecondValueType>
    Descriptor const* PairDescriptor<FirstValueType, SecondValueType>::_secondDescriptor = DescriptorHelper<SecondValueType>::DescriptorType::_getDescriptorInstance();


    template<typename FirstValueType, typename SecondValueType>
    PairDescriptor<FirstValueType, SecondValueType> const* MapDescriptor<FirstValueType, SecondValueType>::_pairDescriptor = (PairDescriptor<FirstValueType, SecondValueType>*) PairDescriptor<FirstValueType, SecondValueType>::_getDescriptorInstance();

}
RNPPBASICS_NAMESPACE_END()
