#pragma once
#include <string.h>
#include <string>
#include <utility>
#include "Descriptor.h"
#include "DescriptorRegistry.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflections{

class PairDescriptorBase : public Descriptor {
public:
    virtual bool isAContainer() const {
        return true;
    }
};

template<typename FirstType, typename SecondType>
class PairDescriptor : public PairDescriptorBase{
	typedef FirstType                                   FirstValueType;
	typedef SecondType                                  SecondValueType;
    typedef std::pair<FirstValueType, SecondValueType>   InstanceType;
	typedef PairDescriptor<FirstType, SecondType >      SelfType;


	friend class DescriptorRegistry;

	static Descriptor const * _firstDescriptor;
	static Descriptor const * _secondDescriptor;
public:
	PairDescriptor(){}
    static std::string const & _getDescriptorName(){
        static std::string const _descriptorName(std::string("PairDescriptor<")
			.append(_firstDescriptor->getInstanceTypename()).append(",")
			.append(_secondDescriptor->getInstanceTypename()).append(">"));
		 return _descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    virtual std::string const & getInstanceTypename() const {
        return _getInstanceTypeName();
    }
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(std::string("std::pair<").append(_firstDescriptor->getInstanceTypename()).append(",")
			.append(_secondDescriptor->getInstanceTypename()).append(">"));
		return _instanceTypeName;
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

        InstanceType * memory = 0;
        newDescriptor->addField("key", &memory->first, _firstDescriptor);
        newDescriptor->addField("value", &memory->second, _secondDescriptor);

		_descriptor = newDescriptor;
		return _descriptor;
    }
    static Descriptor const* _getFirstDescriptorInstance()
    {
        return _firstDescriptor;
    }
    static Descriptor const* _getSecondDescriptorInstance()
    {
        return _secondDescriptor;
    }
};

};
RNPPBASICS_NAMESPACE_END()