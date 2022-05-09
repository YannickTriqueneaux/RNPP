#include "pch.h"
#include "StringDescriptor.h"
#include <iostream>
#include "Instance.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflections {
    
std::string const StringDescriptor::_descriptorName = STRINGIZEStringDescriptor);


void StringDescriptor::ToString(std::ostream & streamResult, Instance const & instance) const{
    assert(!instance.isEmpty() && "StringDescriptor::stringize - the given instance is empty");
    streamResult << *reinterpret_cast<std::string*>(instance.get());
}

};
RNPPBASICS_NAMESPACE_END()