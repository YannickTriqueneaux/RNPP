#pragma once
#include "StringId.h"
#include "Context.h"
RNPP_NAMESPACE_BEGIN()

class ContextManager
{
    std::unordered_map<StringId, Context, StringId::hasher_t> m_contexts;

};

RNPP_NAMESPACE_END()

