#pragma once
#include "INode.h"
#include "IVariable.h"
#include "IConnection.h"
#include "IConnectable.h"
#include "StringId.h"
#include "ConnectionResult.h"


RNPP_NAMESPACE_BEGIN()

class INodeType;
class IInput;
class IOutput;
class ConverterRegistry;
class IConnectionType;

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

    std::unordered_map<id_t, Context*> m_innerContexts;
    std::unordered_map<INode::id_t, INode*> m_nodes;
    std::unordered_map<IVariable::id_t, IVariable*> m_variables;
    std::unordered_map<IConnection::id_t, IConnection*> m_connections;
    std::unordered_map<IConnectable::id_t, IConnectable*> m_connectables;


public:
    Context(id_t id, const StringId& name, const ConverterRegistry* converterRegistry, Context* parent = nullptr, INode* associatedNode = nullptr)
        : m_id(id), m_name(name), m_converterRegistry(converterRegistry), m_parent(parent), m_associatedNode(associatedNode) {}

    INode* CreateNode(const INodeType* nodeType);
    const IConnection* Connect(const IOutput* from, const IInput* to, const IConnectionType* connectionType);


    bool DeleteNode(INode::id_t nodeId);
    bool Disconnect(IConnection::id_t connectionId);

    virtual bool Step();
};


RNPP_NAMESPACE_END()