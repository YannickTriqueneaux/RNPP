#include "pch.h"
#include "const_string.h"

RNPPBASICS_NAMESPACE_BEGIN()

const_string const_string::null()
{
    static const_string nullInstance = const_string();
    return const_string();
}

RNPPBASICS_NAMESPACE_END()
