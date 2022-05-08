#include "pch.h"
#include "Field.h"
#include "Descriptor.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflexions{

Field::Field() :descriptor(nullptr), fieldName(nullptr){}


Field::Field(int pOffset, Descriptor const & descriptor, StringId const & name) 
    : offset(pOffset)
    , descriptor(&descriptor)
    , fieldName(name){

}

Instance Field::getInstance(Instance const & parent) const {
    assert(!parent.isEmpty() && "Instance::getInstance - The given parent is empty");
    if (parent.getType()->containsField(*this)) {
        Instance instance(reinterpret_cast<unsigned int*>(parent.get()) + offset, descriptor);
        return instance;
    }
    else{
        return Instance();
    }
}

StringId const & Field::getName() const{
    return fieldName;
}

Descriptor const & Field::getType() const {
    return *descriptor;
}


};
RNPPBASICS_NAMESPACE_END()