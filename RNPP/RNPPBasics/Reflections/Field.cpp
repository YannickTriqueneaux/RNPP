#include "pch.h"
#include "Field.h"
#include "../RNPPBasics.h"
#include <assert.h>
#include "Descriptor.h"
#include "Instance.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflections{

Field::Field() :descriptor(nullptr), fieldName(nullptr){}


Field::Field(int pOffset, Descriptor const & descriptor, std::string const & name) 
    : offset(pOffset)
    , descriptor(&descriptor)
    , fieldName(name){

}

void Field::operator=(Field const& other)
{
    offset = other.offset;
    descriptor = other.descriptor;
    fieldName = other.fieldName;
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

std::string const & Field::getName() const{
    return fieldName;
}

Descriptor const & Field::getType() const {
    return *descriptor;
}


};
RNPPBASICS_NAMESPACE_END()