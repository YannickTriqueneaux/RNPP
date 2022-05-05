#include "pch.h"
#include "IConnectable.h"
RNPP_NAMESPACE_BEGIN()

const INode* IConnectable::GetNode() const
{
    return m_node;
}

const Context* IConnectable::GetContext() const
{
    return m_context;
}

#if defined(RNPP_INTERNAL)
void IConnectable::SetNode(IConnectable* instance, INode* node)
{
    assert(instance->m_node == nullptr && "Node already assigned");
    instance->m_node = node;
}

void IConnectable::SetContext(IConnectable* instance, Context* context)
{
    assert(instance->m_context == nullptr && "Context already assigned");
    instance->m_context = context;
}
#endif

RNPP_NAMESPACE_END()