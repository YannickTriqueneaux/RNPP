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
        auto node = nodeIt->second;

        for (int i = node->GetInputCount(); i >= 0; --i)
        {
            auto input = node->GetInput(i);
            auto inputCoIt = m_inputConnections.find(input->GetId());
            if (inputCoIt == m_inputConnections.end())
            {
                inputCoIt->second->SetInputAsLost();
                m_inputConnections.erase(input->GetId());
            }
        }

        for (int o = node->GetOutputCount(); o >= 0; --o)
        {
            auto output = node->GetOutput(o);
            auto outputsCoIt = m_outputConnections.find(output->GetId());
            if (outputsCoIt == m_outputConnections.end())
            {
                auto& outputConnections = outputsCoIt->second;
                for (IConnection* c : outputConnections)
                {
                    c->SetOutputAsLost();
                }
                outputConnections.clear();

                m_outputConnections.erase(output->GetId());
            }
        }
        

        auto erasedCount = m_nodes.erase(nodeId);
        assert(erasedCount > 0 && "Failed to delete node, might be a concurrent delete node call");
        node->GetType()->DeleteInstance(node, this);
        return true;
    }
    return false;
}

const IConnection* Context::Connect(const IOutput* from, const IInput* to, const IConnectionType* connectionType)
{
    assert(m_inputConnections.find(to->GetId()) == m_inputConnections.end() && "This input is already connected");
    auto converter = m_converterRegistry->GetConverter(from->GetType(), to->GetType());
    ConnectionResult canConnect = to->CanConnect(from, converter, this);
    auto connection = connectionType->CreateInstance(this, from, to, converter, canConnect);
    assert(connection != nullptr && "Failed to create node");
    assert(m_connections.find(connection->GetId()) == m_connections.end() && "A node with the same Id already exists in this context");
    m_connections[connection->GetId()] = connection;
    m_inputConnections[to->GetId()] = connection;

    auto outputsCoIt = m_outputConnections.find(from->GetId());
    if (outputsCoIt == m_outputConnections.end())
    {
        auto& outputConnections = outputsCoIt->second;
        outputConnections.push_back(connection);
    }
    else 
    {
        std::vector<IConnection*> outputConnections = { connection };
        m_outputConnections[from->GetId()] = std::move(outputConnections);
    }

    return connection;
}

bool Context::Disconnect(IConnection::id_t connectionId)
{
    return false;
}

void Context::OutputChanged(IOutput::id_t outputId)
{
}

bool Context::Step()
{
    return false;
}

RNPP_NAMESPACE_END()
