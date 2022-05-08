RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflexions {
    
std::string const StringDescriptor::_descriptorName = _stringize(StringDescriptor);


void StringDescriptor::stringize(std::ostream & streamResult, Instance const & instance) const{
    assert(!instance.isEmpty() && "StringDescriptor::stringize - the given instance is empty");
    streamResult << *reinterpret_cast<std::string*>(instance.get());
}

};
RNPPBASICS_NAMESPACE_END()