#pragma once
#include <iostream>
#include "../Utils/Macros.h"
#include "StringDescriptor.h"
#include "DescriptorRegistry.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflections{

template<typename Type>
class NativeDescriptor : public StringizableDescriptor{
};

class BooleanBaseDescriptor : public StringizableDescriptor{
public:
    virtual bool instanceToBoolean(Instance const & instance) const = 0;
    virtual bool isABoolean() const {
        return true;
    }
};

class NumberBaseDescriptor : public StringizableDescriptor{
public:
    virtual bool isANumber() const {
        return true;
    }
};

template<>
class NativeDescriptor<bool> : public BooleanBaseDescriptor{
    static std::string const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(STRINGIZE(bool));
		return _instanceTypeName;
    }
    virtual std::string const & getInstanceTypename() const {
        return _getInstanceTypeName();
    }
	typedef NativeDescriptor<bool> SelfType;
	typedef int InstanceType;
    static std::string const & _getDescriptorName(){
		return _descriptorName;
	}
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
	static Descriptor const * _getClassDescriptor(){
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
    virtual bool instanceToBoolean(Instance const & instance) const;
    virtual void ToString(std::ostream & streamResult, Instance const & instance) const;
};
template<>
class NativeDescriptor<int> : public NumberBaseDescriptor{
    static std::string const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(STRINGIZE(int));
		return _instanceTypeName;
    }
    virtual std::string const & getInstanceTypename() const {
        return _getInstanceTypeName();
    }
	typedef NativeDescriptor<int> SelfType;
	typedef int InstanceType;
    static std::string const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
	static Descriptor const * _getClassDescriptor(){
		static Descriptor const * _descriptor;
		if(_descriptor){
			return _descriptor;
		}
		_descriptor = DescriptorRegistry::_getDescriptor(_getDescriptorName());
		if(_descriptor != nullptr){
			return _descriptor;
		}
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		_descriptor = newDescriptor;
		return _descriptor;
	}
    virtual void ToString(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<short> : public NumberBaseDescriptor{
    static std::string const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<short> SelfType;
	typedef int InstanceType;
    static std::string const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(STRINGIZE(short));
		return _instanceTypeName;
    }
    virtual std::string const & getInstanceTypename() const {
        return _getInstanceTypeName();
    }
	static Descriptor const * _getClassDescriptor(){
		static Descriptor const * _descriptor;
		if(_descriptor){
			return _descriptor;
		}
		_descriptor = DescriptorRegistry::_getDescriptor(_getDescriptorName());
		if(_descriptor != nullptr){
			return _descriptor;
		}
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		_descriptor = newDescriptor;
		return _descriptor;
    }
    virtual void ToString(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<long> : public NumberBaseDescriptor{
    static std::string const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<long> SelfType;
	typedef long InstanceType;
	
    static std::string const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(STRINGIZE(long));
		return _instanceTypeName;
    }
    virtual std::string const & getInstanceTypename() const {
        return _getInstanceTypeName();
    }
	static Descriptor const * _getClassDescriptor(){
		static Descriptor const * _descriptor;
		if(_descriptor){
			return _descriptor;
		}
		_descriptor = DescriptorRegistry::_getDescriptor(_getDescriptorName());
		if(_descriptor != nullptr){
			return _descriptor;
		}
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		_descriptor = newDescriptor;
		return _descriptor;
	}
    virtual void ToString(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<float> : public NumberBaseDescriptor{
    static std::string const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<float> SelfType;
	typedef float InstanceType;

    static std::string const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(STRINGIZE(float));
		return _instanceTypeName;
    }
    virtual std::string const & getInstanceTypename() const {
        return _getInstanceTypeName();
    }
	static Descriptor const * _getClassDescriptor(){
		static Descriptor const * _descriptor;
		if(_descriptor){
			return _descriptor;
		}
		_descriptor = DescriptorRegistry::_getDescriptor(_getDescriptorName());
		if(_descriptor != nullptr){
			return _descriptor;
		}
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		_descriptor = newDescriptor;
		return _descriptor;
	}
    virtual void ToString(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<double> : public NumberBaseDescriptor{
    static std::string const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<double> SelfType;
	typedef double InstanceType;

    static std::string const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(STRINGIZE(double));
		return _instanceTypeName;
    }
    virtual std::string const & getInstanceTypename() const {
        return _getInstanceTypeName();
    }
	static Descriptor const * _getClassDescriptor(){
		static Descriptor const * _descriptor;
		if(_descriptor){
			return _descriptor;
		}
		_descriptor = DescriptorRegistry::_getDescriptor(_getDescriptorName());
		if(_descriptor != nullptr){
			return _descriptor;
		}
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		_descriptor = newDescriptor;
		return _descriptor;
	}
    virtual void ToString(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<unsigned int> : public NumberBaseDescriptor{
    static std::string const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<unsigned int> SelfType;
	typedef unsigned int InstanceType;

    static std::string const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual std::string const & getName() const {
        return _getDescriptorName();
    }
    static std::string const & _getInstanceTypeName(){
        static std::string const _instanceTypeName(STRINGIZE(unsigned int));
		return _instanceTypeName;
    }
    virtual std::string const & getInstanceTypename() const {
        return _getInstanceTypeName();
    }
	static Descriptor const * _getClassDescriptor(){
		static Descriptor const * _descriptor;
		if(_descriptor){
			return _descriptor;
		}
		_descriptor = DescriptorRegistry::_getDescriptor(_getDescriptorName());
		if(_descriptor != nullptr){
			return _descriptor;
		}
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		_descriptor = newDescriptor;
		return _descriptor;
	}
    virtual void ToString(std::ostream & streamResult, Instance const & instance) const;
};


};
RNPPBASICS_NAMESPACE_END()