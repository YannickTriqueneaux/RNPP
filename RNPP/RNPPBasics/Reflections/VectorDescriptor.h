#pragma once
#include <assert.h>
#include "../Utils/Macros.h"
#include "Instance.h"
#include <string.h>
#include "Descriptor.h"
#include "DescriptorRegistry.h"
#include "ArrayDescriptor.h"
#include <string>

RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflections {

class VectorDescriptorBase : public ArrayDescriptor{
public:
};

template<typename T>
class VectorDescriptor : public VectorDescriptorBase{
    static std::string const _descriptorName;

    typedef std::vector<T>		InstanceType;
	typedef T					ValueType;
	typedef VectorDescriptor<T> SelfType;

	friend class DescriptorRegistry;
	static Descriptor const * _valueDescriptor;
	VectorDescriptor(){}
public:
    static std::string const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    static std::string const& _getInstanceTypeName();

    virtual std::string const & getInstanceTypename() const {
        return _getInstanceTypeName();
    }
	static Descriptor const * _getDescriptorInstance(){
		static Descriptor const * descriptor;
		if(descriptor){
			return descriptor;
		}
		descriptor = DescriptorRegistry::_getDescriptor(_getDescriptorName());
		if(descriptor != nullptr){
			return descriptor;
		}
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		descriptor = newDescriptor;
		return descriptor;
	}

    virtual std::vector<Instance> getInstancesOfElements(Instance const & vectorInstance) const {
        
        assert(!vectorInstance.isEmpty() && "VectorDescriptor::getInstancesOfElements - the given vector instance cannot be empty");
        assert((vectorInstance.getType() == this) && "VectorDescriptor::getInstancesOfElements - the given instance don't match with the expected descriptor");
        InstanceType const * vector = reinterpret_cast<InstanceType const*>(vectorInstance.get());
        std::vector<Instance> elements;
        std::for_each(vector->begin(), vector->end(), [&elements](ValueType const & elmt){
            elements.emplace_back((void*)(&elmt), _valueDescriptor);
        });
        return std::move(elements);
    }
};


};
RNPPBASICS_NAMESPACE_END()