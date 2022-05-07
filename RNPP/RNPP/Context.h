#pragma once
#include "INode.h"
#include "IVariable.h"
#include "IConnection.h"
#include "IConnectable.h"
#include "ConnectionResult.h"
#include "IInput.h"
#include "IOutput.h"


RNPP_NAMESPACE_BEGIN()

class INodeType;
class ConverterRegistry;
class IConnectionType;
class IContextExecutor;

class Context
{
public:
    typedef unsigned int id_t;

private:
    id_t m_id;
    const ConverterRegistry* m_converterRegistry;
    Context* m_parent;
    INode* m_associatedNode;

    IContextExecutor* m_executor;

    std::unordered_map<INode::id_t, INode*> m_nodes;
    std::unordered_map<IConnection::id_t, IConnection*> m_connections;
    std::unordered_map<IInput::id_t, IConnection*> m_inputConnections;
    std::unordered_map<IOutput::id_t, std::vector<const IConnection*>> m_outputConnections;


public:
    Context(id_t id, IContextExecutor* executor, const ConverterRegistry* converterRegistry,
        Context* parent = nullptr, INode* associatedNode = nullptr);

    ~Context();

    INode* CreateNode(const INodeType* nodeType);
    const IConnection* Connect(const IOutput* from, const IInput* to, const IConnectionType* connectionType);

    bool DeleteNode(INode::id_t nodeId);
    bool Disconnect(IConnection::id_t connectionId);

    bool OutputChanged(IOutput::id_t outputId);

    virtual bool Step();
};


RNPP_NAMESPACE_END()