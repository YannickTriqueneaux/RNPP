#pragma once
#include "StringizableDescriptor.h"
#include "Descriptor.h"
#include "../Utils/Macros.h"
#include <string.h>
#include "DescriptorRegistry.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflections {

class StringBaseDescriptor : public StringizableDescriptor{
public:

    virtual bool isAString() const {
        return true;
    }
    virtual void ToString(std::ostream & streamResult, Instance const & instance) const = 0;
};
class StringDescriptor : public StringBaseDescriptor{
    static std::string const _descriptorName;
	friend class DescriptorRegistry;
	StringDescriptor(){}
public:
	typedef StringDescriptor SelfType;
    typedef std::string InstanceType;
    static std::string const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(STRINGIZE(std::string));
		return _instanceTypeName;
    }
    virtual std::string const & getInstanceTypename() const {
        return _getInstanceTypeName();
    }
	static Descriptor const * _getDescriptorInstance(){
		static Descriptor const * _descriptor;
		if(_descriptor){
			return _descriptor;
		}
		_descriptor = DescriptorRegistry::_getDescriptor(_getDescriptorName());
		if(_descriptor != nullptr){
			return _descriptor;
		}
        _descriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		return _descriptor;
	}
    virtual void ToString(std::ostream & streamResult, Instance const & instance) const;
};


};
RNPPBASICS_NAMESPACE_END()