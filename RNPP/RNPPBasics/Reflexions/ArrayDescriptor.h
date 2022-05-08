
#pragma once
#include <vector>
#include "Descriptor.h"
#include "Instance.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Reflections{

    class ArrayDescriptor : public Descriptor{
    public:
        virtual bool isAnArray() const { 
            return true;
        }
        virtual std::vector<Instance> getInstancesOfElements(Instance const & arrayInstance) const = 0;
    };
};
RNPPBASICS_NAMESPACE_END()