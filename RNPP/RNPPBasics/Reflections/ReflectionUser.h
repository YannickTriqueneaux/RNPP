#pragma once
#include <iostream>
#include "../RNPPBasics.h"
#include "../Utils/Macros.h"
#include "Descriptor.h"
#include <string>
#include "DescriptorRegistry.h"
#include "GenericDescriptor.h"
#include "NativeDescriptor.h"
#include "StringDescriptor.h"
#include "DescriptorHelper.h"

#include "DescriptorInternalImpls.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflections {


    class NO_PARENT_CLASS{
    public:
        static Descriptor const * _getClassDescriptor(){ return nullptr; }
    };


#define REFLECTED_CLASS\
    public:\
    virtual RNPPBasics::Reflections::Descriptor const * getDescriptor() const; \
    static RNPPBasics::Reflections::Descriptor const * _getClassDescriptor(); \
    static const bool _isTemplateClass = false;\
    static std::string const & _getClassName();\
    private:\
    typedef RNPPBasics::Reflections::NO_PARENT_CLASS Reflected_ParentClass;



#define REFLECTED_SUPER_CLASS(ParentClass)\
    public:\
    virtual RNPPBasics::Reflections::Descriptor const * getDescriptor() const;\
    static RNPPBasics::Reflections::Descriptor const * _getClassDescriptor();\
    static const bool _isTemplateClass = false;\
    static std::string const & _getClassName();\
    private:\
    typedef ParentClass Reflected_ParentClass;

#define REFLECTED_TEMPLATE_CLASS\
    private:\
    typedef NO_PARENT_CLASS Reflected_ParentClass; \

#define REFLECTED_SUPER_TEMPLATE_CLASS(ParentClass)\
    private:\
    typedef ParentClass Reflected_ParentClass; \



#define REFLECT_CLASS_BEGIN(ClassName)\
    RNPPBasics::Reflections::Descriptor const * ClassName::getDescriptor() const{\
        return ClassName::_getClassDescriptor();\
    }\
    std::string const & ClassName::_getClassName(){\
        static const std::string _instanceTypeName(STRINGIZE(ClassName));\
        return _instanceTypeName;\
    }\
    RNPPBasics::Reflections::Descriptor const * ClassName::_getClassDescriptor(){\
        using namespace RNPPBasics::Reflections;\
        static Descriptor const * _descriptor = nullptr;\
        if(_descriptor){\
            return _descriptor;\
                                        }\
        _descriptor = DescriptorRegistry::_getDescriptor(STRINGIZE(ClassName));\
        if(_descriptor != nullptr){\
            return _descriptor;\
                                        }\
        ClassName * memory = nullptr;\
        Descriptor * newDescriptor = DescriptorRegistry::_createDescriptor<GenericDescriptor<ClassName>>();\
        newDescriptor->setParentClassDescriptor(Reflected_ParentClass::_getClassDescriptor());

#pragma warning(disable:6011)
#define REFLECT_FIELD(fieldname)\
    RNPPBasics::Reflections::Field const * field_##fieldname =  newDescriptor->addField(STRINGIZE(fieldname),&memory->fieldname, DescriptorHelper<decltype(fieldname)>::DescriptorType::_getDescriptorInstance())
#pragma warning(default:6011)

#define REFLECT_CLASS_END\
    _descriptor = newDescriptor;\
    return _descriptor;\
    }

#define REFLECT_TEMPLATE_CLASS_BEGIN(ClassName,InferType)\
private:\
    typedef InferType _InferType; \
    static const int _inferTypeNumber = 1;\
    static const bool _isTemplateClass = true;\
    friend class RNPPBasics::Reflections::GenericDescriptor< ClassName<InferType> > ;\
public:\
    static std::string const & _getClassName(){\
        using namespace RNPPBasics::Reflections;\
        static std::string const templateClassName = std::string(STRINGIZE(ClassName)).append("<").append(DescriptorHelper<InferType>::DescriptorType::_getInstanceTypeName()).append(">");\
        return templateClassName;\
    }\
    virtual RNPPBasics::Reflections::Descriptor const * getDescriptor() const {\
        return ClassName<InferType>::_getClassDescriptor();\
    }\
    static RNPPBasics::Reflections::Descriptor const * _getClassDescriptor(){\
        using namespace RNPPBasics::Reflections;\
        static Descriptor const * _descriptor = nullptr;\
        if (_descriptor){\
            return _descriptor;\
        }\
        _descriptor = DescriptorRegistry::_getDescriptor(_getClassName());\
        if (_descriptor != nullptr){\
            return _descriptor;\
        }\
        ClassName<InferType> * memory = nullptr;\
        GenericDescriptor<ClassName<InferType>> * newDescriptor = (GenericDescriptor<ClassName<InferType>>*)DescriptorRegistry::_createDescriptor<GenericDescriptor<ClassName<InferType>>>();\
        newDescriptor->setParentClassDescriptor(Reflected_ParentClass::_getClassDescriptor());\
        newDescriptor->addInferType<InferType>();



};};//TENS