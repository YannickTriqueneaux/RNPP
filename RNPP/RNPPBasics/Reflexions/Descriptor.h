
#pragma once
#include <unordered_map>
#include <assert.h>
#include "Field.h"


#include "..\Utils\StringId.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflexions{

class Field;

class Descriptor{
	friend class DescriptorRegistry;
    friend class Field;
protected:
	Descriptor();

public:
    template<typename FieldType>
    Field const * addField(StringId const & fieldName, FieldType const * offset){
        assert(fields.find(fieldName) == fields.end() && "Descriptor::addField - field already added");
        Descriptor const * fieldDescriptor = getDescriptorOf<FieldType>();
        assert(fieldDescriptor && "Descriptor::addField - unknown field descritor");
        auto & pair = fields.insert(std::make_pair(fieldName, Field())).first;
        pair->second = Field(static_cast<int>((unsigned int*)offset - (unsigned int*)0), *fieldDescriptor, pair->first);
        return &(pair->second);
    }

    template<typename FieldType>
    Field const * addDescriptorField(StringId const & fieldName, Descriptor const * offset){
        assert(descriptorField.find(fieldName) == descriptorField.end());
        Descriptor const * fieldDescriptor = getDescriptorOf<FieldType>();
        assert(fieldDescriptor);
        auto & pair = descriptorField.insert(std::make_pair(fieldName, Field())).first;
        pair->second = Field(static_cast<int>((unsigned int*)offset - (unsigned int*)0), *fieldDescriptor, pair->first);
        return &(pair->second);;
    }

    template<typename Type>
    bool isA(){
        auto compareDescriptor = getDescriptorOf<Type>();
        if (compareDescriptor == this){
            return true;
        }
        else{//maybe in inherit class.  Recursive search
            auto parentDesc = getParentClassDescriptor();
            if (parentDesc){
                return parentDesc->isA<Type>();
            }
        }
        return false;
    }

    /**
    * find the Field by the given name
    * @param field name
    * @return nullptr if not found
    */
    Field const * getField(StringId const & fieldName) const ;


    std::vector<Field const *> getFields(bool withParentFields = true) const;

    /**
    * @return true if the given Field exist inside the descriptor
    */
    bool containsField(Field const & field) const ;
    bool containsField(StringId const & fieldname) const ;


    
    static Descriptor const * _getDescriptorInstance();
    virtual void setParentClassDescriptor(Descriptor const * parentClassDescriptor);
    virtual Descriptor const * getParentClassDescriptor() const ;

    virtual StringId const & getName() const ;
    virtual StringId const & getInstanceTypename() const;
    virtual bool isStringizable() const ;
    virtual bool isAnArray() const ;
    virtual bool isAGeneric() const;
    virtual bool isAContainer() const;
private:
    typedef std::unordered_map<StringId, Field> FieldsMapType;
    FieldsMapType fields;
    std::unordered_map<StringId, Descriptor const *> descriptorField;
};


};
RNPPBASICS_NAMESPACE_END()