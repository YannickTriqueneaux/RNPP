#pragma once
#include "INode.h"
#include "IVariable.h"
#include "IConnection.h"
#include "IConnectable.h"
#include "StringId.h"
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
    StringId m_name;
    const ConverterRegistry* m_converterRegistry;
    Context* m_parent;
    INode* m_associatedNode;

    IContextExecutor* m_executor;

    std::unordered_map<INode::id_t, INode*> m_nodes;
    std::unordered_map<IConnection::id_t, IConnection*> m_connections;
    std::unordered_map<IInput::id_t, IConnection*> m_inputConnections;
    std::unordered_map<IOutput::id_t, std::vector<IConnection*>> m_outputConnections;

#if RNPP_ALLOW_PARALLEL()
    concurrent_unordered_set<INode::id_t> m_nodesToExecuteIds[2];
    concurrent_vector<INode*> m_nodesToExecuteQueue[2];
    bool m_stepswapIndexes;
#endif

public:
    Context(id_t id, const StringId& name, IContextExecutor* executor, const ConverterRegistry* converterRegistry, Context* parent = nullptr, INode* associatedNode = nullptr)
        : m_id(id), m_name(name), m_executor(executor), m_converterRegistry(converterRegistry), m_parent(parent), m_associatedNode(associatedNode) {}



    INode* CreateNode(const INodeType* nodeType);
    const IConnection* Connect(const IOutput* from, const IInput* to, const IConnectionType* connectionType);

    bool DeleteNode(INode::id_t nodeId);
    bool Disconnect(IConnection::id_t connectionId);

    bool OutputChanged(IOutput::id_t outputId);

    virtual bool Step();
};


RNPP_NAMESPACE_END()