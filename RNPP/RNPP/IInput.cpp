#include "pch.h"
#include "IInput.h"

RNPP_NAMESPACE_BEGIN()

const INode* IInput::GetNode(const IInput* instance)
{
    return instance->m_node;
}

void IInput::SetNode(IInput* instance, INode* node)
{
    assert(instance->m_node == nullptr && "Node already assigned");
    instance->m_node = node;
}

RNPP_NAMESPACE_END()

