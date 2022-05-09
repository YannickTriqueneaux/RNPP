#pragma once
#include "../RNPPBasics.h"
#include "../Reflections/Instance.h"
#include "Page.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Serializations{

    template<typename FORMAT>
    class InstanceSerializer{
    public:
        InstanceSerializer(Instance const & instanceToSerialize) : instance(instanceToSerialize){}

        bool serialize(std::ostream & streamResult);
    private:
        Instance instance;
        Page<FORMAT> page;
        bool alreadyParsed = false;
    };

};
RNPPBASICS_NAMESPACE_END()