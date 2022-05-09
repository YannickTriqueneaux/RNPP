#include "pch.h"
#include "NativeDescriptor.h"
#include "../Utils/Macros.h"
#include "Instance.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflections{


std::string const NativeDescriptor<bool>::_descriptorName = STRINGIZE(NativeDescriptor<bool>);
std::string const NativeDescriptor<int>::_descriptorName = STRINGIZE(NativeDescriptor<int>);
std::string const NativeDescriptor<short>::_descriptorName = STRINGIZE(NativeDescriptor<short>);
std::string const NativeDescriptor<long>::_descriptorName = STRINGIZE(NativeDescriptor<long>);
std::string const NativeDescriptor<float>::_descriptorName = STRINGIZE(NativeDescriptor<float>);
std::string const NativeDescriptor<double>::_descriptorName = STRINGIZE(NativeDescriptor<double>);
std::string const NativeDescriptor<unsigned int>::_descriptorName = STRINGIZE(NativeDescriptor<unsigned int>);


void NativeDescriptor<bool>::ToString(std::ostream & streamResult, Instance const & instance) const{
    assert(!instance.isEmpty() && "NativeDescriptor<bool>::stringize - the given instance is empty");
    streamResult << *reinterpret_cast<bool*>(instance.get());
}
void NativeDescriptor<int>::ToString(std::ostream & streamResult, Instance const & instance) const{
    assert(!instance.isEmpty() && "NativeDescriptor<int>::stringize - the given instance is empty");
    streamResult << *reinterpret_cast<int*>(instance.get());
}
void NativeDescriptor<short>::ToString(std::ostream & streamResult, Instance const & instance) const{
    assert(!instance.isEmpty() && "NativeDescriptor<short>::stringize - the given instance is empty");
    streamResult << *reinterpret_cast<short*>(instance.get());
}
void NativeDescriptor<long>::ToString(std::ostream & streamResult, Instance const & instance) const{
    assert(!instance.isEmpty() && "NativeDescriptor<long>::stringize - the given instance is empty");
    streamResult << *reinterpret_cast<long*>(instance.get());
}
void NativeDescriptor<float>::ToString(std::ostream & streamResult, Instance const & instance) const{
    assert(!instance.isEmpty() && "NativeDescriptor<float>::stringize - the given instance is empty");
    streamResult << *reinterpret_cast<float*>(instance.get());
}
void NativeDescriptor<double>::ToString(std::ostream & streamResult, Instance const & instance) const{
    assert(!instance.isEmpty() && "NativeDescriptor<double>::stringize - the given instance is empty");
    streamResult << *reinterpret_cast<double*>(instance.get());
}
void NativeDescriptor<unsigned int>::ToString(std::ostream & streamResult, Instance const & instance) const{
    assert(!instance.isEmpty() && "NativeDescriptor<unsigned int>::stringize - the given instance is empty");
    streamResult << *reinterpret_cast<unsigned int*>(instance.get());
}

bool NativeDescriptor<bool>::instanceToBoolean(Instance const & instance) const {
    assert(!instance.isEmpty() && "NativeDescriptor<bool>::instanceToBoolean - the given instance if empty");
    return *reinterpret_cast<bool const*>(instance.get());
}

};
RNPPBASICS_NAMESPACE_END()