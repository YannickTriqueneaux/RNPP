#include "pch.h"
#include "StringDescriptor.h"
#include <iostream>
#include "Instance.h"
#include "../Utils/Macros.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflections {
    
std::string const StringDescriptor::_descriptorName = STRINGIZE(StringDescriptor);


void StringDescriptor::ToString(std::ostream & streamResult, Instance const & instance) const{
    assert(!instance.isEmpty() && "StringDescriptor::stringize - the given instance is empty");
    streamResult << *reinterpret_cast<std::string*>(instance.get());
}

};
RNPPBASICS_NAMESPACE_END()