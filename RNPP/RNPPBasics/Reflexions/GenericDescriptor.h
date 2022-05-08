RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflexions{

template<typename Type>
class GenericDescriptor : public Descriptor{
    static StringId const _descriptorName;
	friend class DescriptorRegistry;
	GenericDescriptor():parentClassDescriptor(nullptr){}
    static StringId const & _getDescriptorName(){
		return _descriptorName;
	}
	Descriptor const * parentClassDescriptor;
    std::vector<Descriptor const*> inferDescriptors;
public:
    virtual StringId const & getName() const {
        return _getDescriptorName();
    }
    static StringId const & _getInstanceTypeName(){
        return Type::_getClassName();
    }
    virtual StringId const & getInstanceTypename() const {
        return _getInstanceTypeName();
    }
	static bool _isTemplateClass(){
		return Type::_isTemplateClass;
	}
	typedef GenericDescriptor<Type> SelfType;
	typedef Type InstanceType;
	static Descriptor const * _getDescriptorInstance(){
        return Type::_getClassDescriptor();
	}
	virtual void setParentClassDescriptor(Descriptor const * parentClassDescriptor){
		this->parentClassDescriptor = parentClassDescriptor;
	}

	template<typename InferType>
	inline void addInferType();

	virtual Descriptor const * getParentClassDescriptor() const {
		return parentClassDescriptor;
	}
    virtual bool isAGeneric() const {
        return true;
    }
};


template<typename Type>
StringId const GenericDescriptor<Type>::_descriptorName = StringId("GenericDescriptor<").append(GenericDescriptor<Type>::_getInstanceTypeName()).append(">");

template<typename Type>
template<typename InferType>
void GenericDescriptor<Type>::addInferType(){
    using namespace TrustEngine::System::StringHelper;
    Descriptor const * inferDescriptor = DescriptorHelper<InferType>::DescriptorType::_getDescriptorInstance();
    if (inferDescriptor){
        inferDescriptors << inferDescriptor;
    }
}


};
RNPPBASICS_NAMESPACE_END()
