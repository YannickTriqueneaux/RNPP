#include "pch.h"
#include "Context.h"
#include "INodeType.h"
#include "IOutput.h"
#include "IInput.h"
#include "ConverterRegistry.h"
#include "IConnectionType.h"

RNPP_NAMESPACE_BEGIN()

INode* Context::CreateNode(const INodeType* nodeType)
{
    auto node = nodeType->CreateInstance(this);
    assert(node != nullptr && "Failed to create node");
    assert(m_nodes.find(node->GetId()) == m_nodes.end() && "A node with the same Id already exists in this context");
    m_nodes[node->GetId()] = node;
    return node;
}

bool Context::DeleteNode(INode::id_t nodeId)
{
    auto nodeIt = m_nodes.find(nodeId);
    if (nodeIt != m_nodes.end())
    {
        
    }
    return false;
}

const IConnection* Context::Connect(const IOutput* from, const IInput* to, const IConnectionType* connectionType)
{
    auto converter = m_converterRegistry->GetConverter(from->GetType(), to->GetType());
    ConnectionResult canConnect = to->CanConnect(from, converter);
    auto connection = connectionType->CreateInstance(this, from, to, converter, canConnect);
    assert(connection != nullptr && "Failed to create node");
    assert(m_connections.find(connection->GetId()) == m_connections.end() && "A node with the same Id already exists in this context");
    m_connections[connection->GetId()] = connection;
    return connection;
}

bool Context::Disconnect(IConnection::id_t connectionId)
{
    return false;
}

bool Context::Step()
{
    return false;
}

RNPP_NAMESPACE_END()
