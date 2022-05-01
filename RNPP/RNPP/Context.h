#pragma once
#include "INode.h"
#include "IVariable.h"
#include "IConnection.h"
#include "IConnectable.h"
#include "StringId.h"

class Context
{
    StringId m_name;

    std::unordered_map<INode::id_t, INode*> m_nodes;
    std::unordered_map<IVariable::id_t, IVariable*> m_variables;
    std::unordered_map<IConnection::id_t, IConnection*> m_connections;
    std::unordered_map<IConnectable::id_t, IConnectable*> m_connectables;


public:
    Context(const StringId& name) : m_name(name) {}
};

