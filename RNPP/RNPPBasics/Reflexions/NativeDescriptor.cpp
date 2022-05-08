#include "pch.h"
#include "NativeDescriptor.h"
#include "Instance.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflexions{


StringId const NativeDescriptor<bool>::_descriptorName = _stringize(NativeDescriptor<bool>);
StringId const NativeDescriptor<int>::_descriptorName = _stringize(NativeDescriptor<int>);
StringId const NativeDescriptor<short>::_descriptorName = _stringize(NativeDescriptor<short>);
StringId const NativeDescriptor<long>::_descriptorName = _stringize(NativeDescriptor<long>);
StringId const NativeDescriptor<float>::_descriptorName = _stringize(NativeDescriptor<float>);
StringId const NativeDescriptor<double>::_descriptorName = _stringize(NativeDescriptor<double>);
StringId const NativeDescriptor<unsigned int>::_descriptorName = _stringize(NativeDescriptor<unsigned int>);


void NativeDescriptor<bool>::stringize(std::ostream & streamResult, Instance const & instance) const{
    assert(!instance.isEmpty() && "NativeDescriptor<bool>::stringize - the given instance is empty");
    streamResult << *reinterpret_cast<bool*>(instance.get());
}
void NativeDescriptor<int>::stringize(std::ostream & streamResult, Instance const & instance) const{
    assert(!instance.isEmpty() && "NativeDescriptor<int>::stringize - the given instance is empty");
    streamResult << *reinterpret_cast<int*>(instance.get());
}
void NativeDescriptor<short>::stringize(std::ostream & streamResult, Instance const & instance) const{
    assert(!instance.isEmpty() && "NativeDescriptor<short>::stringize - the given instance is empty");
    streamResult << *reinterpret_cast<short*>(instance.get());
}
void NativeDescriptor<long>::stringize(std::ostream & streamResult, Instance const & instance) const{
    assert(!instance.isEmpty() && "NativeDescriptor<long>::stringize - the given instance is empty");
    streamResult << *reinterpret_cast<long*>(instance.get());
}
void NativeDescriptor<float>::stringize(std::ostream & streamResult, Instance const & instance) const{
    assert(!instance.isEmpty() && "NativeDescriptor<float>::stringize - the given instance is empty");
    streamResult << *reinterpret_cast<float*>(instance.get());
}
void NativeDescriptor<double>::stringize(std::ostream & streamResult, Instance const & instance) const{
    assert(!instance.isEmpty() && "NativeDescriptor<double>::stringize - the given instance is empty");
    streamResult << *reinterpret_cast<double*>(instance.get());
}
void NativeDescriptor<unsigned int>::stringize(std::ostream & streamResult, Instance const & instance) const{
    assert(!instance.isEmpty() && "NativeDescriptor<unsigned int>::stringize - the given instance is empty");
    streamResult << *reinterpret_cast<unsigned int*>(instance.get());
}

bool NativeDescriptor<bool>::instanceToBoolean(Instance const & instance) const {
    assert(!instance.isEmpty() && "NativeDescriptor<bool>::instanceToBoolean - the given instance if empty");
    return *reinterpret_cast<bool const*>(instance.get());
}

};
RNPPBASICS_NAMESPACE_END()