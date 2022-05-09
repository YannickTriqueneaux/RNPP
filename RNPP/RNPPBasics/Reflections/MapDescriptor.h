#pragma once
#include <assert.h>
#include <string>
#include <unordered_map>
#include "Descriptor.h"
#include "ArrayDescriptor.h"
#include "Instance.h"
#include "DescriptorHelper.h"
#include "DescriptorRegistry.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflections{


class MapDescriptorBase : public ArrayDescriptor {
public:
};

template<typename FirstType,typename SecondType>
class MapDescriptor : public MapDescriptorBase{
    static std::string const descriptorName;

    typedef std::unordered_map<FirstType, SecondType >        InstanceType;
    typedef std::pair<FirstType, SecondType >	    ValueType;
	typedef MapDescriptor<FirstType, SecondType >   SelfType;

	typedef FirstType FirstValueType;
	typedef SecondType SecondValueType;

	friend class DescriptorRegistry;

	static Descriptor const * _pairDescriptor;
	MapDescriptor(){}
public:
    static std::string const & _getDescriptorName(){
        static std::string const descriptorName(std::string("MapDescriptor<")
			.append(DescriptorHelper<FirstValueType>::DescriptorType::_getInstanceTypeName()).append(",")
			.append(DescriptorHelper<SecondValueType>::DescriptorType::_getInstanceTypeName()).append(">"));
		return descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(std::string("std::unordered_map<").append(DescriptorHelper<FirstValueType>::DescriptorType::_getInstanceTypeName()).append(",")
			.append(DescriptorHelper<SecondValueType>::DescriptorType::_getInstanceTypeName()).append(">"));
		return _instanceTypeName;
    }
    virtual std::string const & getInstanceTypename() const {
        return _getInstanceTypeName();
    }
	static Descriptor const * _getDescriptorInstance(){
		static Descriptor const * _descriptor;
		if (_descriptor){
			return _descriptor;
		}
		_descriptor = DescriptorRegistry::_getDescriptor(_getDescriptorName());
		if (_descriptor != nullptr){
			return _descriptor;
		}
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>(); 
		_pairDescriptor = getDescriptorOf<ValueType>();
		_descriptor = newDescriptor;
		return _descriptor;
	}

    virtual std::vector<Instance> getInstancesOfElements(Instance const & mapInstance) const {

        assert(!mapInstance.isEmpty() && "MapDescriptor::getInstancesOfElements - the given map instance cannot be empty");
        assert((mapInstance.getType() == this) && "MapDescriptor::getInstancesOfElements - the given instance don't match with the expected descriptor");
        InstanceType const * vector = reinterpret_cast<InstanceType const*>(mapInstance.get());
        std::vector<Instance> elements;
        std::for_each(vector->begin(), vector->end(), [&elements](typename InstanceType::value_type const & elmt){
            elements.push_back(const_cast<ValueType*>(reinterpret_cast<const ValueType*>(&elmt)));//remove 'const' form the key value type
        });
        return std::move(elements);
    }
};

template<typename FirstValueType, typename SecondValueType>
Descriptor const * MapDescriptor<FirstValueType, SecondValueType>::_pairDescriptor = nullptr;


};
RNPPBASICS_NAMESPACE_END()