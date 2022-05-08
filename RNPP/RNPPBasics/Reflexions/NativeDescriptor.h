RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflexions{

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
    static StringId const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
    static StringId const & _getInstanceTypeName(){
        static StringId const _instanceTypeName(_stringize(bool));
		return _instanceTypeName;
    }
    virtual StringId const & getInstanceTypename() const {
        return _getInstanceTypeName();
    }
	typedef NativeDescriptor<bool> SelfType;
	typedef int InstanceType;
    static StringId const & _getDescriptorName(){
		return _descriptorName;
	}
    virtual StringId const & getName() const {
        return _getDescriptorName();
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
    virtual bool instanceToBoolean(Instance const & instance) const;
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};
template<>
class NativeDescriptor<int> : public NumberBaseDescriptor{
    static StringId const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
    static StringId const & _getInstanceTypeName(){
        static StringId const _instanceTypeName(_stringize(int));
		return _instanceTypeName;
    }
    virtual StringId const & getInstanceTypename() const {
        return _getInstanceTypeName();
    }
	typedef NativeDescriptor<int> SelfType;
	typedef int InstanceType;
    static StringId const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual StringId const & getName() const {
        return _getDescriptorName();
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
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		_descriptor = newDescriptor;
		return _descriptor;
	}
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<short> : public NumberBaseDescriptor{
    static StringId const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<short> SelfType;
	typedef int InstanceType;
    static StringId const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual StringId const & getName() const {
        return _getDescriptorName();
    }
    static StringId const & _getInstanceTypeName(){
        static StringId const _instanceTypeName(_stringize(short));
		return _instanceTypeName;
    }
    virtual StringId const & getInstanceTypename() const {
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
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		_descriptor = newDescriptor;
		return _descriptor;
    }
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<long> : public NumberBaseDescriptor{
    static StringId const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<long> SelfType;
	typedef long InstanceType;
	
    static StringId const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual StringId const & getName() const {
        return _getDescriptorName();
    }
    static StringId const & _getInstanceTypeName(){
        static StringId const _instanceTypeName(_stringize(long));
		return _instanceTypeName;
    }
    virtual StringId const & getInstanceTypename() const {
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
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		_descriptor = newDescriptor;
		return _descriptor;
	}
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<float> : public NumberBaseDescriptor{
    static StringId const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<float> SelfType;
	typedef float InstanceType;

    static StringId const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual StringId const & getName() const {
        return _getDescriptorName();
    }
    static StringId const & _getInstanceTypeName(){
        static StringId const _instanceTypeName(_stringize(float));
		return _instanceTypeName;
    }
    virtual StringId const & getInstanceTypename() const {
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
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		_descriptor = newDescriptor;
		return _descriptor;
	}
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<double> : public NumberBaseDescriptor{
    static StringId const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<double> SelfType;
	typedef double InstanceType;

    static StringId const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual StringId const & getName() const {
        return _getDescriptorName();
    }
    static StringId const & _getInstanceTypeName(){
        static StringId const _instanceTypeName(_stringize(double));
		return _instanceTypeName;
    }
    virtual StringId const & getInstanceTypename() const {
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
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		_descriptor = newDescriptor;
		return _descriptor;
	}
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};

template<>
class NativeDescriptor<unsigned int> : public NumberBaseDescriptor{
    static StringId const _descriptorName;
	friend class DescriptorRegistry;
	NativeDescriptor(){}
public:
	typedef NativeDescriptor<unsigned int> SelfType;
	typedef unsigned int InstanceType;

    static StringId const & _getDescriptorName(){
		return _descriptorName;
    }
    virtual StringId const & getName() const {
        return _getDescriptorName();
    }
    static StringId const & _getInstanceTypeName(){
        static StringId const _instanceTypeName(_stringize(unsigned int));
		return _instanceTypeName;
    }
    virtual StringId const & getInstanceTypename() const {
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
		Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<SelfType>();
		_descriptor = newDescriptor;
		return _descriptor;
	}
    virtual void stringize(std::ostream & streamResult, Instance const & instance) const;
};


};
RNPPBASICS_NAMESPACE_END()