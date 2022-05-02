#pragma once
#include "StringId.h"
#include "Context.h"
RNPP_NAMESPACE_BEGIN()

class ContextManager
{
    std::unordered_map<StringId, Context, StringId::hasher_t> m_contexts;

public:
    Context& GetContext(const StringId& contextId) const;
    Context& CreateContext(const StringId& contextId);
    void DeleteContext(const StringId& contextId);
};

RNPP_NAMESPACE_END()

