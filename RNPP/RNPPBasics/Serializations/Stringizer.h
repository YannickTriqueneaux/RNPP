#pragma once
#include "../RNPPBasics.h"
#include <iostream>


RNPPBASICS_NAMESPACE_BEGIN()

namespace Reflections { class Instance; }

namespace Serializations {
    namespace Stringizer {
        using Reflections::Instance;
        bool instanceToString(std::ostream& streamResult, Instance const& instance);

    };
};
RNPPBASICS_NAMESPACE_END()