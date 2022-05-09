#pragma once
#include <string>
#include "../RNPPBasics.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflections{

class Instance;
class Descriptor;

class Field{
public:
    Field(int pOffset, Descriptor const & descriptor, std::string const & name);
    void operator=(Field const& other);

    /**
    *  return the instance of this field form his parent
    * @param parent instance
    * @return an empty Instance of the filed is not found into the given parent
    */
    Instance getInstance(Instance const & parent) const;

    /**
    * @return the name of the field
    */
    std::string const & getName() const;

    /**
    * @return the name of the field
    */
    Descriptor const & getType() const;
private:
    Descriptor const * descriptor;
    std::string fieldName;
    unsigned int offset;

private:
    Field();
    friend class Descriptor;
};

};
RNPPBASICS_NAMESPACE_END()