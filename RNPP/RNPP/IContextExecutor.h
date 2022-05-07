#pragma once
#include "pch.h"
#include "INode.h"
#include "IConnection.h"

RNPP_NAMESPACE_BEGIN()


class IContextExecutor
{
public:
    virtual void Initialize(
        std::unordered_map<INode::id_t, INode*>& nodes,
        std::unordered_map<IConnection::id_t, IConnection*>& connections
    ) = 0;
    virtual void Uninitialize() = 0;

    virtual void OnNodeAdded(const INode* node) = 0;
    virtual void OnNodeRemoved(const INode* code) = 0;
    virtual void OnConnectionAdded(const IConnection* connection) = 0;
    virtual void OnConnectionRemoved(const IConnection* connection) = 0;

    virtual void OnOutputChanged(const IOutput* output, const std::vector<const IConnection*>& connections) = 0;

    virtual bool Step() = 0;
};

RNPP_NAMESPACE_END()
