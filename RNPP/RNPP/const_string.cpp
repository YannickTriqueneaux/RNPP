#include "pch.h"
#include "const_string.h"


const_string const_string::null()
{
    static const_string nullInstance = const_string();
    return const_string();
}
