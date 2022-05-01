#pragma once
#include "StringId.h"
#include "Context.h"

class ContextManager
{
    std::unordered_map<StringId, Context, StringId::hasher_t> m_contexts;

public:
    Context& GetContext(const StringId& contextId) const;
    Context& CreateContext(const StringId& contextId);
    void DeleteContext(const StringId& contextId);
};

