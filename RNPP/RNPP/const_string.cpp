#include "pch.h"
#include "const_string.h"

RNPP_NAMESPACE_BEGIN()

const_string const_string::null()
{
    static const_string nullInstance = const_string();
    return const_string();
}

RNPP_NAMESPACE_END()
