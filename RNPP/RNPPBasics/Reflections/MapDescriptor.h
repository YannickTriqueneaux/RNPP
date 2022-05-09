#pragma once
#include "../RNPPBasics.h"
#include <assert.h>
#include <string>
#include <unordered_map>
#include <vector>
#include "Descriptor.h"
#include "ArrayDescriptor.h"
#include "Instance.h"
#include "DescriptorRegistry.h"
#include "PairDescriptor.h"

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

	static PairDescriptor<FirstType, SecondType> const * _pairDescriptor;
	MapDescriptor(){}
public:
    static std::string const & _getDescriptorName(){
        static std::string const descriptorName(std::string("MapDescriptor<")
			.append(_pairDescriptor->_getFirstDescriptorInstance()->getInstanceTypename()).append(",")
			.append(_pairDescriptor->_getSecondDescriptorInstance()->getInstanceTypename()).append(">"));
		return descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(std::string("std::unordered_map<").append(_pairDescriptor->_getFirstDescriptorInstance()->getInstanceTypename()).append(",")
			.append(_pairDescriptor->_getSecondDescriptorInstance()->getInstanceTypename()).append(">"));
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

		_descriptor = newDescriptor;
		return _descriptor;
	}

    virtual std::vector<Instance> getInstancesOfElements(Instance const & mapInstance) const {

        assert(!mapInstance.isEmpty() && "MapDescriptor::getInstancesOfElements - the given map instance cannot be empty");
        assert((mapInstance.getType() == this) && "MapDescriptor::getInstancesOfElements - the given instance don't match with the expected descriptor");
        InstanceType const * map = reinterpret_cast<InstanceType const*>(mapInstance.get());
        std::vector<Instance> elements;
        auto end = map->end();
        for (auto it = map->begin(); it != end; ++it)
        {
            elements.emplace_back((void*)(&*it), _pairDescriptor);//remove 'const' form the key value type
        }

        return std::move(elements);
    }
};


};
RNPPBASICS_NAMESPACE_END()