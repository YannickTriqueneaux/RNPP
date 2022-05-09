#include "pch.h"
#include "Stringizer.h"
#include <iostream>
#include "..\Reflections\Instance.h"
#include "..\Reflections\StringDescriptor.h"

RNPPBASICS_NAMESPACE_BEGIN()
namespace Serializations{
    namespace Stringizer {
        using Reflections::Instance;

        bool instanceToString(std::ostream& streamResult, Instance const& instance) {
            if (!instance.isEmpty()
                && instance.getType()->isStringizable()) {
                static_cast<Reflections::StringizableDescriptor const*>(instance.getType())->ToString(streamResult, instance);
                return true;
            }
            return false;
        }
    }
};
RNPPBASICS_NAMESPACE_END()