#pragma once
#include "pch.h"
#include "INode.h"
#include "IConnection.h"

RNPP_NAMESPACE_BEGIN()


class IContextExecutor
{
    virtual void Initialize(
        std::unordered_map<INode::id_t, INode*>& nodes,
        std::unordered_map<IConnection::id_t, IConnection*>& connections
    ) = 0;




    virtual bool Execute() = 0;
};

RNPP_NAMESPACE_END()
