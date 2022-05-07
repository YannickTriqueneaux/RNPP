#include "pch.h"
#include "Context.h"
#include "INodeType.h"
#include "IOutput.h"
#include "IInput.h"
#include "ConverterRegistry.h"
#include "IConnectionType.h"
#include "ICOntextExecutor.h"

RNPP_NAMESPACE_BEGIN()

Context::Context(id_t id, const StringId& name, IContextExecutor* executor, const ConverterRegistry* converterRegistry, 
    Context* parent, INode* associatedNode)
    : m_id(id), m_name(name), m_executor(executor), m_converterRegistry(converterRegistry), m_parent(parent), m_associatedNode(associatedNode)
{
    executor->Initialize(m_nodes, m_connections);
}

Context::~Context() 
{
    m_executor->Uninitialize();
}

INode* Context::CreateNode(const INodeType* nodeType)
{
    auto node = nodeType->CreateInstance(this);
    assert(node != nullptr && "Failed to create node");
    assert(m_nodes.find(node->GetId()) == m_nodes.end() && "A node with the same Id already exists in this context");
    m_nodes[node->GetId()] = node;

    for (int i = node->GetInputCount(); i >= 0; --i)
    {
        auto input = node->GetInput(i);
        IInput::SetNode(input, node);
    }

    for (int o = node->GetOutputCount(); o >= 0; --o)
    {
        auto output = node->GetOutput(o);
        IOutput::SetNode(output, node);
        IOutput::SetContext(output, this);
    }

    m_executor->OnNodeAdded(node);

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
                for (const IConnection* c : outputConnections)
                {
                    const_cast<IConnection*>(c)->SetOutputAsLost();
                }
                outputConnections.clear();

                m_outputConnections.erase(output->GetId());
            }
        }
        

        auto erasedCount = m_nodes.erase(nodeId);
        assert(erasedCount > 0 && "Failed to delete node, might be a concurrent delete node call");


        m_executor->OnNodeRemoved(node);

        node->GetType()->DeleteInstance(node, this);
        return true;
    }
    return false;
}

const IConnection* Context::Connect(const IOutput* from, const IInput* to, const IConnectionType* connectionType)
{
    assert(m_inputConnections.find(to->GetId()) == m_inputConnections.end() && "This input is already connected");
    auto converter = m_converterRegistry->GetConverter(from->GetType(), to->GetType());
    ConnectionResult canConnect = to->CanConnect(from, converter);
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
        std::vector<const IConnection*> outputConnections = { connection };
        m_outputConnections[from->GetId()] = std::move(outputConnections);
    }

    to->GetNode()->OnInputConnected(to, from);

    m_executor->OnConnectionAdded(connection);

    return connection;
}

bool Context::Disconnect(IConnection::id_t connectionId)
{
    auto connectionIt = m_connections.find(connectionId);
    if (connectionIt == m_connections.end())
        return false;
    auto connection = connectionIt->second;
    if (connection->To() != nullptr)
    {
        auto erasedInputConnectionCount = m_inputConnections.erase(connection->To()->GetId());
        assert(erasedInputConnectionCount > 0 && "Input failed to be disconnected, this input was not registered");
        const INode* node = connection->To()->GetNode();
        node->OnInputDisconnected(connection->To(), connection->From());
    }

    if (connection->From() != nullptr)
    {
        auto outputsCoIt = m_outputConnections.find(connection->From()->GetId());
        assert(outputsCoIt != m_outputConnections.end() && "Output failed to be disconnected, this output was not registered");

        auto& outputConnections = outputsCoIt->second;
        auto removedOutputConnectionIt = std::remove(outputConnections.begin(), outputConnections.end(), connection);
        assert(removedOutputConnectionIt != outputConnections.end() && "Output failed to be disconnected, this output was not registered");
        if(outputConnections.size() == 0)
            m_outputConnections.erase(connection->From()->GetId());
    }

    auto erasedConnectionCount = m_connections.erase(connectionId);
    assert(erasedConnectionCount > 0 && "Connection failed to be disconnected, this might be due to a concurrent disconnection");

    m_executor->OnConnectionRemoved(connection);
    
    connection->GetType()->DeleteInstance(connection, this);
    
    return true;
}

bool Context::OutputChanged(IOutput::id_t outputId)
{
    auto outputsCoIt = m_outputConnections.find(outputId);
    if (outputsCoIt == m_outputConnections.end())
        return false;

    auto& outputConnections = outputsCoIt->second;

    assert(outputConnections.size() > 0 && "An output changed without connection to it, but this one hasn't been correctly deleted");
#if !NDEBUG
    for (const IConnection* co : outputConnections)
    {
        //sanity check
        assert(co->From() != nullptr && co->From()->GetId() == outputId && "Invalid connection detected. a connection has been registered but modified without notifying the context. Delete and recreate connections instead of modify them");
    }
#endif
    m_executor->OnOutputChanged(outputConnections[0]->From(), outputConnections);
    return true;
}

bool Context::Step()
{
    return m_executor->Step();
}

RNPP_NAMESPACE_END()
