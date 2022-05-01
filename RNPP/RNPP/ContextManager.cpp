#include "pch.h"
#include "ContextManager.h"

Context& ContextManager::GetContext(const StringId& contextId) const
{
    auto it = m_contexts.find(contextId);
    assert(it != m_contexts.end() && "Context not found");
    return const_cast<Context&>(it->second);
}

Context& ContextManager::CreateContext(const StringId& contextId)
{
    assert(m_contexts.find(contextId) == m_contexts.end() && "Context with this name already exists");
    return m_contexts.emplace(contextId, Context(contextId)).first->second;
}

void ContextManager::DeleteContext(const StringId& contextId)
{
    auto erasedCount = m_contexts.erase(contextId);
    assert(erasedCount > 0 && "Context with this name does not exists");
}
